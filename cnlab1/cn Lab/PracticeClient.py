import socket

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((socket.gethostname(),1024))
while True:
    d=input("-> ")
    for i in range(5):
        s.send(d.encode())
    
    e=str(s.recv(1024).decode())
    print(e)
    
    c=input(": ")
    for i in range(5):
        s.send(c.encode())

    e=str(s.recv(1024).decode())
    print(e)
    
