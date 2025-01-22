import base64

input_str = b'flag{Y0u_ar4_c0nt4mp0rary_Tur1ng}'
key = b''.fromhex('20241130e59bbee781b5')

def encrypt(m: bytes, key: bytes) -> bytes:
    m = bytearray(m)
    key = bytearray(key)
    c = m
    for i in range(len(m)):
        c[i] = m[i] ^ key[i % len(key)]
    c = base64.b64encode(bytes(c))
    return c

print(encrypt(input_str, key))


