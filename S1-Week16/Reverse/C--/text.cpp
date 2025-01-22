#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
//#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double DD;
// const int MAXLEN=1e9;
#define MAXLEN 0x300
const double E = 2.718281828;
const double PI = 3.1415926535897932384626;
const LL MOD = 1e9+7;

unsigned char ans[] = {97,96,114,70,81,28,80,76,51,27,62,102,56,26,57,56,246,167,217,181,153,186,169,195,135};

int main()
{
	vector<int> v{42,198,7,123,250,89,56,214,33,172,99,64,201,150,78,45,220,12,134,87,53,240,19,68,102};
	sort(v.begin(), v.end());
	
	cout << "Hello World!" << endl;
	cout << "Please input your flag: ";

	string s;
	cin >> s;

	if (s.size() != 25)
	{
		cout << "Sorry, you are wrong!" << endl;
		return 0;
	}

	for (auto &&i : s)
	{
		i ^= v[&i - &s[0]];
	}
	// for (auto &&i : s)
	// {
	// 	cout << (int)(unsigned char)i << " ";
	// }
	
	if (s == string((char*)ans, 25))
	{
		cout << "Congratulations! You got the flag!" << endl;
	}
	else
	{
		cout << "Sorry, you are wrong!" << endl;
	}
}