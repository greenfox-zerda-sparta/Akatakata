using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class SynchronousSocketServer {

  // Incoming data from the client.
  public static string data = null;

  public static void StartListening() {
    // Data buffer for incoming data.
    byte[] bytes = new Byte[1024];

    // Establish the local endpoint for the socket.
    IPHostEntry ipHostInfo = Dns.Resolve("10.27.6.82");
    IPAddress ipAddress = ipHostInfo.AddressList[0];
    IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 11000);

    // Create a TCP/IP socket.
    Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

    // Bind the socket to the local endpoint and listen for incoming connections.
    try {
      listener.Bind(localEndPoint);
      listener.Listen(10);

      // Start listening for connections and remains running
      while (true) {

        Console.WriteLine("Waiting for a connection...");
        // Program is suspended while waiting for an incoming connection.
        Socket handler = listener.Accept();
        data = null;

        // An incoming connection needs to be processed.
        while (true) {
          bytes = new byte[1024];
          int bytesRec = handler.Receive(bytes);
          data += Encoding.ASCII.GetString(bytes, 0, bytesRec);
          if (data.Length > 0) {
            break;
          }
        }

        // Show the data on the console.
        Console.WriteLine("Text received : {0}", data);

        // Echo the data back to the client.
        byte[] msg = Encoding.ASCII.GetBytes(data);

        handler.Send(msg);
        handler.Shutdown(SocketShutdown.Both);
        handler.Close();
      }

    } catch (Exception e) {
      Console.WriteLine(e.ToString());
    }

    Console.WriteLine("\nPress ENTER to continue...");
    Console.Read();

  }

  public static int Main(String[] args) {
    StartListening();
    return 0;
  }
}