import socket

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 1024))
while True:
    from curses import KEY_A1

    def generateKey(string, key):
        key = list(key)
        if len(string) == len(key):
            return(key)
        else:
            for i in range(len(string) -len(key)):
                key.append(key[i % len(key)])
        return("" . join(key))
     

    def cipherText(string, key):
        cipher_text = []
        for i in range(len(string)):
            x = (ord(string[i]) +ord(key[i])) % 26
            x += ord('A')
            cipher_text.append(chr(x))
        return("" . join(cipher_text))
    
    text = input("Enter the text to be Encrypted : ")
    s.send(text.encode())
    keyVal = input("Enter KeyVal : ")
    key = generateKey(text, keyVal)
    encStr = cipherText(text,key)
    print(encStr)
    s.send(encStr.encode())
    msg=s.recv(64)
    print("Decrypted Message from server recevied :")
    print(msg.decode())
    if msg.decode()=="close":
        print("Connection ended")
        s.close()
        break