// #pragma once
#ifndef TASK_H
#define TASK_H
#include <vector>
#include <string>

using namespace std;

class Task {
public:
  Task();
  ~Task();
  void create_new_task(string task_to_add);
  void remove_task(int number);
  void add_task_to_file(string task, string filename);
  void print_tasks();
  void read_from_file(string filename);
  void update_storage_file(string filename);
private:
  vector<string> tasks;
};

#endif // !"TASK_H"