import socket
import threading

nickname = input("Choose a nickname: ")

#hostname = socket.getfqdn()
#IP=socket.gethostbyname_ex(hostname)[0]
IP='127.0.0.1'
PORT = 1024

client = socket.socket(socket.AF_INET ,socket.SOCK_STREAM)
client.connect((IP,PORT))

def receive():
    while True:
        try:
            message = client.recv(1024).decode("utf-8")
            if message == "NICK":
                client.send(nickname.encode("utf-8"))
            else:
                print("->"+message)

        except:
            print("An error occured..")
            client.close()
            break

def write():
    while True:
        #name=input("Enter name of client you want to chat with : ")
        #client.send(name.encode("utf-8"))
        m=input('')
        message = f"{nickname}: {m}"
        if m == "Disconnect":
            print("\n!!!Session Ended")
            client.send(message.encode("utf-8"))
            client.close()
            break
        else:
            client.send(message.encode("utf-8"))

receive_thread = threading.Thread(target=receive)
receive_thread.start()

write_thread = threading.Thread(target=write)
write_thread.start()