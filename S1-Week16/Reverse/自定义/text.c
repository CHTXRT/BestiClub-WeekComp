#include<stdio.h>
#include<string.h>

char ans[] = "GRJYG077xwkUvxGqGl3RvxZPqX";

char mychar[] = "gu6NszhZ0QSP/BJ52K7fL8tFcRU+TbYHqn9oeIG1ax3jwCpXmDkvMO4VElrAidyW";

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

char* my_encode(const unsigned char* bindata, char* my, int binlength)
{
	int i, j;
	unsigned char current;
	for (i = 0, j = 0 ; i < binlength ; i += 3)
	{
		current = (bindata[i] >> 2) ;
		current &= (unsigned char)0x3F;
		my[j++] = mychar[(int) current];
		current = ((unsigned char)(bindata[i] << 4)) & ((unsigned char)0x30);
		if (i + 1 >= binlength)
		{
			my[j++] = mychar[(int) current];
			// my[j++] = '=';
			// my[j++] = '=';
			break;
		}
		current |= ((unsigned char)(bindata[i + 1] >> 4)) & ((unsigned char) 0x0F);
		my[j++] = mychar[(int) current];
		current = ((unsigned char)(bindata[i + 1] << 2)) & ((unsigned char) 0x3C);
		if (i + 2 >= binlength)
		{
			my[j++] = mychar[(int) current];
			// my[j++] = '=';
			break;
		}
		current |= ((unsigned char)(bindata[i + 2] >> 6)) & ((unsigned char) 0x03);
		my[j++] = mychar[(int) current];
		current = ((unsigned char)bindata[i + 2]) & ((unsigned char) 0x3F);
		my[j++] = mychar[(int) current];
	}
	my[j] = '\0';
	return my;
}

int main()
{
	ver(mychar);

	puts("Enter the flag:");
	char input_str[100];
	scanf("%s", input_str);
	int input_str_len = strlen(input_str);

	char retchar[100];
	my_encode((unsigned char*)input_str, retchar, input_str_len);
	// printf(retchar);

	if(strcmp(retchar, ans) == 0)
	{
		printf("You are right!\n");
	}
	else
	{
		printf("Wrong!\n");
	}
	return 0;
}        