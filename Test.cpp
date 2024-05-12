/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Test.cpp
 * Author: NoahP
 * 
 * Created on May 6, 2024, 12:18 AM
 */

#include "Test.h"

#include <iostream>

Test::Test() {

}

void Test::run(){
    // Create a Database object
    std::string dbFileName = "userDatabase.bin";
    Database userDatabase(dbFileName);

    // Create items for a user's cart
    Item* item1 = new Item();
    item1->setName("Laptop");
    item1->setInfo("A high-performance laptop");
    item1->setPrice(1200.99);
    item1->setQnty(5);

    Item* item2 = new Item();
    item2->setName("Smartphone");
    item2->setInfo("Latest model with advanced features");
    item2->setPrice(799.49);
    item2->setQnty(10);

    // Create a cart and add items to it
    Cart userCart;
    userCart.addItem(item1, item1->getName(), item1->getInfo(), item1->getPrice(), item1->getQnty());
    userCart.addItem(item2, item2->getName(), item2->getInfo(), item2->getPrice(), item2->getQnty());

    // Create a user and assign the cart to the user
    User newUser;
    newUser.setUsrNme("john_doe");
    newUser.setPswrd("securepassword123");
    newUser.setEmail("john.doe@example.com");
    newUser.getCart() = userCart;

    // Add the user to the database
    userDatabase.addUser(newUser);

    // Write the database to file
    try {
        userDatabase.WriteRecords();
        std::cout << "Database successfully written to " << dbFileName << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error writing database: " << e.what() << std::endl;
    }

    // Read the database back to verify
    try {
        Database loadedDatabase(dbFileName);
        User* loadedUser = loadedDatabase.FetchUser("john_doe");
        if (loadedUser != nullptr) {
            std::cout << "Loaded user: " << loadedUser->getUsrNme() << std::endl;
        } else {
            std::cerr << "User not found." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error reading database: " << e.what() << std::endl;
    }

    // Clean up dynamically allocated items
    delete item1;
    delete item2;
}

Test::~Test() {
}

