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