# БBasic


Simple Basic Like Iterpreter.



Currently supported instructions are:
1.  **VAR**      -> Declaring variable
2.  **LABEL**    -> Declaring label
3.  **GOTO**     -> Go to line number
4.  **GOTOSUB**  -> Go to label
5.  **IF**       -> Condition statement if TRUE do line + 1 else skip
6.  **END**      -> Used to indicate end of the program
7.  **RAND**     -> Generate random number
8.  **INPUT**    -> Allows to enter a variable
9.  **LOAD**     -> Load variable B to A START : STOP
10.  **GRAPHICS** -> Initialize graphics see below
11. **PIXEL**    -> Put pixel on screen
12. **RENDER**   -> Renders the screen


There are 2 build of the interpreter:
1. **bbasic.c** This build does not suport last 3 instructions and not depends on anything except standard library
2. **bbbasicgraphics.c** This build does suport last 3 instuction and depends on SDL


To compile it you need first to compile header libary for desired build. 

1.      gcc bbasic.h 
2.      gcc basicgraphics.h 

Then compile desired build. 


1.      gcc bbasic.c -lm
2.      gcc bbbasicgraphics.c -lm -lSDL2 -lGL

Then run program      

1.     ./a.out filePathToProgram

In example folder we will fine examples of programs. 

This implementation currently is  2 time slower then python in fizzbuzz test on my PC.






