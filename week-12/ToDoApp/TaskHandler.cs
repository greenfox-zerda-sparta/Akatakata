using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ToDoApp {
  class TaskHandler {
    private string filepath = "todolist.txt";
    public string Filepath { get; set; }

    private List<string> todolist = new List<string>();

    public void ReadFromFile() {
      string line;
      StreamReader file = new StreamReader(File.Open(filepath, FileMode.OpenOrCreate));
      if (todolist.Count != 0) {
        todolist.Clear();
      }
      if (!string.IsNullOrEmpty(filepath)) {
        while ((line = file.ReadLine()) != null) {
          todolist.Add(line);
        }
      }
      file.Close();
    }

    public void PrintList() {
      ReadFromFile();
      if (todolist.Count == 0) {
        Console.WriteLine("No todos for today! :)");
      } else {
        foreach (string task in todolist) {
          Console.WriteLine((todolist.IndexOf(task) + 1) + " " + task);
        }
      }
    }

    public void AddTask(string taskToAdd) {
      string task = "[ ] " + taskToAdd;
      using (StreamWriter file = File.AppendText(filepath)) {
        file.WriteLine(task);
      }
      PrintList();
    }

    public void RemoveTask(int number) {
      ReadFromFile();
      if (number > todolist.Count || number < 1) {
        Console.WriteLine("Error: there is no element number " + number + " in the list.");
      } else {
        todolist.RemoveAt(number - 1);
        ListToFile();
        PrintList();
      }
    }

    public void CompleteTask(int number) {
      ReadFromFile();
      if (number > todolist.Count || number < 1) {
        Console.WriteLine("Error: there is no element number " + number + " in the list.");
      } else {
        char[] array = todolist[number - 1].ToCharArray();
        if (array[1] == 'x') {
          array[1] = ' ';
        } else if (array[1] == ' ') {
          array[1] = 'x';
        }
        todolist[number - 1] = new string(array);
        ListToFile();
        PrintList();
      }
    }

    public void ListToFile() {
      StreamWriter file = new StreamWriter(filepath);
      todolist.ForEach(file.WriteLine);
      file.Close();
    }
  }
}
