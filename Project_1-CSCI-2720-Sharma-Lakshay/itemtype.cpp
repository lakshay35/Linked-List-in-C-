/*
Author: Lakshay Sharma
Class: itemtype.cpp
Instructor: Victor Lawson
Description: Defines functions that can be used on the data of nodes
Date: Septermber 22nd 2016
*/

#include "itemtype.h"
#include <fstream>

ItemType::ItemType() {
  value = 0;
  title = "";
}

RelationType ItemType::comparedTo(std::string s) {
  if(title < s) {
    return LESS;
  } else if (title > s) {
    return GREATER;
  } else {
    return EQUAL;
  }
}

void ItemType::setTitle(std::string s) {
  title = s;
}

std::string ItemType::getTitle() {
  return title;
}
