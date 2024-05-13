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




#include <iostream>

UI::UI() {}

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
    
    std::cout << "Enter FROST username and password:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Username: " << std::endl;
    std::cout << "Password: " << std::endl;
}

void UI::regstr() {
    std::cout << "Sign up with username, password and email" <<std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Username: " << std::endl;
    std::cout << "Password: " << std::endl;
    std::cout <<"Email: " << std::endl;
}