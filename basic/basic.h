#ifndef BASIC_IMPLEMENTATION
#define BASIC_IMPLEMENTATION

#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VARS 1000             // HOW MUCH VARS WE COUDE USED AT SAME TIME
#define SIZE_OF_MEMORY 1024*1024      // HOW MUCH MEMORY WILL VM HAVE 
#define MAX_LINE 1000


#define arrSize(x) sizeof(x) / sizeof(x[0])
//Type Declaration
char fileName[40];
typedef enum {
	
	PRINT,       //Token for printing on  screen
	GOTO,        //Token for going onto a Line
	PLUS,        //Token for + 
	MINUS,       //Token for -
	MULTIPLAY,   //Token for *
	DIVIDE,      //Token for /
	MOD,         //Token for % used as MOD operator or as print type
	SEMICOLON,   //Token for end of the line
	END,         //Token for END of a program
	RET,	     //Token for returning from subroutine
	GOTOSUB,     //Token for Jumping to subroutine
	EQUAL,       //Token for Adding value to variable
	IF,	     //Token for Conditional jumping
	BIGER,       //Token for > 
	LESER,       //Token for <
	EQUALCOND,   //Token for ==
	VAR,         //Token for var declaration
	NEWLINE,     //Token for printing new line character $ caracter for new line
	INPUT,       //Token for input of data 
	RAND,        //Token for random genareted number betwen 0 - 100
	LABEL        //Token used as a line number holder for subroutins 
}TOKENS;

//Order must be the same as in enum
const char* CharTokensRepresentation[] = {  
	  								   	 	"PRINT",
 	  								   	    	"GOTO",
											"+",
											"-",
											"*",
											"/",
											"%",
											";",
											"END",
											"RET",
											"GOTOSUB",
											"=",
											"IF",
											">",
											"<",
											"==",
											"VAR",
											"$",
											"INPUT",
											"RAND",
											"LABEL",
                                          };

//
//MEMORY
typedef uint8_t  BYTE;
typedef uint16_t WORD;  
typedef struct{
	
	
	char varName[MAX_VARS][20];   //STORES NAME OF A VARIABLE
	size_t  varMemStartPointers[MAX_VARS];
	int  varMemEndPoiners[MAX_VARS];
	BYTE *mem;
	int RET;                        //REPRESENT VALUE OF RETURN TO MAIN 
	size_t counterVar;               //WHAT VARIABLE VE ARE ON            
	size_t lastMemAddress;
	
}MEMORY;

void allocMemory(MEMORY *memory);  //Allocation of memory in VM
void printMemory(MEMORY *memory, int start, int stop ); //Prints content of memory start stop 
void printVar(MEMORY *memory, int start,int stop);      //Prints var related content
//

//void isVarExist(char* token, MEMORY *mem);
// Function Declaration
void print(char* token,MEMORY *mem);     //PRINTS VALUE FROM MEMORY FROM FOR GIVEN VAR 
void input(char* token,MEMORY *mem);     //Inputs value from console
//
//MATH result is num of index for result
void mathoperations(int a, int b, int result,char sign ,MEMORY *mem);
//
//CONDITIONS
void bif(char* token,MEMORY *mem, FILE *f);
void bgoto(char *token,MEMORY *mem,FILE *f);
void gotosub(char* token, MEMORY* mem, FILE *f);
//
//VAR ALOCATION (all vars are store as a char(BYTE) in memory)
void var(char* token,MEMORY *mem);
void brandom(char* token,MEMORY *mem);
//
//
//
//EXECUTE
void execute(MEMORY *mem);

//

#endif
 
