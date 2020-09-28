/* Author: Allison Delgado
 * Last updated: September 28, 2020
 * StudentList is a program that allows the user to create new student files, print current
 * students, delete student files, and quit the program using the commands ADD, PRINT, DELETE, QUIT
 */

#include <iostream>
using namespace std;

struct Student {
  char firstName[50]; //max char count for student name is 50
  char lastName[50]; //max char count for last name is 50
  int studentID = 0;
  float GPA = 0.00;
};


int main(){
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
    
    while (command != "QUIT"){
      if (command == "ADD"){


      }
      else if (command == "PRINT"){


      }
      else if (command == "DELETE"){


      }
    }
    //terminate program (command = QUIT)

  }
  return 0;
}
