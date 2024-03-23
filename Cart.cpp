/* 
 * File:   Cart.cpp
 * Author: NoahP
 * 
 * Created on March 16, 2024, 9:44 PM
 */

#include "Cart.h"
#include <iostream>
#include <iomanip>

Cart::Cart() : myItems(nullptr), size(0), capacity(0) {}


Cart::~Cart() {
    delete[] myItems;
}

void Cart::addItem(Item* item, const std::string& name, const std::string& info, const float price, const int qnty) {
    if (size >= capacity) {
        increaseCapacity();
    }
    
    myItems[size] = item;
    myItems[size]->setName(name);
    myItems[size]->setInfo(info);
    myItems[size]->setPrice(price);
    myItems[size]->setQnty(qnty);
    size++;

}

void Cart::display() const {
      std::cout << "Cart contains the following items: " << std::endl;
      
      for(int i=0; i < size; i++) {
        std::cout << "Name: " << myItems[i]->getName() << std::endl;
        std::cout << "Description: "<< myItems[i]->getInfo() << std::endl;
        std::cout << "Price: " << "$" << std::fixed << std::setprecision(2) << myItems[i]->getPrice() << std::endl;
        std::cout << "Quantity: " << myItems[i]->getQnty() << " left" << std::endl;
      }
  }

void Cart::increaseCapacity() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    Item** newItems = new Item*[newCapacity];
    
    for(int i = 0; i < size; i++) {
        newItems[i] = myItems[i];
        
    }
    
    delete[] myItems;
    myItems = newItems;
    capacity = newCapacity;
}