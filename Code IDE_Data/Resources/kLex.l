%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>

	#include "calc3.h"
	#include "y.tab.h"
	void invalidToken();
	int CURRENT_LINE = 1;
%}

%%

"void"		{return VOID;}
"main"	 	{return MAIN;}
"int" 		{return INT;}
"char" 		{return CHAR;}
"float" 	{return FLOAT;}
"string" 	{return STRING;}
"boolean" 	{return BOOLEAN;}
"double" 	{return DOUBLE;}
"if" 		{return IF;}
"do" 		{return DO;}
"while" 	{return WHILE;}
"for" 		{return FOR;}
"switch"	{return SWITCH;}
"else" 		{return ELSE;}
"break"		{return BREAK;}
"true" 		{return TRUE;}
"false" 	{return FALSE;}
"case" 		{return CASE;}
"default" 	{return DEFAULT;}


"'"  {return SINGLE_QUOTE;}
"\"" {return DOUBLE_QUOTE;}
";"  {return SEMI_COLON;}
"("  {return OPENED_BRACKET;}
")"  {return CLOSED_BRACKET;}
"{"  {return OPENED_BRACE;}
"}"  {return CLOSED_BRACE;}
"["  {return OPENED_SQ_BRACKET;}
"]"  {return CLOSED_SQ_BRACKET;}
","  {return COMMA;}
":"  {return TWO_DOTS;}

"&&" {return AND_AND;}
"||" {return OR_OR;}
"==" {return EQUAL_EQUAL;}
"!=" {return NOT_EQUAL;}
">"  {return GREATER_THAN;}
">=" {return GREATER_THAN_EQUAL;}
"<"  {return SMALLER_THAN;}
"<=" {return SMALLER_THAN_EQUAL;}
"!"  {return NOT;}


"+"  {return PLUS;}
"-"  {return MINUS;}
"*"  {return MULTIPLY;}
"/"  {return DIVIDE;}
"%"  {return REMAINDER;}
"+=" {return PLUS_EQUAL;}
"-=" {return MINUS_EQUAL;}
"*=" {return MULTIPLY_EQUAL;}
"/=" {return DIVIDE_EQUAL;}
"++" {return PLUS_PLUS;}
"--" {return MINUS_MINUS;}
"="  {return EQUAL;}



(-)?[0-9]+ {yylval.intValue = atoi(yytext); return INT_VALUE;}

(-)?[0-9]*\.?[0-9]+ {yylval.floatValue = atof(yytext); return FLOAT_VALUE;}

(_|[a-zA-Z])(_|[a-zA-Z]|[0-9])* { yylval.identifier = strdup(yytext); return IDENTIFIER;}

\'[\x23-\x7E \t !]?\' {yylval.charValue = strdup(yytext); return CHAR_VALUE;}

(\/\/)+[\x23-\x7E \t ! \/]* {yylval.comment = strdup(yytext); return COMMENT;}

\"[\x23-\x7E \t !]*\" {yylval.stringValue = strdup(yytext); return STRING_VALUE;}

\n {CURRENT_LINE++;}

[ \t\r\v\f]+                ;

.  {}

%%


int yywrap(void) {
	return 1;     
} 

void invalidToken(){
	fprintf(stderr,"\n Error Invalid Token on line %d : %s \n",CURRENT_LINE,yytext);
}