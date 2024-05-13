/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   UI.h
 * Author: NoahP
 *
 * Created on March 19, 2024, 3:20 PM
 */


#ifndef UI_H
#define UI_H

#include"Database.h"

class UI {
public:
    UI(std::string filename);
    ~UI();
    void run();
    void login();
    void regstr();  
    void storeFront();

private:

Database* db;
    
};

#endif /* UI_H */

