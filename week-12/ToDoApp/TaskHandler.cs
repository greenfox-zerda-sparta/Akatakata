using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ToDoApp {
  class TaskHandler {
    private string filepath = @"C:\\greenfox/Akatakata/week-12/ToDoApp/todolist.txt";
    public string Filepath { get; set; }

    private List<string> todolist = new List<string>();

    public void ReadFromFile() {
      string line;
      StreamReader file = new StreamReader(filepath);
      
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
    }

    public void RemoveTask(int number) {
      if (number > todolist.Count) {
        Console.WriteLine("Error: there is no element number " + number + " in the list.");
      } else {
        todolist.RemoveAt(number - 1);
        ListToFile();
      }
    }

    public void CompleteTask(int number) {
      char[] array = todolist[number - 1].ToCharArray();
      if (array[1] == 'x') {
        array[1] = ' ';
      } else if (array[1] == ' ') {
        array[1] = 'x';
      }
      todolist[number - 1] = new string(array);
      ListToFile();
    }

    public void ListToFile() {
      StreamWriter file = new StreamWriter(filepath);
      todolist.ForEach(file.WriteLine);
      file.Close();
    }
  }
}
