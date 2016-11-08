#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
};

int main() {
  // Create a new instace of the Student class and set it's name to "John" and
  // it's age to 21
  Student student_1;
  student_1.name = "John";
  student_1.age = 21;

  cout << student_1.name << " is "  << student_1.age << endl;
  return 0;
}
