#include "basicgraphics.h"



// allocating memory for vm assert if NULL alocation
void allocMemory(MEMORY *memory){
	srand(time(0));
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
		printf("\non mem locarion %lu value is %c\n",i,memory->mem[i]);
	}
	system("pause");
}
void printVar(MEMORY *memory,int start,int stop){
    printf("\n\n\t*******************************************\n\n\t\t\t");
	printf("VAR\n");
	printf("\n\n\t*******************************************\n\n\t\t\t");
		for(size_t i = start; i < stop; i++){
		printf("\nvar %lu has name %s starts at %u ends at %u\n",i,memory->varName[i],memory->varMemStartPointers[i],memory->varMemEndPoiners[i]);
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
		void* s = strcpy(mem->varName[mem->counterVar],token);
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
		if(strcmp(mem->varName[i],token) == 0){
		  isVarExist = 1;	
		  //for(size_t j = mem->varMemStartPointers[i];j <  mem->varMemEndPoiners[i];j++){
		//	if(mem->mem[j] >= 32 && mem->mem[j] <= 127)
		//		printf("%c",mem->mem[j]);
				//putc(mem->mem[h])
				//printf("Nesto");
		  //}
		
	  write(1,&mem->mem[mem->varMemStartPointers[i]],mem->varMemEndPoiners[i]-mem->varMemStartPointers[i]);
				
		  
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
//void bgoto(char *token,MEMORY *mem,FILE *f);

void bgoto(char *token,MEMORY *mem,FILE *f){
	//mem->RET = curentAdress;
	token = strtok(0," ");
	char line[MAX_LINE];
	int gotoAdress = atoi(token)  - 1;
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
  static char valueMemFirst[30],valueMemLast[30];
	size_t counter = 0;
	for(size_t i = mem->varMemStartPointers[a]; i < mem->varMemEndPoiners[a]; i++){
	  valueMemFirst[counter++] = mem->mem[i];
	}
	valueMemFirst[counter] = '\0';
	counter = 0; 
	for(size_t i = mem->varMemStartPointers[b]; i < mem->varMemEndPoiners[b]; i++){
	  valueMemLast[counter++] = mem->mem[i];
	}
	valueMemLast[counter] = '\0';
	counter = 0;
	//printf("FLOAT %s\n",valueMemFirst);
    float value1 =  atof(valueMemFirst);
    float value2 =  atof(valueMemLast);
    static float valueResult;
    static char resMem[10];
    if(sign == '+'){
   	  counter = 0;
   	  valueResult = value1 + value2;
		 
         sprintf(resMem,"%f",valueResult);
		 //itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}

  if(sign == '-'){
   	  counter = 0;
   	  valueResult = value1 - value2;
         sprintf(resMem,"%f",valueResult);
		 //itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}
	
    if(sign == '*'){
   	  counter = 0;
   	  valueResult = value1 * value2;
         sprintf(resMem,"%f",valueResult);
		 //itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}
	
	  if(sign == '/'){
   	  counter = 0;
   	  assert(value2!=0&&"DIVISION BY 0 !!!");
   	  valueResult = value1 / value2;
         sprintf(resMem,"%f",valueResult);
		 //itoa(valueResult,resMem,10);
		 for(size_t i = mem->varMemStartPointers[result]; i  < mem->varMemEndPoiners[result];i++){
           mem->mem[i] = resMem[counter++];
		 }  
	}	

    if(sign == '%'){
   	  counter = 0;
   	  //assert(value1>value2 &&  "MOD ERROR !!!");
      //assert(value2!=0 &&  "MOD ERROR !!!");
   	  int valueResult = (int)value1 % (int)value2;
      //printf("%d", valueResult);
         sprintf(resMem,"%d",valueResult);
		 //itoa(valueResult,resMem,10);
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
	 static char line[MAX_LINE];
     if(strcmp(CharTokensRepresentation[EQUALCOND],operation) == 0){
	 //printf("\na %d b %d\n", a,b);	
        if(a != b){
     		fgets(line,MAX_LINE,f);
		 }
     	
	 }
	 else if(strcmp(CharTokensRepresentation[LESER],operation) == 0){
     	if(a > b){
     		fgets(line,MAX_LINE,f);
		 }
     	
	 }
	 
	else if(strcmp(CharTokensRepresentation[BIGER],operation) == 0){
     	if(a < b){
     		fgets(line,MAX_LINE,f);
		 }
     	
	 }
 }

//

void brandom(char* token,MEMORY *mem){
   	srand(time(0));
    token = strtok(0," ");
	int isVarExist = 0;

	for (size_t i = 0; i < mem->counterVar; i++)
	{
		
		if(strcmp(token, mem->varName[i]) == 0){
			isVarExist = 1;
			
			//Random value (0 - 100)
		for(size_t j = mem->varMemStartPointers[i]; j < mem->varMemEndPoiners[i]; j++)
			{mem->mem[j] =  rand()%10 + '0';}

		}
	}
	assert(isVarExist && "VAR IS NOT DECLARED");
}
//GOTOSUB go to declared lable

void gotosub(char* token, MEMORY* mem, FILE *f){
	//printf("NESTO");
	token = strtok(0," ");
	fseek(f,0,SEEK_SET);
	static char line[MAX_LINE];
	int counter = 0;
	while (!feof(f))
	{
		counter++;
		//printf("%d",counter);
		fgets(line,MAX_LINE,f);
		static char *labelContainer;
		labelContainer = strtok(line," ");
		if(strcmp(CharTokensRepresentation[LABEL],labelContainer) == 0){
		labelContainer = strtok(0," ");
		if(strcmp(token,labelContainer) == 0){
		 fseek(f,0,SEEK_SET); 
			for(size_t i = 0 ; i  < counter; i++){
	  			fgets(line,MAX_LINE,f);
	 			}
		break;
		}
		}
		
	}
	//print("%c",token[0]);

}

//init graphics
void initGraphics(SDL_Renderer *renderer,SDL_Window *window){
	SDL_CreateWindowAndRenderer(width,height,SDL_RENDERER_ACCELERATED,window,renderer);
}



//check quit 

void drawPixel(SDL_Renderer *renderer,SDL_Window *window, char* token, MEMORY *mem, uint8_t PIXELS[height][width]){
  
  static char x[10],y[10],color[10],varX[10],varY[10],varColor[10],isDraw[10]; 
  int X,Y = 1,C = 1,counter = 0,ba;
  token = strtok(0, " ");
  strcpy(x,token);
  //printf("x %s", x);
  token = strtok(0, " ");
  strcpy(y,token);
  token = strtok(0, " ");
  strcpy(color,token);
  //printf("x %s y %s z %s\n",x,y,color);
  for (size_t i = 0; i < mem->counterVar; i++)
  {
	if(strcmp(x,mem->varName[i])==0){
	   counter  = 0;
	   for (size_t j = mem->varMemStartPointers[i]; j < mem->varMemEndPoiners[i]; j++){
		varX[counter++] = mem->mem[j];
	   }		
	}
	if(strcmp(y,mem->varName[i])==0){
	   counter  = 0;
	   for (size_t j = mem->varMemStartPointers[i]; j < mem->varMemEndPoiners[i]; j++){
		varY[counter++] = mem->mem[j];
	   } 	   
    }
  if(strcmp(color,mem->varName[i])==0){
	   counter  = 0;
	   for (size_t j = mem->varMemStartPointers[i]; j < mem->varMemEndPoiners[i]; j++){
		varColor[counter++] = mem->mem[j];
	   }	   
   }  
   }
 X = atoi(varX);
 Y = atoi(varY);
 C = atoi(varColor);
 //Geting all 3 tokens then check if they exist load them from memory and convert them to ints
 //printf("\nx =  %d y  = %d , color = %d",X,Y,C);

 PIXELS[Y][X] = C;
 //printf("%u\n ",PIXELS[Y][X]);
 //printf("x %u, y %u, color %u\n",X,Y,C);
 //MAIN DRAWING LOOP 
//scanf("%d",&ba);
}
//Render pixels
void render(SDL_Renderer *renderer,SDL_Window *window,uint8_t PIXELS[height][width]){
SDL_RenderClear(renderer);
for (size_t i = 0; i < height; i++)
 {
	for (size_t j = 0; j < width; j++)
	{
		//uint8_t r =(uint8_t)(PIXELS[i][j] & 0xFF000000);
		//uint8_t g =(uint8_t)(PIXELS[i][j] & 0x00FF0000);
		//uint8_t b =(uint8_t)(PIXELS[i][j] & 0x0000FF00);
	 	//uint8_t a =(uint8_t)(PIXELS[i][j] & 0x000000FF);
		//if(r!=0)
		//printf("r = %u g = %u b = %u a = %u\n",r,g,b,a);
		//scanf("%d",&ba);
		//SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_SetRenderDrawColor(renderer,PIXELS[i][j],PIXELS[i][j]%125,PIXELS[i][j]%75,PIXELS[i][j]%37);
		SDL_RenderDrawPoint(renderer,j,i);

	}
	
 }
SDL_SetRenderDrawColor(renderer,0,0,0,0);
SDL_RenderPresent(renderer);

}
//Load value of b to a to memory start:stop
void load(char* token,MEMORY *mem){
  token = strtok(NULL," ");
  //printf("%s",token);
  int doesExist = 0;
  size_t A, B;

  //CHECK DOES VAR A AND B  EXIST AND SAVE THER INDEX
  for (size_t i = 0; i < mem->counterVar; i++)
  {
    if (strcmp(token,mem->varName[i]) == 0)
    {
        A = i;
        token = strtok(NULL," ");
        //printf("\n%s\n",token);
        for (size_t j = 0; j < mem->counterVar; j++)
        {
            if (strcmp(token,mem->varName[j]) == 0){
              doesExist = 1;
              B = j + mem->varMemStartPointers[j] - 1; 
              break;
            }
        }
        break;
    }
      

  }
  assert(doesExist && "Var does not exist");
    //size_t start, end
  token = strtok(0," ");
  size_t start  = atoi(token) + mem->varMemStartPointers[A];
  token = strtok(0," ");
  token = strtok(0," ");
  size_t end  = atoi(token) + mem->varMemStartPointers[A];

  //printf("load %ld : %ld\n",start, end);
  size_t counter = 0;
  for (size_t i =  start; i < end; i++)
  {
    // printf("a = %c  b = %c\n",mem->mem[i], mem->mem[B + (counter)]);
     mem->mem[i] =  mem->mem[B + (counter)]; 
     counter++; 
  }
  

}


//

//

//
void execute(MEMORY *mem){

	FILE *f = fopen(fileName,"r");  //Open File prob with args
	char line[MAX_LINE];     //Stores one line of instruction     kasnije flag
	size_t numberOfLine = 0;

	//GRAPHIC STUF
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Event event; 
	//	

	static uint8_t PIXELS[height][width];
	char* token;// = strtok(line , " ");  // First token
	
	while(1){
		
		if(SDL_PollEvent(&event)){	
		if(event.type == SDL_QUIT){
			break;
		}
		}
	  void* s =  fgets(line,MAX_LINE,f);       //Read line of instructions
	  //printf("%s line ",line);
	  if(s == NULL){
        if(feof(f))
          printf("\nEND OF THE PROGRAM !!!\n");
	    else
 	      assert(0 && "ERROR IN READING BUFFER!!!");
		break;
	  }
      
      //token = (char *)calloc(40,sizeof(char));
      //token = strtok(line , " ");  // First token
      //printf("\n%s", token);
	  //int curentAdress = atoi(token); 
	  token = strtok(line ," ");      // Next token
	  //printf("%s\n" ,token);
  	  //printMemory(mem,0,50);
  	  //printVar(mem,0,20);
	  if (strcmp(CharTokensRepresentation[GOTOSUB], token) == 0){
		gotosub(token,mem,f);
	   }
	  
      else if(strcmp(CharTokensRepresentation[IF], token) == 0){
	  	bif(token,mem,f);
	  }  
	else if(strcmp(CharTokensRepresentation[LOAD], token) == 0){
	    load(token,mem);
	}


      else if(strcmp(CharTokensRepresentation[PRINT], token) == 0){   //If token is print
	    print(token,mem);
	  }
	  else if(strcmp(CharTokensRepresentation[GOTO], token) == 0){
        bgoto(token,mem,f);
	  }
	  else if (strcmp(CharTokensRepresentation[PIXEL], token) == 0){
		drawPixel(&renderer,&window,token,mem,PIXELS);
	   }
	  
	  else if(strcmp(CharTokensRepresentation[INPUT], token) == 0){
	  	input(token,mem);

	  }
	  else if(strcmp(CharTokensRepresentation[RAND], token) == 0){
	  	//printf("NESTO");
		brandom(token,mem);
	  }
	   else if(strcmp(CharTokensRepresentation[END], token) == 0){
	   		printf("\nEND OF THE PROGRAM !!!\n");
	   break;
	   }
	   else if(strcmp(token,CharTokensRepresentation[VAR]) == 0){  //If Token is VAR
		var(token,mem); 
	   }
	   else if (strcmp(CharTokensRepresentation[LABEL], token) == 0);
	   else if (strcmp(CharTokensRepresentation[GRAPHICS], token) == 0){
		SDL_CreateWindowAndRenderer(width,height,SDL_RENDERER_ACCELERATED,&window,&renderer);
		//initGraphics(&renderer,&window);
	   }

	   else if (strcmp(CharTokensRepresentation[RENDER], token) == 0){
		render(renderer,window,PIXELS);
	   }
      // if evriting else is finish now we nead to see math operations
	   else{
       static char varName[30],firstOperand[30],lastOperand[30];
       static int varExist = 0,result,firstIndex,lastIndex ;
        strcpy(varName,token);
        //printf("Nesto\n\n");
		//system("pause");
        size_t i = 0;
        //check VarName
        for(;i < mem->counterVar+1;i++){
        	if(strcmp(token,mem->varName[i])==0){
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
		//printf("token %s", token);
			for(size_t j = 0;j < mem->counterVar;j++){
        	if(strcmp(token,mem->varName[j])==0){
        		lastIndex = j;
        		break;
			}
		}
		//printf("\nfirstIndex %d ,lastIndex %d ,i %d,sign %c",firstIndex,lastIndex,i,sign);
		//system("pause");
		mathoperations(firstIndex,lastIndex,i,sign,mem);
	  }
	  //printf("%s", token);
	  

   	  //system("pause");
}
}

int main(int argc, char* argv[])
{
	//printf("%s", CharTokensRepresentation[PLUS]);
	//printf("Nesto\n");
	//printf("Input File You Want to run: ");
	//printf("%s\n",argv[1]);
	//while(1);

	//printf(" %s\n",fileName);
	if(argc == 1){
	  printf("path to program <program.bas>\n");
	  return 0 ;
	 //exit(EXIT_SUCCESS);
	}
	strcpy(fileName,argv[1]);
	MEMORY  memory;
	allocMemory(&memory);
	execute(&memory);
	return 0;
}
