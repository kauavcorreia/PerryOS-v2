#ifndef MEMORY_H
#define MEMORY_H

void memory_init();
void* kmalloc(int size);
void kfree(void* ptr);

#endif