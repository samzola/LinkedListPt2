/*
 * Author: Sam Zola
 * Date: 1/14/2020
 * Program: This program allows the user to create a linked list of students using another student's node.o and node.h files.
 */

//imports
#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node*&); //function to add a student
void print(Node* next); //function to print list
void average(Node* next); //function that takes the average of all ids
void del(Node*&); //function to delete student from the list

Node* head = NULL; //create first node and set to null

int main() {
  bool running = true; //keeps track of if the program is still running
  char* command = new char[10]; //command for add, print, or quit
  while (running == true) { //run this loop while still running
    //ask user to enter a command
    cout << endl << "Please enter a command (add, print, average, delete, or quit)" << endl;
    cin.getline(command, 30, '\n'); //read in command
    if (strcmp(command, "add") == 0) { //if they enter "add"
      add(head); //run add function
    }
    else if (strcmp(command, "print") == 0) { //if they enter "print"
      print(head); //run print function, starting at head
    }
    else if (strcmp(command, "quit") == 0) { //if they enter "quit"
      running = false; //make running false, end program
    }
    else if (strcmp(command, "average") == 0) { //if they enter "average"
      average(head); //run average function
    }
    else if (strcmp(command, "delete") == 0) { //if they enter "delete
      del(head); //run delete function
    }
    else { //if command is invalid, tell user to try again
      cout << "Invalid command. Please try again." << endl;
    }
  }
}

void add(Node* &head) { //function to add a student
  char* name = new char[15]; //char that keeps track of the name
  cout << "Please enter the student's name." << endl; //tell user to enter name
  cin.getline(name, 30, '\n'); //read in name
  int id = 0; //int that keeps track of the id
  cout << "Please enter the student's ID." << endl; //tell user to enter id
  cin >> id; //read in id
  cin.clear();
  cin.ignore(1000000, '\n');
  float gpa = 0; //float that keeps track of the GPA
  cout << "Please enter the student's GPA." << endl; //tell user to enter gpa
  cin >> gpa; //read in gpa
  cin.clear();
  cin.ignore(1000000, '\n');
  Student* newStudent = new Student(name, id, gpa); //make a new student
  if (head == NULL) { //if the current node has no student
    head = new Node(newStudent); //make a node with the recently made student
    return;
  }
  if (head->getStudent()->getID() > newStudent->getID()) { //if head's id > new student's id 
    Node* temp = head; //make a node with new student AFTER head
    head = new Node(newStudent);
    head->setNext(temp);
    return;
  }
  if (head->getNext() == NULL) { //if there is no student in list after head
    Node* temp = new Node(newStudent); //make a node with new student in the empty spot
    head->setNext(temp);
    return;
  }
  if (head->getNext()->getStudent()->getID() > newStudent->getID()) { //if next id > new student id
    Node* temp = new Node(newStudent); //make a node with new student after next node
    temp->setNext(head->getNext());
    head->setNext(temp);
    return;
  }
  Node* next = head->getNext(); //recursion
  add(next);
}

void print(Node* next) { //function for printing list
  if (next == head) { //if at beginning of list
    cout << "list: "; //print out "list: "
  }
  if (next != NULL) { //if the node has a student in it 
      cout << next->getStudent()->getName() << ", " << next->getStudent()->getID() << ", " << next->getStudent()->getGPA() << fixed << setprecision(2) << ", ";
      print(next->getNext()); //recursion
  }
}

void average(Node* next) {
  int nodeCount = 0;
  float total = 0;
  if (head == NULL) { //if there are no students avg cant be taken
    cout << "There are no students in the list." << endl;
  }
  else { //if there are students
    while (next->getNext() != NULL) {
      cout << next->getStudent()->getGPA() << endl;
      total += next->getStudent()->getGPA(); //add all gpa's
      nodeCount++; //add count of the nodes
      next = next->getNext(); //move through entire list
    }
    total += next->getStudent()->getGPA();
    nodeCount++;
    float ave = (total/nodeCount); //take average
    cout << "The average GPA is " << fixed << setprecision(2) << ave << endl; //display avg
  }
}

void del(Node* &head) {
  int id = 0;
  cout << "Please enter the ID of the student you would like to delete." << endl;
  cin >> id; //ask user to enter ID to delete
  cin.clear(); //read in id
  cin.ignore(1000000, '\n');
  if (head == NULL) { //if no students, tell user
    cout << "Student not found." << endl;
    return;
  }
  if (head->getStudent()->getID() == id) { //if id matches head's id
    Node* temp = head;
    head = head->getNext();
    delete temp;
    cout << "Student deleted." << endl; //delete head
    return;
  }
  if (head->getNext() == NULL) { //if next node is empty, you cant delete
    cout << "Student not found." << endl;
    return;
  }
  if (head->getNext()->getStudent()->getID() == id) { //if next node's id matches
    Node* temp = head->getNext();
    head->setNext(head->getNext()->getNext());
    delete temp;
    cout << "Student deleted." << endl; //delete next node
    return;
  }
  Node* next = head->getNext(); //recursion
  del(next);
}
