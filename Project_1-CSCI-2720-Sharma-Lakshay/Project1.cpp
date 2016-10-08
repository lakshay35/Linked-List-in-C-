/*
Author: Lakshay Sharma
Class: Project1.cpp
Instructor: Victor Lawson
Description: File that executes program using the main method.
Date: Septermber 22nd 2016
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <stdio.h>

// this header contains the unsorted array structures
#include "sorted.h"

int main()
{
  std::ifstream inFile;
  std::string inFileName;     // input file external name
  std::string command;        // operation to be executed
  std::string input;

  ItemType item;
  ItemType* item1 = new ItemType();
  SortedType list[26];
  bool found;
  std::cout << "Enter name of input command file; press return." << std::endl;
  std::cin  >> inFileName;
  inFile.open(inFileName.c_str());

  while (command != "Quit")       //Loop to iterate through input file
  {
    inFile >> command;
    if (command == "PutItem") {             //PutItem
      inFile >> input;
      list[(toupper(input[0])) - 65].putItem(input);
      std::cout << input << " Has Been Added\n";
    }
    else if (command == "GetLength") {        //GetLength
      inFile >> input;
      std::cout << "Length Of " << input << " Is " << list[(toupper(input[0])) - 65].getLength() << std::endl;
    }
    else if (command == "DeleteItem") {       //DeleteItem
      inFile >> input;
      list[(toupper(input[0])) - 65].deleteItem(input);
      std::cout << input << " Has Been Deleted\n";
    }
    else if (command == "GetItem") {          //GetItem
      inFile >> input;
      std::string s = list[(toupper(input[0])) - 65].getItem(input);
      if(s == "ERROR: NOT FOUND") {
        std::cout << "ERROR: " << input << " NOT FOUND!";
      } else {
        std::cout << "Here is your item: " << s << std::endl;
      }
    }
    else if (command == "GetNextItem") {      //GetNextItem
      inFile >> input;
      std::string s1 = list[(toupper(input[0])) - 65].getNextItem();
      if(s1 == "error") {
        std::cout << "Error no pointer found." << std::endl;
      } else {
        std::cout << "Here s the item the next address points to: " << s1 << std::endl;
      }
    }
    else if (command == "GetLength") {        //GetLength
      inFile >> input;
      int length = list[(toupper(input[0])) - 65].getLength();
      std::cout << "Length of " << input << " is " << length << std::endl;
    }
    else if (command == "IsFull") {           //IsFull
      if(SortedType::isFull()) {
          std::cout << "Memory Is Not Full\n";
      } else {
        std::cout << "Memory Is Full\n";
      }
    }
    else if (command == "MakeEmpty") {          //MakeEmpty
      for(int i = 0; i < 26; i++){
        list[i].makeEmpty();
      }
      std::cout << "The List Is Now Empty\n";
    }
	  else if (command == "PrintList") {           //PrintList
      std::cout << "Printing List Now" << std::endl;
      for(int i = 0; i < 26; i++) {
        std::cout << "[" << (char)(65 + i) << "]";
        list[i].printList();
        std::cout << std::endl;
      }
    }
    else if (command == "ResetList") {          //ResetList
      for(int i = 0; i < 26; i++) {
        list[i].resetList();
      }
      std::cout << "List Has Been Reset\n";
    }
    else if (command == "Quit") {               //Quit
      std::cout << "Program Is Now Quitting. Goodbye!" << std::endl;
    }
	  else {std::cout << "Command Not Recognized." << std::endl;
    }
}
  inFile.close();
  return 0;
};
