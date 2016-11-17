#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"
#include "ErrorList.h"

using namespace std;

void show_main_menu(string filename);

int main(int argc, char* argv[]) {
  // BEING REFACTORED - error messages first.
  // do not use these if-s, find something else

  Task tasklist;
  tasklist.read_from_file("todolist.txt");
  ErrorList errors;
  errors.read_from_file("errorlist.txt");

  if (argc == 1) {
    show_main_menu("main_menu.txt");
  } 
  else if (argc > 1) {

    string selector = argv[1];

    if (selector == "-l") {
      tasklist.print_tasks();
    } 
    else if (selector == "-a") {
      if (argc < 3) {
        cerr << errors.error_by_index(0) << endl;
      } else {
        string newtask = argv[2];
        tasklist.add_task_to_file(newtask, "todolist.txt");
      }
    } 
    else if (selector == "-r") {
      if (argc < 3) {
        cerr << errors.error_by_index(1) << endl;
      }
      else if (atoi(argv[2]) > errors.get_length()) {
        cerr << errors.error_by_index(2) << endl;
      }
      else {
        char* digittest = argv[2];
        if (!isdigit(*digittest)) {
          cerr << errors.error_by_index(3) << endl;
        }
        else {
          tasklist.remove_task(atoi(argv[2]), "todolist.txt");
        }
      }
    }
    else if (selector == "-c") {
      if (argc < 3) {
        cerr << errors.error_by_index(5) << endl;
      }
      else if (atoi(argv[2]) > errors.get_length()) {
        cerr << errors.error_by_index(6) << endl;
      }
      else {
        char* digittest = argv[2];
        if (!isdigit(*digittest)) {
          cerr << errors.error_by_index(7) << endl;
        }
        else {
          tasklist.check_task(atoi(argv[2]), "todolist.txt");
        }
      }
    }
    else {
      cout << errors.error_by_index(4) << endl;
    }
  }
  return 0;
}

void show_main_menu(string filename) {
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    cout << line << endl;
  }
}