// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef map<string, int> si_map;
#define de(x) cout<<#x<<" = "<<x<<endl;

struct Word {///利用结构体排序
	string word;
	int num;
	bool operator < (const Word & a) const {
		if (num == a.num) return word < a.word;
		else return num > a.num;
	}
};
map<string, int>mp;
bool judge(string str) {//判断是否符合条件
	int len = str.length();
	if (len < 4) return false;//长度小于4
	if ((str[0] <= 'Z'&&str[0] >= 'A') || (str[0] <= 'z'&&str[0] >= 'a')) {//开头不能是数字
		for (int i = 0; i < len; i++) {
			if (str[i] <= 'Z'&&str[i] >= 'A') str[i] = str[i] - 'A' + 'a';
		}
		mp[str]++;//存入map
		return true;
	}
	return false;
}

void get(string str, int & num) {//对每行string进行分解
	int len = str.length();
	string neword = "";
	for (int i = 0; i < len; i++) {
		if ((str[i] > 'Z' || str[i] < 'A') && (str[i] > 'z' || str[i] < 'a') && (str[i] > '9' || str[i] < '0')) {
			if (judge(neword)) num++;
			neword = "";
			continue;
		}
		else neword += str[i];
	}
	if (judge(neword)) num++;
}
void work(string file_name) {
	ifstream fin(file_name, ios::in);
	ofstream fout("output.txt", ios::out);//将 ans 写入output文件
	int chnu = 0, words = 0, lines = 0;
	string tmp;
	int nucnt = 0;
	while (getline(fin, tmp)) {
		lines++;//行数记录
		if (tmp.length() == 0) {
			nucnt++;
		}
		chnu += tmp.length();//字符个数记录
		get(tmp, words);//分解每行字符串
	}
	si_map::iterator it;//利用迭代器遍历map
	vector<Word>w;
	for (it = mp.begin(); it != mp.end(); it++) {
		Word t;
		t.word = it->first; t.num = it->second;
		w.push_back(t);
	}
	sort(w.begin(), w.end());
	//读入output文件
	fout << "characters: " << chnu + lines << endl;///chun没有存取回车符
	fout << "words: " << words << endl;
	fout << "lines: " << lines-nucnt << endl;
	int cnt = w.size();;
	for (int i = 0; i < min(10, cnt); i++)
	{
	
		fout << "<" << w[i].word << ">: " << w[i].num << endl;
	}
		return;
}
void output(string file_name){
	
	ifstream fin(file_name, ios::in);
	if (!fin.is_open()) {
		cout << "未成功打开 output 文件" << endl;
		exit(-1);
	}
	string tmp;
	while (getline(fin, tmp)) {
		cout << tmp << endl;
	}
	return;
}
int main(int argc, char *argv[]){
	string file_name;
	//两种方式file_name会不一样
	//file_name = argv[1];当直接用cmd运行exe文件时 
	file_name = argv[2];//当调试时，
	work(file_name);
	output("output.txt");
	return 0;
}