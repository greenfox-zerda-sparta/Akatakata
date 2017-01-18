using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToDoApp {
  class Program {
    static void Main(string[] args) {
      TaskHandler tasks = new TaskHandler();
      tasks.PrintList();
      Console.WriteLine();
      Console.WriteLine("Type the task to add: ");
      string toAdd = Console.ReadLine();
      if (toAdd != "") {
        tasks.AddTask(toAdd);
      }
      Console.ReadLine();
    }
  }
}
