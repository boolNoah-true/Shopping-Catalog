/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Database.cpp
 * Author: NoahP
 * 
 * Created on March 15, 2024, 11:43 AM
 */

#include "Database.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using std::ios;

    

    // Destructor
    Datastream::~Datastream() {
        std::cout << "Deleting Datastream with data pointer: " << static_cast<void*>(data) << std::endl;
        
        
        delete[] data;
        data = nullptr;
        std::cout << "Deleted successfully" << std::endl;
        
        
    }

    // Copy constructor
    Datastream::Datastream(const Datastream& other) : size(other.size) {
        data = new char[size];
        std::copy(other.data, other.data + size, data);
    }

    // Copy assignment operator
    Datastream& Datastream::operator=(const Datastream& other) {
        if (this != &other) {
            delete[] data;
            data=nullptr;
            size = other.size;
            data = new char[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Move constructor
    Datastream::Datastream(Datastream&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // Move assignment operator
    Datastream& Datastream::operator=(Datastream&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = nullptr;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }


void Serializable::WriteToBuf(char *buffer, const char *data, unsigned long size, unsigned long &cursor){
    
    for(int i=0; i < size; i++){
        buffer[cursor++] = data[i];
    }
}

void Serializable::ReadFromBuf(const char *buffer, char *dst, unsigned long size, unsigned long &cursor){
    for(int i=0; i < size; i++){
        dst[i] = buffer[cursor++];
    }
}



Database::Database(std::string FileName) {
  std::cout << "run" << std::endl;
  this->FileName = FileName;
  this->UserFile.open(FileName, ios::in | ios::binary);

  if (!UserFile.is_open()) {
    // ask if new database needs to be created with file name
    //throw std::string("ERROR: Database could not be loaded!");
  }

  // Logic For Loading Database all at once
  UserFile.read((char *)&nRecords, sizeof(nRecords));
  Records = new User[nRecords];
  
  // change made here for utilizing Load
  for (int i = 0; i < nRecords; i++) {
    Datastream userDataStream = ReadUserDatastream();
    Records[i].Load(&userDataStream);
  }
  UserFile.close();
}

Database::~Database() {
  delete[] Records;
}

User *Database::FetchUser(std::string UserName) {
  for (int i = 0; i < nRecords; i++) {
    if (Records[i].getUsrNme() == UserName)
        return &Records[i];
  }
  return nullptr;
}

bool Database::ValidateUser(std::string UserName, std::string Password) {
  User *temp = FetchUser(UserName);
  
  if (!temp || Password != temp->getPswrd()) return false;

  return true;
}

// write all users in the database function
void Database::WriteRecords() {
    // Open the file only when needed
    if (!UserFile.is_open()) {
        UserFile.open(FileName, std::ios::out | std::ios::binary | std::ios::trunc);
        if (!UserFile) {
            std::cerr << "Error: Unable to open file for writing: " << FileName << std::endl;
            return;  // Exit the function if file cannot be opened
        }
    }

    // Write the number of records first
    UserFile.write(reinterpret_cast<const char *>(&nRecords), sizeof(nRecords));
    if (UserFile.fail()) {
        std::cerr << "Error: Failed to write the number of records to " << FileName << std::endl;
        UserFile.close();
        return;
    }

    // Write each user's serialized data
    for (int i = 0; i < nRecords; ++i) {
        Datastream userStream = Records[i].Serialize();
        UserFile.write(userStream.data, userStream.size);
        if (UserFile.fail()) {
            std::cerr << "Error: Failed to write user data for record " << i << " to " << FileName << std::endl;
            break;  // Break the loop on write failure
        }
    }

    UserFile.close();  // Always close the file
}


// function for reading and returning user datastream from file
Datastream Database::ReadUserDatastream() {
  std::cout << "ReadUserDataStream" << std::endl;
  // Read the size of the next user record.
  long recordSize = 0;
  UserFile.read(reinterpret_cast<char *>(&recordSize), sizeof(recordSize));

  if (UserFile.fail()) {
    throw std::runtime_error("Failed to read record size.");
  }

  // Allocate buffer for user data.
  char *buffer = new char[recordSize];

  // Read the user record data based on the size
  UserFile.read(buffer, recordSize);

  // Check if read was successful
  if (UserFile.fail()) {
    delete[] buffer;
    //throw std::runtime_error("Failed to read user data.");
  }

  return Datastream(buffer, recordSize);
}

// Function for Admin to Edit User Data
//void Database::EditUser(std::string name, std::string Username, std::string password, User *user){
//   if(!user)return;
//   
//   if(name != "") user->setName(name);
//   if(Username != "") user->setUserName(Username);
//   if(password != "") user->setPassword(password);
//}

void Database::addUser(const User& newUser) {
    
    User *temp = new (std::nothrow) User[nRecords + 1];  
    if (!temp) {
        std::cerr << "Error: Memory allocation failed when trying to add new user." << std::endl;
        return;  
    }

    
    std::copy(Records, Records + nRecords, temp);

    
    temp[nRecords] = newUser;

    
    delete[] Records;
    Records = temp;

    nRecords++;
}