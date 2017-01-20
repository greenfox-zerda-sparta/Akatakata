using System;
using System.Net;
using System.Net.Sockets;
using System.Text;


namespace Chatserver {
  class Program {

    public static int Main(String[] args) {
      Server myServer = new Server();
      myServer.Run();
      return 0;
    }
  }
}
