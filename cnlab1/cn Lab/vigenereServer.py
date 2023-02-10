
import socket
from curses import KEY_A1




s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1024))# Ip and Port
s.listen(5)
while True:

    clt, adr=s.accept()
    print(f"connectio to {adr} is establish")
    while True:
        text = clt.recv(64).decode()
        print("message from user : "+ str(text))

        data = clt.recv(64).decode()
        print("message from user : "+ str(data))


        def generateKey(string, key):
            key = list(key)
            if len(string) == len(key):
                return(key)
            else:
                for i in range(len(string) -len(key)):
                    key.append(key[i % len(key)])
            return("" . join(key))

        def originalText(cipher_text, key):
            orig_text = []
            for i in range(len(cipher_text)):
                x = (ord(cipher_text[i]) -ord(key[i]) + 26) % 26
                x += ord('A')
                orig_text.append(chr(x))
            return("" . join(orig_text))

        keyVal = input("Enter key value by which it should be Decrypted : ")
        key = generateKey(text, keyVal)
        print("Original/Decrypted Text :",
           originalText(data, key))

        decStr = originalText(data, key)
        clt.send(decStr.encode())#utf-8
        if str(data)=="close":
            print("Connection ended")
            clt.close()
            break
    s.close()
    break