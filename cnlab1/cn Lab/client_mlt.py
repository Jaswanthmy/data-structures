from concurrent.futures import thread
from http import client, server
import socket
import threading


hostname = socket.getfqdn()
IP=socket.gethostbyname_ex(hostname)[0]
PORT = 5566
ADDR = (IP,PORT)
Size=1024
Format="utf-8"
Disconnect_Msg = "!Disconnect"

def main():
    client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client.connect(ADDR)
    print(f"[Connected] Client connected to server at {IP}:{PORT}")

    connected = True
    while connected:
        msg = input("> ")
        client.send(msg.encode(Format))
        if msg == Disconnect_Msg:
            connected = False
        else:
            msg = client.recv(Size).decode(Format)
            print(f"[SERVER] {msg}")

if __name__=="__main__":
    main()








