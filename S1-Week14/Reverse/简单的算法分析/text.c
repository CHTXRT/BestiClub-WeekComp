#include<stdio.h>
#include<string.h>

unsigned char target_str[] = {0xa,0xd,0x6,0x1c,0x18,0xc,0x2,0x59,0x6b,0x2b,0x44,0x6f,0x2d,0x41,0x45,0x45,0x41,0x1,0x16,0x3a,0x28,0x47,0x42,0x1e,0x8,0x19,0x7d,0};

int main()
{
	puts("Enter the flag:");
	char input_str[100];
	scanf("%s", input_str);
	int input_str_len = strlen(input_str);

	if(input_str_len != 27)
	{
		printf("Wrong!\n");
		return 0;
	}
	
	for(int i=0;i<input_str_len-1;i++)
	{
		input_str[i] ^= input_str[i+1];
	}
	if(strcmp(input_str, target_str) == 0)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong!\n");
	}
	return 0;
}        