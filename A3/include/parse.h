/*Include all the libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>

#define MAXSIZE 151 /*Maxsize for each line*/
/*Define the different rogue character sets*/
#define heightWall '|'
#define widthWall '-'
#define floorTiles '.'
#define doorway '+'
#define singleSpace ' '
#define bluePotion '!'
#define gold '*'
#define monster 'M'
#define stairs '%'
/*#define greyPotion '=';*/
#define balsaStaff '/'

/*Declare struct to hold all neeeded elements for a room*/
struct Room
{
    int height;
    int width;
    int eastDoor;
    int westDoor;
    int southDoor;
    int northDoor;
    char * itemsCoor;
};

typedef struct Room RoomOne; /*Create typedef for ease*/

/*Description:
 *Get the file read and parse it so newlines are after each element
 *Parameters:
 *fileString: the array that has the line that is read from the file
 *Return:
 *Returns the new string parsed with newlines
 */
char * parseInputString(char * fileString);

/*Description:
 *Get the new parsed string and get the dimensions from it
 *Store new dimensions into its own array
 *Parameters:
 *parsedString: new parsed string from parseInputString
 *Return:
 *Returns the new string that contains the dimensions only
 */
char * parseDimensions(char * parsedString);

/*Description:
 *Get the new parsed string and get the items from it
 *Store items into its own array
 *Parameters:
 *parsedString: new parsed string from parseInputString
 *Return:
 *Returns the new string that contains the items only
 */
char * getItems(char * parsedString, char * items);

/*Description:
 *Get the new parsed string and get the doors from it
 *Store new doors into its own array
 *Parameters:
 *parsedString: new parsed string from parseInputString
 *Return:
 *Returns the new string that contains the doors only
 */
char * storeDoors(char * parsedString);

/*Description:
 *Get the new parsed string and get the dimensions from it
 *Store new dimensions into its own array
 *Parameters:
 *RoomOne * roomPtr: To get the struct to point to the function
 *dimensions: get the array that stored the dimensions
 *doors: get the array that stored the doors
 *items: get the array that stored items
 *Return:
 *No return value
 */
void convertEverthing(RoomOne * roomPtr, char * dimensions, char * doors, char * items);

/*Description:
 *Get the height and width stored from dimensions array in convertEverything and print the walls
 *Parameters:
 *RoomOne * roomPtr: To get the struct to point to the function
 *rows: the height of the walls
 *cols: the width of the walls
 *Return:
 *No return value
 */
void drawWalls(RoomOne * roomPtr, int rows, int cols);

/*Description:
 *Get the items that I converted in the convertEverything and pass it to the struct to draw the doors
 *Parameters:
 *RoomOne * roomPtr: To get the struct to point to the function
 *rows: the height of the walls
 *cols: the width of the walls
 *north: top wall
 *east: right wall
 *south: bottom wall
 *west: left wall
 *Return:
 *No return value
 */
void drawDoors(RoomOne * roomPtr, int rows, int cols, int north, int east, int south, int west);

/*Description:
 *Gets the array from convertEverything that has the items and prints them to the map
 *Parameters:
 *RoomOne * roomPtr: To get the struct to point to the function
 *stuff: get the array that stored items
 *Return:
 *No return value
 */
void placeItems(RoomOne * roomPtr, char * stuff);

/*int i,j;
    int doorE;
    int doorW;
    int doorN;
    int doorS;*/

/*RoomOne * sendDoors;

    i = 0;
    j = 0;
    doorE = 0;
    doorW = 0;
    doorN = 0;
    doorS = 0;*/


 /*sendDoors = malloc(sizeof(char) * 4 + 1);

    for(i = 0; i < strlen(parsedString); i++)
    {
        if(parsedString[i] == 'd')
        {
            i++;
            
            for(j = 0; j < strlen(parsedString); j++)
            {
                switch(parsedString[j])
                {
                    case 'n':
                        if(parsedString[j + 1] != '\n')
                        {
                            doorN = atoi(&parsedString[j + 1]);
                        }
                        break;
                    case 's':
                        if(parsedString[j + 1] != '\n')
                        {
                            doorS = atoi(&parsedString[j + 1]);
                        }
                        break;
                    case 'e':
                        if(parsedString[j + 1] != '\n')
                        {
                            doorE = atoi(&parsedString[j + 1]);
                        }
                        break;
                    case 'w':
                        if(parsedString[j + 1] != '\n')
                        {
                            doorW = atoi(&parsedString[j + 1]);
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }

    firstPlaceDoors(sendDoors, doorN, doorE, doorS, doorW);
        printw("East: %d\n", doorE);
        printw("West: %d\n", doorW);
        printw("South: %d\n", doorS);
        printw("North: %d\n", doorN);*/
