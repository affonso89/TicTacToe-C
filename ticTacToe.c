/*
Tic Tac Toe game (jogo da velha)
2 players.
Array to represent the board, 10 positions do not use 0
Check for win, draw
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayGrid(char pos[11]);
void game(char arr[11]);
bool checkForWin(char arr[11]);
void playAgain();

int main(){
  system("clear");
  printf("\n");
  // tabuleiro inicial
  char initPos[11] = "0123456789";
  displayGrid(initPos);
  
  //Game begins
  game(initPos);
  
  return 0;
}

void displayGrid(char positions[10]){
  printf("\tJogo da Velha\n\n");
  printf("Jogador 1 [X]\tJogador 2[O]\n\n");
  
  printf("\t     |     |     \n");
  printf("\t  %c  |  %c  |  %c  \n", positions[7], positions[8], positions[9]);
  printf("\t_____|_____|_____\n");
  printf("\t     |     |     \n");
  printf("\t  %c  |  %c  |  %c  \n", positions[4], positions[5], positions[6]);
  printf("\t_____|_____|_____\n");
  printf("\t     |     |     \n");
  printf("\t  %c  |  %c  |  %c  \n", positions[1], positions[2], positions[3]);
  printf("\t     |     |     \n");
}

bool checkForWin(char arr[11]){
  bool gameOver;
  gameOver = false;
  
  // win conditions
  if(arr[1] == arr[2] && arr[1] == arr[3]){
    gameOver = true;
  } else if(arr[4] == arr[5] && arr[4] == arr[6]){
    gameOver = true;
  } else if(arr[7] == arr[8] && arr[7] == arr[9]){
    gameOver = true;
  } else if(arr[1] == arr[4] && arr[1] == arr[7]){
    gameOver = true;
  } else if(arr[2] == arr[5] && arr[2] == arr[8]){
    gameOver = true;
  } else if(arr[3] == arr[6] && arr[3] == arr[9]){
    gameOver = true;
  } else if(arr[1] == arr[5] && arr[1] == arr[9]){
    gameOver = true;
  } else if(arr[7] == arr[5] && arr[7] == arr[3]){
    gameOver = true;
  }
  
  return gameOver;
}

void game(char arr[11]){
  int p1, p2, count, p3;
  count = 0;
  
  while(checkForWin(arr) == false){
    printf("\nJogador 1, escolha uma posição: ");
    scanf("%i", &p1);
    while(p1 > 9 || p1 < 1 || arr[p1] == 'X' || arr[p1] == 'O'){
      printf("\nPosição inválida. Jogue novamente: ");
      scanf("%i", &p1);
    }
    arr[p1] = 'X';
    system("clear");
    printf("\n");
    displayGrid(arr);
    if(checkForWin(arr) == true){
      printf("\nJogador 1 GANHOU!\n");
      playAgain();
      break;
    }
    count++;
    if(count == 9 && checkForWin(arr) == false){
      printf("\nDeu VELHA!\n");
      playAgain();
      break;
    }
    if(checkForWin(arr) == false){
      printf("\nJogador 2, escolha uma posição: ");
      scanf("%i", &p2);
      while(p2 > 9 || p2 < 1 || arr[p2] == 'X' || arr[p2] == 'O'){
        printf("\nPosição inválida. Jogue novamente: ");
        scanf("%i", &p2);
      }
      arr[p2] = 'O';
      system("clear");
      printf("\n");
      displayGrid(arr);
      if(checkForWin(arr) == true){
        printf("\nJogador 2 GANHOU!\n");
        playAgain();
        break;
      }
      count++;
      if(count == 9 && checkForWin(arr) == false){
        printf("\nDeu VELHA!\n");
        playAgain();
        break;
      }
    }
  }
}

void playAgain(){
  int p3;
  char newGame[11] = "0123456789";
  
  printf("\nJogar novamente?\n");
  printf("\nSIM[1]\tNÃO[2]\n");
  scanf("%i", &p3);
  if(p3 > 2 || p3 < 1){
    printf("\nOpção inválida. Escolha novamente\n");
    printf("\nSIM[1]\tNÃO[2]\n");
    scanf("%i", &p3);
  } else if(p3 == 1){
    system("clear");
    printf("\n");
    displayGrid(newGame);
    game(newGame);
  }
}