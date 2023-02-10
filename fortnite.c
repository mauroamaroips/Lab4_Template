#include "fortnite.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


int fortniteLoadShop(FortniteItem arr[], int howMany) {
    FILE* stream = fopen("fortniteshop.csv", "r");

    /* If file does not exist, abort */ 
    if(stream == NULL) return -1;

    int count = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        if(count == howMany) break;

        char* tmp = strdup(line);
        
        /* creates tokens[3] array, with tokens read from the file line */
        char** tokens = splitString(tmp, 3, ",");
        
        int vbucks = atoi(tokens[2]);
        arr[count++] = /* TODO: create item from tokens */

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}