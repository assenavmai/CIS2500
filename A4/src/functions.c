#include "linkedList.h"
#include "functions.h"

MusicRec * tokenizer(char * read)
{
    MusicRec * head;
    char * songArtist;
    char * songTitle;
    char * ptr;
    char * token;
    char songType;
    int i;
    int length;
    int songLen;
    double songSize;
    
    i = 0;
    length = 0;

    ptr = malloc(sizeof(char) * 10 + 1);

    songArtist = strtok(read, ",");

    songTitle = strtok(NULL, ",");
        
    token = strtok(NULL, ",");
    songLen = atoi(token);
    
    token = strtok(NULL, ",");
    songSize = atof(token);
    calculateAverage(songSize);

    /*length = sizeof(songLen)/sizeof(int);
    printf("\n\n\nLength: %d\n\n\n", length);*/


    ptr = strtok(NULL, ",");

    while(ptr[i] != 'a' && ptr[i] != 'b')
    {
        i++;  
    }
    songType = ptr[i];

    head = createRecord(songTitle, songArtist, songSize, songLen, songType);
    
    return head;
}

int count(MusicRec * recordNodes)
{
    int counter;

    counter = 0;

    while(recordNodes != NULL)
    {
        recordNodes = recordNodes->next;
        counter++;
    }

    return counter;
}
void calculateAverage(double sizeOfSong)
{
    /*length = sizeof(sizeOfSong)/sizeof(double);
    printf("\n\n\nLength: %d\n\n\n", length);*/

  

}
void calculatePlaylist(int lengthSecs)
{

}