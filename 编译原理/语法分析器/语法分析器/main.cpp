#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void E();
void T();
void E1();
void T1();
void F();
void i();
char s[100];
int j, k;
int main() {
	printf("������һ����䣬��#�Ž������\n");
	while (1) {
		k = 0;
		j = 0;
		scanf("%s", &s);
		if (s[0] == '#')
			return 0;
		E();
		if (k == 0) {
			if (s[j] == '#')
				printf("�Ϸ���\n");
		}
		printf("������һ����䣬��#�Ž������\n");
	}
	system("pause");
	return 1;
}
void match(char t)
{
	if (s[j] == t)
	{
		j = j + 1;
	}
	else
	{
		printf("���Ϸ�");
	}
}

void E()
{
	if (k == 0)
	{
		T();
		E1();
	}
}

void E1()
{
	if (k == 0)
	{
		if (s[j] == '+')
		{
			match('+');
			T();
			E1();
		}
		else if (s[j] != '#'&&s[j] != ')')
		{
			printf("���Ϸ���\n");
			k = 1;
		}
	}
}

void T()
{
	if (k == 0)
	{
		F();
		T1();
	}
}

void T1()
{
	if (k == 0)
	{
		if (s[j] == '*')
		{
			match('*');
			F();
			T1();
		}
		else if (s[j] != '#'&&s[j] != ')'&&s[j] != '+')
		{
			printf("���Ϸ���\n");
			k = 1;
		}
	}
}

void F()
{
	if (k == 0)
	{
		if (s[j] == '(')
		{
			match('(');
			E();
			if (s[j] == ')')
				match(')');
			else if (s[j] == '#')
			{
				printf("���Ϸ���\n���Ų�ƥ��\n");
				++j;
				k = 1;
			}
		}
		else  i();
	}
}

void i() {
	if (s[j] >= '0'&&s[j] <= '9')
		++j;
	else
	{
		printf("���Ϸ���\n");
		k = 1;
	}
}