using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Santa {
  class Program {

    public class Names {
      private List<string> nameList = new List<string>();
      public List<string> NameList { get { return nameList; } }
      private int nameCount;
      public int NameCount { get { return nameCount; } }

      public Names() { 
        this.GetNames();
        this.ShuffleNames();
      }

      public void GetNames() {
        string input = "";
        Console.WriteLine("Please add a name to the Secret Santa Maker! Type /stop if you finished adding names. ");
        while (input != "/stop") {
          input = Console.ReadLine();
          if (input == "/stop" && (nameCount % 2 == 1)) {
            Console.WriteLine("The number of names given is odd, I can't make pairs. Please add one more name.");
            input = "";
            continue;
          } else if (input == "/stop") {
            break;
          }
          nameList.Add(input);
          nameCount++;
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
      Names names = new Names();
      private List<string> buysTo = new List<string>();
      public List<string> BuysTo { get { return buysTo; } }

      public void Run() {
        GenerateBuysTo();
        PushList(ref buysTo);
        PrintPairs();
      }

      public void GenerateBuysTo() {
        buysTo = names.NameList;

      }

      public void PushList(ref List<string> s) {
        buysTo.Add(buysTo[0]);
      }

      public void PrintPairs() {
        Console.WriteLine("darab: " + names.NameCount);
        for (int i = 0; i < names.NameCount; i++) {
          Console.WriteLine(names.NameList[i] + " buys to " + buysTo[i + 1]);
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
