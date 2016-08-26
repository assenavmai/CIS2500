/*************************a1.c****************************
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

#include "a1.h" /* include header file*/

/*static variables for the player character, trailing char to erase @ signs as they move, and character for the border*/
static char playerChar = '@';
static char trailingChar = ' ';
static char borderChar = 'x';

int main(void)
{
    initscr();
    keypad(stdscr, TRUE); /*get keypad  working*/
    cbreak();

    start_color(); /* enable color */
    
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK); /*change user input prompt to purple*/
    attron(COLOR_PAIR(1)); /*turn on the color(attribute)*/
    getInput(); /* call get input function */
    attroff(COLOR_PAIR(1));/* turn off the color*/

    noecho(); /*stop input from user*/

    createMaze(); /* generate the maze*/

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    moveCursor(); /* call function to move cursor */
    attroff(COLOR_PAIR(1));
    
    getch(); 
    endwin();
    
    return  0;
}

void getInput()
{
    /* prompt user to enter their name */
    char name[100];

    mvprintw(3, 70, "Please enter your name: "); /*Print out prompt for user and get their name */
    getstr(name);
    
    erase(); /*Erase input lines*/
    
    /*Show controls on the terminal for the user to use */
    mvprintw(2, 90, "Hello, %s. Can you solve this maze?", name); 
    napms(1000);
    mvprintw(4, 90, "Controls");
    mvprintw(5, 90, "UP - i");
    mvprintw(6, 90, "DOWN - k");
    mvprintw(7, 90, "RIGHT - l");
    mvprintw(8, 90, "LEFT - j");
    mvprintw(9, 90, "QUIT - q");
}

void moveCursor() /* Controls cursor movement */
{
    int keyPressed, xPos, yPos, rows, cols, keystrokes; /*Declaration of varibles */
    /*Creating messages to print out when the user finishes the maze*/
    char congratsMessage[] = "Congrats! You finished the maze!";
    char waffleMessage[] = "Here's a waffle to congratulate you on your hard work! (>'.')>#";
    char quitMessage[] = "Press q to quit.";
    char movesMade[] = "Total moves you made: ";

    /*Set the y position and x position to the beginning of the maze */
    yPos = 6;
    xPos = 4;
    keyPressed = 0;
    keystrokes = 1;
    

    /*while the user does not type q */
    while(keyPressed != QUIT)
    {
        curs_set(0); /*make the cursor invisible */
        
        keyPressed = mvaddch(yPos, xPos, playerChar); /*add the cursor character and mvgetch is getting the character as it moves */
        keyPressed = mvgetch(yPos,xPos); 
        
        getmaxyx(stdscr, rows, cols);  /*get the size of the terminal */   
        
        mvprintw(11, 90, "Moves made so far: %d", keystrokes); 
        
        /*Switch statement to determine what key they are pressing */
        /*add the space so that the @ sign does not repeat as it moves */
        /*If while moving there is no 'x', continue moving*/
        /*if while moving there is an 'x' do not move there go back one */
        switch(keyPressed)
        {
            case UP:
                mvaddch(yPos, xPos, trailingChar);
 
                if(mvinch(yPos, xPos) != borderChar) 
                {
                    yPos--;
                    keystrokes++;
                }
                if(mvinch(yPos, xPos) == borderChar) 
                {
                    move(yPos++, xPos);
                }
                break;
            case DOWN:
                 mvaddch(yPos, xPos, trailingChar);
                
                if(mvinch(yPos, xPos) != borderChar)
                {
                    yPos++;
                    keystrokes++;
                }
                if(mvinch(yPos, xPos) == borderChar)
                {
                    move(yPos--, xPos);
                }
                break; 
            case LEFT:
                 mvaddch(yPos, xPos, trailingChar);
                
                if(mvinch(yPos, xPos) != borderChar)
                {
                    xPos--;
                    keystrokes++;
                }
                if(mvinch(yPos, xPos) == borderChar)
                {
                    move(yPos, xPos++);
                }
                break;
            case RIGHT:
                 mvaddch(yPos, xPos, trailingChar);
                
                if(mvinch(yPos, xPos) != borderChar)
                {
                    xPos++;
                    keystrokes++;
                }
                if(mvinch(yPos, xPos) == borderChar)
                {
                    move(yPos, xPos--);
                }
                break;
            case QUIT: /*if they press q close the terminal */
                endwin();
                exit(0);
             default:
                break;
        }
        
        if(finishMaze(yPos, xPos)) /*If the user finished the maze, congratulate them */
        {
            erase(); /*Erase what is currently on the screen*/
            
            init_pair(1, COLOR_RED, COLOR_BLACK);
            attron(COLOR_PAIR(1));
            /*Congrats the user and tell them how to quit*/
            mvprintw((rows / 2) - 2, (cols - (strlen(congratsMessage))) / 2, "%s",  congratsMessage);
            mvprintw((rows / 2) - 1, (cols - (strlen(waffleMessage))) / 2, "%s",  waffleMessage);
            mvprintw(rows / 2, (cols - (strlen(quitMessage))) / 2, "%s",  quitMessage);
            mvprintw(rows / 2, (cols - (strlen(movesMade))) / 2, "%s%d",  movesMade, keystrokes);
            attroff(COLOR_PAIR(1));
        }

        refresh();
    }

}

int finishMaze(int yCoor, int xCoor)
{
    int checkWin; /*Declarations of variables*/

    if(yCoor == 41 && xCoor == 56) /*if the user gets to the position where the maze ends then return 1*/
    {
        checkWin = 1;
    }
    else
    {
        checkWin = 0; /*else return 0*/
    }

    return checkWin;
}

void createMaze()
{
    mvprintw(2,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    mvprintw(3,3, "xxx          xxxx  xxxxxxxxxx                   xx xx  xxxxx");
    mvprintw(4,3, "xxxxxxxxxxx  xxxx  xxxxxxxxxx  xx  xx  xxxxxxx  xx xx  xxxxx");
    mvprintw(5,3, "xxxxxxxxxxx  xxxx  xxxxxxxxxx  xx  xx  xxxxxxx  xx xx  xxxxx");
    mvprintw(6,3, "x                  xxxxxxxxxx  xx  xx  xxxxxxx  xx xx  xxxxx");
    mvprintw(7,3, "xxxxxxxxxxx  xxxx  xxxxxxxxxx  xx  xx  xxxxxxx         xxxxx");
    mvprintw(8,3, "xx  xxxxxxx  xxxx  xxxxxxxxxx  xx  xx  xxxxxxx  xxxxxxxxxxxx");
    mvprintw(9,3, "xx  xxxxxxxxxxxxx  xxxxxxxxxx  xx  xx  xxxxxxx  xxxxxxxxxxxx");
    mvprintw(10,3, "xx  xxxxxxxxxxxxx  xxxxxxxxxx  xx  xx       xx  xxxxxxxxxxxx");
    mvprintw(11,3, "xx  xxxxxxxxxxxxx  xxxxxxxxxx  xxxxxxxxxxx  xxxxxxxxxxxxxxxx");
    mvprintw(12,3, "xx  xxxxxxxxxxxxx  xxxxxxxxxx      xxx      xxxxxxxxxxxxxxxx");
    mvprintw(13,3, "xx    xxxxxxxxxxx  xxxxxxxxxx  xxxxxxxxxxx  xxxxxxxxxxxxxxxx");
    mvprintw(14,3, "xxxx                           xxxxxxxxxxx  xxxxxxxxxxxxxxxx");
    mvprintw(15,3, "xxxxxxxxxxxx    xxxxxxxxxxxxxxxxxxxxxxxxxx    xxxxxxx     xx");
    mvprintw(16,3, "xxxxxxxxxxxxxx  xxxxxxxxxxxxxx      xxxxxx  xxxxxxxxx  x  xx");
    mvprintw(17,3, "xxxxxxxxxxxxxx  xxxxxxxxxxxxxx  xxxxxxxxxx  xxxxxxxxx  x  xx");
    mvprintw(18,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  xxxxxxxxxx  xxxxxxxxx  x  xx");
    mvprintw(19,3, "xxxxxxxxxxxxxxxxxxxx                        x      xx  x  xx");
    mvprintw(20,3, "xxx                   xxxxxxxxxxxxxxxxxxxxxxx  xx  xx  x  xx");
    mvprintw(21,3, "xxxxxx  xxxxxxxxxxxx  xxxxxxxxxxxxxxxxxxxxxxx  xx  xx  x  xx");
    mvprintw(22,3, "xxxxxx  xxxxxxxxxxxx                xxxxxxxxx  xx      x  xx");
    mvprintw(23,3, "xxxxxx  xxxxxxxxxxxxxxxxxxxxxxxxx   xxxxxxxxx  xx  xxxxx  xx");
    mvprintw(24,3, "xxx        xxxxxxxxxxxxxxxxxxxxxx   xxxxxxxxx  xx     xx  xx");
    mvprintw(25,3, "xxxxxxx  xxxxxx                     xxxxx  xx  xxxxxxxxx  xx");
    mvprintw(26,3, "xxxxxxx      xxxxxxxxxxxxxxxxxxxx   xxxxx  xx  xxxxxxxxx  xx");
    mvprintw(27,3, "xxxxxxx  xxxxxxxxxxxxxxxxxxxxxxxx   xxxxx  xx  xxxxx      xx");
    mvprintw(28,3, "xxx  xx  xxxxxx                     xxxxx  xx  xxxxx  xxxxxx");
    mvprintw(29,3, "xxx  xx  xxxxxx  xxxxxxxxxxxxxxxxxxxxxxxx  xx  xxxxx  xxxxxx");
    mvprintw(30,3, "xxx      xxxxxx  xxxxxxxxxxxxxxxxxxxxxxxx  xx  xxxxx      xx");
    mvprintw(31,3, "xxxxxxx  xxxxxx                                xxxxx  xx  xx");
    mvprintw(32,3, "xxxxxxx  xxxxxxxxxxxxxxx  xxxxxxxxx  xxxx  xxxxxxxxx  xx  xx");
    mvprintw(33,3, "xxx  xx  xxxxxxxxxxxxxxx  xxxxxxxxx  xxxx       xxxx  xx  xx");
    mvprintw(34,3, "xxx  xx  xxxxxxxxxxxxxxx  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  xx");
    mvprintw(35,3, "xxx      xxxxxxx                xxxxxxxxxxxxxxxxx         xx");
    mvprintw(36,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  xxxxx  xx");
    mvprintw(37,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  xxxxx  xx");
    mvprintw(38,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      xxxxx");
    mvprintw(39,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  xxxxx");
    mvprintw(40,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx          xx");
    mvprintw(41,3, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx xxxxxx");

}

