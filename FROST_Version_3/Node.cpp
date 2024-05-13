/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ItemNode.cpp
 * Author: NoahP
 * 
 * Created on March 15, 2024, 12:37 PM
 */

#include "Node.h"

Node::Node() {}

void Node::setNItems(const& newINum) {\
     
    nItems = newINum;
    
}

int Node::getNItems() const {
    
    return nItems;
    
}

void Node::setNUsers(const& newUNum) {
    
    nUsers = newUNum;
    
}

int Node::getNUsers() const {
    
    return nUsers;
    
}
