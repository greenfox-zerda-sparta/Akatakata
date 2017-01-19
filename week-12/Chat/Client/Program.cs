﻿using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class SynchronousSocketClient {

  public static void StartClient() {
    bool shutdown = false;
    // Data buffer for incoming data.
    byte[] bytes = new byte[1024];

    try {
      // Establish the remote endpoint for the socket.
      IPHostEntry ipHostInfo = Dns.Resolve(Dns.GetHostName());
      IPAddress ipAddress = ipHostInfo.AddressList[0];
      IPEndPoint remoteEndpoint = new IPEndPoint(ipAddress, 11000);

      // Create a TCP/IP  socket.
      Socket client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

      // Connect the socket to the remote endpoint. Catch any errors.
      try {
        client.Connect(remoteEndpoint);
        Console.WriteLine("Socket connected to {0}", client.RemoteEndPoint.ToString());

        do {

          // Receive
           if (client.Poll(100, SelectMode.SelectRead)) {
            bytes = new byte[1024];
            int bytesRec = client.Receive(bytes);
            if (bytesRec > 0) {
              Console.WriteLine("Echoed test = {0}", Encoding.ASCII.GetString(bytes, 0, bytesRec));
            }
          }

          // Send: Encode the data string into a byte array and Send
            string message = Console.ReadLine();
            byte[] msg = Encoding.ASCII.GetBytes(message);
            int bytesSent = client.Send(msg);


        } while (shutdown == false);
        // Release and close the socket.
        client.Shutdown(SocketShutdown.Both);
        client.Close();

      } catch (ArgumentNullException ane) {
        Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
      } catch (SocketException se) {
        Console.WriteLine("SocketException : {0}", se.ToString());
      } catch (Exception e) {
        Console.WriteLine("Unexpected exception : {0}", e.ToString());
      }

    } catch (Exception e) {
      Console.WriteLine(e.ToString());
    }
  }

  public static int Main(String[] args) {
    StartClient();
    return 0;
  }
}