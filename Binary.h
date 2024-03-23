/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Binary.h
 * Author: NoahP
 *
 * Created on March 23, 2024, 12:22 AM
 */

#ifndef BINARYFILE_H
#define BINARYFILE_H

#include "MoviesStruct.h"
#include "MovieInfoSturc.h"
#include <string>

class BinaryFile {
public:
    BinaryFile();
    BinaryFile(const BinaryFile& orig);
    virtual ~BinaryFile();
    
   void readBin(const std::string &filename, Movies &movies);
    
   void writeBin(const std::string &filename, const Movies &movies);
    
private:

};

#endif /* BINARYFILE_H */

