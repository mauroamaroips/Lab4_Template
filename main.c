#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "fortnite.h"

int main() {

//Nível 1

    FortniteItem fortniteShop[100];
    int shopSize = fortniteLoadShop(fortniteShop, 100);

    fortniteLoadShop(fortniteShop, shopSize);

//Nível 2

    fortniteArrayPrint(fortniteShop, shopSize);

// Nível 3

    int itemIdx = findMostExpensiveItemIndex(fortniteShop,shopSize);
    printf("%d\n", itemIdx);
    fortniteItemPrint(&fortniteShop[itemIdx]);

//Nível 4
    
    //Ordenação alfabeticamente por raridade (A-Z) - bubble sort
    fortniteArraySortByRarity(fortniteShop, shopSize);
    fortniteArrayPrint(fortniteShop, shopSize);

    //Ordenar por ordem descrescente de preço - bubble sort
    fortniteArraySortByCost(fortniteShop, shopSize);
    fortniteArrayPrint(fortniteShop, shopSize);

//Nível 5 
    
    FortniteItem it = fortniteItemCreate("Teste","Teste", 1200);
    printf("%ld bytes\n", sizeof(it));





    return EXIT_SUCCESS;
}
