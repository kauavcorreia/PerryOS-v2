#include "io.h"

//funcao input manipulada a nivel de bytes
unsigned char inb(unsigned short port) {
    unsigned char result;

    __asm__ volatile ("inb %1, %0"      // %1 = input %0 = output
                      : "=a"(result)    //aloca resultado em al
                      : "Nd"(port));    //aloca entrada em dx 

    return result;

}
//funcao output manipulada a nivel de bytes
void outb(unsigned short port, unsigned char data) {

    __asm__ volatile ("outb %0, %1" 
                      :
                      : "a"(data), "Nd"(port));


    /*traducao
    mov,al,data
    mov,dx,port
    out,dx,al*/
}

/*funcoes unsigned trata variaveis como >= 0 
dobrando a quantidade de armazenamento positivo*/

