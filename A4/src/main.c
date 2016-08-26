#include "linkedList.h"
#include "functions.h"


int main(int argc, char const *argv[])
{
    FILE * musicInfo;
    MusicRec * recordPtr = NULL;
    MusicRec * head = NULL;
    char line[MAXSIZE];
    int numRecs;
    int amountOfNodes;

    numRecs = 0;
    amountOfNodes = 0;

    if (argc != 2)/*If they do not put a file name in the terminal, exit*/
    { 
      printf("Usage: Enter an input file name. Exiting.\n");
      exit(1);
    }
    musicInfo = fopen(argv[1], "r");

    if(musicInfo == NULL)
    {
        fprintf(stderr, "Error: File cannot be opened. Exiting.\n");
    }

    head = malloc(sizeof(MusicRec));

    fgets(line, sizeof(line), musicInfo);
    head = tokenizer(line);
    numRecs++;

    while(fgets(line, sizeof(line), musicInfo) != NULL)
    {
        numRecs++;
        recordPtr = tokenizer(line);
        
        if(recordPtr->type == 'a')
        {
            head = addToFront(head, recordPtr);
        }
        else if(recordPtr->type == 'b')
        {
            head = addToBack(head, recordPtr);
        }   
    }
    amountOfNodes = count(recordPtr);
    
    printList(head);
    destroyList(head);

    /*for(i = 0; i < numRecs; i++)
    {
        destroyRecord(arrayRecs[i]);
        free(arrayRecs[i]);
    }*/
    fclose(musicInfo);
 
    return 0;
}



