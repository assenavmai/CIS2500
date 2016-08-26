#include "linkedList.h"

/*This function takes in two strings for title and artist, the fileSize 
of the tune and the length in seconds. 
The function allocates memory for the struct, initializes the variables to the supplied
values,  initializes the next pointer to null and returns a pointer to the allocated memory. 
Returns NULL on failure.The value for title and artist are copied into newly allocated memory.
The passed-in memory for title and artist must be released elsewhere in the program.
Memory for the struct must be freed elsewhere in the program. 
*/
MusicRec * createRecord(char * title, char * artist, double fileSize, int length, char theType)
{
    MusicRec * newInfo = malloc(sizeof(MusicRec));

    newInfo->title = malloc(sizeof(char) * (strlen(title) + 1));
    newInfo->artist = malloc(sizeof(char) * (strlen(artist) + 1));
    strcpy(newInfo->title, title);
    strcpy(newInfo->artist, artist);
    newInfo->sizeInKB = fileSize;
    newInfo->lengthInSeconds = length;
    newInfo->type = theType;
    newInfo->next = NULL;

    if(newInfo == NULL) /*not sure here*/
    {
        printf("Out of memory\n");
        return NULL;
    }

    return(newInfo);
}

/*This function takes a pointer to a music record and returns a pointer to a string 
that contains the information from the struct formatted
in the  following manner:  "Title (Artist):lengthInSeconds[fileSize]  The string should not 
contain a newline. File size should be reported to two decimal places.
The string memory is allocated in this function and must be freed elsewhere in 
the program.
*/
char * printRecord(MusicRec * toPrint) /*fix*/
{
    int stringInfo;
    char * buffer;

    stringInfo = strlen(toPrint->title) + strlen(toPrint->artist) + MAXSIZE;

    buffer = malloc(sizeof(char) * stringInfo);

    sprintf(buffer,"%s (%s):%d[%0.2f]", toPrint->title, toPrint->artist, toPrint->lengthInSeconds, toPrint->sizeInKB);

    return buffer;
}

/*Takes a pointer to a music record and frees the memory for the internal variables.
the music record pointer must be freed separately */
void destroyRecord(MusicRec * theRecord)
{
    free(theRecord->artist);
    free(theRecord->title);
    theRecord->sizeInKB = 0;
    theRecord->lengthInSeconds = 0;
    theRecord->type = ' ';
}

/*addToFront(MusicRec * theList, MusicRec * toBeAdded)
Takes a pointer to the head of the list and an initialized music 
record.  Adds the music record to the front of the linked list and
returns a pointer to the head of the list.  */
MusicRec * addToFront(MusicRec * theList, MusicRec * toBeAdded)
{  
    if(theList == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(theList != NULL)
    {
        toBeAdded->next = theList;
    }
    
    return toBeAdded;
}

/*addToBack(MusicRec *  theList, MusicRec * toBeAdded)
Takes a pointer to the head of the list and an initialized music 
record.  Adds the music record to the back of the linked list and
returns a pointer to the head of the list.  */
MusicRec * addToBack(MusicRec *  theList, MusicRec * toBeAdded)
{   
    MusicRec * temp;
    
    temp = theList;
    
   /* if(theList == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }*/

    while(temp->next != NULL)
    {
        temp = temp->next;    
    }
    temp->next = toBeAdded;
    toBeAdded->next = NULL;
 
    return theList;
}

/*removeFromFront(MusicRec * theList)
Takes a pointer to the head of the list.  Removes the front
item from the head of the list.  Does not free the memory for 
the item removed.  Returns a pointer to the head of the list.
Returns NULL if the list is empty*/
MusicRec * removeFromFront(MusicRec * theList)
{
    MusicRec * temp;
    
    if(theList == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    
    temp = theList->next;

    theList->next = NULL;
    
    theList = temp;

    return theList;
}

/*removeFromBack(MusicRec *  theList)
Takes a pointer to the head of the list.  Removes the last
item from the head of the list.  Does not free the memory for 
the item removed.  Returns a pointer to the removed item.
Returns NULL if the list is empty.
*/
MusicRec * removeFromBack(MusicRec *  theList)
{
    MusicRec * temp;
    
    temp = theList;
    
    if(theList == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    while(temp->next->next != NULL)
    {
        temp->next->next = NULL;
    }
    theList = temp->next;
    temp->next = NULL;
    
    return theList;
}

/*getLastItem(MusicRec * theList)
Takes a pointer to the head of the list.  Returns 
a pointer to the item at the end of the list.
Returns NULL if the list is empty.
*/
MusicRec * getLastItem(MusicRec * theList)
{
    MusicRec * temp;
    
    temp = theList;
    
    if(theList == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    temp = temp->next->next;
    theList = temp;

    return theList;
}

/*isEmpty(MusicRec * theList)
Takes a pointer to the head of the list.  Returns 
TRUE if the list is empty and FALSE 
if the list has any elements.
*/
bool isEmpty(MusicRec * theList)
{
    if(theList == NULL)
    {
        return true;
    }
    
    return false;
}

/*printList(MusicRec *  theList)
Takes a pointer to the head of the list.  Prints to stdout
 all of the elements of the list (formatted 
as specified for the printRecord function) separated by newlines.

*/
void printList(MusicRec *  theList)
{
    if(theList == NULL)
    {
        printf("List is empty.\n");
    }
    
    while(theList != NULL)
    {
        printf ("%s (%s):%d[%.2f]", theList->title, theList->artist, theList->lengthInSeconds, theList->sizeInKB);
        printf("\n");
        theList = theList->next;
    }
}


/*destroyList(MusicRec * theList)
Takes a pointer to the list and frees the memory for each struct in the list.

*/
void  destroyList(MusicRec * theList)
{
    MusicRec * temp;

    while(theList != NULL)
    {
        temp = theList;
        theList = temp->next;
        free(theList);
    } 
}
