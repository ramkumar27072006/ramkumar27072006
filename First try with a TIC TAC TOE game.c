#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void playGame() {
    int row, col;
    char currentPlayer = 'X';
    
    while (1) {
        printBoard();
        printf("Player %c (%s), enter row and column (1-3): ", currentPlayer, currentPlayer == 'X' ? "Ramkumar" : "Ramkumar's opponent");
        scanf("%d %d", &row, &col);
        
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            printf("Oops! Invalid move. Try again and don't embarrass yourself!\n");
            continue;
        }
        
        board[row-1][col-1] = currentPlayer;
        
        if (checkWin()) {
            printBoard();
            printf("Hooray! Player %c (%s) wins! Bragging rights unlocked!\n", currentPlayer, currentPlayer == 'X' ? "Ramkumar" : "Ramkumar's opponent");
            break;
        }
        
        if (isDraw()) {
            printBoard();
            printf("It's a draw! No winners, just mutual disappointment!\n");
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    printf("Welcome to Ramkumar's Tic-Tac-Toe Battle! May the best player win (or at least try).\n");
    initializeBoard();
    playGame();
    printf("Game over! Now go brag or make excuses!\n");
    return 0;
}
