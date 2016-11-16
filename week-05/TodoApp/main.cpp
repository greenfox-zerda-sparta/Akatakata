#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"

using namespace std;

void show_main_menu(string filename);

int main(int argc, char* argv[]) {
  Task tasklist;
  tasklist.read_from_file("todolist.txt");

  if (argc == 1) {
    show_main_menu("main_menu.txt");
  } else if (argc > 1) {

    string selector = argv[1];

    if (selector == "-l") {
      tasklist.print_tasks();
    } 
    else if (selector == "-a") {
      if (argc < 3) {
        cerr << "Unable to add: No task is provided" << endl;
      } else {
        string newtask = argv[2];
        tasklist.create_new_task(newtask);
        tasklist.add_task_to_file(newtask, "todolist.txt");
      }
    } 
    else if (selector == "-r") {
      int to_remove = stoi(argv[2]);
      tasklist.remove_task(to_remove);
      tasklist.update_storage_file("todolist.txt");
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