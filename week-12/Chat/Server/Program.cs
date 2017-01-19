using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Collections.Generic;

public class SynchronousSocketServer {

  // Incoming data from the client.
  public static string data = null;

  public static void StartListening() {

    byte[] bytes = new Byte[1024];

    IPHostEntry ipHostInfo = Dns.Resolve(Dns.GetHostName());
    IPAddress ipAddress = ipHostInfo.AddressList[0];
    IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 11000);

    Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
    List<Socket> SocketList = new List<Socket>();

    try {
      listener.Bind(localEndPoint);
      listener.Listen(10);

      Console.WriteLine("Waiting for a connection...");
      while (true) {
      //  if (listener.Available > 0) {
          SocketList.Add(listener.Accept());
          Console.WriteLine("Connected!");
        Console.WriteLine(SocketList.Count);
        //     listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        //   }

        //while (true) {
        //  data = null;
        //  for (int i = 0; i < SocketList.Count; i++) {
        //    if (SocketList[i].Available > 0) {
        //      bytes = new byte[1024];
        //      int bytesRec = SocketList[i].Receive(bytes);
        //      data += Encoding.ASCII.GetString(bytes, 0, bytesRec);
        //      if (data.Length > 0) {
        //        break;
        //      }
        //    }
        //  }
        //}

        //Console.WriteLine("Text received : {0}", data);
        //byte[] msg = Encoding.ASCII.GetBytes(data);

        //SocketList[0].Send(msg); // HA TOBB SOCKET VAN, VEGIG KELL NEZNI
      }
     // handler.Shutdown(SocketShutdown.Both);
     // handler.Close();

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