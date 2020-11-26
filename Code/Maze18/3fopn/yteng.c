#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS 6
#define SIZE 10
#define ARR_LEN 200

int read_maze(char * arr, FILE * fp, char (* maze)[SIZE]);
int escape_route(int x, int y, char (* maze)[SIZE], int dir, int prev_x, int prev_y);

enum direction {down, right, up, left};
typedef enum direction dir;

int main(void)
{
  FILE *fp;
  int row, col;
  char arr[ARR_LEN] = {0};
  int start_y = 0, prev_y = 0;
  int start_x = 1, prev_x = 1, dir = 1;
  char maze[SIZE][SIZE];

  fp = fopen("maze.txt", "r");

  read_maze(arr, fp, maze);
  escape_route(start_x, start_y, maze, dir, prev_x, prev_y);
  /* Print maze route */
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      printf("%c", maze[row][col]);
    }
    printf("\n");
  }
  fclose(fp);

  return 0;
}

int read_maze(char * arr, FILE * fp, char (* maze)[SIZE])
{
  int i, row = 0, col = 0;
  /* Read the first line containing size info */
  if (fread(arr, sizeof(char), CHARS, fp) == 0) {
    return 1;
  }
  /* Read the whole maze */
  if (fread(arr, sizeof(char), (SIZE * SIZE) + SIZE, fp) == 0) {
    return 1;
  }
  /* Store maze in a 2D array */
  for (i = 0; i < (SIZE * SIZE) + SIZE; i++) {
    if (arr[i] == '\n') {
      row++;
      col = 0;
    }
    else {
      maze[row][col] = arr[i];
      col++;
    }
  }
  return 0;
}

int escape_route(int x, int y, char (* maze)[SIZE], int dir, int prev_x, int prev_y)
{
  int start_x = 1, start_y = 0;
  int end_x = SIZE-2, end_y = SIZE-1;
  /* If end position */
  if (x == end_x && y == end_y) {
    maze[x][y] = '.';
    return 0;
  }
  /* If start position */
  if (x == start_x && y == start_y) {
    maze[x][y] = '.';
  }
  /* If position is outside the boundaries */
  if ((x < 0) || (y < 0) || (x >= SIZE) || (y >= SIZE)) {
    x = prev_x;
    y = prev_y;
    if (dir != left) {
      dir++;
    }
    else {
      dir = down;
    }
  }
  /* If position is a wall or already visited */
  else if (maze[x][y] == '#' || maze[x][y] == '.') {
    x = prev_x;
    y = prev_y;
    if (dir != left) {
      dir++;
    }
    else {
      dir = down;
    }
  }
  /* If position is a valid space */
  else {
    maze[x][y] = '.';
    prev_x = x;
    prev_y = y;
    maze[prev_x][prev_y] = '.';
  }
  /* Change directions on the next move */
  if (dir == down) {
    escape_route(x+1, y, maze, dir, prev_x, prev_y);
  }
  if (dir == right) {
    escape_route(x, y+1, maze, dir, prev_x, prev_y);
  }
  if (dir == up) {
    escape_route(x-1, y, maze, dir, prev_x, prev_y);
  }
  if (dir == left) {
    escape_route(x, y-1, maze, dir, prev_x, prev_y);
  }

  return 1;
}
