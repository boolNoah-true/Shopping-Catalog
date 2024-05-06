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


Datastream Cart::Serialize() {
    unsigned long totalItems = size;
    unsigned long totalSize = sizeof(totalItems);

    
    for (int i = 0; i < size; ++i) {
        totalSize += myItems[i]->Serialize().size;
    }

 
    char *buffer = new char[totalSize];
    unsigned long cursor = 0;

    
    WriteToBuf(buffer, (const char *)&totalItems, sizeof(totalItems), cursor);

    
    for (int i = 0; i < size; ++i) {
        Datastream itemStream = myItems[i]->Serialize();
        WriteToBuf(buffer, itemStream.data, itemStream.size, cursor);
    }

    return Datastream(buffer, totalSize);
}

Datastream Cart::ReadItemDataStream(const char * buffer, unsigned long& cursor) {
    unsigned long itemSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&itemSize), sizeof(itemSize), cursor);
    
    char* itemBuffer = new char[itemSize];
    ReadFromBuf(buffer, itemBuffer, itemSize, cursor);
    
    return Datastream(itemBuffer, itemSize);
}

void Cart::Load(Datastream * data) {
    unsigned long cursor = 0;
    const char* buffer = (const char *)data->data;

    // Read the number of items in the cart
    unsigned long itemCount = 0;
    ReadFromBuf(buffer, (char *)&itemCount, sizeof(unsigned long), cursor);

    // Allocate or reallocate myItems array
    delete[] myItems; // Clear any previously allocated memory
    myItems = new Item*[itemCount];
    size = itemCount;
    capacity = itemCount;

    // Read and deserialize each item
    for (unsigned long i = 0; i < itemCount; ++i) {
        Datastream itemDataStream = ReadItemDataStream(buffer, cursor); // Helper function to extract item data
        myItems[i] = new Item();
        myItems[i]->Load(&itemDataStream);
    }
}