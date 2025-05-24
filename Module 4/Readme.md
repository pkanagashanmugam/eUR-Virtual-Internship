# Module 4 - Socket Programming

**Question 1:**

The client server architecture is widely used to implement Socket Programming wherein the client interacts with a server and exchanges information. As a part of the client server process, the Server creates a socket, binds the port number to its IP address and actively listens to the socket for any communication from the client. Based on the Transport Layer protocol used, the server either accepts connection or directly reads the buffer for any communication from the client. It can also send messages to the client by writing to the buffer.

**Question 2:**

bind() function is called after socket creation. It binds the port number to the IP address used in socket initialization. This function is called strictly on the server side to inform the server to listen to a specific port number for messages.If the bind function is missed, the server will not know the port number it should listen to.

**Question 3:**

Datagram Socket is one of the two types of socket, other one being Stream Socket. A Datagram Socket uses UDP (User Datagram Protocol) as its transport layer protocol. Unlike Stream Socket in a Datagram Socket, the client does not connect to a server, it simply sends the message to the server. Datagram Sockets are used in places where throughput is prioritized over reliability. 

**Question 4 Execution:**

![image](https://github.com/user-attachments/assets/11d11f48-f69b-4a0f-b7fb-7b0821091df5)

**Question 5 Execution:**

![image](https://github.com/user-attachments/assets/cd8ea478-a3e6-40a1-9ace-c062b979b029)

**Question 6 Execution:**
