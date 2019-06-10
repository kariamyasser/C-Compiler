%{


	#include <stdarg.h>

	#include "compiler.c"

	#include<math.h> 



	

	  int yylex(void);
	extern int CURRENT_LINE;


		/* prototypes */
	nodeType *opr(int oper, int nops, ...);
	nodeType *id( int flag, char name[], int per);
	nodeType *getid(char name[]);
	nodeType *con(char* s, int flag);


	void freeNode(nodeType *p);
	int ex(nodeType *p);



		/*Braces*/

	#define nestingStackMaxLength 15
	int NestingStack[15];
	int level = -1; //The level of the scope  ( we can Inc and Dec this variable)
	int scopeId = 0; //The ID of the scope   (We can only Inc this variable to ensure we have a unique identifer for each scope)

	int isLogical = 0;
	int isDeclaration = 0 ;
	void openScope();
	void closeScope();

	/*End of Braces */

%}


%union {     


	int   intValue;	    	/* integer value */
	float floatValue;    	/* float value */
	char  charValue;    	/* char value */
	char* stringValue;  	/* string value*/
	char* identifier;       /* identifier name */
	char* comment;
	char* DataType;
	nodeType* nPtr;

}; 


%start main
%token <intValue> INT_VALUE
%token <floatValue> FLOAT_VALUE
%token <charValue> CHAR_VALUE
%token <stringValue> STRING_VALUE
%token <comment> COMMENT
%token <identifier> IDENTIFIER



%token <DataType>  INT CHAR FLOAT STRING BOOLEAN DOUBLE


%token SINGLE_QUOTE DOUBLE_QUOTE SEMI_COLON 
%token OPENED_BRACKET CLOSED_BRACKET OPENED_BRACE CLOSED_BRACE OPENED_SQ_BRACKET CLOSED_SQ_BRACKET
%token COMMA TWO_DOTS AND_AND OR_OR EQUAL_EQUAL NOT_EQUAL 
%token GREATER_THAN GREATER_THAN_EQUAL SMALLER_THAN SMALLER_THAN_EQUAL NOT  
%token PLUS_PLUS MINUS_MINUS 
%token PLUS MINUS MULTIPLY DIVIDE REMAINDER 
%token PLUS_EQUAL MINUS_EQUAL MULTIPLY_EQUAL DIVIDE_EQUAL
%token IF ELSE DO WHILE FOR SWITCH CASE  DEFAULT BREAK 
%token TRUE FALSE
%token MAIN VOID
%token EQUAL

%left EQUAL_EQUAL NOT_EQUAL 
%left SMALLER_THAN SMALLER_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%nonassoc PLUS_PLUS MINUS_MINUS
%left PLUS MINUS
%left DIVIDE MULTIPLY REMAINDER
%left OR_OR AND_AND
%left NOT
%right EQUAL 



%nonassoc IF
%nonassoc ELSE


%type <DataType> datatype
%type <nPtr> leftfactor leftfactorlist bodyloop body declaration  assignment mathassignment logicalexpr expr mathexpr pp ifstmt whilestmt forstmt a b dowhilestmt switchstmt casestmt defaultstmt val number   boolean


%%
	/*-------------------------------------------------------------------------------------------------------------------------*/
	/*Language Body */	


program:    main
		;


main: VOID MAIN OPENED_BRACKET CLOSED_BRACKET OPENBRACE body CLOSEBRACE
		;



body:  body leftfactor  { fprintf(yyout," "); int error = ex($2);freeNode($2); if(error == -1) return; }
				|{ $$ = opr(9999, 0);}
			  ;

leftfactor:  whilestmt
						| ifstmt
						| dowhilestmt
						| forstmt
						| switchstmt
						| declaration
						| assignment SEMI_COLON
						| mathassignment SEMI_COLON
						| pp SEMI_COLON
			    ;
	/*-------------------------------------------------------------------------------------------*/



declaration:   datatype IDENTIFIER SEMI_COLON {
									isDeclaration = 1;
								if ($1 == "int" ) $$ = id( 0, $2, 0);
								else if($1 == "float") $$ = id(1, $2, 0);
								else if  ($1 == "char") $$ = id(2, $2, 0);
								else if  ($1 == "string") $$ = id(3, $2, 0);
								else if($1 == "boolean" ) $$ = id( 4, $2, 0);
							}
						| datatype IDENTIFIER EQUAL IDENTIFIER SEMI_COLON {
							if ($1 == "int") {$$ = opr(EQUAL, 2, id(0, $2, 0), getid($4));}
							else if ($1 == "float") {$$ = opr(EQUAL, 2, id( 1, $2, 0), getid($4));}
	  					else if ($1 == "char") {$$ = opr(EQUAL, 2, id(2, $2, 0), getid($4));}
	  					else if ($1 == "string") {$$ = opr(EQUAL, 2, id(3, $2, 0), getid($4));}
							else if ($1 == "boolean") {$$ = opr(EQUAL, 2, id(4, $2, 0), getid($4));}
						  }
						| datatype IDENTIFIER EQUAL val SEMI_COLON {
							  if( $1 == "int")  $$ = opr(EQUAL, 2, id(0, $2, 0), $4);
							  else if($1 == "float") $$ = opr(EQUAL, 2, id(1, $2, 0), $4);
	  						else if($1 == "char")  $$ = opr(EQUAL, 2, id( 2, $2, 0), $4);
	  						else if($1 == "string") $$ = opr(EQUAL, 2, id( 3, $2, 0), $4);
	  						else if($1 == "boolean") $$ = opr(EQUAL, 2, id(4, $2, 0), $4);
		  															}
						| datatype IDENTIFIER EQUAL expr SEMI_COLON {
								if ($1 == "int")  $$ = opr(EQUAL, 2, id(0, $2, 0), $4);
								else if ($1 == "float")   $$ = opr(EQUAL, 2, id(1, $2, 0), $4);
								else if ($1 == "char")   $$ = opr(EQUAL, 2, id(2, $2, 0), $4);
								else if ($1 == "string") $$ = opr(EQUAL, 2, id(3, $2, 0), $4);
								else if ($1 == "boolean") $$ = opr(EQUAL, 2, id(4, $2, 0), $4);
						}
			      ;


assignment: IDENTIFIER EQUAL IDENTIFIER  { $$ = opr(EQUAL, 2, getid($1), getid($3));}
					| IDENTIFIER EQUAL val   { $$ = opr(EQUAL, 2, getid($1), $3);}
					| IDENTIFIER EQUAL expr   { $$ = opr(EQUAL, 2, getid($1), $3);}
					;

	/*-------------------------------------------------------------------------------------------*/

mathassignment:
						   IDENTIFIER MINUS_EQUAL mathexpr { $$ = opr(MINUS_EQUAL, 2, getid($1), $3);}
						 | IDENTIFIER PLUS_EQUAL mathexpr { $$ = opr(PLUS_EQUAL, 2, getid($1), $3);}
						 | IDENTIFIER DIVIDE_EQUAL mathexpr { $$ = opr(DIVIDE_EQUAL, 2, getid($1), $3);}
						 | IDENTIFIER MULTIPLY_EQUAL mathexpr { $$ = opr(MULTIPLY_EQUAL, 2, getid($1), $3);}
				;

	/*-------------------------------------------------------------------------------------------*/

logicalexpr:
					  IDENTIFIER {isLogical=1; $$ = getid($1);}
					  | STRING_VALUE   { isLogical=1; $$ = con($1,3);}
					  | CHAR_VALUE  { char *pChar = malloc(sizeof($1));isLogical=1; $$ = con(pChar,2);}
					  | boolean { $$ = $1; }
					  | INT_VALUE { char c[] = {}; myitoa($1, c, 10); isLogical=1; $$ = con(c,0);}
					  | FLOAT_VALUE {char c[] = {}; myftoa($1, c, 10);isLogical=1;   $$ = con(c,1);}
					  | logicalexpr OR_OR logicalexpr { $$ = opr(OR_OR, 2, $1, $3);}
				 	  | logicalexpr AND_AND logicalexpr { $$ = opr(AND_AND, 2, $1, $3);}
					  | logicalexpr NOT_EQUAL logicalexpr { $$ = opr(NOT_EQUAL, 2, $1, $3);}
					  | logicalexpr EQUAL_EQUAL logicalexpr { $$ = opr(EQUAL_EQUAL, 2, $1, $3);}
					  | mathexpr NOT_EQUAL mathexpr { $$ = opr(NOT_EQUAL, 2, $1, $3);}
				    | mathexpr EQUAL_EQUAL mathexpr { $$ = opr(EQUAL_EQUAL, 2, $1, $3);}
					  | mathexpr GREATER_THAN mathexpr { $$ = opr(GREATER_THAN, 2, $1, $3);}
					  | mathexpr GREATER_THAN_EQUAL mathexpr { $$ = opr(GREATER_THAN_EQUAL, 2, $1, $3);}
					  | mathexpr SMALLER_THAN mathexpr { $$ = opr(SMALLER_THAN, 2, $1, $3);}
					  | mathexpr SMALLER_THAN_EQUAL mathexpr { $$ = opr(SMALLER_THAN_EQUAL, 2, $1, $3);}
					  | NOT logicalexpr { $$ = opr(NOT,1, $2);}
					  |	OPENED_BRACKET logicalexpr CLOSED_BRACKET  { $$ =$2; }
					  ;

expr: mathexpr { $$ = $1; }
	   | logicalexpr { $$ = $1; }
	   ;

	/*-------------------------------------------------------------------------------------------*/
	/*Handling math epressions*/
mathexpr:
			     IDENTIFIER { $$ = getid($1);}
				 | INT_VALUE { char c[] = {}; myitoa($1, c, 10);  $$ = con(c,0);}
				 | FLOAT_VALUE {char c[] = {}; myftoa($1, c, 10);   $$ = con(c,1);}
				 | mathexpr MINUS mathexpr { $$ = opr(MINUS, 2, $1, $3);}
				 | mathexpr PLUS mathexpr { $$ = opr(PLUS, 2, $1, $3);}
				 | mathexpr DIVIDE  mathexpr { $$ = opr(DIVIDE, 2, $1, $3);}
				 | mathexpr MULTIPLY mathexpr  	{ $$ = opr(MULTIPLY, 2, $1, $3);}
				 | mathexpr REMAINDER mathexpr { $$ = opr(REMAINDER, 2, $1, $3);}
				 | OPENED_BRACKET mathexpr CLOSED_BRACKET { $$ = $2; }
				 | pp { $$ = $1; }
	 		 	 ;

pp:  PLUS_PLUS IDENTIFIER  { $$ = opr(PLUS_PLUS, 1,getid($2));}
		| MINUS_MINUS IDENTIFIER { $$ = opr(MINUS_MINUS, 1,getid($2));}
		| IDENTIFIER PLUS_PLUS  { $$ = opr(PLUS_PLUS, 1,getid($1));}
		| IDENTIFIER MINUS_MINUS { $$ = opr(MINUS_MINUS, 1,getid($1));}
		;


	/*-------------------------------------------------------------------------------------------*/


ifstmt: IF OPENED_BRACKET logicalexpr CLOSED_BRACKET OPENBRACE bodyloop CLOSEBRACE { $$ = opr(IF, 2, $3,$6); }
		  | IF OPENED_BRACKET logicalexpr CLOSED_BRACKET OPENBRACE bodyloop CLOSEBRACE ELSE OPENBRACE bodyloop CLOSEBRACE  { $$ = opr(IF, 3, $3,$6,$10); }
		;

		/*-------------------------------------------------------------------------------------------*/



whilestmt: WHILE OPENED_BRACKET logicalexpr CLOSED_BRACKET OPENBRACE bodyloop CLOSEBRACE {$$ = opr(WHILE,2 ,$3,$6) ;}
	;

leftfactorlist:  leftfactorlist leftfactor { $$=$2;} | leftfactor { $$=$1;}
					;
bodyloop: leftfactorlist{ $$=opr(SEMI_COLON,1,$1);}
					| { $$ = opr(9999, 0);}
					;
forstmt: FOR OPENED_BRACKET a b mathexpr CLOSED_BRACKET OPENBRACE bodyloop CLOSEBRACE {$$ = opr(FOR,4,$3,$4,$5,$8) ;}
	;

a:
	declaration {$$ = $1;}
	| assignment SEMI_COLON {$$ = $1 ;}
	;

b:
	logicalexpr SEMI_COLON {$$ = $1 ;}
	;

dowhilestmt: DO OPENBRACE bodyloop CLOSEBRACE WHILE OPENED_BRACKET logicalexpr CLOSED_BRACKET SEMI_COLON {$$ = opr(DO,2,$3,$7) ;}
	;



	/*-------------------------------------------------------------------------------------------*/



switchstmt:
	SWITCH OPENED_BRACKET IDENTIFIER CLOSED_BRACKET OPENBRACE casestmt CLOSEBRACE {$$ = opr(SWITCH,2,getid($3),$6);}
	;

casestmt: CASE val TWO_DOTS bodyloop BREAK SEMI_COLON casestmt {$$ = opr(CASE,4, $2,$4,opr(BREAK,0),$7);}
		     | defaultstmt { $$=$1;}
		     ;

defaultstmt: DEFAULT TWO_DOTS bodyloop BREAK SEMI_COLON {$$ =opr(DEFAULT,2,$3,opr(BREAK,0));}
	;

	/*-------------------------------------------------------------------------------------------------*/
	/*----------------------------------------ALL TERMINALS----------------------------------------------*/
val: number { $$ = $1 ;}
	| STRING_VALUE  { $$ = con($1,3);}
	| CHAR_VALUE  { char *pChar = malloc(sizeof($1)); $$ = con(pChar,2);}
	| boolean { $$ = $1 ;}
	;

number: INT_VALUE { char c[] = {}; myitoa($1, c, 10);  $$ = con(c,0);}
			| FLOAT_VALUE { char c[] = {}; myftoa($1, c, 10);  $$ = con(c,1);}
		;

OPENBRACE: OPENED_BRACE {openScope();};

CLOSEBRACE: CLOSED_BRACE {closeScope();};

datatype: INT {$$ = "int";}
			  | FLOAT { $$ = "float";}
			  | STRING {$$ = "string";}
			  | CHAR {$$ = "char"; }
			  | BOOLEAN {$$ = "boolean";}
			  | DOUBLE {$$ ="double";}
		 ;

boolean: TRUE {  $$ = con("true",4);}
			| FALSE {  $$ = con("false",4);}
	;

%%


#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)

nodeType *con(char* s, int flag) {
	nodeType *p;

	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");

	/* copy information */
	p->type = typeCon;
	p->con.value = strdup(s);
	p->con.flag = flag;
	p->con.isLogical = isLogical;
	isLogical = 0;
	return p;
}

nodeType *id( int flag, char name[], int per) {

	//Implementing new entry in the symbol table :)
	struct symbol_info *STEntry = malloc(sizeof(struct symbol_info));
	(*STEntry).name = name;
	printf("\n %s ",(*STEntry).name);
	(*STEntry).classtype = flag;
	if(level!=-1)
		(*STEntry).scopeId = NestingStack[level];
	if(per == -2)
		(*STEntry).isFinal = true;
	else
		(*STEntry).isFinal = false;


	nodeType *p;

	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");


	if( cInsert(STEntry) )
	{
		p->type = typeId;
		p->id.scopeId = NestingStack[level];
		p->id.name = strdup(name);
		p->id.permission = per;
		p->id.flag = flag;
		p->id.isDeclaration = isDeclaration;
		isDeclaration = 0;
		return p;

	}

	p->id.name = strdup(name);
	p->type = typeId;
	p->id.permission = -3;
	return p;
}

nodeType *getid(char name[]) {
	nodeType *p;

	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");

	int *errorMsg;
	struct symbol_info *STEntry = valSearch(name,NestingStack,level,errorMsg);
	p->type = typeId;
	p->id.name = strdup(name);
	if(*errorMsg == 404){
		p->id.permission = -1;
		return p;
	}
	else if((*STEntry).isFinal == true)
				p->id.permission = -2;
	else
				p->id.permission = 43;

	p->id.flag = STEntry->classtype;
	p->id.scopeId = STEntry->scopeId;
	p->id.name = strdup(name);


	p->type = typeId;

	isLogical=0;
	return p;
}

nodeType *opr(int oper, int nops, ...) {
	va_list ap;
	nodeType *p;
	int i;

	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");

	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);

	va_end(ap);

	return p;
}

void freeNode(nodeType *p) {
	int i;
	if (!p)
		return;

	if (p->type == typeOpr) {
		for (i = 0; i < p->opr.nops; i++)
			freeNode(p->opr.op[i]);
	}

	free (p);
}


void openScope(){
	level = level + 1;
	printf("\n new level %d ",level);
	if(level!=-1)
		NestingStack[level] = scopeId;
	scopeId = scopeId + 1;

}


void closeScope(){

	printf("\n close level %d ",level);
	level = level -1;

	if(level ==-1)
		showSymbolTable();

}






 int yyerror(char *msg){
  fprintf(stderr," %s at line : << %d >> \n",msg,CURRENT_LINE);
return 1;
}



int main(){

yyin = fopen("testcase.txt", "r");
	yyout = fopen("symbolTable.txt", "w");
	if(yyin==NULL)
		 fprintf(yyout, "Error file not found!");
	else
	{
		printf("Hello file opened");

		yyparse();

	}
	return 0;
}