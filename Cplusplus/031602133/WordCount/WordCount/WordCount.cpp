#include "pch.h"
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<map>
#pragma warning(disable:4996)
using namespace std;
const int N = 100007;
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
int main(int argc, char *argv[])
{
	init();
	Scan(argv[1]);
	efchar = Countchar();
	efword = Countword();
	Countmaxword();
	Print();
	return 0;
}