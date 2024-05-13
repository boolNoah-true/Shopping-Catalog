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
    
    Item* item;
    
    void setNItems(const& newNum);
    int getNItems() const;
    //User* user;
    
    
private:
    
    int nUsers;
    int nItems;

};

#endif /* NODE_H */

