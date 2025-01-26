#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/mman.h>

void* _readline(char* buf)
{
    unsigned char tempstr[0x100];
    read(0, tempstr, 0x110);
    tempstr[strcspn(tempstr, "\n")] = 0;
    strncpy(buf, tempstr, 0x100);
}

char* readline()
{
    char* buf;
    buf = malloc(0x100);
    if (!buf)
    {
        exit(1);
    }
    _readline(buf);
    return buf;
}

void writestr(char* str)
{
    write(1, str, strlen(str));
}

void* getfunc(int idx)
{
    switch (idx)
    {
    case 0:
        return readline;
    case 1:
        return writestr;
    default:
        return NULL;
    }
}

void vuln()
{
    ((void (*)(char*))getfunc(1))("What's your name?\n");
    char* name = ((char* (*)(void))getfunc(0))();
    ((void (*)(char*))getfunc(1))("Hello, ");
    ((void (*)(char*))getfunc(1))(name);
    ((void (*)(char*))getfunc(1))("\n");
}

void banner()
{
    puts("\
  ____            _   _    _____ _       _     \n\
 |  _ \\          | | (_)  / ____| |     | |    \n\
 | |_) | ___  ___| |_ _  | |    | |_   _| |__  \n\
 |  _ < / _ \\/ __| __| | | |    | | | | | '_ \\ \n\
 | |_) |  __/\\__ \\ |_| | | |____| | |_| | |_) |\n\
 |____/ \\___||___/\\__|_|  \\_____|_|\\__,_|_.__/ \n\
    ");
    puts("Welcome to BestiCTF!");
    puts("");
}

void init()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

void init_heap()
{
    intptr_t page_size = getpagesize();
    intptr_t heap_addr = (intptr_t) malloc(1);
    intptr_t heap_base = (heap_addr | (page_size - 1)) ^ (page_size - 1);
    mprotect((void *)heap_base, 2 * page_size, PROT_WRITE|PROT_READ|PROT_EXEC);
}

int main()
{
    init();
    init_heap();
    banner();
    vuln();
    return 0;
}