#!/usr/bin/env python3

from pwn import remote

r = remote('140.113.207.240', 8831)
r.recvuntil('Give me a magic number')
r.send(str(0xDEADBEAF))
r.recvuntil('OK, then give me a magic string')
r.sendline('YOUSHALLNOTPASS')
r.recvuntil('Maybe you learn something :)')
print(r.recvall(1))

# FLAG{h1nj4kuHInJ4ku_muD4MudAmuda}
