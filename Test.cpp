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
    // // Create a Database object
    std::string dbFileName = "userDatabase.bin";
    Database userDatabase(dbFileName);

    

    // Create items for a user's cart
    Item item1("Laptop", "A high-performance laptop", 1200.99, 5);


    Item item2("Smartphone", "Latest model with advanced features", 799.49, 10);


    // Item* item3 = new Item();
    // item3->setName("Bidet");
    // item3->setInfo("Latest model");
    // item3->setPrice(67.49);
    // item3->setQnty(12);


    
    // Create a cart and add items to it
    Cart userCart;
    userCart.addItem(item1);
    userCart.addItem(item2);
    //userCart.addItem(item3, item3->getName(), item3->getInfo(), item3->getPrice(), item3->getQnty());

    // Create a user and assign the cart to the user
    User newUser;
    newUser.setUsrNme("john_doe");
    newUser.setPswrd("securepassword123");
    newUser.setEmail("john.doe@example.com");
    newUser.getCart() = userCart;

    newUser.getCart().display();

    // Add the user to the database
    //userDatabase.addUser(newUser);
    //newUser.getCart().display();
    // Write the database to file
    // try {
    //     userDatabase.WriteRecords();
    //     std::cout << "Database successfully written to " << dbFileName << std::endl;
    // } catch (const std::exception &e) {
    //     std::cerr << "Error writing database: " << e.what() << std::endl;
    // }

    // // Read the database back to verify
    // try {
    //     Database loadedDatabase(dbFileName);
    //     std::cout << "running.." << std::endl;
    //     User* loadedUser = loadedDatabase.FetchUser("john_doe");
    //     std::cout << "complete" << std::endl;
    //     if (loadedUser != nullptr) {
    //         std::cout << "Loaded user: " << loadedUser->getUsrNme() << std::endl;
    //         std::cout << "Loaded password: " << loadedUser->getPswrd() << std::endl;
    //         std::cout << "Loaded email: " << loadedUser->getEmail() << std::endl;
    //         loadedUser->getCart().display();
    //     } else {
    //         std::cerr << "User not found." << std::endl;
    //     }
    // } catch (const std::exception &e) {
    //     std::cerr << "Error reading database: " << e.what() << std::endl;
    // }

    //Clean up dynamically allocated items

 }

Test::~Test() {
}

