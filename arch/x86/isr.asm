global isr0
extern isr0_handler

isr0:
    cli

    push byte 0
    push byte 0

    jmp isr_common

isr_common:
    pusha

    push ds     ; salvar os registradores de valores
    push es     ;registrador de segmento extra
    push fs     ;registrador de segmento de uso geral
    push gs     ;registrador de segmento de uso geral

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    push esp ; passar o endereço da pilha para o handler

    call isr0_handler

    ; restaurar os registradores
    pop gs  
    pop fs
    pop es
    pop ds 

    popa       

    add esp, 8 ; limpar os argumentos da pilha

    ; habilitar as interrupções novamente e retornar
    sti
    iret

