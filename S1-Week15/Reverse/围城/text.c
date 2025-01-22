#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char road[] = "s****######*********\
###*#######*#######*\
###*********#####***\
#####*###########*##\
#####*###########*##\
#####***********#*##\
###***#####*###*#*##\
###*#######*###*#*##\
###*#######*###*#*##\
###*#######*###***##\
##*****####*###*#*##\
#####*#####*###*#*##\
#####*#####*###*#*##\
#####*******###*#*##\
###########*###*#*##\
###########*###*#*##\
###########*###*#*##\
###########*###*#*##\
###*************#*##\
#################**y";

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
    puts("Welcome to DKYer Maze!");
    puts("");
}

int main()
{
	banner();

	puts("You are in a maze, and you need to find the shortest road to the destination to get the flag.");
	char nextstep;
	int nowx = 0;
	int nowy = 0;
	int steps = 0;

	while(1)
	{
		printf("Enter your next step (w: up, s: down, a: left, d: right): ");
		while((nextstep = getchar()) == '\n' || nextstep == ' ');
		steps ++;
		
		switch(nextstep)
		{
			case 'w':
				if(nowy == 0)
				{
					puts("You can't go up.");
					continue;
				}
				if(road[(nowy-1)*20+nowx] == '#')
				{
					puts("You hit the wall and died.");
					exit(0);
				}
				if(road[(nowy-1)*20+nowx] == 'y')
				{
					goto end;
				}
				nowy--;
				break;
			case 's':
				if(nowy == 19)
				{
					puts("You can't go down.");
					continue;
				}
				if(road[(nowy+1)*20+nowx] == '#')
				{
					puts("You hit the wall and died.");
					exit(0);
				}
				if(road[(nowy+1)*20+nowx] == 'y')
				{
					goto end;
				}
				nowy++;
				break;
			case 'a':
				if(nowx == 0)
				{
					puts("You can't go left.");
					continue;
				}
				if(road[nowy*20+nowx-1] == '#')
				{
					puts("You hit the wall and died.");
					exit(0);
				}
				if(road[nowy*20+nowx-1] == 'y')
				{
					goto end;
				}
				nowx--;
				break;
			case 'd':
				if(nowx == 19)
				{
					puts("You can't go right.");
					continue;
				}
				if(road[nowy*20+nowx+1] == '#')
				{
					puts("You hit the wall and died.");
					exit(0);
				}
				if(road[nowy*20+nowx+1] == 'y')
				{
					goto end;
				}
				nowx++;
				break;
			default:
				puts("Invalid input.");
				continue;
		}
	}

end:
	puts("");
	puts("Congratulations! You found the destination!");
	if(steps == 38)
	{
		puts("Flag: flag{what you input}");
		puts("such as \"flag{wssadawd}\"");
		puts("Bye!");
	}
	else
	{
		puts("But it\'s not the shortest road.");
		puts("Try again!");
	}
	
	return 0;
}        