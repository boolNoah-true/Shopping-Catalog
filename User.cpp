/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   User.cpp
 * Author: NoahP
 * 
 * Created on March 15, 2024, 12:22 PM
 */

#include "User.h"
#include <iostream>

User::User() : myCart() {}

Cart& User::getCart() {
    return myCart;
}

void User::setUsrNme(const std::string& u) {
    username = u;

}

void User::setPswrd(const std::string& p) {
    password = p;

}

void User::setEmail(const std::string& e) {
    email = e;

}


std::string User::getUsrNme() const {
    
    return username;
    
}

std::string User::getPswrd() const {
    
    return password;
    
}

std::string User::getEmail() const {
    
    return email;
    
}

Datastream User::Serialize() {
    // Calculate total size needed
    unsigned long usernameSize = username.length();
    unsigned long passwordSize = password.length();
    unsigned long emailSize = email.length();
    Datastream cartStream = myCart.Serialize();  // Serialize cart first to get its size

    unsigned long totalSize = sizeof(unsigned long) * 7 + usernameSize + passwordSize + emailSize + cartStream.size;
    
    char *buffer = new char[totalSize];  // Allocate buffer
    if (!buffer) {
        throw std::bad_alloc();  // Handle allocation failure
    }

    unsigned long cursor = 0;
    WriteToBuf(buffer, reinterpret_cast<const char *>(&totalSize), sizeof(totalSize), cursor);
    WriteToBuf(buffer, reinterpret_cast<const char *>(&usernameSize), sizeof(usernameSize), cursor);
    WriteToBuf(buffer, username.c_str(), usernameSize, cursor);
    WriteToBuf(buffer, reinterpret_cast<const char *>(&passwordSize), sizeof(passwordSize), cursor);
    WriteToBuf(buffer, password.c_str(), passwordSize, cursor);
    WriteToBuf(buffer, reinterpret_cast<const char *>(&emailSize), sizeof(emailSize), cursor);
    WriteToBuf(buffer, email.c_str(), emailSize, cursor);
    WriteToBuf(buffer, cartStream.data, cartStream.size, cursor);

    return Datastream(buffer, totalSize);
}



void User::Load(Datastream *data) {
    std::cout << "User Load" << std::endl;
    unsigned long cursor = 0L;
    const char* buffer = (const char *)data->data;

    // Helper lambda to read strings safely and efficiently
    auto readString = [&cursor, buffer](unsigned long size) -> std::string {
        std::string result(buffer + cursor, size);
        cursor += size;
        return result;
    };

    // Read username size and then the username itself
    unsigned long usernameSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&usernameSize), sizeof(usernameSize), cursor);
    username = readString(usernameSize);

    // Read password size and then the password itself
    unsigned long passwordSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&passwordSize), sizeof(passwordSize), cursor);
    password = readString(passwordSize);

    // Read email size and then the email itself
    unsigned long emailSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&emailSize), sizeof(emailSize), cursor);
    email = readString(emailSize);

    // Calculate the remaining size for the cart data
    unsigned long remainingSize = data->size - cursor;
    if (remainingSize > 0) {
        Datastream cartDataStream(const_cast<char*>(buffer + cursor), remainingSize);
        myCart.Load(&cartDataStream);
    } else {
        std::cout << "No cart data to load." << std::endl;
    }
}

