#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<sstream>
#include"student.h"
using namespace std;
class admin :virtual public student		//虚拟派生函数，这样可以调用student中的属性
{
public:
	admin* point1;				//定义对象指针point1
	admin* point2;				//定义对象指针point2
	admin();					//admin的默认构造函数
	void add(admin* n);			//添加函数
	admin* delname1();			//根据姓名删除
	admin* delid1();			//根据学号删除

	void show();				//用来显示admin端的
	void reviseID();			//多个修改函数
	void reviseName();
	void reviseEnglish();
	void reviseC();
	void reviseMath();
};
admin* delname1(admin& head, string name);		//找到要删除的位置
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
