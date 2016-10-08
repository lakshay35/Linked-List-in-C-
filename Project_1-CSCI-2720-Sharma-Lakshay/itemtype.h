/*
Author: Lakshay Sharma
Class: itemtype.h
Instructor: Victor Lawson
Description: Defines prototypes for the itemtype.cpp file
Date: Septermber 22nd 2016
*/

#include <fstream>

enum RelationType {LESS, EQUAL, GREATER};

class ItemType {
  public:                       //public methods
    ItemType();
    RelationType comparedTo(std::string);
    void setTitle(std::string);
    std::string getTitle();
  private:                      //private properties
    int value;
    std::string title;
};
