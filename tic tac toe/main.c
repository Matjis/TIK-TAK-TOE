#include <stdio.h>
#include <stdlib.h>

void info(){
    printf("\n        Tic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (/)\n\n");
}

int drawGrid(char grid[10]){  //draws grid
    for(int i=0;i<9;i+=3){ //draws the grid and puts values in each field  from grid array
        printf("     |     |   \n");
        printf("  %c  |  %c  |  %c \n", grid[i],grid[i+1],grid[i+2]);
        if(i>5)
        printf("     |     |   \n");
        else
        printf("_____|_____|_____\n");
    }
}

int wrongSymbol(char fieldNumber){
    int gameState=0;
    int i=1;

    for( ; i<10; i++){
        if(i==fieldNumber){
            printf("right symbol");
            break;
        }
    }

    if(i>9){
        gameState=10;
        printf("wrong symbol\n");
    }

    printf("game state value %d\n", gameState);
    return gameState;
}

int wrongField(int fieldNumber, char grid[10], char player1char, char player2char){
    int gameState=0;

    if(grid[fieldNumber-1]==player1char || grid[fieldNumber-1]==player2char ){
        gameState=1;
    }

    return gameState;
}

int checkWinner(char grid[10], char playerChar){
    int gameState=0;
    int returnValue=0;

    for(int i=0; i<9; i+=3){
        if(grid[i]==playerChar && grid[i+1]==playerChar && grid[i+2]==playerChar)
            gameState=1;
    }
    for(int i=0; i<3; i+=1){
        if(grid[i]==playerChar && grid[i+3]==playerChar && grid[i+6]==playerChar)
            gameState=1;
    }
    if(grid[0]==playerChar && grid[4]==playerChar && grid[8]==playerChar)
            gameState=1;
    if(grid[2]==playerChar && grid[4]==playerChar && grid[6]==playerChar)
            gameState=1;

    if(gameState==1){
        //printf("position %d is %c\n",i,grid[i]);
        printf("winner\n");
        returnValue=10;
    }

    return returnValue;
}

int checkDraw(char grid[10], char player1char, char player2char){
    int gameState=0;

    for(int i=0; i<9; i+=1){
        if(grid[i]!= player1char || grid[i]!= player2char){
            //printf("%c hmm %d\n",grid[i],i);
            break;
        }
        else if (grid[i]==player1char && grid[i]==player2char){
            gameState=10;
            printf("Game over, no one won, try again");
        }
    }

    return gameState;
}

int playerChoosing(char playerChar, char player1char, char player2char){ //changes the character used for first and secound player

    if (playerChar==player1char)
        playerChar=player2char;
    else
        playerChar=player1char;

    return playerChar;
}

int playersNumber(char playerChar, char player1char, char player2char){
    int num=0;

    if(playerChar==player1char)
        num=1;
    else if(playerChar==player2char)
        num=2;

    return num;
}

int main()
{
    int winner=0; //is game over with winner?
    int draw=0;   //is game over with draw?
    int fieldNumber=10; //fields number picked by player
    int wrongF=0;
    int wrongS=0;

    int playerNumber=1;
    char player1char= 'X';
    char player2char= '/';
    char playerAutoChar=player1char; //players character depending on the player
    //char gridStartValues[]={[1]='1',[2]='2',[3]='3',[4]='4',[5]='5',[6]='6',[7]='7',[8]='8',[9]='9'};
    char gridStartValues[]={"123456789"};

    //system("cls");
    info();
    drawGrid(gridStartValues);

    while(winner==draw){

        playerNumber=playersNumber(playerAutoChar, player1char, player2char);
        printf("\n\nPlayer%d, enter a number: ",playerNumber);
        scanf("%d", &fieldNumber);

        wrongF=wrongField(fieldNumber, gridStartValues, player1char, player2char);
  //    wrongS=wrongSymbol(fieldNumber);

        system("cls");
        info();

        if(wrongF==0 && wrongS==0){
            if(fieldNumber<10 && fieldNumber>0)
                gridStartValues[fieldNumber-1]=playerAutoChar;//when player inputs a number this will change that field to character X

            winner=checkWinner(gridStartValues, playerAutoChar);
            draw=checkDraw(gridStartValues, player1char, player2char);
            //printf("draw value: %d\n",draw);
            playerAutoChar=playerChoosing(playerAutoChar, player1char, player2char);
        }


        drawGrid(gridStartValues);



        if (wrongF==1){
            printf("\nThat field is taken, try another one");
        }



        if(wrongS==1){
            printf("\nWrong symbol, you need to use numbers between 1 and 9");
        }

    }
    return 0;
}
