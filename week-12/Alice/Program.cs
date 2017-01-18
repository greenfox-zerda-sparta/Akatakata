using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Alice {
  class Program {
    static void Main(string[] args) {
      string[] text = File.ReadAllText(@"C:\greenfox\Akatakata\week-12\Alice\AliceBook.txt").Split(' ');
      Dictionary<string, int> words = new Dictionary<string, int>();
      foreach (string word in text) {
        if (!words.ContainsKey(word)) {
          words.Add(word, 1);
        } else {
          words[word] += 1;
        }
      }
      foreach (KeyValuePair<string, int> pair in words) {
        Console.WriteLine(pair);
      }
      Console.ReadLine();
    }
  }
}
