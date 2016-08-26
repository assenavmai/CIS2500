/*Include libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>

/*define constants used for the hero and gameplay*/
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define QUIT 'q'
#define hero '@'

/*Description:
 *Moves the player around the map
 *Blocks them from moving into monsters and walls
 *Parameters:
 *yPos: y position of the hero from file
 *xPos: x position of the hero from file
 *Return:
 *No return value
 */
void moveHero(int yPos, int xPos);

/*Description:
 *Prints when the player picks up an item
 *Parameters:
 *yPos: y position of the hero from file
 *xPos: x position of the hero from file
 *Return:
 *No return value
 */
void printFound(int yPos, int xPos);

/*Description:
 *Clears the coordinates where printFound prints the item
 *Parameters:
 *yPos: y position of the hero from file
 *xPos: x position of the hero from file
 *Return:
 *No return value
 */
void clearFound(int yPos, int xPos);

/*Description:
 *Clears screen when they go on the stairs
 *Parameters:
 *yPos: y position of the hero from file
 *xPos: x position of the hero from file
 *Return:
 *Checkwin: if they are at the stairs then return 1 for true, else false (0);
 */
int finishLevel(int yPos, int xPos);
