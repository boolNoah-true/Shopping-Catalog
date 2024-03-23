/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Binary.cpp
 * Author: NoahP
 * 
 * Created on March 23, 2024, 12:22 AM
 */

#include "Binary.h"
#include "Node.h"
#include "User.h"
#include "Item.h"

#include <iostream>
#include <fstream>

void Binary::writeBinUsr(const string &filename, const Node &uNode) {
    ofstream outFile;
    
    outFile.open(filename, ios::binary | ios::app);
    
    if(!outFile) {
        cerr << "Error: Could not open file!" << endl;
        
        return;
        
    }
    
    //write number of users
    
    outFile.write(reinterpret_cast<const char*>(&uNode.getNUsers()), sizeof(uNode.getNUsers()));
    
   //write each User data
    //TODO finish this function
    
    for (int i = 0; i < uNode.getNUsers(); i++) {
        User* userPtr = uNode.getUPtr(i);
        if(userPtr) {
            User& users = *userPtr;
            
            
            
            
            
            
        }
    }
        
        
}

