/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Store.cpp
 * Author: NoahP
 * 
 * Created on March 16, 2024, 10:02 PM
 */

#include "Store.h"


Store::Store() : invSize(0)
{
    storeItems = new Item[10];
}

int Store::getInv() const{
    return invSize;
}

void Store::setInventory(const int& newInv) {
    invSize = newInv;
}