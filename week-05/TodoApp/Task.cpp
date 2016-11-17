#include "Task.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Task::Task() {
  tasks = {};
}

Task::~Task() {
}

void Task::create_new_task(string task_to_add) { // adding from file to vector
  tasks.push_back(task_to_add);
}

void Task::remove_task(int number, string filename) { // removes from vector, needs to update file
  tasks.erase((tasks.begin() + number - 1));
  update_storage_file(filename);
}

void Task::check_task(int number, string filename) {
  if (tasks[number - 1].at(1) == 'x') {
    tasks[number - 1].at(1) = ' ';
  }
  else {
    tasks[number - 1].at(1) = 'x';
  }
  update_storage_file(filename);
}

void Task::print_tasks() {
  if (tasks.empty()) {
    cout << "No todos for today! :)" << endl;
  } else {
    for (unsigned int i = 0; i < tasks.size(); i++) {
      cout << i + 1 << " - " << tasks[i] << endl;
    }
  }
}

void Task::add_task_to_file(string task, string filename) { // adds to file and vector too
  tasks.push_back("[ ] " + task);
  update_storage_file(filename);
}

void Task::read_from_file(string filename) {
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    create_new_task(line);
  }
  my_file.close();
}

void Task::update_storage_file(string filename) {
  ofstream my_file;
  my_file.open(filename, ios::out | ios::trunc); // clear contents
  for (unsigned int i = 0; i < tasks.size(); i++) {
    my_file << tasks[i] << endl;
  }
  my_file.close();
}

int Task::getLength() {
  return tasks.size();
}