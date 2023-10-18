#include <stdio.h>
#define BOARD_SIZE 8

/* Logic of 8 Queen Problem:
You place a queen in one row,
Then, using Safe, we check if column, upper left diagonal and lower left diagonal are safe,
Since this is iterative, this ensures that right diagonals are also clear,
We recursively proceed through all rows, reaching base case where all queens are successfully placed.
 */
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    solution_count++;
    int temp=1;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col]){
                printf(" %d ",temp); // Queen placed
                temp++;}
            else
                printf(((row + col) % 2 == 0 ? "[] " : "   ")); // Unoccupied black box
        }
        printf("\n");
    }
    printf("\n\n");
}

// Checking if it's safe to place a queen at a given position
int Safe(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    for (int prev_col = 0; prev_col < col; prev_col++) {
        if (board[row][prev_col])
            return 0; // Queen in the same row
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0; // Queen in the upper-left diagonal
    }
    for (int i = row, j = col; i < BOARD_SIZE && j >= 0; i++, j--) {
        if (board[i][j])
            return 0; // Queen in the lower-left diagonal
    }
    return 1; // Safe
}

// Recursive function to solve the Eight Queens problem
int solveEightQueens(int board[BOARD_SIZE][BOARD_SIZE], int col) {
    if (col >= BOARD_SIZE) {
        // All queens have been placed, print the solution
        print_board(board);
        return 1; // success
    }
    int found_solution = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (Safe(board, row, col)) {
            board[row][col] = 1; // Place queen
            found_solution = solveEightQueens(board, col + 1) || found_solution;
            board[row][col] = 0; // Remove queen
        }
    }
    return found_solution;
}

int main() {
    int chessboard[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize the chessboard with all empty positions
    if (solveEightQueens(chessboard, 0) == 0) {
        printf("No solution exists");
    }
    return 0;
}
