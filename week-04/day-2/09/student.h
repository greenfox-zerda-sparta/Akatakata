#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

// Create a student Class
class Student {
  private:
   vector<int> grades;

  public:
    Student(int grade);

    void add_grade(int number);

    double get_average();
};

#endif /* STUDENT_H_ */
