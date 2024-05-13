/* 
 * File:   Item.h
 * Author: NoahP
 *
 * Created on March 15, 2024, 12:22 PM
 */

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "Database.h"

class Item : public Serializable  {
public:
    Item();
    Item(std::string name, std::string info, float price, int qnty); //constructor declaration
    std::string getName() const; 
    std::string getInfo() const; 
    float getPrice() const;
    int getQnty() const;
    void setName(const std::string& newName); 
    void setInfo(const std::string& newInfo);
    void setPrice(const float& newPrice);
    void setQnty(const int& newQnty);
    
    Datastream Serialize();
    void Load(Datastream *);
    
private:
    
    std::string name = "";
    std::string info = "";    // description of item
    float price;
    int qnty; //quantity

};


#endif /* ITEM_H */

