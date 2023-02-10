import threading
import socket

#hostname = socket.getfqdn()
#IP=socket.gethostbyname_ex(hostname)[0]
IP='127.0.0.1'
PORT = 1024

server = socket.socket(socket.AF_INET ,socket.SOCK_STREAM)
server.bind((IP,PORT))
server.listen()

clients=[]
nicknames=[]

#def broadcast(message,client1):
#    for client in clients:
#        if client == client1:
#           client.send(message)


def broadcast(message):
    for client in clients:
            client.send(message)

def handle(client):
    while True:
            message = client.recv(1024)
            #index1 = nicknames.index(str(message))
            #clt = clients[index1]
            if ('Disconnect' in str(message)):
                index = clients.index(client)
                clients.remove(client)
                client.close()
                nickname = nicknames[index]
                nicknames.remove(nickname)
                broadcast(f"{nickname} left the chat!".encode("utf-8"))
                print(f" ->Disconnected with {nickname}")
                break
            else:
                broadcast(message)


def receive():
    while True:
        client, address = server.accept()
        print(f" ->connected with {str(address)}")

        client.send("NICK".encode("utf-8"))
        nickname = client.recv(1024).decode("utf-8")
        nicknames.append(nickname)
        clients.append(client)

        print(f"Nickname of client is {nickname}!\n")
        broadcast(f"{nickname} joined the chat!".encode("utf-8"))
        client.send("\n->You are now connected to the server...\n".encode("utf-8"))

        thread = threading.Thread(target=handle, args=(client,))
        thread.start()

print("Server is Listening....\n")
receive()

