/*  This program reads in a maze file #defined by MAZE_FILE.
The maze file has a header of two integer values, representing
number of columns and rows, respectively. These values must be
#defined as YS and XS, respectively. The maze consists of a 2d
array of '#' as walls and ' ' (spaces) as paths. The program
outputs a path (if it exists) from the entrance (closest open
space to the top left corner on boundary wall) to the exit
somewhere else on the boundary wall. Valid path is marked with
'.'; dead end paths are marked with '-'. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAZE_FILE "maze.txt"
#define YS 10
#define XS 10
#define MAX(x, y) ((x > y) ? (x) : (y)) 
typedef enum bool {false, true} bool;

void init_maze(char maze[YS + 1][XS + 1]);
void print_maze(char maze[YS + 1][XS + 1]);
bool find_start(int *x, int *y, char maze[YS + 1][XS + 1]);
bool find_exit(int x, int y, char maze[YS + 1][XS + 1], int *cnt);

int main(void)
{
    char maze[YS + 1][XS + 1];
    int x = 0, y = 0, steps = 0, *p_x, *p_y, *p_steps;
    p_x = &x;
    p_y = &y;
    p_steps = &steps;

    init_maze(maze);
    if (find_start(p_x, p_y, maze) == false) {
        print_maze(maze);
        fprintf(stderr, "\nCould not determine starting point of maze.\n");
        exit(EXIT_FAILURE); 
    }
    printf("Starting at \"S\" to explore the maze!\n\n");
    maze[y][x] = 'S';

    print_maze(maze);
    if (find_exit(x, y, maze, p_steps) == true) {
        printf("\nFound exit at \"E\"! (%d steps taken)\n\n", steps);
    } else {
        printf("\nCould not find exit. (%d steps taken)\n\n", steps);
    }
    print_maze(maze);
    return EXIT_SUCCESS;
}

void init_maze(char maze[YS + 1][XS + 1])
{
    FILE *fp;
    int width, height, i, j;
    if ((fp = fopen(MAZE_FILE, "r")) == NULL) {
        fprintf(stderr, "Cannot open file.\n");
        exit(EXIT_FAILURE); 
    }
    fscanf(fp, "%d %d\n", &width, &height);
    for (i = 0; i < height + 1; i++) {
        for (j = 0; j < width + 1; j++) {
            fscanf(fp, "%c", &maze[i][j]);
        }
    }
    fclose(fp);
}

void print_maze(char maze[YS + 1][XS + 1])
{
    int i, j;
    for (i = 0; i < YS; i++) {
        for (j = 0; j < XS; j++) {
            printf("%c", maze[i][j]);
        }
    printf("\n");
    }
}

bool find_start(int *x, int *y, char maze[YS + 1][XS + 1])
{
    int i;
    for (i = 0; i < MAX(YS, XS); i++) {
        if (i < XS) {
            if (maze[0][i] == ' ') {
                *x = i;
                return true;
            }
        }
        if (i < YS) {
            if (maze[i][0] == ' ') {
                *y = i;
                return true;
            }
        }
    }
    return false;
}

bool find_exit(int x, int y, char maze[YS + 1][XS + 1], int *steps)
{
    static int count = 0;
    *steps = count++;
    if (x < 0 || y < 0 || x > XS || y > YS) {
        return false;
    }
    if (maze[y][x] == '#' || maze[y][x] == '.') {
        return false;
    }
    if ((x == 0 || y == 0 || x == XS - 1 || y == YS - 1) && maze[y][x] != 'S') {
        maze[y][x] = 'E'; /* mark exit */
        return true;
    }
    maze[y][x] = '.'; /* leave a breadcrumb '.' to mark where you were */
    if (find_exit(x, y + 1, maze, steps) == true){
        return true;
    }
    if (find_exit(x + 1, y, maze, steps) == true) {
        return true;
    }
    if (find_exit(x, y - 1, maze, steps) == true) {
        return true;
    } 
    if (find_exit(x - 1, y, maze, steps) == true) {
        return true;
    }
    maze[y][x] = '-'; /* if you reached a dead end, cross out '-' that cell */
    return false;
}
