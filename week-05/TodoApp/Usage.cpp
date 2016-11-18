#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include "Usage.h"
#include "Task.h"

Usage::Usage(int argc, char* argv[], string filename, Task list) {
  this->argc = argc;
  this->argv = argv;
  this->filename = filename;
  this->list = list;
}

Usage::~Usage() {}

void Usage::start() {
  if (argc == 1) {
    show_main_menu("main_menu.txt");
  } else if (argc > 1) {
    select_usage();
  }
}

void Usage::show_main_menu(string filename) {
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    cout << line << endl;
  }
}

void Usage::select_usage() {
  is_valid_selector();
  string selector = argv[1];
  if (selector == "-l") {
    print_list();
  }
  else if (selector == "-a") {
    append();
  }
  else if (selector == "-r") {
    remove();
  }
  else if (selector == "-c") {
    check();
  }
}

bool Usage::is_valid_selector() {
  string selector = argv[1];
  if (selector != "-l" && selector != "-a" && selector != "-r" && selector != "-c") {
    cerr << "Unsupported argument.\n";
    return false;
  } else {
    return true;
  }
}

void Usage::print_list() {
  list.print_tasks();
}

void Usage::append() {
  if (argc == 2) {
    cerr << "Unable to add: No task is provided.\n";
  } else {
    string newtask = argv[2];
    list.add_task_to_file(newtask, filename);
  }
}

void Usage::remove() {
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

void Usage::check() {
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