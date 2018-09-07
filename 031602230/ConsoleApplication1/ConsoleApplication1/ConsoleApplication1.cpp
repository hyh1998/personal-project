#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <map>
using namespace std;
bool check_isChar(char s1)
{
	if ((s1 >= 'a'&&s1 <= 'z') || (s1 >= 'A'&&s1 <= 'Z'))return true;
	else return false;
}
bool check_isVal(char s1)
{
	if ((s1 >= 'a'&&s1 <= 'z') || (s1 >= 'A'&&s1 <= 'Z') || (s1 >= '0'&&s1 <= '9'))return true;
	else return false;
}
bool check(string str)
{
	if (str.length() <= 3)return false;
	if (!(check_isChar(str[0]) && check_isChar(str[1]) && check_isChar(str[2]) && check_isChar(str[3])))return false;
	for (int i = 4; i < str.length(); i++)
	{
		if (!check_isVal(str[i]))return false;
	}
	return true;  
}
int main()
{
	ifstream myfile("配置hpl.txt");
	string str;
	int line_count = 0;
	int line_len = 0;
	int allcount = 0;
	while (getline(myfile, str))
	{
		//cout << str << endl;
		line_len = str.length() + 1; //+1是因为换行符
		//cout << line_len << endl;
		allcount += line_len;		//计算总字符数
		line_count++;				//计算总行数
		int j = 0;
		char tmp[50];
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				//cout << i << ' ' << j;
				int len = i - j;
				//tmp = (char*)malloc(sizeof(char)*len);
				
				memset(tmp, '\0', sizeof(char)*50);
				cout << tmp << endl;
				int t = 0;
				for (int h = j; h < i; h++)
				{
					cout << ' ' << tmp[t] << ' ';
					tmp[t++] = str[h];
					
				}
				j = i + 1;
				cout << tmp << endl;
			}
		}
	}
	cout << "总行数：" << line_count << endl;
	cout << "总字符数：" << allcount << endl;
	//map <string, int> mapStudent;
	//map <string, int> ::iterator it = mapStudent.find("student_one");
	//if (it != mapStudent.end())
	//{
	//	it->second++;
	//	cout << it->second << endl;
	//}
	//else
	//{
	//	mapStudent.insert(map<string, int>::value_type("student_one", 1));
	//}
	//it = mapStudent.find("student_one");
	//if (it != mapStudent.end())
	//{
	//	it->second++;
	//	cout << it->second << endl;
	//}


	return 0;
}


