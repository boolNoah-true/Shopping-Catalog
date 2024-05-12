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

Datastream User::Serialize()  {
    // Get user information sizes
    unsigned long usernameSize = username.length();
    unsigned long passwordSize = password.length();
    unsigned long emailSize = email.length();

    // Serialize the cart and get its size
    Datastream cartStream = myCart.Serialize();
    unsigned long cartSize = cartStream.size;

    // Calculate total size
    unsigned long recordSize = usernameSize + passwordSize + emailSize + cartSize + 3 * sizeof(unsigned long);

    // Create buffer to hold all data
    char *buffer = new char[recordSize];
    unsigned long cursor = 0L;

    WriteToBuf(buffer, (const char *)&recordSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&usernameSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&passwordSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&emailSize, sizeof(unsigned long), cursor);
    


    WriteToBuf(buffer, username.c_str(), usernameSize, cursor);
    WriteToBuf(buffer, password.c_str(), passwordSize, cursor);
    WriteToBuf(buffer, email.c_str(), emailSize, cursor);
    WriteToBuf(buffer, cartStream.data, cartStream.size, cursor);

    
    

    return Datastream(buffer, recordSize);
}


void User::Load(Datastream *data) {
    unsigned long cursor = 0L;
    const char* buffer = (const char *)data->data;

    // Read username
    unsigned long usernameSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&usernameSize), sizeof(usernameSize), cursor);
    char* usernameBuffer = new char[usernameSize + 1];
    ReadFromBuf(buffer, usernameBuffer, usernameSize, cursor);
    usernameBuffer[usernameSize] = '\0';
    username = std::string(usernameBuffer);
    delete[] usernameBuffer;

    // Read password
    unsigned long passwordSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&passwordSize), sizeof(passwordSize), cursor);
    char* passwordBuffer = new char[passwordSize + 1];
    ReadFromBuf(buffer, passwordBuffer, passwordSize, cursor);
    passwordBuffer[passwordSize] = '\0';
    password = std::string(passwordBuffer);
    delete[] passwordBuffer;

    // Read email
    unsigned long emailSize = 0;
    ReadFromBuf(buffer, reinterpret_cast<char*>(&emailSize), sizeof(emailSize), cursor);
    char* emailBuffer = new char[emailSize + 1];
    ReadFromBuf(buffer, emailBuffer, emailSize, cursor);
    emailBuffer[emailSize] = '\0';
    email = std::string(emailBuffer);
    delete[] emailBuffer;

    // Read the cart information
    unsigned long remainingSize = data->size - cursor;
    Datastream cartDataStream(const_cast<char*>(buffer + cursor), remainingSize);
    myCart.Load(&cartDataStream);
}
