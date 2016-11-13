#include <iostream>
#include "IntLinkedList.h"

IntLinkedList::Node::Node(int _a) {
  //Node* newnode = new Node;
  this->value = _a;
  this->next = nullptr;
  this->prev = nullptr; // if head?
  //this->prev = &newnode;
  //delete newnode;
}

void IntLinkedList::Node::setValue(int value) {
  this->value = value;
}

void IntLinkedList::Node::setNext(Node* ptr) {
  this->next = ptr;
}

void IntLinkedList::Node::setPrev(Node* ptr) {
  this->prev = ptr;
}

int IntLinkedList::Node::getValue() {
  return this->value;
}

IntLinkedList::Node* IntLinkedList::Node::getNext() {
  return this->next;
}

IntLinkedList::Node* IntLinkedList::Node::getPrev() {
  return this->prev;
}

IntLinkedList::Node::~Node() {
  delete next;
  delete prev;
}

IntLinkedList::IntLinkedList(int _a) {
  this->head = new Node(_a);
}

IntLinkedList::~IntLinkedList() {
  Node* temp = head;
  Node* temp2;
  while (temp->getNext() != 0) {
    temp2 = temp->getNext();
    temp->setNext(temp2->getNext());
    delete temp2;
  }
  delete temp;
}

int IntLinkedList::getFirst() { 
  return head->getValue(); 
}

int IntLinkedList::getLast() {
  Node* temp = head;
  while (temp->getNext() != nullptr) {
    temp = temp->getNext();
  }
  temp = temp->getPrev();
  return temp->getValue();
}

IntLinkedList::Node* IntLinkedList::getLastPtr() {
  Node* temp = head;
  while (temp->getNext() != nullptr) {
    temp = temp->getNext();
  }
  return temp;
}

IntLinkedList::Node* IntLinkedList::getFirstPtr() {
  return this->head;
}

void IntLinkedList::append(int _a) {
  Node* newnode = new Node(_a);
  Node* temp = head;
  while (temp->getNext() != nullptr) {
    temp = temp->getNext();
  }
  temp->setNext(newnode);
  newnode->setPrev(temp);
  IntList::setLength(IntList::getLength() + 1);
}

IntLinkedList::Node* IntLinkedList::ListPtrAt(int _idx) {
  Node* temp = this->head;
  for (int i = 0; i <= _idx; i++) {
    temp = temp->getNext();
  }
  return temp;
}

void IntLinkedList::insert(int _idx, int _a) {
  int size = IntList::getLength();
  if (_idx > size) {
    std::cout << "The given index is out of range. Nothing to insert.\n";
    return;
  }
  if (_idx == size) {
    append(_a);
    return;
  }
  Node* newnode = new Node(_a);
  if (_idx == 0) {
    Node* temp = head->getNext();
    head->setNext(newnode);
    newnode->setPrev(head);
    newnode->setNext(temp);
    IntList::setLength(IntList::getLength() + 1);
    return; 
  }
  Node* temp = this->ListPtrAt(_idx); 
  newnode->setNext(temp);
  newnode->setPrev(temp->getPrev());
  Node* tempprev = this->ListPtrAt(_idx - 1);
  tempprev->setNext(newnode);
  Node* tempnext = this->ListPtrAt(_idx + 1);
  tempnext->setPrev(newnode);
  IntList::setLength(IntList::getLength() + 1);
}

int IntLinkedList::getLength() {
  Node* temp = head;
  int count = 0;
  while (temp->getNext() != nullptr) {
    temp = temp->getNext();
    count++;
  }
  return count;
}

bool IntLinkedList::isEmpty() {
  if (getLength() == 1) {
    return true;
  }
  return false;
}

void IntLinkedList::printList() {
  Node* temp = head;
  for (int i = 0; i < getLength(); i++) {
    std::cout << temp->getValue() << " ";
    temp = temp->getNext();
  }
  std::cout << "\n";
}
