#include "screen.h"

#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x07

static int cursor = 0;

void screen_print_char(char c) {

    char* video = (char*) VIDEO_MEMORY;

    video[cursor * 2] = c;
    video[cursor * 2 + 1] = WHITE_ON_BLACK;

    cursor++;
}

void screen_print(const char* str) {

    int i = 0;

    while (str[i] != 0) {
        screen_print_char(str[i]);
        i++;
    }

}

void screen_clear() {

    char* video = (char*) VIDEO_MEMORY;

    for (int i = 0; i < 80 * 25; i++) {

        video[i * 2] = ' ';
        video[i * 2 + 1] = WHITE_ON_BLACK;

    }

    cursor = 0;
}