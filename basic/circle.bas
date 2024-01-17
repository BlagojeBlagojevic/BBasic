GRAPHICS ;
VAR A = 0000 ; 
VAR B = 0000 ; 
VAR C = 100 ;
VAR A^2 = 000000000 ; 
VAR B^2 = 000000000 ;
VAR R^2 = 10000 ;
VAR CX = 200 ; 
VAR CY = 200 ;
VAR 400 = 400 ;
VAR 000 = 000 ; 
VAR 1 = 1 ;
LABEL TOP ;
A^2 = CX - A ;
A^2 = A^2 * A^2 ;
B^2 = CY - B ;
B^2 = B^2 * B^2 ;
B^2 = B^2 + A^2 ;
IF A == 400 ; 
GOTOSUB LOOP ;
IF B^2 < R^2 ;
PIXEL A B C ;
A = A + 1 ;
GOTOSUB TOP ;
LABEL LOOP :
A = 000 + 000 ; 
B = B + 1 ;
PRINT B $ ;
RENDER ;
IF B == 400 ; 
END .
GOTOSUB TOP ;

