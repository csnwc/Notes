#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 10

int explore(int row, int col, char maze[MAXEDGE][MAXEDGE], int endr, int endc);
void printMaze(char maze[MAXEDGE][MAXEDGE]);

int main(void)
{
    FILE *fp;
    char maze[MAXEDGE][MAXEDGE];
    int sizer, sizec;
    int startr=0, startc=0, endr=0, endc=0;
    int i=0, j=0;
    char c;
    
    if((fp = fopen("maze.txt", "r")) == NULL)
    {
        printf("Cannot open the file.\n");
        return 1;
    }
    
    fscanf(fp, "%d %d",&sizer, &sizec);
    
    while(i<sizer)
    {
        if ((c=getc(fp)) != '\n')
        {
            maze[i][j]=c;
            j++;
        }
        if(j==sizec)
        {
            i++;
            j=0;
        }
    }
    
    for(i=0; i<sizer; i++)
    {
        for(j=0; j<sizec; j++)
        {
            if(i==0 || j==0)
            {
                if(maze[i][j] == ' ')
                {
                    startr =i;
                    startc =j;
                }
            }
            if(i==sizer-1 || j==sizec-1)
            {
                if(maze[i][j] == ' ')
                {
                    endr =i;
                    endc =j;
                }
            }
        }
    }

    if (explore(startr, startc, maze, endr, endc))
    {
        printf("Find the path!\n");
        printMaze(maze);
    }
    else
    {
        printf("No path found!\n");
    }
    
    fclose(fp);
    return 0;
}

int explore(int row, int col, char maze[MAXEDGE][MAXEDGE], int endr, int endc)
{
    maze[row][col] = '1';
    
    if (row == endr && col == endc)
        return 1;
    
    if (maze[row][col] == EOF)
        return 0;
    
    if (maze[row+1][col] == ' ')
    {
        if(explore(row+1, col, maze, endr, endc))
            return 1;
    }

    if (maze[row-1][col] == ' ')
    {
        if(explore(row-1, col, maze, endr, endc))
            return 1;
    }

    if (maze[row][col+1] == ' ')
    {
        if(explore(row, col+1, maze, endr, endc))
            return 1;
    }

    if (maze[row][col-1] == ' ')
    {
        if(explore(row, col-1, maze, endr, endc))
            return 1;
    }
    
    maze[row][col]=' ';

    return 0;
}

void printMaze(char maze[MAXEDGE][MAXEDGE])
{
    int i, j;
    for(i=0; i< MAXEDGE; i++)
    {
        for(j=0; j<MAXEDGE; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}
