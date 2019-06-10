	#include <stdio.h>
	 #include "calc3.h"
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
   


    

// It has been seen if chain length is < 50 then some space is underutilized,
// Theoretically seen if > 50, prime number is taken then chain takes moderate space.
// So thats why 53 is used.
#define SYMBOL_TABLE_SIZE 53


//Struct that stores info we need to know about the functions

//Think about an effective method
struct functionArguments{
   char* name[50];
   char* classtype[50];
};


union Value {

    int intValue;       /* integer value */
    float floatValue;    /* float value */
    char charValue;    /* char value */
    char* stringValue;    /* string value*/
    char* identifier;       /* identifier name */ 
    char* comment;
    bool isValid;
    nodeType* nPtr;
    };

//Add something for the functions arguments and return type
struct symbol_info{
    char *name;
    int classtype;
    int scopeId;
    bool isFinal;
    union Value value;
    bool isInit;
    struct symbol_info *next;
} *block[SYMBOL_TABLE_SIZE];

void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void myftoa(float n, char res[], int afterpoint);
void myitoa(float n, char res[], int afterpoint);

int cHash(char* name);
bool cInsert(struct symbol_info *newNode );
bool cSearch(char* name,  int scopeId);
struct symbol_info* valSearch(char* name, int *NestingStack,int level, int *errorMsg);
union Value getValue(char* name, int classtype,int scopeId);
void cDelete(char* name, int classtype,int scopeId);
bool varIsFinal(char* name, int classtype, int scopeId);
bool cUpdate(char* name, int classtype, int scopeId, union Value newValue);
void showSymbolTable();
int showMenu();
void setInit(char* name,  int scopeId);
bool getInit(char* name,  int scopeId);

int hashingIndex = -1;

int cHash(char* name){
    int idx = 0;
    for(int i = 0; name[i]; ++i){
        idx = idx + name[i];
    }
    hashingIndex++;
    return (idx  % SYMBOL_TABLE_SIZE);

}



bool cInsert(struct symbol_info *newNode ){
    char* name = newNode->name;
    int pos = cHash(name);

    if(cSearch(newNode->name,newNode->scopeId))
    {   printf(" Error -> already declared in this scope"); 
        return false;
    }
    newNode->isInit = false;
    if( block[pos] == NULL ){
        block[pos] = newNode;
        block[pos]->next = NULL;
    }
    else{
        // pointer swap
        struct symbol_info* nextNode = block[pos];
        block[pos] = newNode;
        newNode->next = nextNode;
    }
    return true;
}

void setInit(char* name,  int scopeId)
{
  int pos = cHash(name);

  struct symbol_info* temp = block[pos];

  while( temp != NULL ){
      if( !strcmp( (*temp).name, name )  && (*temp).scopeId == scopeId ) {
          (*temp).isInit = true;
          return;
      }
      temp = temp->next;
  }

  return ;
}

bool getInit(char* name,  int scopeId)
{
  int pos = cHash(name);

  struct symbol_info* temp = block[pos];

  while( temp != NULL ){
      if( !strcmp( (*temp).name, name )  && (*temp).scopeId == scopeId ) {
          return (*temp).isInit;
      }
      temp = temp->next;
  }

  return false ;
}

// Go to certain chain through hashing since we know others will not contain the searched value.
// Next in that chain do a linear search on all element to see if it is there.

// Checks if the given info are avaliable in our tables
bool cSearch(char* name,  int scopeId){
    // Implement
    int pos = cHash(name);

    struct symbol_info* temp = block[pos];

    while( temp != NULL ){
        if( !strcmp( (*temp).name, name )  && (*temp).scopeId == scopeId ) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// errorMsg = 0 , the identifier is found and the value is returned
// errorMsg = 404, the identifier is not found
struct symbol_info* valSearch(char* name, int *NestingStack,int level, int *errorMsg){
    // Implement
    int pos = cHash(name);

    struct symbol_info* temp;
    int scopeId;
    while(level != -1)
    {
        scopeId = NestingStack[level];
        temp = block[pos];

        while( temp != NULL ){
            if( !strcmp( temp->name, name )  && temp->scopeId == scopeId ) {
                *errorMsg = 0;
                 
               
                return temp;
            }
            temp = temp->next;
        }
        level--;
    }
    printf("Error -> Identifier not found"); 
    *errorMsg=404;
    return temp;
}



// Update the value of the identifier, returns false if the variable is final or not found
// if there is a final  id, we can't assign it so we return false else we return true
bool cUpdate(char* name, int classtype, int scopeId, union Value newValue){
    int pos = cHash(name);

    struct symbol_info* temp = block[pos];

    while( temp != NULL ){
        if( !strcmp( (*temp).name, name ) &&  (*temp).classtype != classtype  && (*temp).scopeId == scopeId){
            /* if((*temp).isFinal)
                return false; */
            (*temp).value = newValue;
            return true;
        }
        temp = (*temp).next;
    }
    return false;
}

union Value getValue(char* name, int classtype,int scopeId)
{

    int pos = cHash(name);
    union Value val;
    struct symbol_info* temp = block[pos];

    while( temp != NULL ){
        if( !strcmp( (*temp).name, name )  && (*temp).scopeId == scopeId ) {
            return (*temp).value;
        }
        temp = temp->next;
    }
    val.isValid = false;
     printf("value not valid"); 
    return val;
}


//Testing only

// Print the symbol table chain wise.

void showSymbolTable(){
   printf("showing symbol table \n");
   fprintf(yyout,"\n\n------------------------------------<< SYMBOLS TABLE  >> --------------------------------------------\n");
   fprintf(yyout," Classes Types : 0->int, 1->float, 2->char, 3->string, 4->bool \n");
    // Implement
    int c =0;
    for(int i = 0; i < SYMBOL_TABLE_SIZE; ++i){
     //   fprintf(yyout,"# %d:", i);
    //    printf("# %d:", i);

        // Do not modify the head
        struct symbol_info* temp = block[i];

        while( temp != NULL ){
            fprintf(yyout,"%d )   [Name  %s| Class %d| Scope %d ] \n", c, (*temp).name, (*temp).classtype,(*temp).scopeId);
            printf("->[%s|%d|%d] ", (*temp).name, (*temp).classtype,(*temp).scopeId);
            temp = (*temp).next;
            c++;
        }
/* 
        fprintf(yyout,"\n"); */
    }

      fprintf(yyout,"\n\n ---------------------------------------------------------------------------------------------------------------");
}




void reverse(char *str, int len) {
	int i = 0, j = len - 1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

int toStr(int x, char str[], int d) {
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

void myftoa(float n, char res[], int afterpoint) {

	// Extract integer part
	int ipart = (int)n;

	// Extract floating part
	float fpart = n - (float)ipart;


	// convert integer part to string
	int i = toStr(ipart, res, 0);

	// check for display option after point
	if (afterpoint != 0)
	{
		res[i] = '.';  // add dot

					   // Get the value of fraction part upto given no.
					   // of points after dot. The third parameter is needed
					   // to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		toStr((int)fpart, res + i + 1, afterpoint);
	}
}


void myitoa(float n, char res[], int afterpoint) {

	// Extract integer part
	int ipart = (int)n;

	// Extract floating part
	float fpart = n - (float)ipart;


	// convert integer part to string
	int i = toStr(ipart, res, 0);
}
