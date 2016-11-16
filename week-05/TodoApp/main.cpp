#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void show_main_menu(string filename) {
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    cout << line << endl;
  }
}

void print_todos(string filename) {
  ifstream my_file;
  my_file.open(filename);
  string line;
  int count = 1;
  while (getline(my_file, line)) {
    cout << count << " - " << line << endl;
    count++;
  }
  my_file.close();
}

void add_task(string task) {
  ofstream my_file;
  my_file.open("todolist.txt", ios::app);
  my_file << endl << task;
  cout << task << " is added to your todo list. Check it by entering todo -l." << endl;
  my_file.close();
}


int main(int argc, char* argv[]) {
  if (argc == 1) {
  show_main_menu("main_menu.txt");
  }

  if (argc == 2) {
    string selector = argv[1];
    if (selector == "-l") {
      print_todos("todolist.txt");
    }
  }

  
  string selector = argv[1];
  
  if (selector == "-a") {
    string newtask = argv[2];
    add_task(newtask);
  }


  return 0;
}
