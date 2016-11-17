#include "Error.h"
#include "ErrorList.h"
#include "Task.h"

using namespace std;

Error::Error() {}

Error::~Error() {}

string Error::find_argument_error(int number, char* _input[], Task list) {
  if (number > 1) {
    if (_input[1] != "-l" || _input[1] != "-a" || _input[1] != "-r" || _input[1] != "-c") {
      return "Unsupported argument.\n";
    }
  }
}

string Error::find_nothing_to_add_error(int number, char* _input[], Task list) {
  if (number == 2 && _input[1] == "-a") {
    return "Unable to add: No task is provided.\n";
  }
}

string Error::find_no_index_error_remove(int number, char* _input[], Task list) {
  if (number == 2 && _input[1] == "-r") {
    return "Unable to remove: No index is provided.\n";
  }
}

 string Error::find_isdigit_error_remove(int number, char* _input[], Task list) {
  char* digittest = _input[2];
  if (number == 3 && _input[1] == "-r" && !isdigit(*digittest)) {
    return "Unable to remove: Index is not a number.\n";
  }
}

 string Error::find_out_of_bound_error_remove(int number, char* _input[], Task list) {
   if (_input[1] == "-r" && atoi(_input[2]) > list.getLength()) {
     return "Unable to remove : Index is out of bound.\n";
   }
 }

 string Error::find_no_index_error_remove(int number, char* _input[], Task list) {
   if (number == 2 && _input[1] == "-c") {
     return "Unable to check: No index is provided.\n";
   }
 }

 string Error::find_isdigit_error_remove(int number, char* _input[], Task list) {
   char* digittest = _input[2];
   if (number == 3 && _input[1] == "-c" && !isdigit(*digittest)) {
     return "Unable to check: Index is not a number.\n";
   }
 }

 string Error::find_out_of_bound_error_remove(int number, char* _input[], Task list) {
   if (_input[1] == "-c" && atoi(_input[2]) > list.getLength()) {
     return "Unable to check : Index is out of bound.\n";
   }
 }

 string Error::check_for_errors(int number, char* _input[], Task list) {
  find_argument_error(number, _input, list);
  find_nothing_to_add_error(number, _input, list);
  find_no_index_error_remove(number, _input, list);
  find_isdigit_error_remove(number, _input, list);
  find_out_of_bound_error_remove(number, _input, list);
  find_no_index_error_check(number, _input, list);
  find_isdigit_error_check(number, _input, list);
  find_out_of_bound_error_check(number, _input, list);
 }
