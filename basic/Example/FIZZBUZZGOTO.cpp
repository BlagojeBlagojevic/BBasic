VAR 1 = 1 ; 
VAR 0 = 0 ; 
VAR 5 = 5 ;
VAR 3 = 3 ;
VAR 10000 = 10000 ; 
VAR FIZZ = _fizz ; 
VAR BUZZ = _buzz ; 
VAR I = 000000 ;
VAR REZ3 = 00 ; 
VAR REZ5 = 00 ;
LABEL TOP ;
I = I + 1 ; 
PRINT I $ ; 
IF I == 10000 ;
END . 
REZ3 = I % 3 ;
REZ5 = I % 5 ;
IF REZ3 == 0 ;
GOTO 25 ;
LABEL CHECK5 ;
IF REZ5 == 0 ;
GOTO 29 ;  
GOTO 11 ;

LABEL ISDIV3 ; 
PRINT FIZZ $ ; 
GOTO 20 ;

LABEL ISDIV5 ; 
PRINT BUZZ $ ;
GOTO 11 ; 