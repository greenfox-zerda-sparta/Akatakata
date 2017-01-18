using System;

namespace ToDoApp {
  class Arguments {
    private string[] _args;
    private TaskHandler tasks = new TaskHandler();

    public Arguments(string[] args) {
      _args = args;
      string FirstArgument = GetFirstArgument();
      if (FirstArgument == "") {
        PrintUsage();
        return;
      }
      if (FirstArgument == "-l") {
        List();
        return;
      }
      if (FirstArgument == "-a") {
        Add();
        return;
      }
      if (FirstArgument == "-r") {
        Remove();
        return;
      }
      if (FirstArgument == "-c") {
        Check();
        return;
      }
      if (FirstArgument[0] == '-') {
        Console.WriteLine("Unsupported argument.");
        Console.WriteLine();
      }
      Console.WriteLine("Printing Usage...");
    }

    private string GetFirstArgument() {
      string result = "";
      try {
        result = _args[0];
      } catch { }
      return result;
    }

    private void PrintUsage() {
      Console.WriteLine("Printing Usage...");
    }

    private void List() {
      if (_args.Length > 1) {
        Console.WriteLine("Too many arguments.");
        return;
      }
      tasks.PrintList();
    }

    private void Add() {
      if (_args.Length > 2) {
        Console.WriteLine("Too many arguments.");
        return;
      }
      if (_args.Length < 2) {
        Console.WriteLine("No task is provided.");
        return;
      }
      tasks.AddTask(_args[1]);
    }

    private void Remove() {
      if (_args.Length > 2) {
        Console.WriteLine("Too many arguments.");
        return;
      }
      if (_args.Length < 2) {
        Console.WriteLine("No index is provided.");
        return;
      }
      int index;
      try {
        index = Int32.Parse(_args[1]);
      } catch {
        Console.WriteLine("Index is not a number.");
        return;
      }
      Console.WriteLine("Removing item {0}...", index);
      tasks.RemoveTask(Convert.ToInt32(_args[1]));
    }

    private void Check() {
      if (_args.Length > 2) {
        Console.WriteLine("Too many arguments.");
        return;
      }
      if (_args.Length < 2) {
        Console.WriteLine("No index is provided.");
        return;
      }
      int index;
      try {
        index = Int32.Parse(_args[1]);
      } catch {
        Console.WriteLine("Index is not a number.");
        return;
      }
      Console.WriteLine("Checking item {0}...", index);
      tasks.CompleteTask(Convert.ToInt32(_args[1]));
    }
  }
}