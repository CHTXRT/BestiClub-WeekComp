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

int main()
{
    unsigned char target_str[] =
{
   10,  13,   6,  28,  24,  12,   2,  89, 107,  43, 
   68, 111,  45,  65,  69,  69,  65,   1,  22,  58, 
   40,  71,  66,  30,   8,  25, 125,   0
};
    for(int i = strlen((char *)target_str)-2; i >= 0; i--)
    {
        target_str[i] ^= target_str[i+1];
    }
    for(int i = 0; i < strlen((char *)target_str); i++)
    {
        printf("%c", target_str[i]);
    }
	return 0; //-22 61 13 92
}

//Y0u_4Re_900d_47_id4
/*
input ^ 23 ^ v23
*/