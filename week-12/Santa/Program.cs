using System;
using System.Collections.Generic;
using System.Collections;

namespace Santa {
  class Program {

    public class Names {
      private List<string> nameList = new List<string>();
      public List<string> NameList { get { return nameList; } }
      
      public Names() { 
        this.GetNames();
        this.ShuffleNames();
      }

      public void GetNames() {
        string input = "";
        Console.WriteLine("Please add a name to the Secret Santa Maker! Type /q if you finished adding names. ");
        while (input != "/q") {
          input = Console.ReadLine();
          if (input == "/q" && (NameList.Count % 2 == 1)) {
            Console.WriteLine("The number of names given is odd, I can't make pairs. Please add one more name, then type /q if you finished.");
            input = "";
            continue;
          } else if (input == "/q") {
            break;
          }
          nameList.Add(input);
        }
      }

      public void ShuffleNames() {
        Random random = new Random();
        List<string> temp = new List<string>();
        while (nameList.Count > 0) {
          int index = random.Next(0, nameList.Count);
          temp.Add(nameList[index]); 
          nameList.RemoveAt(index);
        }
        nameList = temp;
      }
    }

    public class SecretSantaMaker {
      private Names names = new Names();
      private Dictionary<string, string> namePairs = new Dictionary<string, string>();
     
      public void Run() {
        MakePairs();
        PrintPairs();
      }
      
      private void MakePairs() {
        for (int i = 0; i < names.NameList.Count; i++) {
          if (i == names.NameList.Count - 1) {
            namePairs.Add(names.NameList[i], names.NameList[0]);
          } else {
            namePairs.Add(names.NameList[i], names.NameList[i + 1]);
          }
        }
      }

      public void PrintPairs() {
        Console.WriteLine("Name - Santa:");
        foreach (KeyValuePair<string, string> entry in namePairs) {
          Console.WriteLine(entry);
        }
      }
    }

    static void Main(string[] args) {
      SecretSantaMaker santa = new SecretSantaMaker();
      santa.Run();
      Console.ReadLine();
    }
  }
}
