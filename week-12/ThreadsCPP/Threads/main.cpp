#include <iostream>
#include <thread>
#include <string>

static const int num_threads = 10;

void call_from_thread();
void cout_things(int num);
void run_or_exit();
void threads();

int main() {

  // use different data structures or barriers (std::mutex) to avoid this mess in output
  //  - mutex: A mutex allows you to lock access to specific resources for one thread only
  //  - semaphore : A way to determine how many users a certain resource still has(= how many threads are accessing it) 
  //                and a way for threads to access a resource. A mutex is a special case of a semaphore.
  //  - critical section : a mutex - protected piece of code(street with only one lane) that can only be travelled by one thread at a time.
  //  - message queue : a way of distributing messages in a centralized queue
  //  - inter - process communication(IPC) - a way of threads and processes to communicate with each other through named pipes, 
  //                                         shared memory and many other ways(it's more of a concept than a special technique)
  threads();
}

void call_from_thread() {
  std::cout << "Hello world! " << std::endl;
}

void cout_things(int num) {
  for (int i = 0; i < num; i++)
    std::cout << "Things " << i + 1 << std::endl;
}

void run_or_exit() {
  std::cout << std::endl;
  std::cout << "Type again for running threads exampe again or quit to quit." << std::endl;
  std::string input;
  std::getline(std::cin, input);
  if (input == "again") {
    threads();
  } else if (input == "quit") {
    std::cout << "Bye!";
  } else {
    run_or_exit();
  }
}

void threads() {
  int times = 5;
  std::thread t0(cout_things, times);
  std::thread t1(call_from_thread); // starts t1 thread
  t1.join(); //join t1 with main
  t0.join();
  std::cout << "================================================\n";

  std::thread t[num_threads];
  for (int i = 0; i < num_threads; i++) {
    t[i] = std::thread(call_from_thread);
  }
  std::cout << "Launched from main" << std::endl;
  for (int i = 0; i < num_threads; i++) {
    t[i].join();
  }
  run_or_exit();
}