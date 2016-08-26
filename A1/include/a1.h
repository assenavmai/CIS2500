/*including the libraries*/
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

/*make up, down, right, quit and left to move values */
#define UP 'i'
#define DOWN 'k'
#define LEFT 'j'
#define RIGHT 'l'
#define QUIT 'q'

void getInput(); /*function to get the users name*/
void moveCursor();/*function to move the cursor */
void createMaze();/*function to create the maze*/
int finishMaze(int yCoor, int xCoor);/*function to know when the user finish the maze*/