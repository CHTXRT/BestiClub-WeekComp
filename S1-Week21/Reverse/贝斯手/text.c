#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

const char listchars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int sna[] = {90,109,120,104,90,51,116,105,89,88,77,48,88,122,66,110,101,87,49,102,99,51,81,120,88,50,78,119,99,72,48,61};

// ×Ô¶¨Òåbase64
char* enc(char *s)
{
    unsigned char *input = (unsigned char *)s;
    int len = strlen(s);
    char *encoded = (char *)malloc(((len + 2) / 3) * 4 + 1);
    int i, j;
    int enc_len = 0;

    for (i = 0; i < len; i += 3) {
        unsigned int octet_a = i < len ? input[i] : 0;
        unsigned int octet_b = i + 1 < len ? input[i + 1] : 0;
        unsigned int octet_c = i + 2 < len ? input[i + 2] : 0;

        unsigned int triple = (octet_a << 16) + (octet_b << 8) + octet_c;

        encoded[enc_len++] = listchars[(triple >> 18) & 0x3F];
        encoded[enc_len++] = listchars[(triple >> 12) & 0x3F];
        encoded[enc_len++] = listchars[(triple >> 6) & 0x3F];
        encoded[enc_len++] = listchars[triple & 0x3F];
    }

    for (j = 0; j < (3 - len % 3) % 3; j++) {
        encoded[enc_len - 1 - j] = '=';
    }

    encoded[enc_len] = '\0';
	return encoded;
}

int main()
{
	printf("Please input the flag: ");
	char flag[100];
	scanf("%s", flag);
	char *C = enc(flag);
	for(int i = 0; i < strlen(C); i++)
	{
		if(C[i] != sna[i])
		{
			printf("Sorry, the flag is wrong.\n");
			return 0;
		}
	}
	printf("Congratulations! You got the flag!\n");
	return 0;
}        