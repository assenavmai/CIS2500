/*************************main.c****************************
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

int main (int argc, char * argv[])
{
    /*Declaration of variables*/
    FILE * inputFile;
    char * storeLine;
    char * parse;
    char * storeParsed;
    char * storeItems;
    char * arrDoors;
    char * arrDimensions;
    char * arrItems;
    char * getReturn;
    RoomOne * roomPtr;
    int i;
    
    i = 0;

    roomPtr = malloc(sizeof(struct Room) * 6);/*Create an array of structs*/

    if (argc != 2)/*If they do not put a file name in the terminal, exit*/
    { 
      printf("Usage: Enter an input file name");
      exit(1);
    }
    
    initscr();/*Start ncurses*/
    
    storeLine = malloc(sizeof(char) * MAXSIZE + 1);

    inputFile = fopen(argv[1], "r"); /*Open the file the user input*/

    if(inputFile == NULL)/*If the file is empty, exit*/
    {
        printf("Error opening file\n");
        exit(0);
    }
    else
    {
        getReturn = fgets(storeLine, 151, inputFile); /*make a char equal fgets*/

        while (getReturn != NULL)
        {
            storeItems = malloc(sizeof(char) * strlen(storeLine) + 1);/*allocate memory*/
            storeParsed = malloc(sizeof(char) * strlen(storeLine) + 1);

            parse = parseInputString(storeLine); /*send input file to function to add new lines*/
            strcpy(storeParsed, parse);/*copy new pointer to a new one to keep original*/

            arrDoors = storeDoors(parse);/*send parsed file to get the doors in its own array*/
            arrItems = getItems(storeParsed, storeItems);/*send copy of parsed file and allocated memory to get items in its own array*/
            arrDimensions = parseDimensions(parse);/*send parsed file to get dimensions into its own file*/
            /*mvprintw(0,0, "%s %s %s", arrDoors, arrItems, arrDimensions);*/

            convertEverthing(roomPtr,arrDimensions, arrDoors, arrItems);/*Convert returned string to ints and send to struct*/

            getReturn = fgets(storeLine, 151, inputFile); /*get the next line*/
        }

        fclose(inputFile); /*close the file*/
    }

    refresh();
    getch();
    endwin();

    return 0;

    for(i = 0; i < 151 * 6; i++)/*Free for everything I malloced*/
    {
        free(roomPtr);
        free(storeLine);
        free(storeItems);
        free(storeParsed);
    }
    
}