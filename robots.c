#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_COLOURS=4;
const int NUM_DIRECTIONS=4;

void quickPrint(const char *printValue){
    printf("\n%s",printValue);
}

int intValueCheck(int intValue,short int inputTypeValue,int fscanfValue,int turns){return 1;}
// int intValueCheck(int intValue,short int inputTypeValue,int fscanfValue,int turns){
    
//     switch (inputTypeValue)
//     {
//     case 1:
//         /* test rows */
//         if(fscanfValue==EOF) fprintf(stderr,"\nERROR: The number of rows was not in the input file (reached eof)");
//         else{
//         if(fscanfValue==0) fprintf(stderr,"\nERROR: The number of rows could not be read due to corrupt data in the file");
//         else{
//             if(intValue<20 || 300<intValue) fprintf(stderr,"\nERROR: The number of rows was outside the specified range (20 to 300 inclusive)");
        
//         }
//         }
//         if((fscanfValue==EOF)||((fscanfValue==0)||(intValue<20 || 300<intValue))){
// return 0;
//         }
//         break;
//     case 2:
//         /* test cols */
//         if(fscanfValue==EOF) fprintf(stderr,"\nERROR: The number of columns was not in the input file (reached eof)");
//         else{
//             if(fscanfValue==0) fprintf(stderr,"\nERROR: The number of columns could not be read due to corrupt data in the file");
//         else{
//             if(intValue<20 || 300<intValue) fprintf(stderr,"\nERROR: The number of columns was outside the specified range (20 to 300 inclusive)");
        
//         }
//         }
//         if((fscanfValue==EOF)||((fscanfValue==0)||(intValue<20 || 300<intValue))){
// return 0;
//         }
//         break;
//     case 3:
//         /* test robots */
//         if(fscanfValue==EOF) fprintf(stderr,"\nERROR: The number of robots was not in the input file (reached eof)");
//         else{
//             if(fscanfValue==0) fprintf(stderr,"\nERROR: The number of robots could not be read due to corrupt data in the file");
//         else{
//             if(intValue<1 || 10<intValue) fprintf(stderr,"\nERROR: The number of robots was outside the specified range (20 to 300 inclusive)");
        
//         }
//         }
//         if((fscanfValue==EOF)||((fscanfValue==0)||(intValue<1 || 10<intValue))){
// return 0;
//         }
//         break;
// case 4:
//         /* test initTypeValue */
//         if(fscanfValue==EOF) fprintf(stderr,"\nERROR: The initTypeValue was not in the input file (reached eof)");
//        else{
//          if(fscanfValue==0) fprintf(stderr,"\nERROR: The initTypeValue could not be read due to corrupt data in the file");
//         else{
//             if(intValue<1 || 3<intValue) fprintf(stderr,"\nERROR: The initTypeValue was outside the specified range (20 to 300 inclusive)");
        
//         }
//        }
//        if((fscanfValue==EOF)||((fscanfValue==0)||(intValue<1 || 3<intValue))){
// return 0;
//         }
//         break;
// case 5:
//         /* test initTypeValue */
//         if(fscanfValue==EOF) fprintf(stderr,"\nERROR: The initSeed was not in the input file (reached eof)");
//        else{
//          if(fscanfValue==0) fprintf(stderr,"\nERROR: The initSeed could not be read due to corrupt data in the file");
//         else{
//             if(intValue<10 || 32767<intValue) fprintf(stderr,"\nERROR: The initSeed was outside the specified range (20 to 300 inclusive)");
       
//         }
//        }
//         if((fscanfValue==EOF)||((fscanfValue==0)||(intValue<10 || 32767<intValue))){
// return 0;
//         }
//         break;
// case 6:
//         /* test initTypeValue */
//         if(fscanfValue==EOF) fprintf(stderr,"\nERROR: The turns was not in the input file (reached eof)");
//        else{
//          if(fscanfValue==0) fprintf(stderr,"\nERROR: The turns could not be read due to corrupt data in the file");
//         else{
//             if(intValue<10 || 5000<intValue) fprintf(stderr,"\nERROR: The turns was outside the specified range (20 to 300 inclusive)");
       
//         }
//        }
//         if((fscanfValue==EOF)||((fscanfValue==0)||(intValue<10 || 5000<intValue))){
// return 0;
//         }
//         break;
// case 7:
//         /* test initTypeValue */
//         if(fscanfValue==EOF) fprintf(stderr,"\nERROR: The turns was not in the input file (reached eof)");
//        else{
//          if(fscanfValue==0) fprintf(stderr,"\nERROR: The turns could not be read due to corrupt data in the file");
//         else{
//             if(intValue<1 || turns<intValue) fprintf(stderr,"\nERROR: The turns was outside the specified range (20 to 300 inclusive)");
            
//         }
//        }
//         if((fscanfValue==EOF)||((fscanfValue==0)||(intValue<1 || turns<intValue))){
          
// return 0;
//         }
//         break;
//     }
//     return 1;
// }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FUNCS
enum initTypeList{ Random = 1, Checkerboard, AllWhite}myList=Random;
struct Robot{
int x;
int y;
int direction;
int paintColour;
};

void InitBoardRand(int **board, int numRows, int numCols, unsigned int seed)
{
	/* Please note that NUM_COLOURS is a global constant or a MACRO*/
	srand(seed);
	for (int K = 0; K < numRows; K++)
	{
		for (int J = 0; J < numCols; J++)
		{
			board[K][J] = rand() % NUM_COLOURS + 1;
		}
	}
}


void InitBoardChecker(int **board, int numRows, int numCols){
// white1 red2 green3 blue4
for(int tmpRows=0;tmpRows<numRows;tmpRows++){
    if(tmpRows%2==0){
        for(int tmpCols=0;tmpCols<numCols;tmpCols++){
            if(tmpCols%2==0)board[tmpRows][tmpCols]=1;else{board[tmpRows][tmpCols]=2;}
        }
    }else{
            for(int tmpCols=0;tmpCols<numCols;tmpCols++){
                if(tmpCols%2==0)board[tmpRows][tmpCols]=2;else{board[tmpRows][tmpCols]=1;}
            }   
    }
}
}

void InitBoardAllWhite(int **board, int numRows, int numCols){
    for(int tmpRows=0;tmpRows<numRows;tmpRows++){
        for(int tmpCols=0;tmpCols<numCols;tmpCols++){
            board[tmpRows][tmpCols]=1;
        }
    }
}

int InitBoard( int **boardpp, int numRows, int numCols, enum initTypeList mylist, unsigned int seed){

}

void ppprint(int **board,int rowCount,int colCount){
        for(int tmpRows=0;tmpRows<rowCount;tmpRows++){
        for(int tmpCols=0;tmpCols<colCount;tmpCols++){
            printf("%d",board[tmpRows][tmpCols]);
        }
        printf("\n");
    }
}
void updateBoardColor(int **board,int x,int y,int paint){
    board[x][y]=paint;
}
void rotateBot(int **board,struct Robot *robotsList, int robotindex,short currentDirection){
    printf("\n==>%d==>%d",robotsList[robotindex].x,robotsList[robotindex].y);
    int short newDirection=currentDirection;
    newDirection=+board[robotsList[robotindex].x][robotsList[robotindex].y];
    if(newDirection>4)newDirection=-4;
    switch (newDirection)       //cypher the direction in the boring order
        {
        case 1:
            newDirection=1;
            break;
        case 2:
            newDirection=3;
            break;
        case 3:
            newDirection=2;
            break;
        case 4:
            newDirection=4;
            break;
        default:
            break;
        }
        robotsList[robotindex].direction=newDirection;
        updateBoardColor(board,robotsList[robotindex].x,robotsList[robotindex].y,robotsList[robotindex].paintColour);
}
void move(int **board,struct Robot *robotsList,int nuRobot,int numRows,int numCols){
    short int tmpDir=0;
    for(int tmpRobotIndex=0;tmpRobotIndex<nuRobot;tmpRobotIndex++){
        switch (robotsList[tmpRobotIndex].direction) //decipher the init direction
        {
        case 1:
            tmpDir=1;
            break;
        case 2:
            tmpDir=3;
            break;
        case 3:
            tmpDir=2;
            break;
        case 4:
            tmpDir=4;
            break;
        default:
            break;
        }
        if(tmpDir==2 || tmpDir==4){          // exception row
            // row manipulation
            if((tmpDir==2)&&(robotsList[tmpRobotIndex].y==(numCols-1))){
                robotsList[tmpRobotIndex].y=0;
                rotateBot(board,robotsList,tmpRobotIndex,robotsList[tmpRobotIndex].direction);

            }else if((tmpDir==4) &&(robotsList[tmpRobotIndex].y==0)){
                robotsList[tmpRobotIndex].y=numCols-1;
                rotateBot(board,robotsList,tmpRobotIndex,robotsList[tmpRobotIndex].direction);
            }else{
                if(tmpDir==2)robotsList[tmpRobotIndex].y+=1;else robotsList[tmpRobotIndex].y-=1;
                rotateBot(board,robotsList,tmpRobotIndex,robotsList[tmpRobotIndex].direction);
            }
        }
        if(tmpDir==1 || tmpDir==3){         //exception cols
            // col manipulation
            if((tmpDir==1)&&(robotsList[tmpRobotIndex].x==(0))){
                robotsList[tmpRobotIndex].x=numRows-1;
                rotateBot(board,robotsList,tmpRobotIndex,robotsList[tmpRobotIndex].direction);
            }else if((tmpDir==3) &&(robotsList[tmpRobotIndex].x==(numRows-1))){
                robotsList[tmpRobotIndex].x=0;
                rotateBot(board,robotsList,tmpRobotIndex,robotsList[tmpRobotIndex].direction);
            }else{
                if(tmpDir==1)robotsList[tmpRobotIndex].x+=1;else robotsList[tmpRobotIndex].x-=1;
                rotateBot(board,robotsList,tmpRobotIndex,robotsList[tmpRobotIndex].direction);
            }
        }

    }
    // directions clockwise: 1north1 2south3 3east2 4west4
    // corrected order: 1north 2est 3south 4west
    //White 90 degrees, Red 180 degrees, green 270 degrees, and blue 360

}
int main(){



printf("vscode?---%d\n",myList);

    // ++++++++++++++++++++++++++++++++



    // ++++++++++++++++++++++++++++++++
    short int status=1;
unsigned short tmpIndx=0;
char outputFileName[200], inputFileName[200]="in.txt";
unsigned int rowCount,colCount,nuRobots,indexInit,intSeed,nuTurns,intervalTurns;
colCount=EOF;

short int r;
while(tmpIndx<=5){
    
    if(tmpIndx==5){
        fprintf(stderr,"\nbERROR: Failed to open the input file 5 times. Terminating the program.");
        return 0;
    }
    //printf("\nEnter the name of the input file: ");
    //scanf("%s",inputFileName);
    FILE *inputFilePointer;
    inputFilePointer=fopen(inputFileName,"r");
    if(inputFilePointer==NULL){
        fprintf(stderr,"\nERROR: Input file not opened correctly.");
    }else{
        

        r = fscanf(inputFilePointer, "%d", &rowCount);
        //printf("\n%d",rowCount);
        status=intValueCheck(rowCount,1,r,0);
        if(status==0){exit(EXIT_FAILURE);return 0; /*terminate program*/}
          //printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^%d",status);  

        r = fscanf(inputFilePointer, "%d", &colCount);
        //printf("\n%d",colCount);
        status=intValueCheck(colCount,2,r,0);
         if(status==0){exit(EXIT_FAILURE);return 0; /*terminate program*/}   

        r = fscanf(inputFilePointer, "%d", &nuRobots);
        //printf("\n%d",nuRobots);
        status=intValueCheck(nuRobots,3,r,0);
        if(status==0){exit(EXIT_FAILURE);return 0; /*terminate program*/}    

        r = fscanf(inputFilePointer, "%d", &indexInit);
        //printf("\n%d",indexInit);
        status=intValueCheck(indexInit,4,r,0);
        if(status==0){exit(EXIT_FAILURE);return 0; /*terminate program*/}else{
            switch (indexInit)
            {
            case 1:
                myList=Random;
                /* code */
                break;
            case 2:
                myList=Checkerboard;
                break;
            case 3:
                myList=AllWhite;
                break;

            default:
                myList=Random;
                break;
            }
        }    

        r = fscanf(inputFilePointer, "%d", &intSeed);
       // printf("\n%d",intSeed);
        status=intValueCheck(intSeed,5,r,0);
        if(status==0){exit(EXIT_FAILURE);return 0; /*terminate program*/}else{
            srand(intSeed);
        } 

      r = fscanf(inputFilePointer, "%d", &nuTurns);
        //printf("\n%d",nuTurns);
        status=intValueCheck(nuTurns,6,r,0);
        if(status==0){exit(EXIT_FAILURE);return 0; /*terminate program*/}        

    r = fscanf(inputFilePointer, "%d", &intervalTurns);
        //printf("\n%d",intervalTurns);
        status=intValueCheck(intervalTurns,7,r,nuTurns);
        if(status==0){exit(EXIT_FAILURE);return 0; /*terminate program*/}
        //printf("\n");

        /*rtert erterteer t__________________________________________________________________*/


    int **boardpp=NULL;
    boardpp=(int**)malloc((sizeof(int*))*rowCount);
    if(boardpp==NULL){
        fprintf(stderr,"ERROR: array of pointers for 2-D array could not be allocated");
        exit(EXIT_FAILURE);
        return 0;
    }
    for(tmpIndx=0;tmpIndx<rowCount;tmpIndx++){
        boardpp[tmpIndx]=(int*)malloc((sizeof(int))*colCount);
        if(boardpp[tmpIndx]==NULL){
        fprintf(stderr,"ERROR: Array storage could not be allocated");
            exit(EXIT_FAILURE);
            return 0;
        }
    }
    struct Robot *robotsStruct;

    robotsStruct=malloc((sizeof(struct Robot))*nuRobots);


    for(tmpIndx=0;tmpIndx<nuRobots;tmpIndx++){
        
        robotsStruct[tmpIndx].x= rand() % rowCount;
        robotsStruct[tmpIndx].y= rand() % colCount;
        robotsStruct[tmpIndx].direction=rand() % NUM_DIRECTIONS + 1;
        robotsStruct[tmpIndx].paintColour=rand() % NUM_COLOURS + 1;
    }

        for(tmpIndx=0;tmpIndx<nuRobots;tmpIndx++){
        printf("\n---------------------------\n");
        printf("%d\n",robotsStruct[tmpIndx].x);
        printf("%d\n",robotsStruct[tmpIndx].y);
        printf("%d\n",robotsStruct[tmpIndx].direction);
        printf("%d\n",robotsStruct[tmpIndx].paintColour);
   
    }


// Initialize the random number generator srand(seed)
//  For each robot (robot(1), robot(2), … , robot(number of robots -1)
//  Robot x coordinate = rand() % numCols;
//  Robot y coordinate = rand() % numRows;
//  Direction robot is facing= rand() % NUM_DIRECTIONS + 1;
//  Colour of paint the robot is carrying = rand() % NUM_COLOURS + 1; 

    // for(int tmpRows=0;tmpRows<rowCount;tmpRows++){
    //     for(int tmpCols=0;tmpCols<colCount;tmpCols++){
    //         boardpp[tmpRows][tmpCols]=8;
    //     }
    // }
    

    //InitBoardChecker(boardpp,rowCount,colCount);
    /*rtert erterteer t___________________________PRINTER         ______=====================_________________*/
  
    InitBoardAllWhite(boardpp,rowCount,colCount);
    ppprint(boardpp,rowCount,colCount);
    for(tmpIndx=0;tmpIndx<1;tmpIndx++){
        move(boardpp,robotsStruct,nuRobots,rowCount,colCount);
    }
    printf("\n");
    ppprint(boardpp,rowCount,colCount);
    
    /*rtert erterteer t__________________________________________________====================________________*/
    


        /*+++++++++++++++++++++++++++++++++++++++*/
        tmpIndx=6;
        break;
    } 
    tmpIndx++;   
}

return 0;

}