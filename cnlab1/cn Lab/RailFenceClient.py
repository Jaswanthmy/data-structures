import socket

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 1024))
while True:
    from curses import KEY_A1


    text = input("Enter the text to be Encrypted : ")
    key = int(input("Enter Key : "))
    lock=0
    row=0
    n=len(text)
    arr=[]
    rows, cols=key,n
    for i in range(rows):
        col = []
        for j in range(cols):
            col.append('-')
        arr.append(col)

    for i in range(n):
        if (lock>=0):
            if(row==key-1):
                arr[row][i]=text[i]
                row=row-1
                lock=-1
            else:
                arr[row][i]=text[i]
                row=row+1
        else:
            if(row==0):
                arr[row][i]=text[i]
                row=row+1
                lock=0
            else:
                arr[row][i]=text[i];
                row=row-1

    print("Matrix: \n---------\n")

    for i in range(key):
        print(*arr[i])

    print("\nAfter Encryption : ")

    enc=[]#array
    idx=0
    for i in range(key):
        for j in range(n):
            if(arr[i][j]!='-'):
                enc.append(arr[i][j])
                idx=idx+1
    encStr=""#encrypted message
    for i in range(idx):
        encStr+=enc[i]

    print(encStr)
    s.send(encStr.encode())
    msg=s.recv(64)
    print("Decrypted Message from server recevied :")
    print(msg.decode())
    if msg.decode()=="close":
        print("Connection ended")
        s.close()
        break