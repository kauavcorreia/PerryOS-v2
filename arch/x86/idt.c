// Uma entrada da IDT (1 interrupção)
struct idt_entry {
    unsigned short base_low;   
    unsigned short selector;   // segmento de código (geralmente 0x08)
    unsigned char zero;        // reservado, deve ser 0
    unsigned char flags;       // define tipo e permissões
    unsigned short base_high;  
} __attribute__((packed)); // garante que a estrutura seja empacotada sem preenchimento


// Ponteiro para a IDT (usado pelo comando lidt)
struct idt_ptr {
    unsigned short limit; // tamanho da IDT - 1
    unsigned int base;   // endereço da IDT
} __attribute__((packed));

#define IDT_SIZE 256 // número total de interrupcoes da CPU

struct idt_entry idt[IDT_SIZE];
struct idt_ptr idtp;

// Função para configurar uma entrada da IDT
void idt_set(unsigned int num, unsigned int handler){

    //dividir o endereço do handler em duas partes
    idt[num].base_low = handler & 0xFFFF; // parte baixa do endereço
    idt[num].base_high = (handler >> 16) & 0xFFFF; // parte alta do endereço

    idt[num].selector = 0x08; // segmento de código
    idt[num].zero = 0; // reservado

    // presente (1), privilégio de anel 0 (0), tipo de interrupção (1110b = 0xE)
    idt[num].flags = 0x8E; 

    

  
}



   
