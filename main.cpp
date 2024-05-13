

/* 
 * File:   main.cpp
 * Author: NoahP
 *
 * Created on March 15, 2024, 11:32 AM
 */
#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include "Item.h"
#include "UI.h"
#include"Cart.h"
#include "User.h"
#include "Database.h"
#include "Test.h"

using namespace std;


int main() {

        UI menu("userdata.bin");

        menu.run();



    // Database db("Test2.bin");
    // //Create a user
    // User testUser;
    // testUser.setUsrNme("TestUser");
    // testUser.setPswrd("123456");
    // testUser.setEmail("test@example.com");

    

    // // Assuming Cart and Item are already included and set up in User
    // Item testItem("Example Item", "Description of the item", 99.99, 10);
    // testUser.getCart().addItem(testItem);
    // Item testItem2("Example Item2", "Description of the item3", 99.99, 10);
    // testUser.getCart().addItem(testItem);
    // Item testItem3("Example Item2", "Description of the item3", 99.99, 10);
    // testUser.getCart().addItem(testItem);

    // db.addUser(testUser);
    // db.WriteRecords();
    // User* user = db.FetchUser("testUser");

    // cout << user->getEmail();

    // //Serialize the user
    // Datastream userData = testUser.Serialize();

    // // Write to binary file
    // std::ofstream outFile("test.bin", std::ios::binary);
    // if (!outFile) {
    //     std::cerr << "Failed to open file for writing." << std::endl;
    //     return 1;
    // }

    // outFile.write(userData.data, userData.size);
    // if (!outFile) {
    //     std::cerr << "Failed to write data to file." << std::endl;
    //     outFile.close();
    //     return 1;
    // }

    // outFile.close();
    // std::cout << "Data successfully written to 'test.bin'" << std::endl;

    return 0;
}


