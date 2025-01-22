import base64
from Crypto.Util.number import *

flag = '#k%s@4)23-'

p = getPrime(64)
q = getPrime(64)
n = p * q
e = 0x10001

c = pow(bytes_to_long(flag.encode()), e, n)

print(bytes_to_long(flag.encode()))

print(f'p = {p}')
print(f'q = {q}')
print(f'n = {n}')
print(f'c = {c}')


