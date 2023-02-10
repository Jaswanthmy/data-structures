import socket


s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1024))# Ip and Port
s.listen(5)
while True:

    clt, adr=s.accept()
    print(f"connectio to {adr} is establish")
    while True:
        data = clt.recv(64).decode()
        print("message from user : "+ str(data))
        i=0
        k=0
        for a in str(data):
            if ((ord(a)>=48) and (ord(a)<58)):
                
                if k!=1:
                    k=1
                    i=i+1
            elif (((ord(a)>=65) and (ord(a)<91)) or ((ord(a)>=97) and (ord(a)<123))):
                if k!=2:
                    k=2
                    i=i+1
            else:
                if k!=3:
                    k=3
                    i=i+1
        Si=str(i)
        clt.send(Si.encode())# cannot send int 
        k=0
        ind=0
        for b in str(data):
            if ((ord(b)>=48) and (ord(b)<58)):
                if k!=1:
                    k=1
                    h=ind
                    h2=str(h)
                    print("hi")
                    h1= "Messgae contains Digit Type \n"
                    clt.send(h2.encode())
                    clt.send(h1.encode())
                ind=ind+1
            elif (((ord(b)>=65) and (ord(b)<91)) or ((ord(b)>=97) and (ord(b)<123))):
                if k!=2:
                    k=2
                    #h=ind
                    #h2=str(h)
                    print("hello")
                    h1= "Messgae contains Text Type \n"
                    #clt.send(h2.encode())
                    clt.send(h1.encode())
                #ind=ind+1
            else:
                if k!=3:
                    k=3
                    #h=ind
                    #h2=str(h)
                    print("bye")
                    h1= "Messgae contains Special Charectors Type \n"
                    #clt.send(h2.encode())
                    clt.send(h1.encode())
                #ind=ind+1
        if h=="close":
            print("Connection ended")
            clt.close()
            break
    s.close()
    break

# Socket()-----> bind()------>listen()------>accept()