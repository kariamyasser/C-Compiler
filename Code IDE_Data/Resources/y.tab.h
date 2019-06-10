
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VALUE = 258,
     FLOAT_VALUE = 259,
     CHAR_VALUE = 260,
     STRING_VALUE = 261,
     COMMENT = 262,
     IDENTIFIER = 263,
     INT = 264,
     CHAR = 265,
     FLOAT = 266,
     STRING = 267,
     BOOLEAN = 268,
     DOUBLE = 269,
     SINGLE_QUOTE = 270,
     DOUBLE_QUOTE = 271,
     SEMI_COLON = 272,
     OPENED_BRACKET = 273,
     CLOSED_BRACKET = 274,
     OPENED_BRACE = 275,
     CLOSED_BRACE = 276,
     OPENED_SQ_BRACKET = 277,
     CLOSED_SQ_BRACKET = 278,
     COMMA = 279,
     TWO_DOTS = 280,
     AND_AND = 281,
     OR_OR = 282,
     EQUAL_EQUAL = 283,
     NOT_EQUAL = 284,
     GREATER_THAN = 285,
     GREATER_THAN_EQUAL = 286,
     SMALLER_THAN = 287,
     SMALLER_THAN_EQUAL = 288,
     NOT = 289,
     PLUS_PLUS = 290,
     MINUS_MINUS = 291,
     PLUS = 292,
     MINUS = 293,
     MULTIPLY = 294,
     DIVIDE = 295,
     REMAINDER = 296,
     PLUS_EQUAL = 297,
     MINUS_EQUAL = 298,
     MULTIPLY_EQUAL = 299,
     DIVIDE_EQUAL = 300,
     IF = 301,
     ELSE = 302,
     DO = 303,
     WHILE = 304,
     FOR = 305,
     SWITCH = 306,
     CASE = 307,
     DEFAULT = 308,
     BREAK = 309,
     TRUE = 310,
     FALSE = 311,
     MAIN = 312,
     VOID = 313,
     EQUAL = 314
   };
#endif
/* Tokens.  */
#define INT_VALUE 258
#define FLOAT_VALUE 259
#define CHAR_VALUE 260
#define STRING_VALUE 261
#define COMMENT 262
#define IDENTIFIER 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define STRING 267
#define BOOLEAN 268
#define DOUBLE 269
#define SINGLE_QUOTE 270
#define DOUBLE_QUOTE 271
#define SEMI_COLON 272
#define OPENED_BRACKET 273
#define CLOSED_BRACKET 274
#define OPENED_BRACE 275
#define CLOSED_BRACE 276
#define OPENED_SQ_BRACKET 277
#define CLOSED_SQ_BRACKET 278
#define COMMA 279
#define TWO_DOTS 280
#define AND_AND 281
#define OR_OR 282
#define EQUAL_EQUAL 283
#define NOT_EQUAL 284
#define GREATER_THAN 285
#define GREATER_THAN_EQUAL 286
#define SMALLER_THAN 287
#define SMALLER_THAN_EQUAL 288
#define NOT 289
#define PLUS_PLUS 290
#define MINUS_MINUS 291
#define PLUS 292
#define MINUS 293
#define MULTIPLY 294
#define DIVIDE 295
#define REMAINDER 296
#define PLUS_EQUAL 297
#define MINUS_EQUAL 298
#define MULTIPLY_EQUAL 299
#define DIVIDE_EQUAL 300
#define IF 301
#define ELSE 302
#define DO 303
#define WHILE 304
#define FOR 305
#define SWITCH 306
#define CASE 307
#define DEFAULT 308
#define BREAK 309
#define TRUE 310
#define FALSE 311
#define MAIN 312
#define VOID 313
#define EQUAL 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 47 "kYacc.y"
     


	int   intValue;	    	/* integer value */
	float floatValue;    	/* float value */
	char  charValue;    	/* char value */
	char* stringValue;  	/* string value*/
	char* identifier;       /* identifier name */
	char* comment;
	char* DataType;
	nodeType* nPtr;




/* Line 1676 of yacc.c  */
#line 186 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


