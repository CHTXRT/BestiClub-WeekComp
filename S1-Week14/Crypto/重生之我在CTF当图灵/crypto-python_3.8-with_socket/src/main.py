from Crypto.Util.number import *
from hashlib import sha256
import socketserver
import signal
import os
import string
import random
import base64

# flag = os.getenv('FLAG')

key = b''.fromhex('20241130e59bbee781b5')

Introduction = """
此脚本仅为演示，使用此模板时请移除此文件
此文件做到当选手连接服务，按照说明输入"ctf"之后，输出flag
"""

BANNER = br'''
     ____            _   _    _____ _       _     
    |  _ \          | | (_)  / ____| |     | |    
    | |_) | ___  ___| |_ _  | |    | |_   _| |__  
    |  _ < / _ \/ __| __| | | |    | | | | | '_ \ 
    | |_) |  __/\__ \ |_| | | |____| | |_| | |_) |
    |____/ \___||___/\__|_|  \_____|_|\__,_|_.__/ 

    DKYCTF 2021 - Your best 1 Cipher machine !
    Welcome to the encryption service!
'''

table = string.ascii_letters+string.digits

MENU = br'''
<OPTION>
'''

def encrypt(m: bytes, key: bytes) -> bytes:
    m = bytearray(m)
    key = bytearray(key)
    c = m
    for i in range(len(m)):
        c[i] = m[i] ^ key[i % len(key)]
    c = base64.b64encode(bytes(c))
    return c

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
        while True:
            self.send(b"\nPlease input the plaintext:")
            string = self.recv()
            self.send(b"Ciphertext: \n" + encrypt(string, key))
            self.send('')
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
