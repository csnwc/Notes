/*/////////////////////////////////////////
///        Created by Haoyu Wu          ///
///          29 October 2018            ///
///       Student Number: 1866332       ///
///         All Rights Reserved         ///
/////////////////////////////////////////*/

/*////////////////////////////////////////////////////
///     This version Can handle multiple exits     ///
///           Or simply no exits at all            ///
///   But plz make the entrance on the first col   ///
////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printMaze(char *, int, int);
void findPath(int* maze, int row, int col, int curRow, int curCol, int startRow, int* flag, int p);
void printLocation(int row, int col, int STEP_BY_STEP_PRINT);
void printStep(int *maze, int row, int col);
void show(int* maze, int row, int col, int curRow, int curCol, int STEP_BY_STEP_PRINT);

int main(int argc, char const *argv[])
{
    int row, col, i, j, curRow, curCol = 0, startRow = 0, flag = 0, ani, *numberMaze;
    char const * filename;
    char l1[255], l2[255], buff[255], *maze;
    FILE *fp;
    if(argc != 3){
        printf("Not enought or arguments input!\n");
        exit(1);
    }
    filename = argv[1];
    ani = atoi(argv[2]);
    /* Here we start reading the file
    * we open the file with a pointer fp pointing to the head of the file
    * the first line represents the row and columns
    * But it is in the format of string, so we use atoi() to transfer it into integers
    * fscanf() split parts by spaces, so we can seperatly read l1 and l2*/
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Open file failed! Program exiting!\n");
        exit(1);
    }
    fscanf(fp, "%s%s", l1, l2);
    row = atoi(l1);
    col = atoi(l2);
    maze = (char*) malloc(row*col*sizeof(char));
    if(maze == NULL){
        exit(1);
    }
    numberMaze = (int*) malloc(row*col*sizeof(int));
    /* Move to the next line 
    * fgets() reads a whole line
    * we read the whole maze here*/
    fgets(buff, 255, (FILE*) fp);
    for(i = 0; i < row; i++){
        j = 0;
        fgets(buff, 255, (FILE*) fp);
        while(buff[j] != '\n'){
            *(maze + i*col + j) = buff[j];
            j++;
        }
    }
    fclose(fp);
    printMaze(maze, row, col);

    /* Here we initialize another 2D array using 1s and 0s to represent the walls (as well as the path we have been to) and available choices */
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(*(maze + i*col + j) == '#'){
                *(numberMaze + i*col +j) = 1; 
            }else{
                *(numberMaze + i*col +j) = 0;
            }
        }
    }

    /* Find the start point */
    for(i = 0; i < row; i++){
        if(*(maze + i*row) == ' '){
            curRow = i;
            curCol = 0;
            startRow = i;
            break;
        }
    }
    findPath(numberMaze, row, col, startRow, curCol, startRow, &flag, ani);
    free(maze);
    free(numberMaze);
    if(!flag){
        printf("No path found!\n");
        exit(1);
    }else{
        printf("End of searching, no more path found!\n");
        exit(0);
    }

    return 0;
}

/* 
*   @Parameters:
*       char *maze: pointer to the maze array
*       int row: maximum row number of the maze
*       int col: maximum column number of the maze
*   
*   @Returns:
*       void
*   
*   @Function:
*       To print out the maze
*/
void printMaze(char *maze, int row, int col){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%c ", *(maze +i*row +j));
        }
        printf("\n");
    }
    printf("\n");
}

/* 
*   @Parameters:
*       int row: current row number of the maze
*       int col: current column number of the maze
*   
*   @Returns:
*       void
*   
*   @Function:
*       To print out the current step
*/
void printLocation(int row, int col, int STEP_BY_STEP_PRINT){
    if(STEP_BY_STEP_PRINT){
        printf("Currently at position (%d, %d)\n", row, col);
    }else{
        printf("(%d, %d) -> ", row, col);
    }
}

/* 
*   @Parameters:
*       int row: current row number of the maze
*       int col: current column number of the maze
*   
*   @Returns:
*       void
*   
*   @Function:
*       To print out the current step
*/
void printStep(int *maze, int row, int col){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(*(maze +i*row +j) == 1){
                printf("# ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* 
*   @Parameters:
*       int *maze: pointer to the maze array
*       int row: maximum row number of the maze
*       int col: maximum column number of the maze
*       int curRow: current working row
*       int curCol: current working column
*       int STEP_BY_STEP_PRINT: if we display the maze step by step
*   
*   @Returns:
*       void
*   
*   @Function:
*       To print out the maze
*/
void show(int* maze, int row, int col, int curRow, int curCol, int STEP_BY_STEP_PRINT){
    printLocation(curRow, curCol, STEP_BY_STEP_PRINT);
    if(STEP_BY_STEP_PRINT){
        printStep(maze, row, col);
        sleep(1);
    }
}

/* 
*   @Parameters:
*       char *maze: pointer to the maze array
*       int row: maximum row number of the maze
*       int col: maximum column number of the maze
*       int curRow: current row
*       int curCol: current COl
*       int targetRow: exit row
*       int targetCol: exit column
*       int *flag: Flag to represent whether there is a solution or not
*       int p: whether we want print every maze after we move or not
*
*   @Returns:
*       void
*   
*   @Function:
*       Find all solution to the maze
*       By set the value of the neighbors of current location
*           n1
*       n2   c  n3
*           n4
*       If the value is 1, it means whether it is a wall or a point that we have been to
*       Then we cannot choose that direction
*       Accordingly, 0 means it is available
*       We use all the possibilities go find the path, simply if we can go up, we go up
*       When we reach a dead end, we return to the last point where we have multiple choices
*       Or if we reach the target, we do the same, but set the flag to 1, means there is at least one way to the exit
*       If no path found, the flag remains 0
*       In this version we use backtrace technique, by setting the current location back to 0 after we try all the options and return at the exit
*       If we just want to finish this program, we can exit(0) at the exit location
*/
void findPath(int* maze, int row, int col, int curRow, int curCol, int startRow, int* flag, int p){
    int n1, n2, n3, n4;
    
    /* Set current location to 1, means we used this location already */
    *(maze + curRow*col + curCol) = 1;
    if(curRow == row-1 || curCol == col-1 || curRow == 0 || (curCol == 0 && curRow != startRow)){
        show(maze, row, col, curRow, curCol, p);
        *(maze + curRow*col + curCol) = 0;
        printf(" Target exit\n\n");
        *flag = 1;
        return;
    }
    n1 = (curRow > 0)? *(maze + (curRow-1)*col + curCol):1;
    n2 = (curCol > 0)? *(maze + curRow*col + curCol-1):1;
    n3 = (curRow < row-1)? *(maze + (curRow+1)*col + curCol):1;
    n4 = (curCol < col-1)? *(maze + curRow*col + curCol+1):1;

    if(n1 && n2 && n3 && n4){
        show(maze, row, col, curRow, curCol, p);
        printf("Dead end! Trace back now! -> ");
        *(maze + curRow*col + curCol) = 0;
        return;
    }
    if(!n1){
        show(maze, row, col, curRow, curCol, p);
        findPath(maze, row, col, curRow-1, curCol, startRow, flag, p);
    }
    if(!n2){
        show(maze, row, col, curRow, curCol, p);
        findPath(maze, row, col, curRow, curCol-1, startRow, flag, p);
    }
    if(!n3){
        show(maze, row, col, curRow, curCol, p);
        findPath(maze, row, col, curRow+1, curCol, startRow, flag, p);
    }
    if(!n4){
        show(maze, row, col, curRow, curCol, p);
        findPath(maze, row, col, curRow, curCol+1, startRow, flag, p);
    }
    *(maze + curRow*col + curCol) = 0;
}
