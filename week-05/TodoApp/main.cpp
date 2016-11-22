#include "Task.h"
#include "Usage.h"

using namespace std;

int main(int argc, char* argv[]) {
  Task tasklist;
  tasklist.read_from_file("todolist.txt");

  Usage usage(argc, argv, "todolist.txt", tasklist);
  usage.start();

  return 0;
}
