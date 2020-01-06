//define
#ifndef STUDENT_H
#define STUDENT_H
//imports
#include <iostream>
#include <cstring>

using namespace std;

class Student { //student class
 public:
  Student(const char*, int, float); //constructor with name
  ~Student(); //destructor
  char* getName(); //returns name of student
  void setName(char* newname); //set name of student
  int getID();
  float getGPA();
 private:
  char* name = new char[50]; //name
  int id;
  float gpa;
};

#endif
