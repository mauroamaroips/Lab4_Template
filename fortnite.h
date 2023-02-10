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
int fortniteLoadShop(FortniteItem arr[], int howMany);
