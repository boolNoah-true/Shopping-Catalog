/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cart.h
 * Author: NoahP
 *
 * Created on March 16, 2024, 9:43 PM
 */

#ifndef CART_H
#define CART_H

#include <string>

#include "Item.h"
#include "Database.h"

class Cart : public Serializable  {
public:

    
    Cart();
  ~Cart();
  
  void addItem(Item* item, const std::string& name, const std::string& info, const float price, const int qnty);
 
  void display() const;
  
  Datastream Serialize();
  void Load(Datastream *);
    
     
private: 
    Item** myItems;
    int size;
    int capacity;
    
    void increaseCapacity();
    Datastream ReadItemDataStream(const char * buffer, unsigned long& cursor);
};

#endif /* CART_H */

