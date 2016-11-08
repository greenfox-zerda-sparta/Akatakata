#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

// construct Student
Student::Student(int grade) {
  this->grades.push_back(grade);
}

// a method `add_grade`, that takes a grade from 1 to 5
void Student::add_grade(int grade) {
  grades.push_back(grade);
}

// method `get_average`, that returns the average of the grades
double Student::get_average() {
  double total = 0;
  for (unsigned int i = 0; i < grades.size(); i++) {
    total+= grades[i];
  }
  return total / grades.size();
}



