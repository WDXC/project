#include <iostream>
#include <string>
#include <fstream>				 //���Ƕ��ļ�����������⺯����ͷ�ļ�
#include"admin.h"
#include"student.h"
#include <iomanip>				
using namespace std;
int passwd = 123456;				//����ȫ�ֱ���������������

int main()
{
	system("cls");
	admin head;
	string id, name, c, english, math;
	double avg;
	int password;
	ifstream read("data.txt"); //ʹ��ifstream��ȡ�Ѿ�������ļ��򼴽�������ļ�
	if (read)
	{
		while (read >> id >> name >> c >> english >> math >> avg)
		{
			init(head, id, name, c, english, math, avg);
		}
	}
	cout << "���������Ա����:";
	cin >> password;
	if (password != passwd)
		exit(0);
	menu1(head);
	return 0;
}