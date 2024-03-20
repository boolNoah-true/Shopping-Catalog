/* 
 * File:   Cart.cpp
 * Author: NoahP
 * 
 * Created on March 16, 2024, 9:44 PM
 */

#include "Cart.h"

Cart::Cart(Item* intialItems, int n) : size(n) {
    myItems = new Item[n];
    for(int i = 0; i < n; i++) {
        myItems[i] = intialItems[i];
    }
}


Cart::~Cart() {
    delete[] myItems;
}