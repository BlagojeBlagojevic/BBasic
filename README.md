# БBasic


Simple Basic Like Iterpreter.



Currently supported instructions are:
1.  **VAR** -> Declaring variable
2.  **LABEL** -> Declaring label
3.  **GOTO** -> Go to line number
4.  **GOTOSUB** -> Go to label
5.  **IF** -> Condition statement if TRUE do line + 1 else skip
6.  **END** -> Used to indicate end of the program
7.  **RAND** -> Generate random number
8.  **INPUT** -> Allows to enter a variable
9.  **GRAPHICS** -> Initialize graphics see below
10. **PIXEL** -> Put pixel on screen
11. **RENDER** -> Renders the screen


There are 2 build of the interpreter:
1. **bbasic.c** This build does not suport last 3 instructions and not depends on anything except standard library
2. **bbbasicgraphics.c** This build does suport last 3 instuction and depends on SDL






