from Crypto.Util.number import *
import socketserver
import signal
import os
import string
import random
import base64

flag = os.getenv('FLAG')
key = b'#k%s@4)23-'

BANNER = br'''
     ____            _   _    _____ _       _     
    |  _ \          | | (_)  / ____| |     | |    
    | |_) | ___  ___| |_ _  | |    | |_   _| |__  
    |  _ < / _ \/ __| __| | | |    | | | | | '_ \ 
    | |_) |  __/\__ \ |_| | | |____| | |_| | |_) |
    |____/ \___||___/\__|_|  \_____|_|\__,_|_.__/ 

    DKYCTF 2024 - Your best 1 RSA Cipher machine !
    Welcome to the Encrypted transmission service!
'''

def encrypt():
    # 生成RSA p,q
    p = getPrime(64)
    q = getPrime(64)
    n = p * q
    e = 0x10001

    c = pow(bytes_to_long(key), e, n)

    return c, n, e

class Task(socketserver.BaseRequestHandler):
    def _recvall(self):
        BUFF_SIZE = 2048
        data = b''
        while True:
            part = self.request.recv(BUFF_SIZE)
            data += part
            if len(part) < BUFF_SIZE:
                break
        return data.strip()

    def send(self, msg, newline=True):
        try:
            if newline:
                msg += b'\n'
            self.request.sendall(msg)
        except:
            pass

    def recv(self, prompt=b''):
        self.send(prompt, newline=False)
        return self._recvall()

    def handle(self):
        signal.alarm(300)
        self.send(BANNER, newline=False)
        
        c, n, e = encrypt()
        self.send(b"\nThis is your RSA public key:")
        self.send(b"n = " + str(n).encode())
        self.send(b"e = " + str(e).encode())

        self.send(b"Here is ciphertext of admin key:")
        self.send(b"c = " + str(c).encode())
        self.send(b"")

        self.send(b"Please input your admin key:")
        input_key = self.recv()
        self.send(b"")

        if input_key == key:
            self.send(b"Welcome, admin! Here is your flag:")
            self.send(flag.encode())
        else:
            self.send(b"Admin Key Wrong!")
        self.request.close()


class ThreadedServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
    pass


class ForkedServer(socketserver.ForkingMixIn, socketserver.TCPServer):
    pass


if __name__ == "__main__":
    HOST, PORT = '0.0.0.0', 9999
    print("HOST:POST " + HOST+":" + str(PORT))
    server = ForkedServer((HOST, PORT), Task)
    server.allow_reuse_address = True
    server.serve_forever()
