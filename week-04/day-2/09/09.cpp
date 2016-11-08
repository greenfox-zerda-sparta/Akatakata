#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main() {
  Student student1 = Student(5);

  student1.add_grade(1);
  student1.add_grade(3);
  student1.add_grade(4);
  student1.add_grade(2);
  student1.add_grade(1);
  student1.add_grade(2);

  cout << "Student1 average: " << student1.get_average() << endl;

  return 0;
}
