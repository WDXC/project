#include "admin.h"
admin::admin()			//Ĭ�Ϲ��캯��������ָ��ĳ�ʼ��
{
	point1 = 0;
	point2 = 0;
}
void admin::add(admin* n)		//���Ӻ���
{
	n->point2 = point2;			//��nָ��point2��λ�ã��ٽ�point2��λ�ô���n
	n->point1 = this;			//��nָ��point1��λ�ã��ٽ�Ҫ�½��Ķ���n��λ�ô���n(this�����Ա�����е��ã���ʾ��ǰ�����λ��)
	if (point2 != NULL)			//���point2����Ӧ��λ��Ϊ�ǿ�
	{
		point2->point1 = n;		//��ʱ����point2ָ��point1��λ�ã��ٰ�Ҫ�½���n����point2
	}
	else
	{
		point2 = n;				//���point2 ���ǿյģ��Ϳ���ֱ�Ӱ�Ҫ�½���n����point2
	}
}
//ɾ��ʱͨ���ҵ����Ӧ��λ�ã�Ȼ��ɾ����
admin* admin::delname1()		//ɾ��������(��������)
{
	if (point1 != 0)			//���point1��ָ���λ�ò��ǿ�
	{
		point1->point2 = point2;		//��point1ָ��point2 ����point2 ָ��point1
	}
	if (point2 != 0)					//���point2��Ϊ��
	{
		point2->point1 = point1;		//��point2ָ��point1���ú�point2ָ��point1
	}									//��������ָ����ָ���λ�ö�Ϊ�գ���ʵ����ɾ���Ĺ�����
	return 0;
}
admin* admin::delid1()			//����ͬ��
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
void admin::show()				//admin����ʾ
{
	cout << "============================" << endl;
	cout << "ѧ�� ��" << setw(8) << ID << endl;
	cout << "���� : " << setw(8) << Name << endl;
	cout << "Ӣ�� : " << setw(8) << English << endl;
	cout << "C���� : " << setw(8) << C << endl;
	cout << "��ѧ : " << setw(8) << Math << endl;
	cout << "ƽ���� �� " << Avg << endl;
	cout << "=============================";
	cout << endl;
}
void admin::reviseName()			//�����Ƕ���޸ĺ���
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
admin* delname1(admin& head, string name)		//����Ҫɾ����λ��(��������)
{
	for (admin* i = head.point2; i != 0; i = i->point2)		//ȫ������һ��
	{
		if (i->Name == name)					//������ҵ���ͬ��
		{
			return i;							//�ͷ��ض�Ӧ��λ��
		}
	}
	return 0;									//�Ҳ����ͷ��ؿ�
}
admin* delid1(admin& head, string id)			//����Ҫɾ����λ��(����id)
{
	for (admin* i = head.point2; i != 0; i = i->point2)		//��������ͬ��
	{
		if (i->ID == id)
		{
			return i;
		}
	}
	return 0;
}
void display(admin& head)						//��ʾ���������Ե���������ʾ������
{

	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		i->show();							//��ʾȫ����Ϣ
	}
}
void init(admin& head, string name, string id, string english, string c, string math, double avg)		//�����ļ���ȡ
{
	admin* n = new admin;
	n->ID = id;
	n->Name = name;
	n->English = english;
	n->C = c;
	n->Math = math;
	n->Avg = avg;
	head.add(n);				//��ӵ�Ҫ�༭���ļ���
}
void searchadd(admin& head, string name)			//�ж��Ƿ��ظ������ѧ��ǰ���ж�
{
	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		if (i->Name != name)
		{
			if (i != 0)
			{
				cout << "=====ϵͳû�и�����Ϣ����������=====" << endl;
				enter(head);
				(void)_getch();
				menu1(head);
			}
		}
		else
		{
			cout << "=====������Ϣ�Ѵ���=====" << endl;
			cout << "=====���ز˵�������������=====" << endl;
			(void)_getch();
			menu1(head);
		}
	}
}
void delname(admin* n)				//�������е�ɾ������ɾ��
{
	if (n != 0)						//��n��Ϊ��ʱ
		n->delname1();				//�͵�����������ɾ������
	delete n;						//�������ɾ����ʱn��λ��
}
void delid(admin* n)				//��������ͬ��
{
	if (n != 0)
	{
		n->delid1();
	}
	delete n;
}
void enter(admin& head)					//���뺯������������µ���Ϣ
{
	admin* n = new admin;
	cout << "����ѧ�š�������Ӣ�C���ԡ���ѧ : " << endl;
	cout << "ѧ�� �� ";
	cin >> n->ID;
	cout << "���� ��";
	cin >> n->Name;
	cout << "Ӣ�� : ";
	cin >> n->English;
	cout << "C���� ��";
	cin >> n->C;
	cout << "��ѧ : ";
	cin >> n->Math;
	double a, b, d;
	istringstream(n->English) >> a;
	istringstream(n->C) >> b;
	istringstream(n->Math) >> d;
	n->Avg = (a + b + d) / 3;
	cout << "====����¼����Ϣ���========" << endl;
	head.add(n);						//�������е�
}
void revisename(admin& head, string name)		//���������޸�
{
	for (admin* i = head.point2; i != 0; i = i->point2)		//ȫ������
	{
		if (i->Name == name)
		{
			if (i != 0)
			{
				cout << "��˶Կ���Ҫ�����޸ĵ�ѧ����Ϣ������ʾ��" << endl;
				i->show();
				cout << endl << endl;
				cout << "��ѡ��Ҫ�޸���һ��޸�֮ǰ��ȷ����Ϣ�Ƿ�׼ȷ���ò��������棡" << endl;
				cout << "******************    1:�޸�ѧ��   *********************" << endl;
				cout << "******************    2:�޸�����   *********************" << endl;
				cout << "******************    a:�޸�Ӣ��ɼ�   *********************" << endl;
				cout << "******************    b:�޸�C���Գɼ�   *********************" << endl;
				cout << "******************    c:�޸���ѧ�ɼ�   *********************" << endl;
				char c;
				cin >> c;
				switch (c)
				{
				case'1':
					cout << "����Ҫ�޸ĵ�ѧ�� �� " << endl;
					i->reviseID();
					break;
				case'2':
					cout << "����Ҫ�޸ĵ����� : " << endl;
					i->reviseName();
					break;
				case'a':
					cout << "����Ҫ�޸ĵ�Ӣ��ɼ� : " << endl;
					i->reviseEnglish();
					break;
				case'b':
					cout << "����Ҫ�޸ĵ�C���Գɼ� : " << endl;
					i->reviseC();
					break;
				case'c':
					cout << "����Ҫ�޸ĵ���ѧ�ɼ� :	 " << endl;
					i->reviseMath();
					break;
					save(head);										//�����޸�
					cout << "=====�����޸ĳɹ���ϵͳ���Զ����汾���޸�=====" << endl;
					(void)_getch();
					menu1(head);				//����menu1�˵�
				}
			}
		}
		else
		{
			cout << "�����ڸ�����Ϣ : " << endl;
			(void)_getch();
			menu1(head);
		}
	}
}
void reviseid(admin& head, string id)			//����id�޸ģ�ԭ��ͬ��
{
	for (admin* i = head.point2; i != 0; i = i->point2)
	{
		if (i->ID == id)
		{
			if (i != 0)
			{
				cout << "��˶Կ���Ҫ�����޸ĵ�ѧ����Ϣ������ʾ��" << endl;
				i->show();
				cout << endl << endl;
				cout << "��ѡ��Ҫ�޸���һ��޸�֮ǰ��ȷ����Ϣ�Ƿ�׼ȷ���ò��������棡" << endl;
				cout << "******************    1:�޸�ѧ��   *********************" << endl;
				cout << "******************    2:�޸�����   *********************" << endl;
				cout << "******************    a:�޸�Ӣ��ɼ�   *********************" << endl;
				cout << "******************    b:�޸�C���Գɼ�   *********************" << endl;
				cout << "******************    c:�޸���ѧ�ɼ�   *********************" << endl;
				char c;
				cin >> c;
				switch (c)
				{
				case'1':
					cout << "����Ҫ�޸ĵ�ѧ�� �� " << endl;
					i->reviseID();
					break;
				case'2':
					cout << "����Ҫ�޸ĵ����� : " << endl;
					i->reviseName();
					break;
				case'a':
					cout << "����Ҫ�޸ĵ�Ӣ��ɼ� : " << endl;
					i->reviseEnglish();
					break;
				case'b':
					cout << "����Ҫ�޸ĵ�C���Գɼ� : " << endl;
					i->reviseC();
					break;
				case'c':
					cout << "����Ҫ�޸ĵ���ѧ�ɼ� :	 " << endl;
					i->reviseMath();
					break;
					save(head);
					cout << "=====�����޸ĳɹ���ϵͳ���Զ����汾���޸�=====" << endl;
					(void)_getch();
					menu1(head);
				}
			}
		}
		else
		{
			cout << "�����ڸ�����Ϣ : " << endl;
			(void)_getch();
			menu1(head);
		}
	}
}
void save(admin& head)			//���溯�����õ�ofstream��������������Ϣ����˳�򱣴浽�ļ�����
{
	ofstream file("data.txt");
	file << "ѧ��" << "\t" << "����" << "\t" << "Ӣ��" << "C����" << "\t" << "��ѧ";
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
				cout << "��ѯ�ɹ���" << endl;
				(void)_getch();
				menu1(head);
			}
		}
		else
		{
			cout << "�����ڸ�����Ϣ��" << endl;
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
				cout << "��ѯ�ɹ���" << endl;
				(void)_getch();
				menu1(head);
			}
		}
		else
		{
			cout << "�����ڸ�����Ϣ��" << endl;
			(void)_getch();
			menu1(head);
		}
	}
}

void menu1(admin& head)								//admin����˵�
{
	string a;
	system("cls");
	cout << "==========ѧ����Ϣ����==========" << endl << endl;
	cout << "1.�����Ϣ" << endl;						//�����ж��ѡ����Զ�ѧ����Ϣ���й���
	cout << "2.�鿴������Ϣ" << endl;				    //����ѡ��ϵͳ��ͬ��Ӧ�����ò�ͬ����
	cout << "3.ɾ����Ϣ" << endl;
	cout << "4.��ѯ��Ϣ" << endl;
	cout << "5.�޸���Ϣ" << endl;
	cout << "6.���ѽ��в�������" << endl;
	cout << "7.�˳�����" << endl;
	cout << "=================================" << endl;
	cout << endl;
	cout << "��ѡ��:" << endl;
	while (true)
	{
		cin >> a;
		if (a == "1")
		{
			cout << "������ ��" << endl;
			searchadd(head, a);
			enter(head);
			(void)_getch();
			menu1(head);
		}
		else if (a == "2")
		{
			cout << "�������� : " << endl;
			display(head);
			(void)_getch();
			menu1(head);
		}
		else if (a == "3")
		{
			cout << "***** ������ɾ����ʽ *****" << endl;
			cout << "***** 1:��������ɾ�� *****" << endl;
			cout << "***** 2:����ѧ��ɾ�� *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case'1':
				cout << "����Ҫɾ��ѧ������ : " << endl;
				cin >> a;
				if (delname1(head, a) != 0)
				{
					delname(delname1(head, a));
					cout << "����ɾ���ɹ���" << endl;
					(void)_getch();
					menu1(head);
				}
				else
				{
					cout << "�����ڸ�����Ϣ��" << endl;
					(void)_getch();
					menu1(head);
				}
			case'2':
				cout << "����Ҫɾ��ѧ����ѧ�� : " << endl;
				cin >> a;
				if (delid1(head, a) != 0)
				{
					delid(delid1(head, a));
					cout << "����ɾ���ɹ���" << endl;
					(void)_getch();
					menu1(head);
				}
				else
				{
					cout << "�����ڸ�����Ϣ��" << endl;
					(void)_getch();
					menu1(head);
				}
			}

		}
		else if (a == "4")
		{
			cout << "***** ��������ҷ�ʽ *****" << endl;
			cout << "***** 1:������������ *****" << endl;
			cout << "***** 2:����ѧ�Ų��� *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case'1':
				cout << "����Ҫ��ѯ������ : " << endl;
				cin >> a;
				searchname(head, a);
				break;
			case'2':
				cout << "����Ҫ��ѯ��ѧ�� : " << endl;
				cin >> a;
				searchid(head, a);
				break;
			default:
				cout << "������� : " << endl;
				break;
			}
			(void)_getch();
			menu1(head);
		}
		else if (a == "5")
		{
			cout << "***** �������޸ķ�ʽ *****" << endl;
			cout << "***** 1:���������޸� *****" << endl;
			cout << "***** 2:����ѧ���޸� *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case'1':
				cout << "����Ҫ�޸ĵ����� : " << endl;
				cin >> a;
				revisename(head, a);
				break;
			case'2':
				cout << "����Ҫ�޸ĵ����� : " << endl;
				cin >> a;
				revisename(head, a);
				break;
			default:
				cout << "�������" << endl;
				break;
			}
			(void)_getch();
			menu1(head);
		}
		else if (a == "6")
		{
			save(head);
			cout << "=====�˴����н��еĲ����Ѿ�����ɹ�������ѡ���˳�����=====" << endl;
			(void)_getch();
			menu1(head);
		}
		else if (a == "7")
		{
			break;
		}
		else
		{
			cout << "��Чָ����������룺";
		}
	}
	exit(1);
}
void menu2(admin& head)
{
	string a;
	system("cls");
	cout << "==========ѧ����Ϣ����==========" << endl << endl;
	cout << "*****1.�������������Ϣ*****" << endl;
	cout << "*****2.�޸���ĳ�����Ϣ*****" << endl;
	cout << "*****3.�˳�����        *****" << endl;
	cout << "================================" << endl;
	cout << endl;
	cout << "��ѡ��" << endl;
	while (true)
	{
		cin >> a;
		if (a == "1")
		{
			cout << "***** ��������ҷ�ʽ *****" << endl;
			cout << "***** 1:������������ *****" << endl;
			cout << "***** 2:����ѧ�Ų��� *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
				cout << " ���ٴ������������: " << endl;
				cin >> a;
				searchname(head, a);
				break;
			case '2':
				cout << " ���ٴ��������ѧ��: " << endl;
				cin >> a;
				searchid(head, a);
				break;
			default:
				cout << "�������" << endl;
				break;
			}
			(void)_getch();
			system("cls");
			menu2(head);
		}
		else if (a == "2")
		{
			cout << "***** �������޸ĵĲ��ҷ�ʽ *****" << endl;
			cout << "***** 1:�����������ҷ�ʽ�޸� *****" << endl;
			cout << "***** 2:����ѧ�Ų��ҷ�ʽ�޸� *****" << endl;
			char c;
			cin >> c;
			switch (c)
			{
			case '1':
				cout << " ���ٴ������������: " << endl;
				cin >> a;
				revisename(head, a);
				break;
			case '2':
				cout << " ���ٴ��������ѧ��: " << endl;
				cin >> a;
				reviseid(head, a);
				break;
			default:
				cout << "�������" << endl;
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
			cout << "��Чָ����������룺";
		}
	}
	exit(1);
}