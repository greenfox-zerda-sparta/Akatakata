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
    usage.select_usage();
  }
  return 0;
}
