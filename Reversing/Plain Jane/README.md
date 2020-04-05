# Reversing - Plain Jane

## Challenge
I'm learning assembly. Think you can figure out what this program returns?

Note: Not standard flag format. Please provide either the unsigned decimal equivalent or hexadecimal equivalent.

Author: nadrojisk

## Solution
The file in this challenge is intel x86 assembly text file. After quick file
check we have 4 functions: `main`, `func_1`, `func_2`, `func_3`. `func_3` got
many conditional jumps. It seems it would take a lot of manual work to calculate
output from pure assembly.

We can solve this challenge in different way. Lets compile this code and check output
```
# as plain_jane.s -o plain_jane.o
# gcc -o plain_jane plain_jane.o
# ./plain_jane
# echo $?
0
# ./plain_jane | xxd
#
```
The binary works but the output is empty.

We can investigate more with `gdb`.
```

pwndbg> disassemble func_3
Dump of assembler code for function func_3:
   0x0000555555554687 <+0>: push   rbp
   0x0000555555554688 <+1>: mov    rbp,rsp
   0x000055555555468b <+4>: mov    DWORD PTR [rbp-0x24],edi
   0x000055555555468e <+7>: mov    DWORD PTR [rbp-0x28],esi
   0x0000555555554691 <+10>:  cmp    DWORD PTR [rbp-0x24],0x40
   0x0000555555554695 <+14>:  jg     0x5555555546a1 <func_3+26>
[...]
   0x0000555555554712 <+139>: add    DWORD PTR [rbp-0x8],0x1
   0x0000555555554716 <+143>: mov    eax,DWORD PTR [rbp-0x8]
   0x0000555555554719 <+146>: cmp    eax,DWORD PTR [rbp-0x14]
   0x000055555555471c <+149>: jl     0x555555554702 <func_3+123>
   0x000055555555471e <+151>: mov    eax,DWORD PTR [rbp-0x4]
   0x0000555555554721 <+154>: pop    rbp
   0x0000555555554722 <+155>: ret
End of assembler dump.
```
If we set breakpoint at `0x0000555555554721`, we should be able to see registers
just before end function `func_3` (also just before end of program.

```
pwndbg> b *0x0000555555554721
Breakpoint 1 at 0x555555554721
pwndbg> r
Starting program: /home/lcf/plain_jane/plain_jane

Breakpoint 1, 0x0000555555554721 in func_3 ()
LEGEND: STACK | HEAP | CODE | DATA | RWX | RODATA
─────────────────────────────────────[ REGISTERS ]──────────────────────────────
 RAX  0x6fcf
 RBX  0x0
 RCX  0x555555554730 (__libc_csu_init) ◂— push   r15
 RDX  0xffffffb6
 RDI  0x42
 RSI  0xcf
 R8   0x7ffff7dd0d80 (initial) ◂— 0x0
 R9   0x7ffff7dd0d80 (initial) ◂— 0x0
 R10  0x1
 R11  0x0
 R12  0x5555555544f0 (_start) ◂— xor    ebp, ebp
 R13  0x7fffffffe4a0 ◂— 0x1
 R14  0x0
 R15  0x0
 RBP  0x7fffffffe3a0 —▸ 0x7fffffffe3c0 —▸ 0x555555554730 (__libc_csu_init) ◂— push   r15
 RSP  0x7fffffffe3a0 —▸ 0x7fffffffe3c0 —▸ 0x555555554730 (__libc_csu_init) ◂— push   r15
 RIP  0x555555554721 (func_3+154) ◂— pop    rbp
─────────────────────────────────────[ DISASM ]─────────────────────────────────
 ► 0x555555554721 <func_3+154>               pop    rbp
   0x555555554722 <func_3+155>               ret
    ↓
   0x55555555462b <main+49>                  mov    dword ptr [rbp - 0xc], eax
   0x55555555462e <main+52>                  mov    eax, 0
   0x555555554633 <main+57>                  leave
   0x555555554634 <main+58>                  ret
    ↓
   0x7ffff7a05b97 <__libc_start_main+231>    mov    edi, eax
   0x7ffff7a05b99 <__libc_start_main+233>    call   exit <0x7ffff7a27120>

   0x7ffff7a05b9e <__libc_start_main+238>    mov    rax, qword ptr [rip + 0x3ced23] <0x7ffff7dd48c8>
   0x7ffff7a05ba5 <__libc_start_main+245>    ror    rax, 0x11
   0x7ffff7a05ba9 <__libc_start_main+249>    xor    rax, qword ptr fs:[0x30]
```

We can see that `RAX` got value `0x6fcf` and that is our flag.

## Flag
```
0x6fcf
```
