#pragma once
#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H
#include "IntList.h"

class IntLinkedList : public IntList {
private:
  class Node {
  private:
    int value;
    Node* next;
    Node* prev;
  public:
    Node(int _a);
    void setValue(int value);
    void setNext(Node* ptr);
    void setPrev(Node* ptr);
    int getValue();
    Node* getNext();
    Node* getPrev();
    ~Node();
  };
  Node* head;
public:
  IntLinkedList(int _a);
  ~IntLinkedList();
  int getFirst();
  int getLast();
  Node* getLastPtr();
  Node* getFirstPtr();
  Node* ListPtrAt(int _idx);
  void append(int _a);
  void insert(int _idx, int _a);
  int getLength();
  bool isEmpty();
  void printList();
};
#endif