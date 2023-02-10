from concurrent.futures import thread
from http import server
import socket
import threading


hostname = socket.getfqdn()
IP=socket.gethostbyname_ex(hostname)[0]
PORT = 5566
ADDR = (IP,PORT)
Size=1024
Format="utf-8"
Disconnect_Msg = "!Disconnect"
clients = []

def broadcast(message):
    for client in clients:
        client.send(message.encode(Format))

def handle_client(conn, addr):
    print(f"[New Connection] {addr} connected.")

    connected = True
    while connected:#until is connected false when server recives disconnected command
        msg = conn.recv(Size).decode(Format)
        broadcast(msg)
        if msg == Disconnect_Msg:
            connected = False
        
        print(f"[{addr}] {msg}")
        msg = f"Msg received : {msg}"
        conn.send(msg.encode(Format))
    conn.close()


def main():
    print("Server is starting...")
    server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.bind(ADDR)
    server.listen()
    print(f"[Listening] Server is listening on {IP} , {PORT}")

    while True:
        conn, addr = server.accept()
        clients.append(conn)
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[Active Connections] {threading.activeCount() -1}")#number of connected clients


if __name__== "__main__":
    main()
