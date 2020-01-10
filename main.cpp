/*
 * Author: Sam Zola
 * Date: 12/9/2019
 * Program: This program allows the user to create a linked list of students.
 */

//imports
#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(); //function to add a student
void print(Node* next); //function to print list
void average(Node* next);
void del(Node* next, Node* previous, int id);

Node* head = NULL; //create first node and set to null

int main() {
  bool running = true; //keeps track of if the program is still running
  char* command = new char[10]; //command for add, print, or quit
  while (running == true) { //run this loop while still running
    //ask user to enter a command
    cout << endl << "Please enter a command (add, print, average, delete, or quit)" << endl;
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
    else if (strcmp(command, "average") == 0) {
      average(head);
    }
    else if (strcmp(command, "delete") == 0) {
      int inID = 0;
      if (head == NULL) {
	cout << "There are no students in the list." << endl;
      }
      else {
	cout << "Please enter the ID of the student you would like to delete." << endl;
	cin >> inID;
	cin.clear();
	cin.ignore(1000000, '\n');
	del(head, NULL, inID);
      }
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
  cout << "Please enter the student's ID." << endl; //tell user to enter id
  cin >> id;
  cin.clear();
  cin.ignore(1000000, '\n');
  float gpa = 0; //float that keeps track of the GPA
  cout << "Please enter the student's GPA." << endl; //tell user to enter gpa
  cin >> gpa;
  cin.clear();
  cin.ignore(1000000, '\n'); 
  Student* newStudent = new Student(name, id, gpa); //make a new student with the entered name
  Node* current = head; //make a node, current, equal to the first node
  if (current == NULL) { //if the current node has no student
    head = new Node(newStudent); //make a node with the recently made student
    head->setStudent(newStudent); //set student of the node
  }
  else {
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
      cout << next->getStudent()->getName() << ", " << next->getStudent()->getID() << ", " << next->getStudent()->getGPA() << fixed << setprecision(2) << ", ";
      print(next->getNext());
  }
}

void average(Node* next) {
  int nodeCount = 0;
  float total = 0;
  if (head == NULL) {
    cout << "There are no students in the list." << endl;
  }
  else {
    while (next->getNext() != NULL) {
      cout << next->getStudent()->getGPA() << endl;
      total += next->getStudent()->getGPA();
      nodeCount++;
      next = next->getNext();
    }
    total += next->getStudent()->getGPA();
    nodeCount++;
    float ave = (total/nodeCount);
    cout << "The average GPA is " << fixed << setprecision(2) << ave << endl;
  }
}

void del(Node* next, Node* previous, int id) {
  char* choice = new char[5];
  if (next == head && (next->getStudent()->getID() == id)) {
    cout << endl << next->getStudent()->getName() << endl;
    cout << "Would you like to delete this student?" << endl;
    cin.getline(choice, 4, '\n');
    if ((strcmp(choice, "yes") == 0) || (strcmp(choice, "y") == 0)) {
      cout << "Student deleted." << endl;
      if (next->getNext() == NULL) {
	next->~Node();
	head = NULL;
      }
      else {
	head = next->getNext();
	next->~Node();
	del(head, NULL, id);
      }
    }
    else if ((strcmp(choice, "no") == 0) || (strcmp(choice, "n") == 0)) {
	cout << "Student not deleted." << endl;
    }
    else {
      cout << "Please enter yes or no." << endl;
    }
  }
  else if (next->getStudent()->getID() == id) {
    cout << endl << next->getStudent()->getName() << endl;
    cout << "Would you like to delete this student?" << endl;
    cin.getline(choice, 10, '\n');
    if ((strcmp(choice, "yes") == 0) || (strcmp(choice, "y") == 0)) {
      cout << "Student deleted." << endl;
      previous->setNext(next->getNext());
      next->~Node();
    }
    else if ((strcmp(choice, "no") == 0) || (strcmp(choice, "n") == 0)) {
      cout << "Student not deleted." << endl;
    }
    else {
      cout << "Please enter yes or no." << endl;
    }
  }
}
