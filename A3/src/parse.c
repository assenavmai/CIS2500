/*************************parse.c****************************
Student Name: Vanessa White                       Student Number:  0832498
Date: January 24th, 2014                          Course Name: CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/
#include "parse.h"

/*This function gets the input file string
 *It will parse it so that instead of being separated by spaces, it will have new lines
 * Memory is allocated for the new char * variable so strtok can be successful
 *while the file is not null, keep storing the file into the new char pointer until it is null
 *the new parsed string is returned so that it can be used throughout
 */
char * parseInputString(char * fileString)
{
    char * storeParsedInput;

    fileString = strtok(fileString, " ");

    storeParsedInput = malloc(sizeof(char) * strlen(fileString) + 1);

   while (fileString != NULL)
    {
        strcat(storeParsedInput, fileString);
        strcat(storeParsedInput, "\n");

        fileString = strtok(NULL, " ");
    }

    return storeParsedInput;
}

/*This function takes the parsed input string and gets the dimensions in its own pointer
 *Strtok is used to remove the X between the rows and cols
 *While that pointer variable is not null, put the two numbers into its own storeDimens pointer
 * remove the extra newline character and replace with a null terminator
 *return the new array and free allocated memory
 */
char * parseDimensions(char * parsedString)
{
    
    char * parseDimens;
    char * removeX;
    char * storeDimens;

    removeX = malloc(sizeof(char) * strlen(parsedString) + 1);
    storeDimens = malloc(sizeof(char) * strlen(parsedString) + 1);

    removeX = strtok(parsedString, "X");

    while (removeX != NULL)
    {
        strcat(storeDimens, removeX);
        strcat(storeDimens, " ");

        removeX = strtok(NULL, "X");
    }

    storeDimens[strlen(storeDimens) - 1] = '\0';

    return storeDimens;

    free(parseDimens);
    free(removeX);
    free(storeDimens);
}

/*This function stores the doors into its own pointer array
 *Allocate memory for the new array and then strtok at the new line
 *While the parsed string is not null and if it is not null, check position one of the array
 *if it is a d, move that whole line into its own array
 *remove the extra new line character
 *return the new array and free the allocated memory*/
char * storeDoors(char * parsedString)
{
    char * doors;
    
    doors = malloc(sizeof(char) * strlen(parsedString) + 1);

    parsedString = strtok(parsedString, "\n");

    while (parsedString != NULL)
    {
        parsedString = strtok(NULL, "\n");

        if(parsedString != NULL)
        {
            switch(parsedString[0])
            {
                case 'd':
                    strcat(doors, parsedString);
                    strcat(doors, "\n");
                    break;
                default:
                    break;
            }
        } 
    }

    doors[strlen(doors) - 1] = '\0';

   /* printw("%s", doors);*/

    return doors;

    free(doors);
}

/*This function stores the doors into its own pointer array
 *Allocate memory for the new array and then strtok at the new line
 *While the parsed string is not null and if it is not null, check position one of the array
 *if it is a s,g,m,h,w or p, move that whole line into its own array
 *remove the extra new line character
 *return the new array and free the allocated memory*/
char * getItems(char * parsedString, char * items)
{
    parsedString = strtok(parsedString, "\n");

    while (parsedString != NULL)
    {
        parsedString = strtok(NULL, "\n");

        if(parsedString != NULL)
        {
            switch(parsedString[0])
            {
                case 's':
                    strcat(items, parsedString);
                    strcat(items, "\n");
                    break;
                case 'g':
                    strcat(items, parsedString);
                    strcat(items, "\n");
                    break;
                case 'm':
                    strcat(items, parsedString);
                    strcat(items, "\n");
                    break;
                case 'h':
                    strcat(items, parsedString);
                    strcat(items, "\n");
                    break;
                case 'p':
                    strcat(items, parsedString);
                    strcat(items, "\n");
                    break;
                case 'w':
                    strcat(items, parsedString);
                    strcat(items, "\n");
                default:
                    break;
            }

        } 
    }

    items[strlen(items) - 1] = '\0';

    /*printw("%s", items);*/

    return items;
}

/*This function takes everything we parsed and converts them to ints (dimensions and doors)
 *for dimensions: strtok the space and get the first and second number
 *use str str to get the colums and store it in its own array and atoi it
 *use strtok to get the height, store it into its own array and atoi it
 *Iterate through the door array and if there is a digit at the last spot, then convert it to an int
 *Store it in its correspoding direction integer
 *Send needed values to the drawWalls, drawDoors and placeItems functions
 *these store them into structs*/
void convertEverthing(RoomOne * roomPtr, char * dimensions, char * doors, char * items)
{
    char * strWid;
    char * height;
    int roomH;
    int roomW;
    int doorW;
    int doorN;
    int doorS;
    int doorE;
    int j;
    /*RoomOne * makeRoom;*/

    roomH = 0;
    roomW = 0;
    doorW = 0;
    doorN = 0;
    doorS = 0;
    doorE = 0;
    j = 0;

    strWid = malloc(sizeof(char) * strlen(dimensions) + 5);
    height = malloc(sizeof(char) * strlen(dimensions) + 5);
   /* makeRoom = malloc(sizeof(char) * strlen(items) * 10 + 1);*/

    strWid = strstr(dimensions, " ");
    roomW = atoi(strWid);

    dimensions = strtok(dimensions, " "); 
    strcpy(height, dimensions);

    roomH = atoi(height);

   /*printw("H %d W %d\n", roomH, roomW);*/


    for(j = 0; j < strlen(doors); j++)
    {
        switch(doors[j])
        {
            case 'n':
                if(isdigit(doors[j + 1]))
                {
                    doorN = atoi(&doors[j + 1]);
                }
                break;
            case 's':
                if(isdigit(doors[j + 1]))
                {
                    doorS = atoi(&doors[j + 1]);
                }
                break;
            case 'e':
                if(isdigit(doors[j + 1]))
                {
                    doorE = atoi(&doors[j + 1]);
                }
                break;
            case 'w':
                if(isdigit(doors[j + 1]))
                {
                    doorW = atoi(&doors[j + 1]);
                }
                break;
            default:
                break;
        }
    }

        /*printw("East: %d\n", doorE);
        printw("West: %d\n", doorW);
        printw("South: %d\n", doorS);
        printw("North: %d\n", doorN);*/

    /*firstRoom(frstRoom, roomH, roomW, doorN, doorE, doorS, doorW, items);*/
    drawWalls(roomPtr, roomH, roomW);
    drawDoors(roomPtr, roomH, roomW, doorN, doorE, doorS, doorW);
    placeItems(roomPtr, items);

    free(height);
}
