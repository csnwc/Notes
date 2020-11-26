/*A program that read the maze from txt file and find clear
route and print it out*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char maze[20][20];

void run_maze(maze mz, int height, int width);

void print_maze(maze mz, int height, int width);

int explore(int x, int y, maze mz, int height, int width);

int is_exit(int x, int y, maze mz);

/*Find the entrance and mark the entrance*/
void find_entrance(maze mz, int height, int width);

/*Find all exit and mark all exit*/
void find_exit(maze mz, int height, int width);

int main(void)
{
  maze mz;
  int x, y, height, width;
  char c;
  FILE *maze_file;

  if((maze_file = fopen("maze.txt", "r")) == NULL){
    fprintf(stderr, "Cannot open file!\n");
    exit(1);
  }

  if (fscanf(maze_file, "%d %d", &height, &width) != 2){
    fprintf(stderr, "Error when scanning file!\n");
    exit(1);
  }

  for (y = 0; y < height; y ++){
    for (x = 0; x < width; x ++){
      c = getc(maze_file);
      if (c == '#' || c == ' '){
        mz[y][x] = c;
      }
      else{
        x --;
      }
    }
  }

  fclose(maze_file);
  run_maze(mz, height, width);

  return 0;
}

void run_maze(maze mz, int height, int width)
{
  int x, y;
  fprintf(stdout, "The maze:\n");
  print_maze(mz, height, width);
  find_entrance(mz, height, width);
  find_exit(mz, height, width);
  for (y = 0; y < height; y ++){
    for (x = 0; x < width; x ++){
      if (mz[y][x] == 'E'){
        mz[y][x] = ' ';
        explore(x, y, mz, height, width);
      }
    }
  }
  fprintf(stdout, "\nThe clear route:\n");
  print_maze(mz, height, width);
}

void print_maze(maze mz, int height, int width)
{
  int x, y;
  for (y = 0; y < height; y ++){
    for (x = 0; x < width; x ++){
      fprintf(stdout, "%c", mz[y][x]);
    }
    fprintf(stdout, "\n");
  }
}

int explore(int x, int y, maze mz, int height, int width)
{
  if (x >= width || y >= height || x < 0 || y < 0){
    return 0;
  }

  if (mz[y][x] == 'X'){
    return 1;
  }

  if (mz[y][x] != ' '){
    return 0;
  }

  mz[y][x] = '+';

  if(explore(x, y + 1, mz, height, width)){
    return 1;
  }

  if(explore(x + 1, y, mz, height, width)){
    return 1;
  }

  if(explore(x, y - 1, mz, height, width)){
    return 1;
  }

  if(explore(x - 1, y, mz, height, width)){
    return 1;
  }

  mz[y][x] = ' ';

  return 0;
}

void find_entrance(maze mz, int height, int width)
{
  int x, y;
  int x_distance, y_distance;
  for (x = 0; x < width; x ++){
    if(mz[0][x] == ' '){
      x_distance = x;
    }
  }

  for (y = 0; y < height; y ++){
    if(mz[y][0] == ' '){
      y_distance = y;
    }
  }

  if(y_distance > x_distance){
    mz[0][x_distance] = 'E';
  }
  else{
    mz[y_distance][0] = 'E';
  }
}

void find_exit(maze mz, int height, int width)
{
  int x, y;
  for (x = 0; x < width; x ++){
    if(mz[0][x] == ' '){
      mz[0][x] = 'X';
    }
  }

  for (x = 0; x < width; x ++){
    if(mz[height - 1][x] == ' '){
      mz[height - 1][x] = 'X';
    }
  }

  for (y = 0; y < height; y ++){
    if(mz[y][0] == ' '){
      mz[y][0] = 'X';
    }
  }

  for (y = 0; y < height; y ++){
    if(mz[y][width - 1] == ' '){
      mz[y][width - 1] = 'X';
    }
  }
}
