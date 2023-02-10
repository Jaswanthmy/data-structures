
import socket
from curses import KEY_A1




s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1024))# Ip and Port
s.listen(5)
while True:

    clt, adr=s.accept()
    print(f"connectio to {adr} is establish")
    while True:
        data = clt.recv(64).decode()
        print("message from user : "+ str(data))
        key1 = int(input("Enter key value by which it should be Decrypted : "))
        arr1=[]
        n=len(str(data))# length of message also sent to server
        enc=str(data)# send encrypted message to server
        rows,cols = key1,n
        lock=0
        row=0

        for i in range(key1):
            col = []
            for j in range(n):
                col.append('-')
            arr1.append(col)

        for i in range(n):
            if(lock>=0):
                if(row==key1-1):
                    arr1[row][i]='*'
                    row=row-1
                    lock=-1
                else:
                    arr1[row][i]='*'
                    row=row+1
            else:
                if(row==0):
                    arr1[row][i]='*'
                    row=row+1
                    lock=0;
                else:
                    arr1[row][i]='*'
                    row=row-1

        count1 = n-1
        for i in range(key1-1,-1,-1):
            for j in range(n-1,-1,-1):
                if(arr1[i][j]=='*'):
                    arr1[i][j]=enc[count1]
                    count1=count1-1

        print("\nMatrix after Descryption :\n-------\n")
        for i in range(key1):
            print(*arr1[i])


        print("\nAfter Descryption")
        lock=0
        row=0
        dec=[]
        for i in range(n):
            if(lock>=0):
                if(row==key1-1):
                    dec.append(arr1[row][i])
                    row=row-1
                    lock=-1
                else:
                    dec.append(arr1[row][i])
                    row=row+1
            else:
                if(row==0):
                    dec.append(arr1[row][i])
                    row=row+1
                    lock=0;
                else:
                    dec.append(arr1[row][i])
                    row=row-1

        decStr=""        
        for i in range(n):
            decStr += dec[i]

        print(decStr)
        clt.send(decStr.encode())#utf-8
        if str(data)=="close":
            print("Connection ended")
            clt.close()
            break
    s.close()
    break