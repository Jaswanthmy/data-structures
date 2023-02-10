import socket
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 1024))
while True:
    message=input("Send message to server : ")
    s.send(message.encode())
    msg=s.recv(64)
    print("Acknowladgement recevied :")
    print(msg.decode())
    if msg.decode()=="close":
        print("Connection ended")
        s.close()
        break


# Why use Tcp ? ?
## is reliable(Packets if dropped during transmission are Detected and retransmitted by sender) 
##  has in order data delivery (Data is read in same order by API as sent by sender)

#socket()------>connect()