#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <unistd.h>
#include "defs.h"
// #include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double DD;

void reverse(char* str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

int main()
{
    char flag[] = "}6vvjCl1_xr4G5d{xsfa";
    reverse(flag);

    for(int i = 0,j = strlen(flag); i < strlen(flag); i++,j--)
    {
        if(isalpha(flag[i]))
        {
            if(flag[i] >= 'a' && flag[i] <= 'z')
                flag[i] = ((flag[i]-'a'-j) % 25 + 25) % 25 + 'a';
            else
                flag[i] = ((flag[i]-'A'-j) % 25 + 25) % 25 + 'A';
        }
        else if(isdigit(flag[i]))
        {
            flag[i] = ((flag[i]-'0'-j) % 9 + 9) % 9 + '0';
        }
    }

    cout << flag << endl;

	return 0; //-22 61 13 92
}

//Y0u_4Re_900d_47_id4
/*
input ^ 23 ^ v23
*/