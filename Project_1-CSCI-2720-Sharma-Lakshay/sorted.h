/*
Author: Lakshay Sharma
Class: sorted.h
Instructor: Victor Lawson
Description: Defines the prototypes for the sorted.cpp file
Date: Septermber 22nd 2016
*/

#include "itemtype.h"

struct NodeType {
  ItemType info;
  NodeType* next;
};

class SortedType {
  public:                 //public methods
    SortedType();
    static bool isFull();
    int getLength() const;
    void makeEmpty();
    std::string getItem(std::string);
    void putItem(std::string);
    void deleteItem(std::string);
    void resetList();
    std::string getNextItem();
    void printList();
    ~SortedType();
  private:              //private properties
    NodeType* listData;
    int length;
    NodeType* currentPos;

};
