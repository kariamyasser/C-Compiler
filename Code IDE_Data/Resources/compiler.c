#include "SymbolTable.h"
#include "y.tab.h"
#include <math.h>



int leftType; /* 0-->int, 1-->float, 2-->char, 3-->string */
int rightType; /* 0-->int/float, 2-->char, 3-->string */
int lbl;
int l=-1,count = -1;
int last = 0;
int br = 0;
int permission;
int base;

void necessaryInitializations (nodeType *p);
int ex(nodeType *p) {
	if (!p)
		return 0;

	int i;
	int j;
	int tempINT;
	char tempSTR[] = {};
	float tempFLOAT;
	int type1;
	int type2;
	int lbl1;
	int lbl2;

 necessaryInitializations (p);

	switch (p->type) {
		//case assigning to val
	    case typeCon:
        printf("Typecon #1  assigning to val");
		if( leftType == 4  && p->con.isLogical == 1){
			fprintf(yyout, "\t MOV R%d, %s \n", last, p->con.value);
			count++;
			last++;
			rightType = p->con.flag;
		}
		else if (leftType == 0  && p->con.flag == 1) {
			tempINT = atoi(p->con.value);
			myitoa(tempINT, tempSTR, 10);
			fprintf(yyout, "\t MOV R%d, %s \n", last, tempSTR);
			count++;
			last++;
			rightType = p->con.flag;
            printf("Warning: assigning float to int \n");
			fprintf(yyout, "Warning: assigning float to int \n");
		}
		else if (leftType == 0  && p->con.flag == 2) {
            printf( "Error: type clash assigning char to integer \n");
			fprintf(yyout, "Error: type clash assigning char to integer \n");
			return -1;
		}
		else if (leftType == 0 && p->con.flag == 3) {
            printf("Error: type clash assigning string to integer \n");
			fprintf(yyout, "Error: type clash assigning string to integer \n");
			return -1;
		}
		else if (leftType == 0 && p->con.flag == 4) {
            printf( "Error: type clash assigning boolean to integer \n");
			fprintf(yyout, "Error: type clash assigning boolean to integer \n");
			return -1;
		}
		else if (leftType == 1 && p->con.flag == 0) {
			tempFLOAT = atof(p->con.value);
			myftoa(tempFLOAT, tempSTR, 6);
			fprintf(yyout, "\t MOV R%d, %s \n", last, tempSTR);
			count++;
			last++;
			rightType = p->con.flag;
            printf( "Warning: assigning int to float \n");
			fprintf(yyout, "Warning: assigning int to float \n");
		}
		else if (leftType == 1&& p->con.flag == 3) {
            printf("Error: type clash assigning string to float \n");
			fprintf(yyout, "Error: type clash assigning string to float \n");
			return -1;
		}
		else if (leftType == 1  && p->con.flag == 4) {
            printf( "Error: type clash assigning boolean to float \n");
			fprintf(yyout, "Error: type clash assigning boolean to float \n");
			return -1;
		}
		else if (leftType == 1 && p->con.flag == 2) {
            printf("Error: type clash assigning char to float \n");
			fprintf(yyout, "Error: type clash assigning char to float \n");
			return -1;
		}
		else if (leftType == 2  && p->con.flag == 0) {
            printf("Error: type clash assigning integer to char \n");
			fprintf(yyout, "Error: type clash assigning integer to char \n");
			return -1;
		}
		else if (leftType == 2  && p->con.flag == 1) {
            printf("Error: type clash assigning float to char \n");
			fprintf(yyout, "Error: type clash assigning float to char \n");
			break;
		}
		else if (leftType == 2  && p->con.flag == 3) {
            printf("Error: type clash assigning string to char \n");
			fprintf(yyout, "Error: type clash assigning string to char \n");
			return -1;
		}
		else if (leftType == 2 && p->con.flag == 4) {
            printf( "Error: type clash assigning boolean to char \n");
			fprintf(yyout, "Error: type clash assigning boolean to char \n");
			break;
		}
		else if (leftType == 3  && p->con.flag == 1) {
            printf("Error: type clash assigning float to String \n");
			fprintf(yyout, "Error: type clash assigning float to String \n");
			break;
		}
		else if (leftType == 3  && p->con.flag == 0) {
            printf("Error: type clash assigning int to string \n");
			fprintf(yyout, "Error: type clash assigning int to string \n");
			return -1;
		}
		else if (leftType == 3  && p->con.flag == 4) {
            printf("Error: type clash assigning boolean to string \n");
			fprintf(yyout, "Error: type clash assigning boolean to string \n");
			return -1;
		}
		else if (leftType == 4  && p->con.flag == 1) {
            printf( "Error: type clash assigning float to Boolean \n");
			fprintf(yyout, "Error: type clash assigning float to Boolean \n");
			return -1;
		}
		else if (leftType == 4  && p->con.flag == 0) {
            printf("Error: type clash assigning int to Boolean \n");
			fprintf(yyout, "Error: type clash assigning int to Boolean \n");
			return -1;
		}
		else if (leftType == 4  && p->con.flag == 2) {
            printf("Error: type clash assigning char to Boolean \n");
			fprintf(yyout, "Error: type clash assigning char to Boolean \n");
			return -1;
		}
		else if (leftType == 4  && p->con.flag == 3) {
            printf("Error: type clash assigning string to Boolean \n");
			fprintf(yyout, "Error: type clash assigning string to Boolean \n");
			return -1;
		}
		else
		{
			fprintf(yyout, "\t MOV R%d, %s \n", last, p->con.value);
			count++;
			last++;
			rightType = p->con.flag;
		}
		break;
		
case typeId:
		printf( "case typeId #2 \n");
		if (p->id.permission == -1) {
            printf( "Error: %s is not declared \n", p->id.name);
			fprintf(yyout, "Error: %s is not declared \n", p->id.name);
			return -1;
		}
		if (p->id.permission == -3) {
            printf("Error: %s is already defined \n", p->id.name);
			fprintf(yyout, "Error: %s is already defined \n", p->id.name);
			return -1;
		}
		else if (p->id.permission != -1) {
			if (p->id.name != NULL) {
				if (leftType == 0  && p->id.flag == 1) {
                    printf("Warning: assigning float to int \n");
					fprintf(yyout, "Warning: assigning float to int \n");
				}
				else if (leftType == 1  && p->id.flag == 0  ) {
                    printf( "Warning: assigning int to float \n");
					fprintf(yyout, "Warning: assigning int to float \n");
				}
				else if (leftType == 0  && p->id.flag == 2) {
                    printf( "Warning: assigning char to int \n");
					fprintf(yyout, "Warning: assigning char to int \n");
				}
				else if (leftType == 2  && p->id.flag == 0  ) {
					printf( "Warning: assigning int to char \n");
					fprintf(yyout, "Warning: assigning int to char \n");
				}
				fprintf(yyout, "\t LD R%d, %s \n", last, p->id.name);
				count++;
				last++;
				rightType = p->id.flag;
			}
			else {
				fprintf(yyout, "\t LD R%d,%s \n", last, p->id.name);
				rightType = p->id.flag;
				count++;
				last++;
			}
		}
		else
			{   printf( "Error: %s is not declared \n", p->id.name);
				fprintf(yyout, "Error: %s is not declared \n", p->id.name);
				return -1;
			}
		break;


	case typeOpr:
	printf(" type operand #3\n");
		switch (p->opr.oper) {
		case 9999:
			printf("  #3  9999\n");
			break;
		case SEMI_COLON:
			printf("  #3  Semicolon\n");
			if(ex(p->opr.op[0])==-1) return -1;
			break;
		case FOR:
			 printf("#3 case FOR \n");
			// Assignment
			if(ex(p->opr.op[0])==-1) return -1;
			//Label to jump to for looping
			fprintf(yyout, "L%d:\n", lbl1 = lbl++);
			//Logical experssion
			if(ex(p->opr.op[1])==-1) return -1;
			//to end the loop if the exp. = false
			fprintf(yyout, "\t JNZ\tL%d\n", lbl2 = lbl++);
			//body of the loop
			if(ex(p->opr.op[3])==-1) return -1;
			//Math expr ex: i++
			if(ex(p->opr.op[2])==-1) return -1;
			//jumping to the label of the loop for looping
			fprintf(yyout, "\t JMP\tL%d\n", lbl1);
			//the exit label
			fprintf(yyout, "L%d:\n", lbl2);
			break;
		case SWITCH:
		printf("#3 case SWITCH \n");
			l++;
			//Execute identifier
			if(ex(p->opr.op[0])==-1) return -1;
			base = last - 1;
			//Execute stmt body
			if(ex(p->opr.op[1])==-1) return -1;
			break;
		case CASE:
			printf( "#3 case CASE \n");
			//Execute val
			if(ex(p->opr.op[0])==-1) return -1;
			fprintf(yyout, "\t CMPE R%d, R%d \n", last, base);
			fprintf(yyout, "\t JNZ\tL%d \n", lbl1 = lbl++);

			//Execute Case Body
			if(ex(p->opr.op[1])==-1) return -1;

			//Execute Break
			if(ex(p->opr.op[2])==-1) return -1;

			//Label to the next case
			fprintf(yyout, "L%d:\n", lbl1);

			//Execute the next case
			if(ex(p->opr.op[3])==-1) return -1;

			last++;
			count++;
			break;
		case BREAK:
			printf("#3 case BREAK \n");
			fprintf(yyout, "\t JMP Label%d \n", l);
			break;
		case DEFAULT:
			// fprintf(yyout, "case DEFAULT \n");
			if(ex(p->opr.op[0])==-1) return -1;
			fprintf(yyout, "Label%d: \n", l);
			break;
		case IF:
			printf( "#3 case IF \n");
			//Execute logical expression
			if(ex(p->opr.op[0])==-1) return -1;

			//If-Else
			if (p->opr.nops > 2) {
				fprintf(yyout, "\t JNZ\tL%d\n", lbl1 = lbl++);

				//Execute Body of the IF
				if(ex(p->opr.op[1])==-1) return -1;

				fprintf(yyout, "\t JMP\tL%d\n", lbl2 = lbl++);
				fprintf(yyout, "L%d:\n", lbl1);

				//Execute Body of the ELSE
				if(ex(p->opr.op[2])==-1) return -1;
				fprintf(yyout, "L%d:\n", lbl2);
			}
			else {

				fprintf(yyout, "\t JNZ\tL%d\n", lbl1 = lbl++);
				//Execute body of the IF
				if(ex(p->opr.op[1])==-1) return -1;

				fprintf(yyout, "L%d:\n", lbl1);

			}
			break;
		case WHILE:
		printf( "case WHILE \n");
			fprintf(yyout, "L%d:\n", lbl1 = lbl++);

			//Execute logicalexpr
			if(ex(p->opr.op[0])==-1) return -1;
			fprintf(yyout, "\t JNZ\tL%d\n", lbl2 = lbl++);

			//Execute body of the while loop
			if(ex(p->opr.op[1])==-1) return -1;

			fprintf(yyout, "\t JMP\tL%d\n", lbl1);
			fprintf(yyout, "L%d:\n", lbl2);
			break;
		case DO:
			printf("case DO \n");
			fprintf(yyout, "L%d:\n", lbl1 = lbl++);

			//Execute body of the loop
			if(ex(p->opr.op[0])==-1) return -1;

			//Execute logicalexpr
			if(ex(p->opr.op[1])==-1) return -1;

			fprintf(yyout, "\t JNZ\tL%d\n", lbl1);
			break;
		case EQUAL:
			printf("case EQUAL \n");
			if( p->opr.op[0]->id.flag != 4 )
				leftType = p->opr.op[0]->id.flag;

			permission = p->opr.op[0]->id.permission;

			if (permission == -1) {
				printf("Error: %s is not declared \n", p->opr.op[0]->id.name);
				fprintf(yyout, "Error: %s is not declared \n", p->opr.op[0]->id.name);
				return -1;

			}
		
			else if (permission == -3) {
				printf("Error: %s is already defined \n", p->opr.op[0]->id.name);
				fprintf(yyout, "Error: %s is already defined \n", p->opr.op[0]->id.name);
				return -1;
			}

			if(ex(p->opr.op[1])==-1) return -1;

			//Testing if initialized
			//Checking if operand 2 is an identifier (not a constant) that is declared but not initialized
			if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) && p->opr.op[1]->id.permission!=-1 ){
				printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
				fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
				return -1;
			}else
				setInit(p->opr.op[0]->id.name, p->opr.op[0]->id.scopeId);

			if( p->opr.op[0]->id.flag == 4 )
				leftType = p->opr.op[0]->id.flag;

			if (rightType != leftType)
			{
				printf("Error : right operand type != right \n");
				return -1;

			}
				
			if (p->opr.op[1]->type == 0)
				{}//cUpdate(p->opr.op[0]->id.name, p->opr.op[0]->id.flag, p->opr.op[0]->id.scopeId, getValue(p->opr.op[1]->id.name,p->opr.op[1]->id.flag ,p->opr.op[1]->id.scopeId));
			else if (p->opr.op[1]->type == 1)
				cUpdate(p->opr.op[0]->id.name, p->opr.op[0]->id.flag, p->opr.op[0]->id.scopeId, getValue(p->opr.op[1]->id.name,p->opr.op[1]->id.flag ,p->opr.op[1]->id.scopeId));

			//Store value of register in data segment
			fprintf(yyout, "\t ST  R%d, %s \n", last - 1, p->opr.op[0]->id.name);

			leftType = -9;
			rightType = -9;
			break;
			default:
			printf( "#3 in Equal case default \n");
			//Execute IDENTIFIER

			if(ex(p->opr.op[0])==-1) return -1;

			i = count;
			type1 = rightType;

			//Checking if it's a binary operation
			if (p->opr.nops == 2 && p->opr.op[1] != NULL) {

				//Execute the right hand side IDENTIFIER
				if(ex(p->opr.op[1])==-1) return -1;
				type2 = rightType;
			}

			j = count;

			switch (p->opr.oper) {
				printf("switch inside default of equal of #3 \n");
			case PLUS:
			printf("PLUS \n");
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 ))
				{
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t ADD R%d, R%d\n", j, i);
				}
				else
				{
						printf("Error: incompatible operands for addition \n");
					fprintf(yyout, "Error: incompatible operands for addition \n");
					return -1;
				}

				break;

			case MINUS:
			printf("MINUS \n");
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 )
				){
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t SUB R%d, R%d \n", i, j);
				}
				else
				{
					printf("Error: incompatible operands for subtraction \n");
					fprintf(yyout, "Error: incompatible operands for subtraction \n");
					return -1;
				}

				break;
			case MULTIPLY:
			printf("MULTIPLY \n");
				if ((type1 == 0 || type1 == 1) && (type2 == 0 || type2 == 1 )) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){

						printf("Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t MUL R%d, R%d\n", i, j);
				}
				else
				{
					printf( "Error: incompatible operands for multiplication \n");
					fprintf(yyout, "Error: incompatible operands for multiplication \n");
					return -1;
				}
				break;
			case DIVIDE:
			printf("DIVIDE \n");
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 )) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t DIV R%d, R%d \n", i, j);
				}
				else{
					printf("Error: incompatible operands for division \n");
					fprintf(yyout, "Error: incompatible operands for division \n");
					return -1;
				}
				break;
			case REMAINDER:
			printf("REMAINDER \n");
				if ((type1 == 0 ) && (type2 == 0)) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t REM R%d, R%d \n", i, j);
				}
				else{
					printf("Error: incompatible operands for remainder \n");
					fprintf(yyout, "Error: incompatible operands for remainder \n");
					return -1;
				}
				break;
			case NOT:
			printf("NOT \n");
				if (type1 == 4 ) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					fprintf(yyout, "\t NOT  R%d\n", i);
				}
				else{
					printf("Error: incompatible operands for ! \n");
					fprintf(yyout, "Error: incompatible operands for ! \n");
					return -1;
				}

				break;
			case AND_AND:
			printf("AND AND \n");
				if ((type1 == 4 ) && (type2 == 4 ) ){
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}

					fprintf(yyout, "\t AND R%d, R%d \n", i, j);
				}
				else{
					printf("Error: incompatible operands for && \n");
					fprintf(yyout, "Error: incompatible operands for && \n");
					return -1;
				}
				break;
			case OR_OR:
				printf("OR OR\n");
				if ((type1 == 4 ) && (type2 == 4 )) {
					
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t OR R%d, R%d\n", i, j);
				}
				else{
					printf("Error: incompatible operands for || \n");
					fprintf(yyout, "Error: incompatible operands for || \n");
					return -1;
				}
				break;

			case GREATER_THAN:
			printf("GrEATER Than\n");
				rightType = 4;
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 )) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf("Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t CMPG R%d, R%d\n", i, j);
				}
				else{
					printf("Error: incompatible operands for > \n");
					fprintf(yyout, "Error: incompatible operands for > \n");
					return -1;
				}
				break;

			case SMALLER_THAN:
				printf("SMALLER Than\n");
				rightType = 4;
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1)) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t CMPL R%d, R%d \n", i, j);
				}
				else{
					printf("Error: incompatible operands for < \n");
					fprintf(yyout, "Error: incompatible operands for < \n");
					return -1;
				}
				break;
			case GREATER_THAN_EQUAL:
				printf("GrEATER Than EQUAL\n");
				rightType = 4;
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 )) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t CMPGE R%d, R%d \n", i, j);

				}
				else{
					printf("Error: incompatible operands for >= \n");

					fprintf(yyout, "Error: incompatible operands for >= \n");
					return -1;
				}

				break;
			case SMALLER_THAN_EQUAL:
				rightType = 4;
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 )) {
					if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t CMPLE R%d, R%d \n", i, j);
				}
				else{
					printf("Error: incompatible operands for <= \n");
					fprintf(yyout, "Error: incompatible operands for <= \n");
					return -1;
				}
				break;
			case NOT_EQUAL:
				rightType = 4;

				//Validating that both types can be compared
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 )) {}
				else if ((type1 == type2) || (type1 + 5 == type2) || (type1 == type2 + 5)) {}
				else {
					printf("Error: incompatible operands for != \n");
					fprintf(yyout, "Error: incompatible operands for != \n");
					return -1;
				}

				if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
					printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
					fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
					return -1;
				}
				else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
					printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
					fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
					return -1;
				}
				fprintf(yyout, "\t CMPNE R%d, R%d \n", i, j);

				break;
			case EQUAL_EQUAL:
				rightType = 4;

				//Validating that both types can be compared
				if ((type1 == 0 || type1 == 1 ) && (type2 == 0 || type2 == 1 )) {}
				else if ((type1 == type2) || (type1 + 5 == type2) || (type1 == type2 + 5)) {}
				else {
					printf("Error: incompatible operands for == \n");
					fprintf(yyout, "Error: incompatible operands for == \n");
					return -1;

				}

				if (p->opr.op[0]->type==1 && !getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
					printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
					fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
					return -1;
				}
				else if (p->opr.op[1]->type==1 && !getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
					printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
					fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
					return -1;
				}
				fprintf(yyout, "\t CMPE R%d, R%d\n", i, j);

				break;
			case PLUS_PLUS:
				if (type1 == 0 || type1 == 1) {
					if (!getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}

					if (p->opr.nops == 1) {
						//Store value of register in data segment
						fprintf(yyout, "\t ST  R%d, %s \n", last - 1, p->opr.op[0]->id.name);

						fprintf(yyout, "\t INC R%d \n", last - 1);
					}
					else {
						fprintf(yyout, "\t INC R%d \n", last - 1);

						//Store value of register in data segment
						fprintf(yyout, "\t ST  R%d, %s \n", last - 1, p->opr.op[0]->id.name);
					}
				}
				else{
					printf("Error: incompatible operands for increment \n");
					fprintf(yyout, "Error: incompatible operands for increment \n");
					return -1;
				}
				break;
			case MINUS_MINUS:
			// printf("In MINUS_MINUS\n" );
				if (type1 == 0 || type1 == 1) {
					if (!getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}

					if (p->opr.nops == 1) {
						//Store value of register in data segment
						fprintf(yyout, "\t ST  R%d, %s \n", last - 1, p->opr.op[0]->id.name);

						fprintf(yyout, "\t DEC R%d \n", last - 1);
					}
					else {
						fprintf(yyout, "\t DEC R%d \n", last - 1);

						//Store value of register in data segment
						fprintf(yyout, "\t ST  R%d, %s \n", last - 1, p->opr.op[0]->id.name);
					}
				}
				else{
					printf("Error: incompatible operands for increment \n");
					fprintf(yyout, "Error: incompatible operands for increment \n");
					return -1;
				}
				break;
			case PLUS_EQUAL:
				if (type1 == 0 || type1 == 1) {
					if (!getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (!getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t ADD R%d, R%d\n", last - 2, last - 1);

					//Store value of register in data segment
					fprintf(yyout, "\t ST  R%d, %s \n", last - 2, p->opr.op[0]->id.name);

				}
				else{
					printf("Error: incompatible operands for PlusEqual \n");
					fprintf(yyout, "Error: incompatible operands for PlusEqual \n");
					return -1;
				}
				break;
			case MINUS_EQUAL:
				if (type1 == 0 || type1 == 1) {
					if (!getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (!getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t SUB R%d, R%d\n", last - 2, last - 1);

					//Store value of register in data segment
					fprintf(yyout, "\t ST  R%d, %s \n", last - 2, p->opr.op[0]->id.name);

				}
				else{
					printf("Error: incompatible operands for minusEqual \n");
					fprintf(yyout, "Error: incompatible operands for minusEqual \n");
					return -1;
				}
				break;
			case MULTIPLY_EQUAL:
				if (type1 == 0 || type1 == 1) {
					if (!getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (!getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t MUL R%d, R%d\n", last - 2, last - 1);

					//Store value of register in data segment
					fprintf(yyout, "\t ST  R%d, %s \n", last - 2, p->opr.op[0]->id.name);

				}
				else{
					printf("Error: incompatible operands for mulEqual \n");
					fprintf(yyout, "Error: incompatible operands for mulEqual \n");
					return -1;
				}

				break;
			case DIVIDE_EQUAL:
				if (type1 == 0 || type1 == 1) {
					if (!getInit(p->opr.op[0]->id.name,p->opr.op[0]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[0]->id.name);
						return -1;
					}
					else if (!getInit(p->opr.op[1]->id.name,p->opr.op[1]->id.scopeId) ){
						printf( "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						fprintf(yyout, "Error: %s is not initialized \n", p->opr.op[1]->id.name);
						return -1;
					}
					fprintf(yyout, "\t DIV R%d, R%d\n", last - 2, last - 1);

					//Store value of register in data segment
					fprintf(yyout, "\t ST  R%d, %s \n", last - 2, p->opr.op[0]->id.name);

				}
				else{
					printf("Error: incompatible operands for divEqual \n");
					fprintf(yyout, "Error: incompatible operands for divEqual \n");
					return -1;
				}
				break;

			}
		}
	}
	return 0;
}


///////////////////////////////////////////////////////


void necessaryInitializations (nodeType *p){
	if (p->opr.oper >= 281 && p->opr.oper <= 309 || p->opr.oper == 312 || p->opr.oper == 314 || p->opr.oper == 272)
		p->type = 2;
}
