#include "Task.h"
#include <fstream>
#include <vector>
#include <iostream>

Task::Task() {
  tasks = {};
}

Task::~Task() {
}

void Task::create_new_task(string task_to_add) {
  tasks.push_back(task_to_add);
}

void Task::remove_task(int number) {
  tasks.erase((tasks.begin() + number - 1));
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

void Task::add_task_to_file(string task, string filename) {
  ofstream my_file;
  my_file.open(filename, ios::app);
  my_file << task << endl;
  my_file.close();
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