/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   User.h
 * Author: NoahP
 *
 * Created on March 15, 2024, 12:22 PM
 */


#ifndef USER_H
#define USER_H

#include "Cart.h"
#include "Database.h"


#include <string>

class User : public Serializable {
public:
    User(); // constructor

    void setUsrNme(const std::string& u);
    void setPswrd(const std::string& p);
    void setEmail(const std::string& e);
    


    std::string getUsrNme() const;
    std::string getPswrd() const;
    std::string getEmail() const;
    
    Cart& getCart();
    
    Datastream Serialize();
    void Load(Datastream *);
    
    
private:
    
    std::string username;
    std::string password;
    std::string email;
    
    Cart myCart;
    Datastream ReadCartDataStream(const char* buffer, unsigned long& cursor, unsigned long remainingSize);
};

#endif /* USER_H */

