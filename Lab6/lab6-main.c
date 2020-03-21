/* Author: Meha Gupta 
 * Date: 06 March 2019
 * Lab6 Assignment: Simple dual player Tic-Tac-Toe game */

#include <stdio.h>

//Declaration of functions used
void printBoard(int board[],int playerA, int playerB); //Fuction to print the tic-tac-toe board
int requestValidInput(int board[],int playerA, int playerB); //Function to collect and check the calidity of user input
int checkForWinner(int board[],int playerA,int playerB); //Function to check for winner/draw of game
    
int main(int argc, char **argv)
{
	int board[9]={49,50,51,52,53,54,55,56,57}; //one-dimensional array representing the tic-tac-toe board (ASCII code used to print A and B in future//
    char apostrophe='\'';
    int gameStatus=0; //initialization to enter the 'while' loop
    int playerA, playerB, i;
    int player=0;
    
    //The game loop ('while' loop used)
    while (gameStatus!=65 && gameStatus!=66 && gameStatus!=12){
        printf("The current state of the Tic-tac-toe Board:\n");
        printBoard(board, playerA, playerB);
        //if-else statement (with 'modulo' operation) used to ensure alternating player turns (Starting with player A)
        if ((player%2)==0){ 
            printf("It is Player A%cs turn.\n",apostrophe);
            playerA=requestValidInput(board,playerA,playerB);
            for (i=1;i<=9;i++){
                if (playerA==(i)) {
                    board[i-1]=65;
                    }
            } //used to update game status
        gameStatus=checkForWinner(board,playerA,playerB);
        player=player+1;
        }
        else {
            printf("It is Player B%cs turn.\n",apostrophe);
            playerB=requestValidInput(board,playerA,playerB);
            for (i=1;i<=9;i++){
                if (playerB==(i)) {
                    board[i-1]=66;
                    }
            } //used to update game status
            gameStatus=checkForWinner(board,playerA,playerB);
            player=player+1;
        }
    }
    
    //Displaying game result
    if (gameStatus==65){
        printf("Player A wins!\n");
        printBoard(board,playerA,playerB);
    }
    else if (gameStatus==66){
        printf("Player B wins!\n");
        printBoard(board, playerA, playerB);
    }
    else {
        printf("It%cs a draw!\n", apostrophe);
        printBoard(board,playerA,playerB);
    }
    return 0;
}

void printBoard(int board[], int playerA, int playerB){
	int i;
    for (i=0; i<=6; i=i+3){
    printf(" %c %c %c\n",board[i],board[i+1],board[i+2]); //'%c' used for appropriate display of ASCII characters
    }
}

int requestValidInput(int board[], int playerA, int playerB){
    int tempPosition;
    printf("Please enter a valid position to play.\n");
    scanf("%d",&tempPosition);
    //Checking the validity of input
    //Using 'while' loop to keep requesting for input until a valid iput is entered
    while (tempPosition>9 || board[tempPosition-1]==65 || board[tempPosition-1]==66 || tempPosition<1) {
        if (tempPosition>9 ||tempPosition<1){
            printf("Invalid input, please try again.\n");
        }
        else if (board[tempPosition-1]==65 || board[tempPosition-1]==66){
            printf("That position has already been played, please try again.\n");
        }
        scanf("%d",&tempPosition);
    }
    return tempPosition;
}

int checkForWinner(int board[],int playerA,int playerB) {
    int winner;
    //checking for winner by brute force
    if (board[0]==board[1] && board[1]==board [2]){
        winner=board[1];
    }
    else if (board[3]==board[4] && board[4]==board [5]){
        winner=board[3];
    }
    else if (board[6]==board[7] && board[7]==board [8]){
        winner=board[6];
    }
    else if (board[0]==board[4] && board[4]==board [8]){
        winner=board[1];
    }
    else if (board[1]==board[4] && board[4]==board [7]){
        winner=board[2];
    }
    else if (board[2]==board[4] && board[4]==board [6]){
        winner=board[3];
    }
    else if (board[0]==board[3] && board[3]==board[6]){
        winner=board[0];
    }
    else if (board[2]==board[5] && board[5]==board [8]){
        winner=board[2];
    }
    //Draw condition:
    else if (board[0]!=49 && board[1]!=50 && board[2]!=51 && board[3]!=52 && board[4]!=53 && board[5]!=54 && board[6]!=55 && board[7]!=56 && board[8]!=57){
        winner=12;
    }
    else winner=13;
    
    return winner;
}

