/*************************hero.c****************************
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
#include "hero.h"
#include "parse.h"

/*This function controls the movement of the hero
 *It takes the y and x position of the hero from the placeItems function
 *Changes the cursor to an @ sign
 *If the user moves, make sure to block the walls, monsters
 *Make the trailing character to a floorTile
 *If the user presses q, then the program end*/
void moveHero(int yPos, int xPos)
{
    int keyPressed;/*, rows, cols*/ /*Declaration of varibles */

    /*Set the y position and x position to the beginning of the maze */
    keyPressed = 0;

    while(keyPressed != QUIT)
    {
        curs_set(1); /*make the cursor invisible */
        
        keyPressed = mvaddch(yPos, xPos, hero); /*add the cursor character and mvgetch is getting the character as it moves */
        keyPressed = mvgetch(yPos,xPos); 
        
        /*getmaxyx(stdscr, rows, cols);*/  /*get the size of the terminal */   
      
        /*Switch statement to determine what key they are pressing */
        /*add the space so that the @ sign does not repeat as it moves */
        /*If while moving there is no walls, continue moving*/
        /*if while moving there is a wall(any type, especially when on doors moving up or down, side to side) 
         *or monster do not move there go back one */
       /*clearFound clears the found items message
        *printFound prints when an item is found*/
        switch(keyPressed)
        {
            case UP:

                mvaddch(yPos, xPos, floorTiles);
 
                if(mvinch(yPos, xPos) != widthWall) 
                {
                    yPos--;
                    clearFound(yPos, xPos);
                }
                if(mvinch(yPos, xPos) == widthWall || mvinch(yPos, xPos) == heightWall || mvinch(yPos, xPos) == monster) 
                {
                    move(yPos++, xPos);
                }
                printFound(yPos, xPos);
                break;
            case DOWN:
                 mvaddch(yPos, xPos, floorTiles);
                
                if(mvinch(yPos, xPos) != widthWall)
                {
                    yPos++;
                    clearFound(yPos, xPos);
                }
                if(mvinch(yPos, xPos) == widthWall || mvinch(yPos, xPos) == heightWall || mvinch(yPos, xPos) == monster)
                {
                    move(yPos--, xPos);
                }
                printFound(yPos, xPos);
                break; 
            case LEFT:
                mvaddch(yPos, xPos, floorTiles);
                
                if(mvinch(yPos, xPos) != heightWall)
                {
                    xPos--;
                    clearFound(yPos, xPos);
                }
                if(mvinch(yPos, xPos) == heightWall || mvinch(yPos, xPos) == widthWall || mvinch(yPos, xPos) == monster)
                {
                    move(yPos, xPos++);
                }
                printFound(yPos, xPos);
                break;
            case RIGHT:
                 mvaddch(yPos, xPos, floorTiles);
                
                if(mvinch(yPos, xPos) != heightWall)
                {
                    xPos++;
                    clearFound(yPos, xPos);
                }
                if(mvinch(yPos, xPos) == heightWall || mvinch(yPos, xPos) == widthWall || mvinch(yPos, xPos) == monster)
                {
                    move(yPos, xPos--);
                }
                printFound(yPos, xPos);
                break;
            case QUIT: /*if they press q close the terminal */
                endwin();
                exit(0);
             default:
                break;
        }
        if(finishLevel(yPos,xPos) == 1)
        {
            erase();

            mvprintw(0,0, "You finished!");
        }
    }
}

/*A function to print out what the player found when they pick it up
 *Gets the y and x position of where the cursor is
 *If the move over an item, a print statement will show what they picked up
 */
void printFound(int yPos, int xPos)
{
    if(mvinch(yPos, xPos) == gold)
    {
        mvprintw(0, 0, "You found gold!");
    }
    if(mvinch(yPos, xPos) == balsaStaff)
    {
        mvprintw(0, 0, "You found a weapon!");
    }
    if(mvinch(yPos, xPos) == bluePotion)
    {
        mvprintw(0, 0, "You found a potion!");
    }
}

/*This function adds a print statement where they printFound prints the stuff
 *Basically makes it go blank again
 *gets the y and x position where the user moved
 *if they move, clear it
 */
void clearFound(int yPos, int xPos)
{
    mvprintw(0, 0, "                   ");
}

/*This function sees when the user goes over stairs and lets them leave the level*/
/*If there are stairs return one, if not return 0*/
int finishLevel(int yCoor, int xCoor)
{
    int checkWin; /*Declarations of variables*/

    if(mvinch(yCoor, xCoor) == stairs) /*if the user gets to the position where the stairs are then return 1*/
    {
        checkWin = 1;
    }
    else
    {
        checkWin = 0; /*else return 0*/
    }

    return checkWin;
}

