/* 
 * File:   Cart.cpp
 * Author: NoahP
 * 
 * Created on March 16, 2024, 9:44 PM
 */

#include "Cart.h"
#include <iostream>
#include <iomanip>

using namespace std;

Cart::Cart() : size(0), capacity(10)  {
    myItems = new Item[capacity];
}


Cart::~Cart() {
    delete[] myItems;

}



void Cart::addItem(const Item& newItem) {
    if (size >= capacity) {
        increaseCapacity();
    }
    myItems[size++] = newItem;
    cout << "Item Array size: " << size << endl;
}

void Cart::display() const {
      std::cout << "Cart contains the following items: " << std::endl;
      
      for(int i=0; i < size; i++) {
        std::cout << "Name: " << myItems[i].getName() <<  std::endl;
        std::cout << "Description: "<< myItems[i].getInfo() << std::endl;
        std::cout << "Price: " << "$" << std::fixed << std::setprecision(2) << myItems[i].getPrice() << std::endl;
        std::cout << "Quantity: " << myItems[i].getQnty() << " left" << std::endl;
      }
  }

void Cart::increaseCapacity() {
    capacity *=2;
    Item* newItems = new Item[capacity];

    for(int i = 0; i < size; i++) {
        newItems[i] = myItems[i];

    }

    delete[] myItems;
    myItems = newItems;
    cout << "New cap: " << capacity << endl;
}


Datastream Cart::Serialize() {
    unsigned long totalItems = size;
    unsigned long totalSize = sizeof(totalItems);
    //display();

    for (int i = 0; i < size; ++i) {
    std::cout << "Serializing item " << i <<  std::endl;

            totalSize += myItems[i].Serialize().size;

}

    std::cout << "This is the total size: " << totalSize << std::endl;


    char *buffer = new char[totalSize];
    unsigned long cursor = 0;


    WriteToBuf(buffer, reinterpret_cast<const char*>(&totalItems), sizeof(totalItems), cursor);


    for (int i = 0; i < size; ++i) {
        Datastream itemStream = myItems[i].Serialize();
        WriteToBuf(buffer, itemStream.data, itemStream.size, cursor);
    }

    return Datastream(buffer, totalSize);
}

Datastream Cart::ReadItemDataStream(const char * buffer, unsigned long& cursor) {
    std::cout << "Cart Readids" << std::endl;
    unsigned long itemSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&itemSize), sizeof(itemSize), cursor);
    
    char* itemBuffer = new char[itemSize];
    ReadFromBuf(buffer, itemBuffer, itemSize, cursor);
    
    return Datastream(itemBuffer, itemSize);
}

void Cart::Load(Datastream * data) {
    std::cout << "Cart load" << std::endl;
    unsigned long cursor = 0;
    const char* buffer = data->data;


    unsigned long itemCount = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&itemCount), sizeof(itemCount), cursor);


    delete[] myItems;
    myItems = new Item[itemCount];
    capacity = itemCount;
    size = 0;


    for (unsigned long i = 0; i < itemCount; ++i) {
        std::cout << "Loading item " << (i + 1) << std::endl;
        Datastream itemDataStream = ReadItemDataStream(buffer, cursor);
        myItems[i].Load(&itemDataStream);
        size++;
    }
}