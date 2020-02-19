#include "admin.h"
admin::admin()			//默认构造函数，对象指针的初始化
{
	point1 = 0;
	point2 = 0;
}
void admin::add(admin* n)		//增加函数
{
	n->point2 = point2;			//让n指向point2的位置，再将point2的位置传给n
	n->point1 = this;			//让n指向point1的位置，再将要新建的对象n的位置传给n(this在类成员函数中调用，表示当前对象的位置)
	if (point2 != NULL)			//如果point2所对应的位置为非空
	{
		point2->point1 = n;		//此时，让point2指向point1的位置，再把要新建的n传给point2
	}
	else
	{
		point2 = n;				//如果point2 就是空的，就可以直接把要新建的n传给point2
	}
}
//删除时通过找到相对应的位置，然后删除的
admin* admin::delname1()		//删除链表函数(根据姓名)
{
	if (point1 != 0)			//如果point1所指向的位置不是空
	{
		point1->point2 = point2;		//让point1指向point2 ，将point2 指向point1
	}
	if (point2 != 0)					//如果point2不为空
	{
		point2->point1 = point1;		//让point2指向point1，让后将point2指向point1
	}									//这样两个指针所指向的位置都为空，就实现了删除的功能了
	return 0;
}
admin* admin::delid1()			//功能同上
{
	if (point1 != 0)
	{
		point1->point2 = point2;
	}
	if (point2 != 0)
	{
		point2->point1 = point1;
	}
	return 0;
}
void admin::show()				//admin的显示
{
	cout << "============================" << endl;
	cout << "学号 ：" << setw(8) << ID << endl;
	cout << "姓名 : " << setw(8) << Name << endl;
	cout << "英语 : " << setw(8) << English << endl;
	cout << "C语言 : " << setw(8) << C << endl;
	cout << "数学 : " << setw(8) << Math << endl;
	cout << "平均分 ： " << Avg << endl;
	cout << "=============================";
	cout << endl;
}
void admin::reviseName()			//下面是多个修改函数
{
	string name;
	cin >> name;
	Name = name;
}
void admin::reviseID()
{
	string id;
	cin >> id;
	ID = id;
}
void admin::reviseEnglish()
{
	string english;
	cin >> english;
	English = english;
}
void admin::reviseC()
{
	string c;
	cin >> c;
	C = c;
}
void admin::reviseMath()
{
	string math;
	cin >> math;
	Math = math;
}
admin* delname1(admin& head, string name)		//查找要删除的位置(根据姓名)
{
	for (admin* i = head.point2; i != 0; i = i->point2)		//全部搜索一遍
	{
		if (i->Name == name)					//如果查找到相同的
		{
			return i;							//就返回对应的位置
		}
	}
	return 0;									//找不到就返回空
}
admin* delid1(admin& head, string id)			//查找要删除的位置(根据id)
{
	for (admin* i = head.point2; i != 0; i = i->point2)		//函数功能同上
	{
		if (i->ID == id)
		{
			return i;
		}
	}
	return 0;
}
void display(admin& head)						//显示函数（用以调用类中显示函数）
{

	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		i->show();							//显示全部信息
	}
}
void init(admin& head, string name, string id, string english, string c, string math, double avg)		//方便文件读取
{
	admin* n = new admin;
	n->ID = id;
	n->Name = name;
	n->English = english;
	n->C = c;
	n->Math = math;
	n->Avg = avg;
	head.add(n);				//添加到要编辑的文件中
}
void searchadd(admin& head, string name)			//判断是否重复，添加学生前的判断
{
	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		if (i->Name != name)
		{
			if (i != 0)
			{
				cout << "=====系统没有该生信息，你可以添加=====" << endl;
				enter(head);
				(void)_getch();
				menu1(head);
			}
		}
		else
		{
			cout << "=====该生信息已存在=====" << endl;
			cout << "=====返回菜单后请重新输入=====" << endl;
			(void)_getch();
			menu1(head);
		}
	}
}
void delname(admin* n)				//调用类中的删除函数删除
{
	if (n != 0)						//当n不为空时
		n->delname1();				//就调用依据姓名删除函数
	delete n;						//调用完后，删除此时n的位置
}
void delid(admin* n)				//功能描述同上
{
	if (n != 0)
	{
		n->delid1();
	}
	delete n;
}
void enter(admin& head)					//输入函数，用于添加新的信息
{
	admin* n = new admin;
	cout << "输入学号、姓名、英语、C语言、数学 : " << endl;
	cout << "学号 ： ";
	cin >> n->ID;
	cout << "姓名 ：";
	cin >> n->Name;
	cout << "英语 : ";
	cin >> n->English;
	cout << "C语言 ：";
	cin >> n->C;
	cout << "数学 : ";
	cin >> n->Math;
	double a, b, d;
	istringstream(n->English) >> a;
	istringstream(n->C) >> b;
	istringstream(n->Math) >> d;
	n->Avg = (a + b + d) / 3;
	cout << "====本次录入信息完成========" << endl;
	head.add(n);						//调用类中的
}
void revisename(admin& head, string name)		//根据姓名修改
{
	for (admin* i = head.point2; i != 0; i = i->point2)		//全面搜索
	{
		if (i->Name == name)
		{
			if (i != 0)
			{
				cout << "请核对可能要进行修改的学生信息如下所示：" << endl;
				i->show();
				cout << endl << endl;
				cout << "请选择要修改哪一项，修改之前请确认信息是否准确，该操作不可逆！" << endl;
				cout << "******************    1:修改学号   *********************" << endl;
				cout << "******************    2:修改姓名   *********************" << endl;
				cout << "******************    a:修改英语成绩   *********************" << endl;
				cout << "******************    b:修改C语言成绩   *********************" << endl;
				cout << "******************    c:修改数学成绩   *********************" << endl;
				char c;
				cin >> c;
				switch (c)
				{
				case'1':
					cout << "输入要修改的学号 ： " << endl;
					i->reviseID();
					break;
				case'2':
					cout << "输入要修改的姓名 : " << endl;
					i->reviseName();
					break;
				case'a':
					cout << "输入要修改的英语成绩 : " << endl;
					i->reviseEnglish();
					break;
				case'b':
					cout << "输入要修改的C语言成绩 : " << endl;
					i->reviseC();
					break;
				case'c':
					cout << "输入要修改的数学成绩 :	 " << endl;
					i->reviseMath();
					break;
					save(head);										//保存修改
					cout << "=====本次修改成功，系统已自动保存本次修改=====" << endl;
					(void)_getch();
					menu1(head);				//返回menu1菜单
				}
			}
		}
		else
		{
			cout << "不存在该生信息 : " << endl;
			(void)_getch();
			menu1(head);
		}
	}
}
void reviseid(admin& head, string id)			//根据id修改，原理同上
{
	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		if (i->ID == id)
		{
			if (i != 0)
			{
				cout << "请核对可能要进行修改的学生信息如下所示：" << endl;
				i->show();
				cout << endl << endl;
				cout << "请选择要修改哪一项，修改之前请确认信息是否准确，该操作不可逆！" << endl;
				cout << "******************    1:修改学号   *********************" << endl;
				cout << "******************    2:修改姓名   *********************" << endl;
				cout << "******************    a:修改英语成绩   *********************" << endl;
				cout << "******************    b:修改C语言成绩   *********************" << endl;
				cout << "******************    c:修改数学成绩   *********************" << endl;
				char c;
				cin >> c;
				switch (c)
				{
				case'1':
					cout << "输入要修改的学号 ： " << endl;
					i->reviseID();
					break;
				case'2':
					cout << "输入要修改的姓名 : " << endl;
					i->reviseName();
					break;
				case'a':
					cout << "输入要修改的英语成绩 : " << endl;
					i->reviseEnglish();
					break;
				case'b':
					cout << "输入要修改的C语言成绩 : " << endl;
					i->reviseC();
					break;
				case'c':
					cout << "输入要修改的数学成绩 :	 " << endl;
					i->reviseMath();
					break;
					save(head);
					cout << "=====本次修改成功，系统已自动保存本次修改=====" << endl;
					(void)_getch();
					menu1(head);
				}
			}
		}
		else
		{
			cout << "不存在该生信息 : " << endl;
			(void)_getch();
			menu1(head);
		}
	}
}
void save(admin& head)			//保存函数，用到ofstream函数，将现有信息依照顺序保存到文件里面
{
	ofstream file("data.txt");
	file << "学号" << "\t" << "姓名" << "\t" << "英语" << "C语言" << "\t" << "数学";
	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		file << i->ID << i->Name << i->English << i->C << i->Math;
	}
}
void searchname(admin& head, string name)
{
	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		if (i->Name == name)
		{
			if (i != 0)
			{
				i->show();
				cout << "查询成功！" << endl;
				(void)_getch();
				menu1(head);
			}
		}
		else
		{
			cout << "不存在该生信息！" << endl;
			(void)_getch();
			menu1(head);
		}
	}
}
void searchid(admin& head, string id)
{
	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		if (i->ID == id)
		{
			if (i != 0)
			{
				i->show();
				cout << "查询成功！" << endl;
				(void)_getch();
				menu1(head);
			}
		}
		else
		{
			cout << "不存在该生信息！" << endl;
			(void)_getch();
			menu1(head);
		}
	}
}

void menu1(admin& head)								//admin管理菜单
{
	string a;
	system("cls");
	cout << "==========学生信息管理==========" << endl << endl;
	cout << "1.添加信息" << endl;						//下面有多个选项可以对学生信息进行管理
	cout << "2.查看所有信息" << endl;				    //依据选择，系统不同反应，调用不同函数
	cout << "3.删除信息" << endl;
	cout << "4.查询信息" << endl;
	cout << "5.修改信息" << endl;
	cout << "6.对已进行操作保存" << endl;
	cout << "7.退出程序" << endl;
	cout << "=================================" << endl;
	cout << endl;
	cout << "请选择:" << endl;
	while (true)
	{
		cin >> a;
		if (a == "1")
		{
			cout << "请输入 ：" << endl;
			searchadd(head, a);
			enter(head);
			(void)_getch();
			menu1(head);
		}
		else if (a == "2")
		{
			cout << "数据如下 : " << endl;
			display(head);
			(void)_getch();
			menu1(head);
		}
		else if (a == "3")
		{
			cout << "***** 请输入删除方式 *****" << endl;
			cout << "***** 1:按照姓名删除 *****" << endl;
			cout << "***** 2:按照学号删除 *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case'1':
				cout << "输入要删除学生姓名 : " << endl;
				cin >> a;
				if (delname1(head, a) != 0)
				{
					delname(delname1(head, a));
					cout << "本次删除成功！" << endl;
					(void)_getch();
					menu1(head);
				}
				else
				{
					cout << "不存在该生信息！" << endl;
					(void)_getch();
					menu1(head);
				}
			case'2':
				cout << "输入要删除学生的学号 : " << endl;
				cin >> a;
				if (delid1(head, a) != 0)
				{
					delid(delid1(head, a));
					cout << "本次删除成功！" << endl;
					(void)_getch();
					menu1(head);
				}
				else
				{
					cout << "不存在该生信息！" << endl;
					(void)_getch();
					menu1(head);
				}
			}

		}
		else if (a == "4")
		{
			cout << "***** 请输入查找方式 *****" << endl;
			cout << "***** 1:按照姓名查找 *****" << endl;
			cout << "***** 2:按照学号查找 *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case'1':
				cout << "输入要查询的姓名 : " << endl;
				cin >> a;
				searchname(head, a);
				break;
			case'2':
				cout << "输入要查询的学号 : " << endl;
				cin >> a;
				searchid(head, a);
				break;
			default:
				cout << "输入错误 : " << endl;
				break;
			}
			(void)_getch();
			menu1(head);
		}
		else if (a == "5")
		{
			cout << "***** 请输入修改方式 *****" << endl;
			cout << "***** 1:按照姓名修改 *****" << endl;
			cout << "***** 2:按照学号修改 *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case'1':
				cout << "输入要修改的姓名 : " << endl;
				cin >> a;
				revisename(head, a);
				break;
			case'2':
				cout << "输入要修改的姓名 : " << endl;
				cin >> a;
				revisename(head, a);
				break;
			default:
				cout << "输入错误" << endl;
				break;
			}
			(void)_getch();
			menu1(head);
		}
		else if (a == "6")
		{
			save(head);
			cout << "=====此次所有进行的操作已经保存成功，可以选择退出程序=====" << endl;
			(void)_getch();
			menu1(head);
		}
		else if (a == "7")
		{
			break;
		}
		else
		{
			cout << "无效指令，请重新输入：";
		}
	}
	exit(1);
}
void menu2(admin& head)
{
	string a;
	system("cls");
	cout << "==========学生信息管理==========" << endl << endl;
	cout << "*****1.查找你的所有信息*****" << endl;
	cout << "*****2.修改你的常用信息*****" << endl;
	cout << "*****3.退出程序        *****" << endl;
	cout << "================================" << endl;
	cout << endl;
	cout << "请选择：" << endl;
	while (true)
	{
		cin >> a;
		if (a == "1")
		{
			cout << "***** 请输入查找方式 *****" << endl;
			cout << "***** 1:按照姓名查找 *****" << endl;
			cout << "***** 2:按照学号查找 *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
				cout << " 请再次输入你的姓名: " << endl;
				cin >> a;
				searchname(head, a);
				break;
			case '2':
				cout << " 请再次输入你的学号: " << endl;
				cin >> a;
				searchid(head, a);
				break;
			default:
				cout << "输入错误" << endl;
				break;
			}
			(void)_getch();
			system("cls");
			menu2(head);
		}
		else if (a == "2")
		{
			cout << "***** 请输入修改的查找方式 *****" << endl;
			cout << "***** 1:按照姓名查找方式修改 *****" << endl;
			cout << "***** 2:按照学号查找方式修改 *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
				cout << " 请再次输入你的姓名: " << endl;
				cin >> a;
				revisename(head, a);
				break;
			case '2':
				cout << " 请再次输入你的学号: " << endl;
				cin >> a;
				reviseid(head, a);
				break;
			default:
				cout << "输入错误" << endl;
				break;
			}
			(void)_getch();
			system("cls");
			menu2(head);
		}
		else if (a == "3")
		{
			break;
		}
		else
		{
			cout << "无效指令，请重新输入：";
		}
	}
	exit(1);
}