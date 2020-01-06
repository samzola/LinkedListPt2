/*
Author: Peter Jin
Date: 12/3/2019
Node Class Header
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node {

 public:

  //Constructor
  Node(Student*);

  //Set Value of node
  void setStudent(Student*);

  //Set pointer to next node
  void setNext(Node*);

  //Get pointer to next node
  Node* getNext();

  //Get Student
  Student* getStudent();
  
  //Destructor
  ~Node();

 private:

  Student* value;
  Node* next;

};

#endif
