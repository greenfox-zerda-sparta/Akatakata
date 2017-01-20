using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Chatclient {
  class Program {

    public static int Main(String[] args) {
      Client myClient = new Client();
      myClient.Run();
      return 0;
    }

  }
}
