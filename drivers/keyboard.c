#include "keyboard.h"

#define KEYBOARD_PORT 0x60

// função para ler 1 byte da porta input/output
unsigned char inb(unsigned short port) {

    unsigned char result; 

    
    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port)); 

    return result;
}

// tabela simples de teclas
char keyboard_map[128] = {
0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
'\t',
'q','w','e','r','t','y','u','i','o','p','[',']','\n',
0,
'a','s','d','f','g','h','j','k','l',';','\'','`',
0,
'\\',
'z','x','c','v','b','n','m',',','.','/',
0,
'*',
0,
' '
};

char keyboard_read() {

    unsigned char scancode = inb(KEYBOARD_PORT); //inb : ler scancodes

    if (scancode > 57) {
        return 0;
    }

    return keyboard_map[scancode];
}