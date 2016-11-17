#include <iostream>

using namespace std;

struct Vector {
  double* array;
  int size; // unsigned int
};

Vector* vector_construct(double input[], int size);

void print_vector(Vector vector, int size);

double vector_at(Vector& v, unsigned int index);

void vector_insert(Vector& v, unsigned int index, double value);

unsigned int vector_find(Vector& v, double value);

void vector_remove(Vector& v, unsigned int index);

Vector* vector_concat(Vector& v1, Vector& v2);

int main() {
  double my_input[] = {2, 3, 4, 5, 6, 7};
  int length = sizeof(my_input) / sizeof(double);
  double my_input2[] = {22, 23, 24};
  int length2 = sizeof(my_input2) / sizeof(double);

  Vector* sample_vector = vector_construct(my_input, length);
  Vector* sample_vector2 = vector_construct(my_input2, length2);
  print_vector(*sample_vector, length);

  cout << "AT: at index 3: " << vector_at(*sample_vector, 3) << endl;
  cout << "AT: at non-existing index: " << vector_at(*sample_vector, 18) << endl;

  vector_insert(*sample_vector, 3, 99);
  cout << "INSERT: See the new number at the 4th place?" << endl;
  print_vector(*sample_vector, length + 1);

  cout << "FIND: 5 is at index(0-7): " << vector_find(*sample_vector, 5) << endl;
  cout << "FIND: 19, which is not in the vector, is at index(0-7): " << vector_find(*sample_vector, 19) << endl;

  vector_remove(*sample_vector, 3);
  cout << "REMOVE: removed 99 from 4th place:" << endl;
  print_vector(*sample_vector, length);

  Vector* thrid_vector = vector_concat(*sample_vector, *sample_vector2);
  int length3 = length + length2;
  cout << "Concated: " << endl;
  print_vector(*thrid_vector, length3);

  delete[] sample_vector;
  delete[] sample_vector2;
  delete[] third_vector;
  sample_vector = nullptr;
  sample_vector2 = nullptr;
  third_vector = nullptr;
  return 0;
}

Vector* vector_construct(double input[], int size) {
  Vector* my_vector = new Vector;
  my_vector->size = size;
  my_vector->array = new double[size]; // could use my_vector->array
  for (int i = 0; i < size; i++) { // same
    my_vector->array[i] = input[i];
  }
  return my_vector;
}

void print_vector(Vector v, int size) {
  for (int i = 0; i < size; i++) {
    cout << v.array[i] << " ";
  }
  cout << endl;
}

double vector_at(Vector& v, unsigned int index) {
  double value_at = -1;
  if (index < v.size) {
    value_at = v.array[index];
  }
  return value_at;
}

void vector_insert(Vector& v, unsigned int index, double value) {
  double* new_array = new double[++v.size];
  for (int i = 0; i < v.size; i++) {
    if (i < index) {
      new_array[i] = v.array[i];
    } else if (i == index) {
      new_array[index] = value;
    } else {
      new_array[i] = v.array[i - 1];
    }
  }
  delete[] v.array;
  v.array = new_array;
}

unsigned int vector_find(Vector& v, double value) {
  unsigned int index = 0;
  for (int i = 0; i < v.size; i++) {
    if (v.array[i] == value) {
      index = i;
      return index;
    }
  }
  return v.size + 1;
}

void vector_remove(Vector& v, unsigned int index) {
  double* remaining_array = new double[v.size--];
  for (int i = 0; i < v.size; i++) {
    if (i >= index) {
      remaining_array[i] = v.array[i + 1];
    } else {
      remaining_array[i] = v.array[i];
    }
  }
  delete[] v.array;
  v.array = remaining_array;
}

Vector* vector_concat(Vector& v1, Vector& v2) {
  int concat_size = v1.size + v2.size;
  double* array = new double[concat_size];
  for (int i = 0; i < concat_size; i++) {
      array[i] = i >= v1.size ? v2.array[i - v1.size] : v1.array[i];
  }
  Vector* concated = vector_construct(array, concat_size);
  return concated;
}
