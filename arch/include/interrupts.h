#ifndef INTERRUPTS_H
#define INTERRUPTS_H

// Representa o estado da CPU no momento da interrupção
struct regs {
    unsigned int gs, fs, es, ds; // segmentos

    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; // registradores gerais    

    unsigned int int_no, err_code; // número da interrupção e código de erro (se aplicável)

    unsigned int eip, cs, eflags, useresp, ss; // registradores de controle e estado
    
};

void isr0();

#endif
