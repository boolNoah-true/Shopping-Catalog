/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Store.h
 * Author: NoahP
 *
 * Created on March 16, 2024, 10:02 PM
 */

#ifndef STORE_H
#define STORE_H

#include "Item.h"

class Store {
public:
    Store();
    
    void setInventory(const int& newInv);
    
    int getInv() const;
    
    
    
private:
    int invSize = 0; // inventory size
    Item * storeItems;
};

#endif /* STORE_H */

