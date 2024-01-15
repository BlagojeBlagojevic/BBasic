LABEL BEGIN ;
VAR a = Guess_ ; 
VAR b = THE_ ;
VAR c = number: ;
VAR GUEST = 0 ;
VAR RANDOM = 0 ;
RAND RANDOM ; 
PRINT a ; 
PRINT b ;
PRINT c $;
VAR LOW = toLow ;
VAR HIGH = toHigh ;
LABEL input ;
INPUT GUEST ;
IF GUEST == RANDOM ; 
END ; 
IF GUEST < RANDOM ; 
PRINT LOW $ ; 
IF GUEST > RANDOM ; 
PRINT HIGH $ ; 
PRINT a ; 
PRINT b ;
PRINT c $;
GOTOSUB input ;




 




 
