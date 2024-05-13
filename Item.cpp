/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Item.cpp
 * Author: NoahP
 * 
 * Created on March 15, 2024, 12:22 PM
 */

#include "Item.h"

#include <iostream>

Item::Item() {
    name = '\0';
    info = '\0';
    price = 0.0;
    qnty = 0;
}


Item::Item(std::string name, std::string info, float price, int qnty){
    this->name = name;
    this->info = info;
    this->price = price;
    this->qnty = qnty;
}

std::string Item::getName() const {
    return name;
} 

std::string Item::getInfo() const {
    return info;
}

float Item::getPrice() const {
    return price;
}

int Item::getQnty() const {
    return qnty;
}

void Item::setName(const std::string& newName) {
    name = newName;
}

void Item::setInfo(const std::string& newInfo) {
    info = newInfo;
}

void Item::setPrice(const float& newPrice) {
    price = newPrice;
}

void Item::setQnty(const int& newQnty) {
    qnty = newQnty;
}

void Item::Load(Datastream *data){
    std::cout << "Item Load" << std::endl;
    unsigned long nameSize;
    unsigned long infoSize;
    
    unsigned long cursor = 0L;
    const char *buffer = (const char *)data->data;

    ReadFromBuf(buffer, (char *)&nameSize, sizeof(unsigned long), cursor);
    ReadFromBuf(buffer, (char *)&infoSize, sizeof(unsigned long), cursor);
   

    char *temp = new char[nameSize + 1];
    ReadFromBuf(buffer, temp, nameSize, cursor);
    temp[nameSize] = '\0';
    this->name = std::string((const char *)temp);
    delete []temp;


    temp = new char[infoSize + 1];
    ReadFromBuf(buffer, temp, infoSize, cursor);
    temp[infoSize] = '\0';
    this->info = std::string((const char *)temp);
    delete []temp;

    
    ReadFromBuf(buffer, (char *)&this->price, sizeof(float), cursor);
    ReadFromBuf(buffer, (char *)&this->qnty, sizeof(int), cursor);
          
}



Datastream Item::Serialize(){
    std::cout << "serialize item" << std::endl;
    unsigned long nameSize = name.length();
    unsigned long infoSize = info.length();
    std::cout << "Item Serialize Name Size "<< nameSize << std::endl;
    std::cout << "Item Serialize Name  "<< name << std::endl;
    std::cout << "Item Serialize Info Size "<< infoSize << std::endl;
    std::cout << "Item Serialize Info "<< info << std::endl;
    std::cout << "Item Serialize 2 times unsigned long "<< sizeof(unsigned long) << std::endl;
    std::cout << "Item Serialize Int size "<< sizeof(int) << std::endl;
    std::cout << "Item Serialize Float Size "<< sizeof(float) << std::endl;

    
    unsigned long cursor = 0L;
    unsigned long recordSize = nameSize + infoSize + 2 * sizeof(unsigned long) + sizeof(int) + sizeof(float);
    char *buffer = new char[recordSize + sizeof(unsigned long)];
    
    std::cout << "Record SIZE mutha fuycka: " << recordSize + sizeof(unsigned long) << std::endl;
      
    


    WriteToBuf(buffer, (const char *)&recordSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&nameSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&infoSize, sizeof(unsigned long), cursor);
    
    WriteToBuf(buffer, name.c_str() , nameSize, cursor);
    WriteToBuf(buffer, info.c_str(), infoSize, cursor);
    
    WriteToBuf(buffer, (const char *)&this->price, sizeof(float), cursor);
    WriteToBuf(buffer, (const char *)&this->qnty, sizeof(int), cursor);
   

     Datastream data(buffer, recordSize + sizeof(unsigned long));

std::cout << "waaaahoooooo" << std::endl;
     return data;
}