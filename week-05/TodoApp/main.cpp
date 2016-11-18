#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"
#include "Usage.h"

using namespace std;

int main(int argc, char* argv[]) {
  Task tasklist;
  tasklist.read_from_file("todolist.txt");
  Usage usage;
  
  if (argc == 1) {
    usage.show_main_menu("main_menu.txt");
  } else if (argc > 1) {
    usage.is_valid_selector(argc, argv, "todolist.txt", tasklist);
    string selector = argv[1];
    if (selector == "-l") {
      usage.print_list(argc, argv, "todolist.txt", tasklist);
    } else if (selector == "-a") {
      usage.append(argc, argv, "todolist.txt", tasklist);
    } else if (selector == "-r") {
      usage.remove(argc, argv, "todolist.txt", tasklist);
    } else if (selector == "-c") {
      usage.check(argc, argv, "todolist.txt", tasklist);
    }
  }
  return 0;
}
