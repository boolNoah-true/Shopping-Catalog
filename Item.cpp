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

Item::Item(const std::string& n) : name(n), info(""), price(0.00), qnty(0){}

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