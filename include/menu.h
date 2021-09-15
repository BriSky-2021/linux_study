#pragma once
#include<string>
#include<iostream>
using namespace std;

struct menu_content
{
	char key=0;
	string displaycontent;
};


/*
	简化版，有待后续增加功能
*/
class menu {
protected:
	menu_content* head;
	int len;
	int maxlength;
public:
	menu(int i) { len = 0; maxlength = i; head = new menu_content[maxlength]; }
	~menu() { delete[] head; }
	int getlen() { return len; }
	bool menu_add(const menu_content& cont);
	char menu_choose();
};


bool menu::menu_add(const menu_content& cont)
{
	if (len >= maxlength)
		return 1;//wrong
	head[len] = cont;
	len++;
	return 0;
}



/*
	返回的是char值

*/
char menu::menu_choose()
{
	if (!cin.good())
		cin.clear();
	cin.ignore(1024, '\n');
	while (1)
	{
		cout << "\n请选择您要进行的操作";
		cout << "[";
		int k = getlen();
		for (int m = 0; m < k; m++)
		{
			cout << " "<<((head + m)->key) << "为" << ((head + m)->displaycontent);
		}
		cout << "0为取消操作]\n";

		cout << "\n请选择您要进行的操作";
		int myget = getchar();
		if (myget == '0')//表示退出
			return 0;
		for (int m = 0; m < k; m++)
		{
			if (myget == (head + m)->key)
				return myget;
		}
		if(!cin.good())
			cin.clear();
		cin.ignore(1024, '\n');
	}
}