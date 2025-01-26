#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

char ans[] = "}6vvjCl1_xr4G5d{xsfa";

void ver(char* str)
{
	int len = strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
}

int main()
{
	ver(ans);

	puts("Enter the flag:");
	char input_str[100];
	scanf("%s", input_str);
	int input_str_len = strlen(input_str);
	int j = input_str_len;

	for(int i=0;i<input_str_len;i++,j--)
	{
		if(isalpha(input_str[i]))
		{
			char basechar = '\n';
			if(islower(input_str[i]))
			{
				basechar = 'a';
			}
			else
			{
				basechar = 'A';
			}
			input_str[i] = (input_str[i] + j - basechar) % 25;
			input_str[i] += basechar;
		}
		else if(isdigit(input_str[i]))
		{
			// printf("%d",3 & 0x9);
			input_str[i] = ((input_str[i] + j - '0') % 0x9) + '0';
		}
		// printf("%d: %c\n", j, input_str[i]);
	}
	// puts(input_str);
	// puts(ans);

	if(strcmp(input_str, ans) == 0)
	{
		printf("You are right!\n");
	}
	else
	{
		printf("Wrong!\n");
	}
	return 0;
}        