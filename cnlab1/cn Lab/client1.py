import socket
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 1024))
while True:
    message=input("Send message to server : ")
    s.send(message.encode())
    m=s.recv(64).decode()
    i=0
    while i<int(m):
        msg=s.recv(64)
        print(msg.decode())
        i=i+1
    if msg.decode()=="close":
        print("Connection ended")
        s.close()
        break


# Why use Tcp ? ?
## is reliable(Packets if dropped during transmission are Detected and retransmitted by sender) 
##  has in order data delivery (Data is read in same order by API as sent by sender)

#socket()------>connect()


