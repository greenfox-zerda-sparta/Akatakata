#include "ErrorList.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

ErrorList::ErrorList() {
  errors = {};
}

void ErrorList::read_from_file(string filename) {
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    add_error(line);
  }
  my_file.close();
}

void ErrorList::add_error(string err) {
  errors.push_back(err);
}

string ErrorList::error_by_index(int index) {
  return errors[index];
}

int ErrorList::get_length() {
  return errors.size();
}

ErrorList::~ErrorList()
{
}

