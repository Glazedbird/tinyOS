
main.elf:     file format elf64-littleriscv


Disassembly of section .text:

0000000080000000 <_start>:
    80000000:	00002117          	auipc	sp,0x2
    80000004:	00010113          	mv	sp,sp
    80000008:	0060006f          	j	8000000e <main>

000000008000000c <hang>:
    8000000c:	a001                	j	8000000c <hang>

000000008000000e <main>:
    8000000e:	1141                	addi	sp,sp,-16 # 80001ff0 <stack+0xff0>
    80000010:	e422                	sd	s0,8(sp)
    80000012:	0800                	addi	s0,sp,16
    80000014:	100007b7          	lui	a5,0x10000
    80000018:	04100713          	li	a4,65
    8000001c:	00e78023          	sb	a4,0(a5) # 10000000 <_start-0x70000000>
    80000020:	4781                	li	a5,0
    80000022:	853e                	mv	a0,a5
    80000024:	6422                	ld	s0,8(sp)
    80000026:	0141                	addi	sp,sp,16
    80000028:	8082                	ret
