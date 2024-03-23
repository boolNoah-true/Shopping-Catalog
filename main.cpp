

/* 
 * File:   main.cpp
 * Author: NoahP
 *
 * Created on March 15, 2024, 11:32 AM
 */
#include <iostream>
#include <iomanip>
#include "Item.h"
#include "UI.h"
#include"Cart.h"

int main (){
   // UI menu;
    
 //  menu.run();
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //TODO 
    //Make this section a part of the admin class later on
    int qnty = 0;
    float price = 0;
    std::string info;
    std:: string name;
    
    
    
    std::cout << "Enter item info here: " << std::endl;
    
    std::getline(std::cin, name);
    std::getline(std::cin, info);
    std:: cin >> price;
    std::cin.ignore();
    std::cin >> qnty;
    
    Cart cart;
    Item item;
    cart.addItem(&item, name, info, price, qnty);
    
//    Item item;
//    item.setName(name);
//    item.setInfo(info);
//    item.setPrice(price);
//    item.setQnty(qnty);
//    
//    std::cout << "Name: " << item.getName() << std::endl;
//    std::cout << "Description: "<< item.getInfo() << std::endl;
//    std::cout << "Price: " << "$" << std::fixed << std::setprecision(2) <<item.getPrice() << std::endl;
//    std::cout << "Quantity: " << item.getQnty() << " left" << std::endl;
//    
    cart.display(); // display function for displaying cart
    
    
    return 0;
}

