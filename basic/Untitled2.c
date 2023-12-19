#include "basic.h"

// allocating memory for vm assert if NULL alocation
void allocMemory(MEMORY *memory){
	memory->mem = (BYTE*)calloc(SIZE_OF_MEMORY, sizeof(BYTE));
	assert(memory->mem != NULL && "\nERROR ALOCATING MEMORY!!!\n");
	memory->RET = 0;
	memory->counterVar = 0;	
	memory->lastMemAddress =0;
	for(size_t i = 0; i < MAX_VARS;i++){
	  memory->varMemStartPointers[i] = 1;
    
	  //memory->varName[i] = NULL;	
	}
}
void printMemory(MEMORY *memory,int start,int stop){
	printf("\n\n\t*******************************************\n\n\t\t\t");
	printf("MEMORY\n");
	printf("\n\n\t*******************************************\n\n\t\t\t");
	for(size_t i = start; i < stop; i++){
		printf("\non mem locarion %d value is %c\n",i,memory->mem[i]);
	}
	system("pause");
}
void printVar(MEMORY *memory,int start,int stop){
    printf("\n\n\t*******************************************\n\n\t\t\t");
	printf("VAR\n");
	printf("\n\n\t*******************************************\n\n\t\t\t");
		for(size_t i = start; i < stop; i++){
		printf("\nvar %d has name %s starts at %d ends at %d\n",i,memory->varName[i],memory->varMemStartPointers[i],memory->varMemEndPoiners[i]);
		}	
}
//car
//var stores variable in memory 
//data insde memory is stored as char(BYTE)
//if var alredy exist assert 
//stores var name var start and var end mem pointer
//stores all values in memory 
void var(char* token,MEMORY *mem){
	
	token = strtok(NULL," "); //AFTER VAR NEXT TOKEN
    //printf("\nstring %s",token);
		 //printf("\n%s",token);
		 assert(mem->counterVar < MAX_VARS&&"\n MAX NUMBER OF VARS EXITED\n");  //ASERT THAT ALL MEMORY ISNT ALCOATED
		 //MOzda jos kojI
		void* s = strcpy(&mem->varName[mem->counterVar],token);
		for(size_t i = 0;i < mem->counterVar;i++){
			if(strcmp(mem->varName[i],token) == 0)
			  {
			   assert(0 && "VAR ALREDY DECLARED!!!");
			   
			  }
		}
		 mem->varMemStartPointers[mem->counterVar] = mem->lastMemAddress;
		 //printf("\n%s",&mem->varName[mem->counterVar]);
		 assert(s!= NULL && "ERROR COPING VAR NAME");
		 token = strtok(0, " ");
		 if (token != NULL){
		   token = strtok(0, " ");
		   //printf("\n%s",token);
		   int size = arrSize(token);
		   //printf("\n%d", size);
	   	   //memcpy(&mem->mem[mem->lastMemAddress],token,size);
	   	   for(size_t i = 0; i < size; i++){
             if(token[i]== '\0'){break;}
			 else{
			 	mem->mem[mem->lastMemAddress++] = token[i]; 
			 } 
	        }
	   	   mem->varMemEndPoiners[mem->counterVar] = mem->lastMemAddress; 
           mem->counterVar++;
		   //printf("mem \n%c",mem->mem[0]);
           //printf(" %c\n",mem->mem[1]);
           
		 } 
		 
	
}
//
//PRINT 
//Prints value on screen 
//$ represent new line
void print(char* token,MEMORY *mem){
	token = strtok(0, " ");
	//printf("TOKEN %sA",token);
	int isVarExist = 0;
	for(size_t i = 0;i < mem->counterVar;i++){
		if(strcmp(&mem->varName[i],token) == 0){
		  isVarExist = 1;	
		  for(size_t j = mem->varMemStartPointers[i];j <  mem->varMemEndPoiners[i];j++){
				printf("%c",mem->mem[j]);
				//printf("Nesto");
		  }
          token = strtok(0, " ");
          //printf("%c",token[0]);
          char str = '$'; 
		  if(token[0] == str){
			printf("\n");
		  }
		  break;
		}
		
	}
	assert(isVarExist == 1 && "VAR DOES NOT EXIST!!! ");
}
//
//GOTO 
void bgoto(char *token, int curentAdress,MEMORY *mem,FILE *f){
	mem->RET = curentAdress;
	token = strtok(0," ");
	char line[MAX_LINE];
	int gotoAdress = atoi(token) / 10 - 1;
	//printf("adrres %d\n",gotoAdress);
	fseek(f,0,SEEK_SET); 
	for(size_t i = 0 ; i  < gotoAdress; i++){
	  fgets(line,MAX_LINE,f);
	  //printf("%s\n",line);
	 }
}
//
//MATH
//
void mathoperations(int a, int b, int result, char sign,MEMORY *mem){
	char valueMemFirst[30],valueMemLast[30];
	size_t counter = 0;
	for(size_t i = mem->varMemStartPointers[a]; i < mem->varMemEndPoiners[a]; i++){
	  valueMemFirst[counter++] = mem->mem[i];
	}
	counter = 0; 
	for(size_t i = mem->varMemStartPointers[b]; i < mem->varMemEndPoiners[b]; i++){
	  valueMemLast[counter++] = mem->mem[i];
	}
	counter = 0;
    int value1 = atoi(valueMemFirst);
    int value2 = atoi(valueMemLast);
    if(sign == '+'){
   	  counter = 0;
   	  int valueResult = value1 + value2;
		 char resMem[30];
		 itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}

  if(sign == '-'){
   	  counter = 0;
   	  int valueResult = value1 - value2;
	     char resMem[30];
		 itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}
	
    if(sign == '*'){
   	  counter = 0;
   	  int valueResult = value1 * value2;
 		 char resMem[30];
		 itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}
	
	  if(sign == '/'){
   	  counter = 0;
   	  assert(value2!=0&&"DIVISION BY 0 !!!");
   	  int valueResult = value1 / value2;
		 char resMem[30];
		 itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}	
	
} 
//INPUT
void input(char* token,MEMORY *mem ){
	char str[30];
	int indexOfVar = -1;
	token = strtok(0," ");
	for(size_t i = 0; i < mem->counterVar;i++){
	  if(strcmp(token,mem->varName[i]) == 0){
	  	indexOfVar = i;
	  	break;
	  }
	}
	assert(indexOfVar != -1 && "Var is not declared");
	scanf("%s", str);
	size_t counter = 0; 
	for(size_t i = mem->varMemStartPointers[indexOfVar]; i < mem->varMemEndPoiners[indexOfVar] ;i++){
	  mem->mem[i] = str[counter++];
	}
	
}
//
// IF contition is met jmp to mem location else pass
 void bif(char* token,MEMORY *mem,FILE *f){
 	token = strtok(0," ");
 	int indexOfFirst = -1;
 	for(size_t i = 0; i < mem->counterVar; i++){
 		if(strcmp(token, mem->varName[i])==0){
		  indexOfFirst = i;
		  break;
		 }
	 }
    assert(indexOfFirst!=-1 && " VAR IS NOT DECLARED!!! ");
 	
 	
    token = strtok(0," ");
	char operation[30];
	strcpy(operation,token);
	
	token = strtok(0," ");
 	int indexOfLast = -1;
 	for(size_t i = 0; i < mem->counterVar; i++){
 		if(strcmp(token, mem->varName[i])==0){
		  indexOfLast = i;
		  break;
		 }
	 }
     assert(indexOfLast!=-1 && "VAR IS NOT DECLARED!!!"); 
     
 	char valueMemFirst[30],valueMemLast[30];
	size_t counter = 0;
	for(size_t i = mem->varMemStartPointers[indexOfFirst]; i < mem->varMemEndPoiners[indexOfFirst]; i++){
	  valueMemFirst[counter++] = mem->mem[i];
	}
	counter = 0; 
	for(size_t i = mem->varMemStartPointers[indexOfLast]; i < mem->varMemEndPoiners[indexOfLast]; i++){
	  valueMemLast[counter++] = mem->mem[i];
	}
     
     int a = atoi(valueMemFirst);
     int b = atoi(valueMemLast);
     //printf("%s",operation);
     if(strcmp(CharTokensRepresentation[EQUALCOND],operation) == 0){
	 //printf("\na %d b %d\n", a,b);	
     	if(a != b){
     		char line[MAX_LINE];
     		fgets(line,MAX_LINE,f);
		 }
     	
	 }
	 if(strcmp(CharTokensRepresentation[LESER],operation) == 0){
     	if(a > b){
     		char line[MAX_LINE];
     		fgets(line,MAX_LINE,f);
		 }
     	
	 }
	 
	 if(strcmp(CharTokensRepresentation[BIGER],operation) == 0){
     	if(a != b){
     		char line[MAX_LINE];
     		fgets(line,MAX_LINE,f);
		 }
     	
	 }
 }

//

//

//
void execute(MEMORY *mem){
	FILE *f = fopen("asd.txt","r");  //Open File prob with args
	char line[MAX_LINE];     //Stores one line of instruction     kasnije flag
	size_t numberOfLine = 0;
	
	while(1){
	  void* s =  fgets(line,MAX_LINE,f);       //Read line of instructions
	  //printf("%s line ",line);
	  if(s == NULL){
        if(feof(f))
          printf("\nEND OF THE PROGRAM !!!\n");
	    else
 	      assert(0 && "ERROR IN READING BUFFER!!!");
		break;
	  }
      char* token = strtok(line , " ");  // First token
      //printf("\n%s", token);
	  int curentAdress = atoi(token); 
	  token = strtok(0," ");      // Next token
	  //printf("%s" ,token);
  	  //printMemory(mem,0,7);
  	 // printVar(mem,0,4);
	  if(strcmp(token,CharTokensRepresentation[VAR]) == 0){  //If Token is VAR
	  	var(token,mem); 

	   }  
      else if(strcmp(CharTokensRepresentation[PRINT], token) == 0){   //If token is print
	    print(token,mem);
	  }
	  else if(strcmp(CharTokensRepresentation[GOTO], token) == 0){
        bgoto(token,curentAdress,mem,f);
	  }
	  
	  else if(strcmp(CharTokensRepresentation[INPUT], token) == 0){
	  	input(token,mem);

	  }
	   else if(strcmp(CharTokensRepresentation[IF], token) == 0){
	  	bif(token,mem,f);
	  }
	   else if(strcmp(CharTokensRepresentation[END], token) == 0){
	   printf("\nEND OF THE PROGRAM !!!\n");
	   break;
	   }
      // if evriting else is finish now we nead to see math operations
	  else{
        char varName[30],firstOperand[30],lastOperand[30];
        int varExist = 0,result,firstIndex,lastIndex ;
        strcpy(varName,token);
        //printf("Nesto\n\n");
		//system("pause");
        
        size_t i = 0;
        //check VarName
        for(;i < mem->counterVar;i++){
        	if(strcmp(token,&mem->varName[i])==0){
        		varExist = 1;
        		break;
			}
		}
		//system("pause");
		assert(varExist == 1 && "VAR DOESNT EXIST!!!" );
		token = strtok(0," ");
		assert(strcmp(CharTokensRepresentation[EQUAL], token) == 0); //is token equal
		token = strtok(0," ");
		//printf("token %s", token);
		//strcpy(firstOperand,token);
		for(size_t j = 0;j < mem->counterVar;j++){
        	if(strcmp(token,mem->varName[j])==0){
        		firstIndex = j;
        		
        		break;
			}
		}	
    
		token  = strtok(0," ");
		char sign = token[0];
		token  = strtok(0," ");
		printf("token %s", token);
			for(size_t j = 0;j < mem->counterVar;j++){
        	if(strcmp(token,&mem->varName[j])==0){
        		lastIndex = j;
        		break;
			}
		}
		printf("\nfirstIndex %d ,lastIndex %d ,i %d,sign %c",firstIndex,lastIndex,i,sign);
		system("pause");
		mathoperations(firstIndex,lastIndex,i,sign,mem);
	  }
	  //printf("%s", token);
	  

   	  //system("pause");
}
}


int main()
{
	//printf("%s", CharTokensRepresentation[PLUS]);
	//printf("Nesto\n");
	MEMORY memory;
	allocMemory(&memory);
	execute(&memory);
	
	return 0;
}
