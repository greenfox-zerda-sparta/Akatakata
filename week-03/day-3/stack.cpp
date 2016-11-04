#include <iostream>

using namespace std;

struct Stack {
  int size;
  double* array;
};

Stack* stack_construct(double input[], int size);

void stack_push(Stack& stack, double value);

double stack_pop(Stack& stack);

bool is_empty2(Stack& stack);

int main() {
  double my_input[] = {2, 3, 4, 5, 6, 7};
  int length = sizeof(my_input) / sizeof(double);

  Stack* mystack = stack_construct(my_input, length);
  cout << "Second element of stack: " << mystack->array[1] << endl;

  stack_push(*mystack, 31);
  cout << "Stack after pushing 31: ";
  for (int i = 0; i < length + 1; i++) {
    cout << mystack->array[i] << " ";
  }

  int popped = stack_pop(*mystack);
  cout << endl << "Pop: " << popped << endl;

  cout << "Is this stack empty? " << is_empty2(*mystack) << endl;

  delete[] mystack;
  return 0;
}

Stack* stack_construct(double input[], int size) {
  Stack* newstack = new Stack;
  newstack->size = size;
  newstack->array = new double[size];
  for (int i = 0; i < size; i++) {
    newstack->array[i] = input[i];
  }
  return newstack;
}

void stack_push(Stack& stack, double value) {
  double* new_array = new double[++stack.size];
  for (int i = 0; i < stack.size; i++) {
    new_array[i] = i < stack.size - 1 ? stack.array[i] : value;
  }
  delete[] stack.array;
  stack.array = new_array;
}

double stack_pop(Stack& stack) {
  double to_pop = stack.array[stack.size - 1];
  double* remaining_array = new double[--stack.size];
  for (int i = 0; i < stack.size; i++) {
    remaining_array[i] = stack.array[i];
  }
  delete[] stack.array;
  stack.array = remaining_array;
  return to_pop;
}

bool is_empty2(Stack& stack) {
  return stack.size == 0;
}
