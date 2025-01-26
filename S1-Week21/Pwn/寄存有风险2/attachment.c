#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
// #include <sys/mman.h>

char* mystrncpy(char* dest, const char* src, size_t n)
{
    asm("call strncpy\n");
}

void* _readline(char* buf)
{
    unsigned char tempstr[0x100];
    read(0, tempstr, 0x118);
    tempstr[strcspn(tempstr, "\n")] = 0;
    mystrncpy(buf, tempstr, 0x100);
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

int main()
{
    init();
    // init_heap();
    banner();
    vuln();
    return 0;
}