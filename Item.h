/* 
 * File:   Item.h
 * Author: NoahP
 *
 * Created on March 15, 2024, 12:22 PM
 */

#ifndef ITEM_H
#define ITEM_H
#include <string>
class Item {
public:
    Item(); //constructor declaration
    std::string getName() const; 
    std::string getInfo() const; 
    float getPrice() const;
    int getQnty() const;
    void setName(const std::string& newName); 
    void setInfo(const std::string& newInfo);
    void setPrice(const float& newPrice);
    void setQnty(const int& newQnty);
    
    
private:
    
    std::string name;
    std::string info;    // description of item
    float price;
    int qnty; //quantity

};


#endif /* ITEM_H */

