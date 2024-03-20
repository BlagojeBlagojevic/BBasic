
#ifndef BASIC_IMPLEMENTATION
#define BASIC_IMPLEMENTATION

#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>


//SDL_INCLUDES
#include<SDL2/SDL.h>
#include<SDL2/SDL_hints.h>
#include<SDL2/SDL_error.h>
#include<SDL2/SDL_log.h>
#include<SDL2/SDL_video.h>
#include<SDL2/SDL_render.h>
#include<SDL2/SDL_pixels.h>
#include<SDL2/SDL_rect.h>
#include<SDL2/SDL_surface.h>
#include<SDL2/SDL_clipboard.h>
#include<SDL2/SDL_events.h>

//#include <windows.h>



#define MAX_VARS 1000             // HOW MUCH VARS WE COUDE USED AT SAME TIME
#define SIZE_OF_MEMORY 1024*1024      // HOW MUCH MEMORY WILL VM HAVE 
#define MAX_LINE 100
#define width 400
#define height 400

#define arrSize(x) (sizeof(x) / sizeof(x[0]))

//__attribute__((vector (clauses))) //return_type simd_enabled_function_name(arguments);

//Type Declaration
//char fileName[] = "program.bas";
char fileName[30];
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
	IF,	         //Token for Conditional jumping
	BIGER,       //Token for > 
	LESER,       //Token for <
	EQUALCOND,   //Token for ==
	VAR,         //Token for var declaration
	NEWLINE,     //Token for printing new line character $ caracter for new line
	INPUT,       //Token for input of data 
	RAND,        //Token for random genareted number betwen 0 - 100
	LABEL,       //Token used as a line number holder for subroutins 
	GRAPHICS,    //Token used to load a graphics
	PIXEL,       //Token for store walue of pixel
	RENDER,      //Token used to render the scren in pixels
	LOAD,        //Token for loading part of var in memory
	KEYINPUT,    //Token for loading key value if key is press if not somting return
	SYSTEM       //Token for caling system 
	
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
											"GRAPHICS",
											"PIXEL",
											"RENDER",
											"LOAD",
											"KEYINPUT",
											"SYSTEM"
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
	uint8_t ke;	
}MEMORY;

static inline void allocMemory(MEMORY *memory);  //Allocation of memory in VM
static inline void printMemory(MEMORY *memory, int start, int stop ); //Prints content of memory start stop 
static inline void printVar(MEMORY *memory, int start,int stop);      //Prints var related content
//

//void isVarExist(char* token, MEMORY *mem);
// Function Declaration
static inline void print(char* token,MEMORY *mem);     //PRINTS VALUE FROM MEMORY FROM FOR GIVEN VAR 
static inline void input(char* token,MEMORY *mem);     //Inputs value from console
//
//MATH result is num of index for result
static inline void mathoperations(int a, int b, int result,char sign ,MEMORY *mem);
//
//CONDITIONS

static inline void bif(char* token,MEMORY *mem, FILE *f);
static inline void bgoto(char *token,MEMORY *mem,FILE *f);
static inline void gotosub(char* token, MEMORY* mem, FILE *f);
//
//VAR ALOCATION (all vars are store as a char(BYTE) in memory)
static inline void var(char* token,MEMORY *mem);
static inline void brandom(char* token,MEMORY *mem);
//
//
//
//EXECUTE
static inline void execute(MEMORY *mem);

//
//Graphics Function 
static inline void initGraphics(SDL_Renderer **renderer,SDL_Window **window);
static inline void drawPixel(SDL_Renderer **renderer,SDL_Window **window, char* token, MEMORY *mem, uint8_t PIXELS[height][width]);
static inline void graphicsCheckQuit();
static inline void render(SDL_Renderer *renderer,SDL_Window *window,uint8_t PIXELS[height][width]);
//Memory Function
static inline void load(char* token,MEMORY *mem);
//
//Keybord input
static inline void keyboardCheck(char* token,MEMORY *mem);
//
//System call 
static inline void systemCall(char *token,MEMORY *mem);
//
//
//
#endif
 
