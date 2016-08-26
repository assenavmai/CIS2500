#include "hero.h"
#include "parse.h"


/*This function draws the walls of a room
 *It points the values to the struct and them it had 3 for loops to create the north,south,east and west walls
 *for each wall, add the corresponding character to make the wall*/
void drawWalls(RoomOne * roomPtr, int rows, int cols)
{
    int i,j;

    i = 0;
    j = 0;

    roomPtr->height = rows;
    roomPtr->width = cols;

    /*For loops:
     *First 3 is to draw the walls of the room
     *The last for loop is to draw the floor tiles*/
    for(i = 0; i < cols + 1; i++) 
    {
        mvaddch(8, i + 15, widthWall); /*north wall*/
    }
    for(i = 0; i < rows; i++)
    {
        mvaddch(i + 9, 15, heightWall); /*west wall*/
        mvaddch(i + 9, cols + 15, heightWall);/*east wall*/
    }
    for(i = 0; i < cols + 1; i++)
    {
        mvaddch(rows + 8, i + 15, widthWall);/*south wall*/
    }

    for(i = 0; i < rows - 1; i++)
    {
        for(j = 0; j < cols - 1; j++)
        {
            mvaddch(i + 9, j + 16, floorTiles);
        }
    }
}

/*This function draws the doors for the room, using the information from the convertEverything function
 *It stores the info into a struct and then if the value is 0, do not print a door
 *else print the door to the corresponding spot
 *This is how it works for all the doors*/
void drawDoors(RoomOne * roomPtr, int rows, int cols, int north, int east, int south, int west)
{
    roomPtr->height = rows;
    roomPtr->width = cols;
    roomPtr->northDoor = north;
    roomPtr->eastDoor = east;
    roomPtr->southDoor = south;
    roomPtr->westDoor = west;

    /*If any door is not included in the text file, do not print a door
    *all the if statements are for each letter
    *if there is the door existing, print it*/
    if(north == 0)
    {
        mvaddch(8, north + 14, singleSpace);
    }
    else
    {
        mvaddch(8, north + 14, doorway);
    }

    if(south == 0)
    {
        mvaddch(rows + 8 , south + 14, singleSpace);
    }
    else
    {
        mvaddch(rows + 8 , south + 14, doorway);
    }

   if(east == 0)
    {
        mvaddch(east + 8, cols + 15, singleSpace);
    }
    else
    {
        mvaddch(east + 8, cols + 15, doorway);
    }
    if(west == 0)
    {
        mvaddch(west + 8, 15, singleSpace);
    }
    else
    {
        mvaddch(west + 8, 15, doorway);
    }
}

/*This function places the items and gets their position
 *Store the corresponding items to the struct
 *Then strtok to remove the comma from each line
 *Then strcat the array with no commas into the new array
 *Then there is a for lop to go through the new array
 *Find the character at position i
 *Get the y and x and change them to integers then place the corresponding character on the map
 */
void placeItems(RoomOne * roomPtr, char * stuff)
{
    int i;
    int yCoor, xCoor;
    char * removeComma;
    char * noCommaItems;
    char * temp;

    i = 0;
    yCoor = 0;
    xCoor = 0;

    roomPtr->itemsCoor = malloc(sizeof(char)*(strlen(stuff)+1));/*allocate memory for the room items pointer*/
    strcpy(roomPtr->itemsCoor, stuff);

    removeComma = malloc(sizeof(char) * strlen(stuff) + 1);/*allocate memory for strtok*/
    noCommaItems = malloc(sizeof(char) * strlen(stuff) + 1);

    removeComma = strtok(stuff, ","); 

    while (removeComma != NULL)
    {
        strcat(noCommaItems, removeComma);
        strcat(noCommaItems, " ");
        removeComma = strtok(NULL, ",");
    }
    
    for(i = 0; i < strlen(noCommaItems); i++)
    {
        switch(noCommaItems[i])
        {
            case 'p': /*potion*/
                yCoor = atoi(&noCommaItems[i + 1]);
                temp = strstr(noCommaItems, " ");
                xCoor = atoi(temp);
                mvaddch(yCoor + 8, xCoor + 15, bluePotion);
                break;
            case 'g': /*gold*/
                yCoor = atoi(&noCommaItems[i + 1]);
                temp = strstr(noCommaItems, " ");
                xCoor = atoi(temp);
                mvaddch(yCoor + 8, xCoor + 15, gold);
                break;
            case 'm': /*monsters*/
                yCoor = atoi(&noCommaItems[i + 1]);
                temp = strstr(noCommaItems, " ");
                xCoor = atoi(temp);
                mvaddch(yCoor + 8, xCoor + 15, monster);
                break;
            case 'h': /*hero*/
                yCoor = atoi(&noCommaItems[i + 1]);
                temp = strstr(noCommaItems, " ");
                xCoor = atoi(temp);
               /* mvaddch(yCoor + 8, xCoor + 15, hero);*/
                moveHero(yCoor + 8, xCoor + 15);
                break;
            case 's': /*stairs*/
                yCoor = atoi(&noCommaItems[i + 1]);
                temp = strstr(noCommaItems, " ");
                xCoor = atoi(temp);
                mvaddch(yCoor + 8, xCoor + 15, stairs);
                break;
            case 'w': /*weapon*/
                yCoor = atoi(&noCommaItems[i + 1]);
                temp = strstr(noCommaItems, " ");
                xCoor = atoi(temp);
                mvaddch(yCoor + 8, xCoor + 15, balsaStaff);
                break;
            default:
                break;

        }
    }


} 
