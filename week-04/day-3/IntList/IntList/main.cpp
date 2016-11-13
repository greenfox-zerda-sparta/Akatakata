// Take the attached hpp and cpp files. Read them trough.
// Choose either IntArrayList or IntLinkedList and implement it.
// Write code here in a main function that uses it and tests it in edge cases as well.
#include <iostream>
#include "IntList.h"
#include "IntArrayList.h"
#include "IntLinkedList.h"

using namespace std;

int main() {
  IntList* theList = new IntArrayList; //Your code starts here!
  cout << "ARRAY LIST" << endl;
  // INT ARRAY LIST
  IntList* emptyList = new IntArrayList;
  theList->setLength(12);
  cout << "List length: " << theList->getLength() << endl;
  int numbers[5] = { 1, 2, 3, 4, 5 };
  ((IntArrayList*)theList)->setArray(numbers, 5);
  ((IntArrayList*)theList)->printArray();
  cout << "Appending numbers..." << endl;
  int numbers2[5] = { 6, 7, 8, 9, 10 };
  for (int i = 0; i < 5; i++) { // adding elements to check if list length will be increased
    ((IntArrayList*)theList)->append(numbers2[i]); 
  }
  ((IntArrayList*)theList)->printArray(); 
  cout << "List length now :" << theList->getLength() << endl; // List length should be doubled (24)
  cout << "First element: " << ((IntArrayList*)theList)->getFirst() << endl;
  cout << "First element of an empty list: " << ((IntArrayList*)emptyList)->getFirst() << endl;
  cout << "Last element: " << ((IntArrayList*)theList)->getLast() << endl;
  cout << "Last element of an empty list: " << ((IntArrayList*)emptyList)->getLast() << endl;
  cout << "Inserting 1000 at index 4: " << endl;
  ((IntArrayList*)theList)->insert(4, 10000);
  ((IntArrayList*)theList)->printArray();
  cout << "Trying to insert to non-existent place in the list: ";
  ((IntArrayList*)theList)->insert(34, 10000);
  cout << "List length now :" << theList->getLength() << endl;
  cout << endl;

  // INT LINKED LIST
  cout << "LINKED LIST" << endl;
  IntList* LinkedList = new IntLinkedList(0);
  for (int i = 0; i < 5; i++) { 
    ((IntLinkedList*)LinkedList)->append(numbers[i]);
  }
  ((IntLinkedList*)LinkedList)->printList();
  cout << "Appending numbers..." << endl;
  for (int i = 0; i <= 5; i++) { 
    ((IntLinkedList*)LinkedList)->append(numbers2[i]);
  }
  ((IntLinkedList*)LinkedList)->printList(); 
  cout << "List length now :" << LinkedList->getLength() << endl;
  cout << "First element: " << ((IntLinkedList*)LinkedList)->getFirst() << endl;
  cout << "Last element: " << ((IntLinkedList*)LinkedList)->getLast() << endl;
  cout << "Inserting 1000 at index 4: " << endl;
  ((IntLinkedList*)LinkedList)->insert(4, 10000);
  ((IntLinkedList*)LinkedList)->printList();
  cout << "Trying to insert to non-existent place in the list: ";
  ((IntLinkedList*)LinkedList)->insert(34, 10000);
  cout << "List length now :" << LinkedList->getLength() << endl;
  return 0;
}
