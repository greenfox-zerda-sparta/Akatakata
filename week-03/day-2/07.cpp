#include <string>
#include <iostream>

using namespace std;

// Create a struct called IntBuffer
// It should store:
// A pointer that points to a dynamically allocated array of ints (could be null)
// The length of the array
struct IntBuffer {
  int length;
  int* array;
};

// Create a function that returns a dynamically allocated IntBuffer
// (the buffer itself should be allocated as well, not just the array inside)
// It should take a normal array and it's length as argument, and it should
// fill all the buffer values from the array
IntBuffer* fill_intBuffer(int arr[], int size) {
  IntBuffer* new_buffer = new IntBuffer;
  new_buffer->length = size;
  new_buffer->array = new int[size];
  for (int i = 0; i < size; i++) {
    new_buffer->array[i] = arr[i];
  }
  return new_buffer;
}

// Create a function that resizes an IntBuffer, it should take an IntBuffer
// as reference and change that buffers length and reallocate it's array as well. (copying it's values)
void resize(IntBuffer& buffer, int new_size) {
  buffer.length = new_size;
  int* new_array = new int[new_size];
  for (int i = 0; i < buffer.length; i++) {
    new_array[i] = buffer.array[i];
  }
  delete[] buffer.array;
  buffer.array = new_array;
}

// Create a function that takes an IntBuffer and returns a new IntBuffer that
// only contains the the even numbers from the old intBuffer
IntBuffer* contains_only_evens(IntBuffer* buffer) {
  IntBuffer* buffer_evens = new IntBuffer;
  buffer_evens->array = new int[buffer->length];
  int index = 0;
  for (int i = 0; i < buffer->length; i++) {
    if (buffer->array[i] % 2 == 0) {
      buffer_evens->array[index] = buffer->array[i];
      index++;
    }
  }
  buffer_evens->length = index;
  return buffer_evens;
}

// Try all the functions in the main function, plase deallocate any buffer
// and the array inside it after using them
void print_buffer(IntBuffer* buffer) {
  for (int i = 0; i < buffer->length; i++) {
    cout << buffer->array[i] << " ";
  }
  cout << endl;
}

int main() {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = 10;
  int new_size = 20;
  IntBuffer* buffer_one = fill_intBuffer(numbers, size);
  cout << "The buffer is: ";
  print_buffer(buffer_one);
  resize(*buffer_one, new_size);
  cout << "Resized: ";
  print_buffer(buffer_one);
  resize(*buffer_one, 10);
  IntBuffer* evens_from_buffer_one = contains_only_evens(buffer_one);
  cout << "Only evens put in new buffer: ";
  print_buffer(evens_from_buffer_one);

  delete[]buffer_one->array;
  delete[]buffer_one;
  delete[]evens_from_buffer_one->array;
  delete[]evens_from_buffer_one;
  buffer_one = nullptr;
  evens_from_buffer_one = nullptr;
  // ha a buffer_one->array is nullptr, akkor behal a vegen. Miert?
  return 0;
}
