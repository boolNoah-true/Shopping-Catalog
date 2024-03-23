/* 
 * File:   ItemNode.h
 * Author: NoahP
 *
 * Created on March 15, 2024, 12:37 PM
 */

#ifndef NODE_H
#define NODE_H
#include "Item.h"
#include "User.h"

class Node {
public:
    Node();
    
    
    
    void setNItems(const int& newINum);
    int getNItems() const;
    Item* itemPtr() const;
    
 
    
    void setNUsers(const int& newUNum);
    int getNUsers() const;
    User* getUPtr(int index) const;
    
    
    
private:
    Item* item;
    User* user;
    
    
    int nUsers;
    int nItems;
    User* users = new User[nUsers];

};

#endif /* NODE_H */

