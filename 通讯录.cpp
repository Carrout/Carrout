#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;
int num = 0;//�����ı��
struct linkman {
	char name[10];
	int num;
	char phone[12];
}people[50] = { 0 };
int operate()
{
	int choice;

	cout << "1.����\t\t2.���\t\t3.ɾ��" << endl;
	cout << "4.�޸�\t\t5.����\t\t6.�˳�����" << endl;
	cout << "\n���������ѡ��   ";
	cin >> choice;
	getchar();
	return choice;
}
int meun()
{
	int i;
	cout << "==========ͨѶ¼==========\n\n";
	for (i = 0;i < num;i++)
	{
		if (people[i].num != 0)
			printf("��ţ�%d\t\t������%s\t\t�绰��%s\t\t\n", people[i].num, people[i].name, people[i].phone);
	}
	cout << "==========��ҳ==========" << endl;
	return operate();
}
void sort2()
{
	int d, f, num6 = 0;
	for (d = 0;d < num;d++)
	{
		num6 = people[d].num;
		for (f = d + 1;f < num;f++)
		{
			if (people[f].num < num6)
			{
				swap(people[f], people[d]);
			}
		}
	}
}
void sort3()
{
	int d, f;
	char name1[10];
	for (d = 0;d < num;d++)
	{
		strcpy(name1, people[d].name);
		for (f = d + 1;f < num;f++)
		{
			if (strcmp(people[f].name, name1) < 1)
			{
				swap(people[f], people[d]);
			}
		}
	}
}
void sort1()
{
	int choice1;
	cout << "1.���������\t2.����������\n��ѡ������ʽ: ";
	cin >> choice1;
	getchar();
	switch (choice1)
	{
	case 1:sort2();break;
	case 2:sort3();break;
	}
	return;
}
void add(int num1)
{
	int num0;
	cout << "��������ϵ�˱�ţ�";
	cin >> num0;
	getchar();
	for (int k = 0;k < 50;k++)
	{
		if (people[k].num == num0)
		{
			cout << "��ϵ���Ѵ��ڣ���";
			system("pause");
			return;
		}
	}
	people[num1].num = num0;
	cout << "��������ϵ��������";
	cin.getline(people[num1].name, 10);
	cout << "��������ϵ�˵绰��";
	cin.getline(people[num1].phone, 12);
}
void delete1()
{
	int num2;
	cout << "��������Ҫɾ���ı�ţ�";
	cin >> num2;
	getchar();
	for (int k = 0;k < 50;k++)
	{
		if (people[k].num == num2)
		{
			people[k].num = 0;
		}
	}

}
void rewrite()
{
	int num5;
	char rename[10], rephone[12];
	cout << "�����������޸ĵ�ͨѶ¼��Ա��ţ�";
	cin >> num5;
	getchar();
	for (int k = 0;k < 50;k++)
	{
		if (people[k].num == num5)
		{
			cout << "�޸�ǰ:\nName: " << people[k].name
				<< "\tPhone: " << people[k].phone << endl;
			cout << "���޸ģ�\nName: ";
			cin.getline(rename, 10);
			strcpy(people[k].name, rename);

			cout << "Phone: ";
			cin.getline(rephone, 12);
			strcpy(people[k].phone, rephone);
			cout << "�޸���ϣ�\n���س�����";
			system("pause");
			return;
		}
	}
	cout << "���޴��ˣ�������";
	system("pause");
}
void locate()
{
	int num3;
	cout << "��������Ҫ���ҵı�ţ�";
	cin >> num3;
	getchar();
	for (int q = 0;q < 50;q++)
	{
		if (people[q].num == num3)
		{
			cout << "Name: " << people[q].name
				<< "\tPhone: " << people[q].phone << endl;
			cout << "���س�����";
			system("pause");
			return;
		}
	}
	cout << "Not Found!!!" << endl;
	cout << "���س�����";
	system("pause");
}
int main()
{
	int choice;
	while (true)
	{
		system("cls");
		choice = meun();
		switch (choice)
		{
		case 1:sort1();break;
		case 2:add(num++);break;
		case 3:delete1();break;
		case 4:rewrite();break;
		case 5:locate();break;
		case 6:return 0;break;
		default:cout << "������󣡣���\n";system("pause");break;
		}
	}
}