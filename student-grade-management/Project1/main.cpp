#include <iostream>
#include <string>
#include <fstream>				 //这是对文件的输入输出库函数的头文件
#include"admin.h"
#include"student.h"
#include <iomanip>				
using namespace std;
int passwd = 123456;				//定义全局变量用作输入密码

int main()
{
	system("cls");
	admin head;
	string id, name, c, english, math;
	double avg;
	int password;
	ifstream read("data.txt"); //使用ifstream读取已经保存的文件或即将保存的文件
	if (read)
	{
		while (read >> id >> name >> c >> english >> math >> avg)
		{
			init(head, id, name, c, english, math, avg);
		}
	}
	cout << "请输入管理员密码:";
	cin >> password;
	if (password != passwd)
		exit(0);
	menu1(head);
	return 0;
}