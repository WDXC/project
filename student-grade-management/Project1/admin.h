#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<sstream>
#include"student.h"
using namespace std;
class admin :virtual public student		//���������������������Ե���student�е�����
{
public:
	admin* point1;				//�������ָ��point1
	admin* point2;				//�������ָ��point2
	admin();					//admin��Ĭ�Ϲ��캯��
	void add(admin* n);			//��Ӻ���
	admin* delname1();			//��������ɾ��
	admin* delid1();			//����ѧ��ɾ��

	void show();				//������ʾadmin�˵�
	void reviseID();			//����޸ĺ���
	void reviseName();
	void reviseEnglish();
	void reviseC();
	void reviseMath();
};
admin* delname1(admin& head, string name);		//�ҵ�Ҫɾ����λ��
admin* delid1(admin& head, string name);
void init(admin& head, string name, string id, string english, string c, string math, double avg);
void searchadd(admin& head, string name);
void delname(admin* n);
void delname(admin* n);
void revisename(admin& head, string name);
void reviseid(admin& head, string id);
void enter(admin& head);
void display(admin& head);
void save(admin& head);
void menu1(admin& head);
void searchname(admin& head, string name);
void searchid(admin& head, string id);
