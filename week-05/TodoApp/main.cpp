#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"
#include "Usage.h"

using namespace std;

int main(int argc, char* argv[]) {
  Task tasklist;
  tasklist.read_from_file("todolist.txt");
  Usage usage(argc, argv, "todolist.txt", tasklist);
  
  if (argc == 1) {
    usage.show_main_menu("main_menu.txt");
  } else if (argc > 1) {
    usage.is_valid_selector();
    string selector = argv[1];
    if (selector == "-l") {
      usage.print_list();
    } else if (selector == "-a") {
      usage.append();
    } else if (selector == "-r") {
      usage.remove();
    } else if (selector == "-c") {
      usage.check();
    }
  }
  return 0;
}
