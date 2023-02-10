import socket

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1024))# Ip and Port
s.listen(5)
while True:

    clt, adr=s.accept()
    print(f"connection to {adr} is established")
    while True:
        data = clt.recv(64).decode()
        print("message from user : "+ str(data))
        h=input("Send a reply : ")
        clt.send(h.encode())#utf-8
        if h=="close":
            print("Connection ended")
            clt.close()
            break
    s.close()
    break

# Socket()-----> bind()------>listen()------>accept()