using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

// Write a program that creates a text file named alice_words.txt
// containing an alphabetical listing of all the words,
// and the number of times each occurs, in the text version of
// Alice’s Adventures in Wonderland.
// How many times does the word alice occur in the book?
// What is the longest word in Alice in Wonderland?
// How many characters does it have?

namespace Alice {
  class Program {
    
    static void wordCleaner(ref string word) {
      if (word.Length > 0) {
        while (!char.IsLetter(word[0])) {
          word = word.Substring(1);
          if (word.Length == 0) {
            break;
          }
        }
      }
      if (word.Length > 0) {
        while (!char.IsLetter(word[word.Length - 1])) {
          word = word.Remove(word.Length - 1);
          if (word.Length == 0) {
            return;
          }
        }
      }
    }

    static void Main(string[] args) {
      string text = File.ReadAllText(@"C:\greenfox\Akatakata\week-12\Alice\AliceBook.txt");
      var list = from Match match in Regex.Matches(text, @"\b\S+\b")
                 select match.Value; //Get IEnumerable of words
      SortedDictionary<string, int> words = new SortedDictionary<string, int>();
      string longestWord = "";
      foreach (string word in list) {
        string nextWord = word;

        wordCleaner(ref nextWord);
        if (word.Length > 0) {
          longestWord = word.Length > longestWord.Length ? word : longestWord;
          if (!words.ContainsKey(nextWord)) {
            words.Add(nextWord, 1);
          } else {
            words[nextWord] += 1;
          }
        }
      }
      foreach (KeyValuePair<string, int> pair in words) {
        Console.WriteLine(pair);
      }
      Console.WriteLine();
      Console.WriteLine("Alice occurs: " + words["Alice"]);
      Console.WriteLine("Number of different words: " + words.Count);
      Console.WriteLine("The longest word: " + longestWord);
      Console.ReadLine();
    }
  }
}
