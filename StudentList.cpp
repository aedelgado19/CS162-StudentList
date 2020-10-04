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
void deleteStudent(vector<Student> *vptr, int studentID);
void printStudent(vector<Student> *vptr);
bool isUnique(int id);
void quit();

bool isUnique(int id){
  //checks if student ID entered in addStudent function is unique
  if (id ){
    return false;
  }

  return false;
}

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
    cin.get();
    isUnique(int id);
    if (isUnique == true){
      student->studentID = id;
    } else {
      //error out
      cout << "Error: Student ID already exists." << endl;
      delete student;
      return;
    }
  
  //prompt GPA
  cout << "Enter GPA: " << endl;
  cin >> gpa;
  cin.get();
  student->GPA = gpa;

  //add to vector pointer
  vptr->push_back(*student);
  
  return;
}

//print out existing students
void printStudent(vector <Student> *vptr){
  //learned how iterators work from cplusplus.com
  for(vector<Student>::iterator index = vptr->begin(); index != vptr->end(); ++index){
    cout << "\n" << index->firstName << " " << index->lastName << endl;
    cout << "student ID: " << index->studentID << endl;
    cout << "GPA: " << index->GPA << endl;
  }
  return;
}

//delete an existing student
void deleteStudent(vector <Student> *vptr, int studentID){
  for(vector<Student>::iterator index = vptr->begin(); index != vptr->end(); ++index){
    if (index->studentID == studentID){
      vptr->erase(index);
    }
  }
  
  return;
}

void quit(){

  return;
}


int main(){

  //create vectors
  vector<Student> structVtr; //vector of structs type student
  vector<Student> *vptr = &structVtr; //vector pointer to vector of structs of type student  
  
  char command[7]; //6 is max amount of letters for this set of commands ("DELETE")
  char commandChar = 'c';
  cout << "Welcome to Student List. Would you like to hear a list of commands? (Y/N)" << endl;
  int idnum = 0; //temp variable for student ID
  
  cin >> commandChar;
  cin.get();
  if (commandChar == 'Y'){
    cout << "To add a new student, type ADD" << endl;
    cout << "To delete an existing student, type DELETE" << endl;
    cout << "To print current students, type PRINT" << endl;
    cout << "To quit the program, type QUIT" << endl;
  }
  while (strcmp(command, "QUIT") != 0){ //while command is not quit...
    cout << "Enter a command." << endl;
    cin.get(command, 7);
    cin.get();

    //format to all uppercase
    for (int i = 0; i < strlen(command); i++){
      command[i] = toupper(command[i]);
    }

      if (strcmp(command, "ADD") == 0){
	addStudent(vptr);
      }
      else if (strcmp(command, "PRINT") == 0){
	printStudent(vptr);
      }
      else if (strcmp(command, "DELETE") == 0){
	cout << "Enter the ID number of the student you would like to delete" << endl;
	cin >> idnum;
	cin.get();
	deleteStudent(vptr, idnum);
      }
    }
    //terminate program (command = QUIT)
    quit();
    return 0;
}
