#include <iostream>
#include <string>
using namespace std;

// Illustrating how constructors work when inheriting
// Write proper destructors for these classes.
// Play around with constructors.

class ParentClass {
  private:
    string* mParentString;
  public:
    ParentClass(string _str);
    string getText();
    virtual ~ParentClass();
};

ParentClass::ParentClass(string _str) {
  this->mParentString = new string(_str);
}

string ParentClass::getText() {
  return string(*mParentString);
}

ParentClass::~ParentClass() {
  cout << "deleting mParentString" << endl;
  delete mParentString;
}

class ChildClass : public ParentClass {
  private:
    string* mChildString;
  public:
    ChildClass(string _pstr, string _str);
    string getChildText();
    virtual ~ChildClass();
};

ChildClass::ChildClass(string _pstr, string _str) : ParentClass(_pstr) {
  mChildString = new string(_str);
}

string ChildClass::getChildText() {
  return string(*mChildString);
}

ChildClass::~ChildClass() {
  cout << "deleting mChildString" << endl;
  delete mChildString;
}

int main() {
  ChildClass* a = new ChildClass("text for parent", "child text");
  cout << a->getText() << "  ||  " << a->getChildText() << endl;
  ParentClass* b = new ChildClass("text for parent", "child text");
  cout << b->getText() << "  ||  " << ((ChildClass*)b)->getChildText() << endl;
  delete a;
  delete b;
  return 0;
}

