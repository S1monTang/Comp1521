    .data
string: .asciiz"I MIPS you!\n"
    .text
    .globl main
main:
    la $a0 , string
    li $v0 , 4
    syscall
    li $v0 , 0
    jr $ra
