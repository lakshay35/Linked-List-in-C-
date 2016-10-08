/*
Author: Lakshay Sharma
Class: sorted.cpp
Instructor: Victor Lawson
Description: library of functions to be used on linked lists
Date: Septermber 22nd 2016
*/

#include "sorted.h"
#include <iostream>

//Constructor for Linked List
SortedType::SortedType() {
  length = 0;
  listData = NULL;
  currentPos = NULL;
}

//Checks if memory is full or not
bool SortedType::isFull() {
  NodeType* node;
  try {
    node = new NodeType;
    delete node;
    return true;
  } catch (std::bad_alloc exception) {
    return false;
  }
}

//Returns the length of a linked list
int SortedType::getLength() const {
  return length;
}

//Returns iteam if found. Else, returns error
std::string SortedType::getItem(std::string s) {
  bool moreToSearch;
  NodeType* location;
  location = listData;
  bool found = false;
  std::string s1;
  moreToSearch = (location != NULL);

  while(moreToSearch && !found) {
    if(s > location->info.getTitle()) {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (s == location->info.getTitle()) {
      found = true;
      s1 = location->info.getTitle();
    }
    else if (s < location->info.getTitle()) {
      moreToSearch = false;
    }
    else {
      s1 = "ERROR: NOT FOUND";
    }
  }
  return s1;
}

//Empties the linked list
void SortedType::makeEmpty() {
  NodeType* tempPtr;
  while(listData != NULL) {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
}

//Adds item to the linked list
void SortedType::putItem(std::string s) {
  NodeType* newNode;
  NodeType* predLoc;
  NodeType* location;
  bool moreToSearch;
  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  while(moreToSearch) {
      if(s > location->info.getTitle()) {
        predLoc = location;
        location = location->next;
        moreToSearch = (location != NULL);
      }
      else {
        moreToSearch = false;
      }
  }
  newNode = new NodeType;
  newNode->info.setTitle(s);
  if(predLoc == NULL) {
    newNode->next = listData;
    listData = newNode;
  } else {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}

//Prints the whole list
void SortedType::printList() {
  NodeType* predLoc;
  NodeType* location;
  bool moreToSearch;
  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  while(moreToSearch) {
      predLoc = location;
      location = location->next;
      std::cout  << "->" << "[" << predLoc->info.getTitle() << "]";
      moreToSearch = (location != NULL);
    }
  }

//Deletes the item from the linked list.
void SortedType::deleteItem(std::string s) {
  NodeType* location = listData;
  NodeType* tempLocation;

  if(s == listData->info.getTitle()) {
    tempLocation = location;
    listData = listData->next;
  } else {
    while((s == ((location->next)->info.getTitle()))) {
      location = location->next;
    }
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;

}

//Resets the list
void SortedType::resetList() {
  currentPos = NULL;
}

//Retrieves next item in linked list
std::string SortedType::getNextItem() {
  std::string s;
  if(currentPos == NULL) {
    currentPos = listData;
  }
  if(length == 0) {
    s = "error";
  } else {
    s = currentPos->info.getTitle();
    currentPos = currentPos->next;
  }
  return s;
}

//Deletes the linked list
SortedType::~SortedType() {
  NodeType* tempPtr;
  while(listData != NULL) {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}
