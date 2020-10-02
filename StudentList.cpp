/* Author: Allison Delgado
 * Last updated: Oct 1, 2020
 * StudentList is a program that allows the user to create new student files, print current
 * students, delete student files, and quit the program using the commands ADD, PRINT, DELETE, QUIT
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


struct Student {
  char firstName[20]; //max char count for student name is 20
  char lastName[20]; //max char count for last name is 20
  int studentID;
  float GPA;
};


void addStudent(vector<Student> *vptr);
void deleteStudent(vector<Student> *vptr);
void printStudent(vector<Student> *vptr);
void quit();


//add a new student
void addStudent(vector<Student> *vptr){

  Student *student = new Student;
  char firstName[20];
  char lastName[20];
  int id = 0;
  float gpa = 0.00;
  
  //prompt first name
  cout << "Enter first name: " << endl;
  cin.get(firstName, 20);
  cin.get();
  strcpy(student->firstName, firstName); //destination, source

  
  //prompt last name
  cout << "Enter last name: " << endl;
  cin.get(lastName, 20);
  cin.get();
  strcpy(student->lastName, lastName); //destination, source
  
  //prompt student id
  cout << "Enter student id: " << endl;
  cin >> id;
  student->studentID = id;
  
  //prompt GPA
  cout << "Enter GPA: " << endl;
  cin >> gpa;
  student->GPA = gpa;

  //add to vector pointer
  vptr->push_back(*student);
  
  return;
}

//print out existing students
void printStudent(vector <Student> *vptr){


  
  return;
}

//delete an existing student
void deleteStudent(vector <Student> *vptr){


  
  return;
}

void quit(){

  return;
}


int main(){

  //create vectors
  vector<Student> structVtr; //vector of structs type student
  vector<Student> *vptr = &structVtr; //vector pointer to vector of structs of type student  
  
  char command[6]; //6 is max amount of letters for this set of commands ("DELETE")
  char commandChar = 'c';
  cout << "Welcome to Student List. Would you like to hear a list of commands? (Y/N)" << endl;
  cin >> commandChar;
  if (commandChar == 'Y'){
    cout << "To add a new student, type ADD" << endl;
    cout << "To delete an existing student, type DELETE" << endl;
    cout << "To print current students, type PRINT" << endl;
    cout << "To quit the program, type QUIT" << endl;
  }
    cout << "Enter a command." << endl;
    cin.get(command, 6);
    cin.get();
    
    //format to all uppercase
    for (int i = 0; i < strlen(command); i++){
      command[i] = toupper(command[i]);
    }
    
    while (strcmp(command, "QUIT") != 0){ //while command is not quit...
      if (strcmp(command, "ADD") == 0){
	addStudent(vptr);
      }
      else if (strcmp(command, "PRINT") == 0){
	printStudent(vptr);
      }
      else if (strcmp(command, "DELETE") == 0){
	deleteStudent(vptr);
      }
    }
    //terminate program (command = QUIT)
    quit();
    return 0;
}
