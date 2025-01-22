from pwn import *

# context.log_level = "debug"

target = b"RkhwV57CjpLe1FIQTlPV9crT7MUQVnBCnMTqkvOETkNs"
tables = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_{}"

p = remote("node6.anna.nssctf.cn", 25555)

p.sendline(b'\x00'*100)

p.interactive()

'''
ICQRMOWbvueBtSAkETDlm77ngbUgJBEw5Zu+54G1ICQRMOWbvueBtSAkETDlm77ngbUgJBEw5Zu+54G1ICQRMOWbvueBtSAkETDlm77ngbUgJBEw5Zu+54G1ICQRMOWbvueBtQ==
'''