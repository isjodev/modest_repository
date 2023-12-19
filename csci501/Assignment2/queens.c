// The n queens puzzle.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Store the puzzle size and the number of valid solutions.
typedef struct {
  int size;
  int solutions;
} n_queens_t;

// Show the queens positions on the board in compressed form,
// each number represent the occupied column position in the corresponding row.
void show_short_board(n_queens_t *n_queens, int *positions) {
  for (int i = 0; i < n_queens->size; ++i) {
    printf("%d ", positions[i]);
  }
  printf("\n");
}

// Show the full NxN board
void print_board(n_queens_t *n_queens, int *positions) {
  for (int row = 0; row < n_queens->size; ++row) {
    for (int column = 0; column < n_queens->size; ++column) {
      if (positions[row] == column) {
        printf("Q ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

// Check if a given position is under attack from any of
// the previously placed queens (check column and diagonal positions)
bool check_place(int *positions, int ocuppied_rows, int column) {
  for (int i = 0; i < ocuppied_rows; ++i) {
    if (positions[i] == column || positions[i] - i == column - ocuppied_rows ||
        positions[i] + i == column + ocuppied_rows) {
      return false;
    }
  }
  return true;
}

// Try to place a queen on target_row by checking all N possible cases.
// If a valid place is found the function calls itself trying to place a queen
// on the next row until all N queens are placed on the NxN board.
void place_queen(n_queens_t *n_queens, int *positions, int target_row) {
  // Base (stop) case - all N rows are occupied
  if (target_row == n_queens->size) {
    // show_short_board(n_queens, positions);
    print_board(n_queens, positions);
    n_queens->solutions++;
  } else {
    // For all N columns positions try to place a queen
    for (int column = 0; column < n_queens->size; ++column) {
      // Reject all invalid positions
      if (check_place(positions, target_row, column)) {
        positions[target_row] = column;
        place_queen(n_queens, positions, target_row + 1);
      }
    }
  }
}

// Solve the n queens puzzle and print the number of solutions
void solve(n_queens_t *n_queens) {
  int *positions = malloc(n_queens->size * sizeof(int));
  memset(positions, ~0, n_queens->size * sizeof(int));
  place_queen(n_queens, positions, 0);
  printf("Found %d solutions\n", n_queens->solutions);
  free(positions);
}

int main(void) {
  n_queens_t n_queens = {.size = 8};
  solve(&n_queens);
  return 0;
}
