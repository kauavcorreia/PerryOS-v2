#include "arch/x86/interrupts.h"
#include "drivers/screen.h"


//handler de central de interrupcoes
void isr_handler(struct regs* r) {

    kprint("Interrupção recebida: ");


    if (r->int_no == 0) {
        kprint("Divisão por zero!\n");
    } 
    
    else {
        kprint("outro tipo de interrupção\n");
    }

    while (1);
        // Loop infinito para evitar que o sistema continue após a interrupção
   
}

