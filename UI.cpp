/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   UI.cpp
 * Author: NoahP
 * 
 * Created on March 19, 2024, 3:20 PM
 */

#include "UI.h"
#include "Database.h"
#include "User.h"



#include <iostream>
#include <String>

UI::UI(std::string filename) {
   db = new Database(filename); 
}

UI::~UI() {
    delete db;
}

void UI::run() {
    
    int input = 0;
    
    std::cout << "FROST" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Quit" << std::endl;
    
    std::cin >> input;
    std::cin.ignore();
    switch(input) {
        case 1:
            login();
            break;
        case 2: 
            regstr();
        case 3:
            return;
        default:
            std::cout << "Invalid Choice" << std::endl;
    }
    return;
}

void UI::login() {
    std::string userName, passWord;

    std::cout << "Enter FROST username and password:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Username: " << std::endl;
    std::cout << "Password: " << std::endl;

    db->ValidateUser(userName, passWord);

}

void UI::regstr() {
    std::string userName, passWord, email;
    User newUser;
    std::cout << "Sign up with username, password and email" <<std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Username: " << std::endl;
    std::cin >> userName;
    newUser.setUsrNme(userName);
    std::cout << "Password: " << std::endl;
    std::cin >> passWord;
    newUser.setPswrd(passWord);
    std::cout <<"Email: " << std::endl;
    std::cin >> email;
    newUser.setEmail(email);

    db->addUser(newUser);
    db->WriteRecords();
}

void UI::storeFront() {
    

}