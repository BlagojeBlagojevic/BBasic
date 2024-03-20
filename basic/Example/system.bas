GRAPHICS ; 
VAR A = 0 ; 
VAR a = 6 ;
VAR 0 = 0 ;
VAR > = _>_ ;
VAR < = _<_ ;
VAR = = _=_ ;
VAR input = Input ; 
VAR num = _num-> ;
PRINT input ;
PRINT num ; 
INPUT a ;
LABEL TOP : 
KEYINPUT A ;
IF A == a ;
GOTOSUB E ;
IF A > a :
GOTOSUB B ;
IF A < a ;
GOTOSUB C ; 
GOTOSUB TOP ;

LABEL B :
PRINT A ;
A = 0 + 0 ;
PRINT > ;  
PRINT a $ ;
SYSTEM CLS ;
GOTOSUB TOP ;

LABEL C :
PRINT A ; 
PRINT < ; 
PRINT a $ ; 
SYSTEM CLS ;
GOTOSUB TOP ;

LABEL E :
PRINT A ; 
PRINT = ; 
PRINT a $ ;
SYSTEM CLS ; 
GOTOSUB TOP ;