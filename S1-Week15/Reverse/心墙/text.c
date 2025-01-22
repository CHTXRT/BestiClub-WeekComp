#include<stdio.h>
#include<string.h>

char flag[] = "}1laW_t2a4H-ed{galf";

int main()
{
	puts("Enter the flag:");
	char input_str[100];
	scanf("%s", input_str);
	int input_str_len = strlen(input_str);

	if(input_str_len != 19)
	{
		printf("Wrong!\n");
		return 0;
	}
	
	for(int i=0;i<input_str_len;i++)
	{
		if(input_str[i] != flag[input_str_len-i-1])
		{
			printf("Wrong!\n");
			return 0;
		}
	}
	printf("You are right!\n");
	return 0;
}        