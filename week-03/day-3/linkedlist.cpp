#include <iostream>

using namespace std;

struct Node {
  double value;
  Node* ptr_next;
};

Node* list_construct_one(double value);
unsigned int list_length(Node& head);
Node* list_get_last(Node& head);
void list_append(Node* head, double value);
Node* list_at(Node& head, unsigned int index);
void list_insert(Node& head, unsigned int index, double value);
void display(Node* head);
unsigned int list_find(Node& head, double value);
void list_remove(Node& head, double value);
void list_concat(Node& head, Node& other_list);

int main() {
  double head_value = 1;
  double arr[5] = {2, 3, 4, 5, 6};
  Node* headnode = list_construct_one(head_value);
  cout << "Headnode is created. The list now: ";
  display(headnode);
  cout << "Head node value: " << headnode->value << ", ptr_next: " << headnode->ptr_next << endl;
  list_construct_one(head_value);

  for (int i = 0; i < 5; i++) {
      list_append(headnode, arr[i]);
  }
  cout << "The list after adding elements: ";
  display(headnode);
  cout << "List length: " << list_length(*headnode) << endl;

  Node* last = list_get_last(*headnode);
  cout << "Last element pointer: " << last << endl;

  cout << "Node (not its value) at index 3: " << list_at(*headnode, 3) << endl;

  list_insert(*headnode, 3, 1111);
  cout << "Inserted 111 at index 3:" << endl;
  display(headnode);
  cout << "Now node (not its value) at index 3: " << list_at(*headnode, 3) << endl;

  cout << "Find 111 in the list (at index):" << list_find(*headnode, 111) << endl;
  cout << "Find 29 in the list (at index):" << list_find(*headnode, 29) << endl;

  /* LIST FIND IS BROKEN, SO THIS WONT WORK
   list_remove(*headnode, 111);
  cout << "Removing 111: ";
  display(headnode);*/

  delete headnode;
  delete last;
  return 0;
}

Node* list_construct_one(double value) {
  Node* node = new Node;
  node->value = value;
  node->ptr_next = nullptr;
  return node;
}

unsigned int list_length(Node& head) {
  unsigned int counter = 0;
  Node* pointer = &head;
  while (pointer != nullptr) {
    counter++;
    pointer = pointer->ptr_next;
  }
  return counter;
}

Node* list_get_last(Node& head) {
  Node* pointer = head.ptr_next;
  while (pointer != 0) {
    pointer = pointer->ptr_next;
  }
  return pointer;
}

void list_append(Node* head, double value) {
  Node* newnode = list_construct_one(value);
  while(head->ptr_next != nullptr) {
    head = head->ptr_next;
  }
  head->ptr_next = newnode;
}

Node* list_at(Node& head, unsigned int index) {
  Node* pointer = &head;
  for (unsigned int i = 0; i < index; i++) {
    pointer = pointer->ptr_next;
  }
  return pointer;
}

void list_insert(Node& head, unsigned int index, double value) {
  Node* previous = list_at(head, index - 1);
  Node* next = previous->ptr_next;
  previous->ptr_next = list_construct_one(value);
  previous->ptr_next->ptr_next = next;
}

void display(Node* head) {
  Node *node = head;
  while(node) {
    cout << node->value << " ";
    node = node->ptr_next;
  }
  cout << endl;
}

// Doesn't give right answer...
unsigned int list_find(Node& head, double value) {
  Node* node = &head;
  for (unsigned int i = 0; i < list_length(head); i++) {
    if (node->value == value) {
      return i;
    }
    node = node->ptr_next;
  }
  return -1;
}

// Doesn't work because of list_find()
void list_remove(Node& head, double value) {
  unsigned int previous_index = list_find(head, value) - 1;
  unsigned int to_remove_index = list_find(head,value);
  Node* previous = list_at(head, previous_index);
  Node* next = head.ptr_next;
  Node* to_remove = list_at(head, to_remove_index);
  delete to_remove;
  previous->ptr_next = next;
}

void list_concat(Node& head, Node& other_list) {
  Node* last_node = list_get_last(head);
  last_node->ptr_next = &other_list;
}
