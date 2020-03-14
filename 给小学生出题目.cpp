#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
double answer(double a, double b, double c, char m, char n)
{
	double answer2 = 0;

	if (m == '+')
	{
		if (n == '*')
			answer2 = b * c;
		if (n == '/')
			answer2 = b / c;
		if (n == '+')
			answer2 = b + c;
		if (n == '-')
			answer2 = b - c;
		answer2 += a;
	}
	if (m == '-')
	{
		if (n == '*')
			answer2 = b * c;
		if (n == '/')
			answer2 = b / c;
		if (n == '+')
			answer2 = b + c;
		if (n == '-')
			answer2 = b - c;
		answer2 = a - answer2;
	}
	if (m == '*' && n == '*')
		answer2 = a * b * c;
	if (m == '*' && n == '/')
		answer2 = a * b / c;
	if (m == '*' && n == '-')
		answer2 = a * b - c;
	if (m == '*' && n == '+')
		answer2 = a * b + c;
	if (m == '/' && n == '*')
		answer2 = a / b * c;	
	if (m == '/' && n == '/')
		answer2 = a / b / c;
	if (m == '/' && n == '-')
		answer2 = a / b - c;
	if (m == '/' && n == '+')
		answer2 = a / b + c;
	return answer2;
}
void help()
{
	printf("帮助信息\n");
	printf("您需要输入命令代号来进行操作, 且\n");
	printf("一年级题目为不超过十位的加减法;\n");
	printf("二年级题目为不超过百位的乘除法;\n");
	printf("三年级题目为不超过百位的加减乘除混合题目.\n");
}
void menu()
{
	printf("操作列表：\n");
	printf("（1）一年级\t（2）二年级\t（3）三年级\n");
	printf("（4）帮助\t（5）退出程序\t（6）清屏\n");
}
void first_grade()
{
	int num1, num2, num3 = 0, algorithm, i;
	char symbol, symbol2 = '+';
	double answer1;
	printf("一年级计算题目生成！！\n请输入生成个数");
	scanf("%d", &i);
	while (i)
	{
		num1 = rand() % 10;
		num2 = rand() % 10;
		algorithm = rand() % 10;
		if (algorithm % 2 == 0)
			symbol = '-';
		else
			symbol = '+';
		answer1 = answer(num1, num2, num3, symbol, symbol2);
		printf("%d %c %d = %g\n", num1, symbol, num2, answer1);
		i--;
	}
}
void second_grade()
{
	int num1, num2, num3 = 0, algorithm, i;
	char symbol, symbol2 = '+';
	double answer1;
	printf("二年级计算题目生成！！\n请输入生成个数");
	scanf("%d", &i);
	while (i)
	{
		num1 = rand() % 100;
		num2 = rand() % 100;
		algorithm = rand() % 10;
		if (algorithm % 2 == 0)
			symbol = '*';
		else
		{
			symbol = '/';
			num2 = rand() % 100 + 1;
		}
		answer1 = answer(num1, num2, num3, symbol, symbol2);
		printf("%d %c %d = %g\n", num1, symbol, num2, answer1);
		i--;
	}
}
void third_grade()
{
	int num1, num2, num3, algorithm1, algorithm2, i;
	char symbol, symbol2;
	double answer1;
	printf("三年级计算题目生成！！\n请输入生成个数");
	scanf("%d", &i);
	while (i)
	{
		num1 = rand() % 100;
		num2 = rand() % 100;
		num3 = rand() % 100;
		algorithm1 = rand() % 40;
		algorithm2 = rand() % 80;
		if (algorithm1 % 4 == 0)
			symbol = '*';
		else if (algorithm1 % 4 == 1)
		{
			symbol = '/';
			num2 = rand() % 100 + 1;
		}
		else if (algorithm1 % 4 == 2)
			symbol = '+';
		else
			symbol = '-';
		if (algorithm2 % 4 == 0)
			symbol2 = '*';
		else if (algorithm2 % 4 == 1)
		{
			symbol2 = '/';
			num3 = rand() % 100 + 1;
		}
		else if (algorithm2 % 4 == 2)
			symbol2 = '+';
		else
			symbol2 = '-';

		answer1 = answer(num1, num2, num3, symbol, symbol2);
		printf("%d %c %d %c %d = %g\n", num1, symbol, num2, symbol2, num3, answer1);
		i--;
	}
}
int main()
{
	int choice, num_operate;
	printf("欢迎使用口算生成器 ：\n\n\n");
	help();
	printf("（按回车继续）\n\n");
	getchar();
lp:system("cls");
	menu();
	printf("请输入你的选择 ：____");
	srand((unsigned)time(NULL));
	while (1)
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:first_grade();break;
		case 2:second_grade();break;
		case 3:third_grade();break;
		case 4:help();break;
		case 5:printf("程序结束, 欢迎下次使用");return 0;
		case 6:goto lp;break;
		default:printf("Error!!!\n错误指令请重新输入");break;
		}
		printf("生成完毕，请继续输入你的选择 ：____\n\n\n");
	}
}