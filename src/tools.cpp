
#include<iostream>
using namespace std;


/*
输入参数：提示，下界，上界
*/
int NumberInput(const char* a, int LowerBound, int UpperBound)
{
	while (1) {
		
		cout << a << "     " << "\b\b\b\b\b";
		int value;
		cin >> value;
		if (cin.good() && value >= LowerBound && value <= UpperBound)
		{
			return value;
		}
		else
		{
			cout << "输入错误，请重新输入\n";
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}

}

int AlphaInput(const char* a, int LowerBound, int UpperBound)
{
	while (1) {
		cout << a;
		char value;
		cin >> value;
		if (value >= LowerBound && value <= UpperBound)
		{
			return value;
		}
		else
		{
			cout << "\n输入错误，请重新输入\n";
			cin.clear();
			cin.ignore();
		}
	}
}