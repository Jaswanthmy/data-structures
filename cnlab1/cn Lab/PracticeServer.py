import socket

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((socket.gethostname(),1024))
s.listen(5)
while True:

    client,address = s.accept()
    while True:
        c=str(client.recv(1024).decode())
        print(c)
        d=input("-> ")
        for i in range(5):
            client.send(d.encode())
        if str(c)=="close":
            client.close()
            break


    s.close()
    break
    

