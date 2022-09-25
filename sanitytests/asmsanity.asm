%use masm

global main
extern puts

section .text
main:
    push    rbp
    mov     rbp, rsp
    
    lea     rdi, byte ptr [str]
    call    puts wrt ..plt

    xor     rax, rax
    pop     rbp
    ret

section .data
str: db "This is a test assembly program", 0