#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;
int num = 0;//真正的编号
struct linkman {
	char name[10];
	int num;
	char phone[12];
}people[50] = { 0 };
int operate()
{
	int choice;

	cout << "1.排序\t\t2.添加\t\t3.删除" << endl;
	cout << "4.修改\t\t5.查找\t\t6.退出程序" << endl;
	cout << "\n请输入你的选择   ";
	cin >> choice;
	getchar();
	return choice;
}
int meun()
{
	int i;
	cout << "==========通讯录==========\n\n";
	for (i = 0;i < num;i++)
	{
		if (people[i].num != 0)
			printf("编号：%d\t\t姓名：%s\t\t电话：%s\t\t\n", people[i].num, people[i].name, people[i].phone);
	}
	cout << "==========首页==========" << endl;
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
	cout << "1.按编号排序\t2.按姓名排序\n请选择排序方式: ";
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
	cout << "请输入联系人编号：";
	cin >> num0;
	getchar();
	for (int k = 0;k < 50;k++)
	{
		if (people[k].num == num0)
		{
			cout << "联系人已存在！！";
			system("pause");
			return;
		}
	}
	people[num1].num = num0;
	cout << "请输入联系人姓名：";
	cin.getline(people[num1].name, 10);
	cout << "请输入联系人电话：";
	cin.getline(people[num1].phone, 12);
}
void delete1()
{
	int num2;
	cout << "请输入你要删除的编号：";
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
	cout << "请输入你想修改的通讯录人员编号：";
	cin >> num5;
	getchar();
	for (int k = 0;k < 50;k++)
	{
		if (people[k].num == num5)
		{
			cout << "修改前:\nName: " << people[k].name
				<< "\tPhone: " << people[k].phone << endl;
			cout << "请修改：\nName: ";
			cin.getline(rename, 10);
			strcpy(people[k].name, rename);

			cout << "Phone: ";
			cin.getline(rephone, 12);
			strcpy(people[k].phone, rephone);
			cout << "修改完毕！\n按回车继续";
			system("pause");
			return;
		}
	}
	cout << "查无此人！！！！";
	system("pause");
}
void locate()
{
	int num3;
	cout << "请输入你要查找的编号：";
	cin >> num3;
	getchar();
	for (int q = 0;q < 50;q++)
	{
		if (people[q].num == num3)
		{
			cout << "Name: " << people[q].name
				<< "\tPhone: " << people[q].phone << endl;
			cout << "按回车继续";
			system("pause");
			return;
		}
	}
	cout << "Not Found!!!" << endl;
	cout << "按回车继续";
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
		default:cout << "输入错误！！！\n";system("pause");break;
		}
	}
}