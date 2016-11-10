#include <iostream>
#include <string>
using namespace std;

// Create a class called ParentClass. It should have two public functions. Both return a string.
// One virtual, the other not.
// Each should return a unique string.
// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the nonvirtual one both.
// These should return unique string again.
//
// Create a main() function. In this function, create a ParentClass* pointer and
// instanciate a ChildClass member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
// Print out the result of both functions on this a ponter.
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*
//

class ParentClass {
  public:
    ParentClass();
    virtual ~ParentClass();
    virtual string return_v_string();
    string return_string();
};

ParentClass::ParentClass() {}

string ParentClass::return_v_string() {
  return "This is the virtual string return.";
}

string ParentClass::return_string() {
  return "It's the non-virtual string return here.";
}

ParentClass::~ParentClass() {}

class ChildClass: public ParentClass {
  public:
    ChildClass();
    virtual ~ChildClass();
    virtual string return_v_string();
    string return_string();
};

ChildClass::ChildClass() {}

ChildClass::~ChildClass() {}

string ChildClass::return_v_string() {
  return "OVERWRITTEN virtual string return function";
}

string ChildClass::return_string() {
  return "OVERWRITTEN non-virtual string return function";
}

int main() {
  ParentClass* a = new ChildClass();
  cout << "As ParentClass*" << endl;
  cout << a->return_v_string() << endl << a->return_string() << endl;
  cout << "       The non-virtual function is not overwritten." << endl;
  cout << endl << "As ChildClass*" << endl;
  cout <<((ChildClass*)a)->return_v_string() << endl << ((ChildClass*)a)->return_string() << endl;
  cout << "       Both are overwritten. o.O" << endl;
  return 0;
}
