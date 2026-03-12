#include "../drivers/screen.h"
#include "../drivers/keyboard.h"
#include "../fs/fs.h"
#include "../kernel/memory.h"
#include "../kernel/interrupts.h"

void kernel_main() {

    screen_clear();
    screen_print("PerryOS iniciado\n");

    memory_init();
    fs_init();

    screen_print("Filesystem inicializado\n");

    while (1) {

        char c = keyboard_read();

        if (c) {
            screen_print_char(c);
        }

    }

}