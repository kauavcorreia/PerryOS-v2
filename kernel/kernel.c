#include "../drivers/keyboard.h"
#include "../drivers/screen.h"

void kernel_main() {

    screen_clear();
    screen_print("PerryOS iniciado\n");

    while (1) {

        char c = keyboard_read();

        if (c) {
            screen_print_char(c);
        }

    }

}