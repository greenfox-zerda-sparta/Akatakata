#include <iostream>
#include <math.h>

using namespace std;

struct Stack {
  int size;
  double* array;
  int array_size;
};

int closest_upper_power_two(int array_size) {
  int index = 0;
  while(array_size != 0) {
    array_size /= 2;
    index++;
  }
  if (index < 4) {
    index = 4;
  }
  int size = pow(2, index);
  return size;
}

Stack* stack_construct(double input[], int size);

void stack_push(Stack& stack, double value);

double stack_pop(Stack& stack);

int main() {
  double my_input[] = {2, 3, 4, 5, 6, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3};
  int length = sizeof(my_input) / sizeof(double);

  Stack* mystack = stack_construct(my_input, length);
  cout << "Second element of stack: " << mystack->array[1] << endl;
  cout << "Stack size: " << mystack->size << ", array size: " << mystack->array_size << endl;

  stack_push(*mystack, 31);
  cout << "Stack after pushing 31: ";
  for (int i = 0; i < length + 1; i++) {
    cout << mystack->array[i] << " ";
  }

  int popped = stack_pop(*mystack);
  cout << endl << "Pop: " << popped << endl;

  delete[] mystack;
  mystack = nullptr;
  return 0;
}

Stack* stack_construct(double input[], int size) {
  Stack* newstack = new Stack;
  newstack->size = size;
  newstack->array_size = closest_upper_power_two(size);
  newstack->array = new double[newstack->array_size];
  for (int i = 0; i < size; i++) {
    newstack->array[i] = input[i];
  }
  return newstack;
}

void stack_push(Stack& stack, double value) {
  stack.size++;
  stack.array[stack.size - 1] = value;
  if (stack.size >= stack.array_size * 0.8) {
    stack.array_size *= 2;
    double* new_array = new double[stack.array_size];
    for (int i = 0; i < stack.size; i++) {
      new_array[i] = stack.array[i];
    }
    delete[] stack.array;
    stack.array = new_array;
  }
}

double stack_pop(Stack& stack) {
  double to_pop = stack.array[stack.size - 1];
  stack.size--;
  return to_pop;
}
