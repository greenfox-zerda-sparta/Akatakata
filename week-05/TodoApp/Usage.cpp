#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include "Usage.h"
#include "Task.h"

Usage::Usage() {}

Usage::~Usage() {}

void Usage::show_main_menu(string filename) {
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    cout << line << endl;
  }
}

bool Usage::is_valid_selector(int argc, char* argv[], string filename, Task list) {
  string selector = argv[1];
  if (selector != "-l" && selector != "-a" && selector != "-r" && selector != "-c") {
    cerr << "Unsupported argument.\n";
    return false;
  } else {
    return true;
  }
}

void Usage::print_list(int argc, char* argv[], string filename, Task list) {
  list.print_tasks();
}

void Usage::append(int argc, char* argv[], string filename, Task list) {
  if (argc == 2) {
    cerr << "Unable to add: No task is provided.\n";
  } else {
    string newtask = argv[2];
    list.add_task_to_file(newtask, filename);
  }
}

void Usage::remove(int argc, char* argv[], string filename, Task list) {
  char* digittest = argv[2];
  if (atoi(argv[2]) > list.getLength()) {  
    cout << "Unable to remove : Index is out of bound.\n"; 
  } else if (argc == 2) {
    cerr << "Unable to remove: No index is provided.\n";
  } else if (argc > 2 && !isdigit(*digittest)) {
    cerr << "Unable to remove: Index is not a number.\n";
  } else {
    list.remove_task(atoi(argv[2]), filename);
  }
}

void Usage::check(int argc, char* argv[], string filename, Task list) {
  char* digittest = argv[2];
  if (argc == 2) {
    cerr << "Unable to check: No index is provided.\n"; 
  } else if (atoi(argv[2]) > list.getLength()) {
    cerr << "Unable to check : Index is out of bound.\n"; 
  } else if (argc > 2 && !isdigit(*digittest)) { 
    cerr << "Unable to check: Index is not a number.\n";
  }
  else {
    list.check_task(atoi(argv[2]), filename);
  }
}