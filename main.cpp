/*
 * Author: Sam Zola
 * Date: 12/9/2019
 * Program: This program allows the user to create a linked list of students.
 */

//imports
#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(); //function to add a student
void print(Node* next); //function to print list

Node* head = NULL; //create first node and set to null

int main() {
  bool running = true; //keeps track of if the program is still running
  char* command = new char[10]; //command for add, print, or quit
  while (running == true) { //run this loop while still running
    //ask user to enter a command
    cout << endl << "Please enter a command (add, print, or quit)" << endl;
    cin.getline(command, 30, '\n'); //read in command
    if (strcmp(command, "add") == 0) { //if they enter "add"
      add(); //run add function
    }
    else if (strcmp(command, "print") == 0) { //if they enter "print"
      print(head); //run print function, starting at head
    }
    else if (strcmp(command, "quit") == 0) { //if they enter "quit"
      running = false; //make running false, end program
    }
    else { //if command is invalid, tell user to try again
      cout << "Invalid command. Please try again." << endl;
    }
  }
}

void add() { //function to add a student
  char* name = new char[30]; //char that keeps track of the name
  cout << "Please enter the student's name." << endl; //tell user to enter name
  cin.getline(name, 30, '\n'); //read in name
  int id = 0; //int that keeps track of the id
  cout << "Please enter the student's ID." << endl; //tell user to enter name
  cin >> id;
  cin.clear();
  cin.ignore(1000000, '\n');
  float gpa = 0; //float that keeps track of the GPA
  cout << "Please enter the student's GPA." << endl; //tell user to enter name
  cin >> gpa;
  cin.clear();
  cin.ignore(1000000, '\n');
 
  Student* newStudent = new Student(name, id, gpa); //make a new student with the entered name
  Node* current = head; //make a node, current, equal to the first node
  if (current == NULL) { //if the current node has no student
    head = new Node(newStudent); //make a node with the recently made student
    head->setStudent(newStudent); //set student of the node
  }
  else { //if current node has a student
    while (current->getNext() != NULL) { //when the next node has no student
      current = current->getNext(); //make current the next node
    }
    current->setNext(new Node(newStudent)); //set the recently made student to the empty node
    current->getNext()->setStudent(newStudent); //set student of node
  }
}

void print(Node* next) { //function for printing list
  if (next == head) { //if at beginning of list
    cout << "list: "; //print out "list: "
  }
  if (next != NULL) { //if the node has a student in it
    if (next->getNext() != NULL) { //if the next node has a student in it 
      cout << next->getStudent()->getName() << ", "; //print name of student with comma after
    }
    else if (next->getNext() == NULL) { //if the next node has no student
      cout << next->getStudent()->getName() << " "; //print name of student w/o comma after
    }
    print(next->getNext()); //recursion, keep printing until end of list
  }
}
