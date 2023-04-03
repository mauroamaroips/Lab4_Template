#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "fortnite.h"

//Nível 1

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
        arr[count++] = fortniteItemCreate(tokens[0], tokens[1], vbucks);  /* TODO: create item from tokens */

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}

FortniteItem fortniteItemCreate(char skinName[], char rarity[], int price){
    FortniteItem newItem;
    strcpy(newItem.skinName, skinName);
    strcpy(newItem.rarity, rarity);
    newItem.price = price;
    return newItem;
}

void fortniteItemPrint(PtFortniteItem item){
    printf("%-30s | %-30s | %d\n", item->skinName, item->rarity, item->price);
}

void fortniteArrayPrint(FortniteItem arr[], int arrLength){
    printf("Imported %d fortnite items: \n", arrLength);
    //Nível 2
    /*for (int i = 0; i < arrLength; i++)
    {
        fortniteItemPrint(&arr[i]);
    } */

    //Nível 5
    
    FortniteItem *ptr = arr; // cria um ponteiro para o início do array
    FortniteItem *endPtr = arr + arrLength; //cria um ponteiro para o fim do array

    for (; ptr < endPtr; ptr++)
    {
        fortniteItemPrint(ptr);
    }
    
}

//Nível 3

int findMostExpensiveItemIndex(FortniteItem arr[], int arrLength){

    int price = 0;
    int mostExpensiveIdx = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if(arr[i].price > price){
            price = arr[i].price;
            mostExpensiveIdx = i;
        }
    }

    return mostExpensiveIdx;

}

//Nível 4

void fortniteArraySortByRarity(FortniteItem arr[], int arrLength){

  for (int i = 0; i < arrLength; i++)
        {
            for (int j = 0; j < arrLength-i-1; j++)
            {
                if(strcmp(arr[j].rarity, arr[j+1].rarity) > 0){
                    //Nível 4
                    /*FortniteItem temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;*/

                    //Nível 5
                    swap(&arr[j], &arr[j+1]);
                }
            }           
        }    
}

void fortniteArraySortByCost(FortniteItem arr[], int arrLength){
      for (int i = 0; i < arrLength; i++)
        {
            for (int j = 0; j < arrLength-i-1; j++)
            {
                if(arr[j].price < arr[j+1].price){
                    //Nível 4
                    /*FortniteItem temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;*/

                    //Nível 5
                    swap(&arr[j], &arr[j+1]);
                }
            }           
        } 
}

//Nível 5

void swap(PtFortniteItem item1, PtFortniteItem item2){
    FortniteItem temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

    