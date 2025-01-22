#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

bool check(char* cmd)
{
    //读取文件：blacklist.txt，读取其中每一行，测试每一行是否在cmd中
    FILE* fp = fopen("blacklist.txt", "r");
    char line[0x100];
    while (fgets(line, 0x100, fp) != NULL)
    {
        line[strlen(line) - 1] = '\0';
        if (strstr(cmd, line) != NULL)
        {
            return false;
        }
    }
    fclose(fp);
    return true;
}

void backdoor(char* cmd)
{
    system(cmd);
}

void vuln()
{
    char input_str[0x100];
    while(1)
    {
        puts("Please input your code:");
        read(0, input_str, 0x100);
        if (!check(input_str))
        {
            puts("Hackerrr!");
            continue;
        }
        backdoor(input_str);
    }
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
    banner();
    vuln();
    return 0;
}