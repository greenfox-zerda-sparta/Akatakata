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
      int counter = 0;
      string line;
      StreamReader file = new StreamReader(filepath);
      while ((line = file.ReadLine()) != null) {
        string task = "[ ] " + (counter + 1).ToString() + " - " + line;
        todolist.Add(task);
        counter++;
      }
      file.Close();
    }

    public void PrintList() {
      ReadFromFile();
      foreach (string task in todolist) {
        Console.WriteLine(task);
      }
    }

    public void AddTask(string taskToAdd) {
      using (StreamWriter file = File.AppendText(filepath)) {
        Console.WriteLine();
        file.WriteLine(taskToAdd);
      }
    }
  }
}
