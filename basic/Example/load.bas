VAR B = 00000 ;
VAR I = 00000 ;
VAR 10000 = 10000 ;
VAR 1 = 1 ;
LABEL TOP ;
LOAD B I 0 : 5 ; 
PRINT I $ ; 
IF I == 10000 ;
END.
I = I + 1 ;  
GOTOSUB TOP ;

