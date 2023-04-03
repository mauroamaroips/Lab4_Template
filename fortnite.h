#pragma once

/**
 * @brief Loads contents of fortnite shop from csv file.
 * 
 * The caller states 'howMany' records are to be loaded.
 * If less are available, then only those are loaded into the array.
 * 
 * @param arr an array with at least capacity for 'howMany'
 * @param howMany how many items to load. 
 * @return int number of items loaded into 'arr'
 */

//Nível 1

typedef struct fortniteItem
{
    char skinName[25];
    char rarity[15];
    int price;
    
} FortniteItem;

int fortniteLoadShop(FortniteItem arr[], int howMany);  

FortniteItem fortniteItemCreate(char skinName[], char rarity[], int price);

//Nível 2

typedef FortniteItem *PtFortniteItem;
void fortniteItemPrint(PtFortniteItem item);
void fortniteArrayPrint(FortniteItem arr[], int arrLength);

//Nível 3

int findMostExpensiveItemIndex(FortniteItem arr[], int arrLength);

//Nível 4

void fortniteArraySortByRarity(FortniteItem arr[], int arrLength);
void fortniteArraySortByCost(FortniteItem arr[], int arrLength);

//Nível 5

void swap(PtFortniteItem item1, PtFortniteItem item2);
