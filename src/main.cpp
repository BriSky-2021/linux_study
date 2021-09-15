#define _CRT_SECURE_NO_WARNINGS
#include"TestStudent.h"
#include"LinkedList.h"
#include"menu.h"
#include"tools.h"
#include<iostream>
using namespace std;

//性别的输入选择
static const char GENDER[2][4]={"男","女"};


const int AMOUNT_OF_MUNE=5;

const menu_content CONMENU[AMOUNT_OF_MUNE] = {
	{'1',"插入"},
	{'2',"删除"},
	{'3',"查找"},
	{'4',"修改"},
	{'5',"统计"}
};

const struct {
	unsigned int number;//考号
	string name;//姓名
	string gender;//性别
	unsigned int age;//年龄
	string occupation;//报考类别
}TStu[4] = {
	{234,"Dick","男",18,"蓝翔技术学院"},
	{123,"张三","男",20,"新东方厨师烹饪学院"},
	{789,"Richard","男",30,"外包企业工"},
	{555,"小龙女","女",18,"武林高手"}
};



int main()
{

	//cout<<"hello world"<<endl;

	if (1)
	{
		//链表建立
		TestStudent stu;

		LinkedList<TestStudent> LL;

		LL.input();

		while (1)
		{
			//输出链表信息
			cout << endl;
			display_student();
			LL.output();

			//菜单建立
			menu ME(AMOUNT_OF_MUNE);
			for (int i = 0; i < AMOUNT_OF_MUNE; i++)
				ME.menu_add(CONMENU[i]);
			int ret = ME.menu_choose();
			if (ret == CONMENU[0].key)//插入
			{
				int lllen = LL.Length();
				int pos=0;
				char messa[50] = {0};
				sprintf(messa, "请输入你要插入的考生的位置[1,%d]\n", lllen + 1);
				pos=NumberInput(messa, 1, lllen + 1);
				cout << "请依次输入要插入的考生的考号，姓名，性别，年龄与报考类别" <<endl;
				TestStudent inpuStudent;
				cin >> inpuStudent;
				LL.Insert(pos, inpuStudent);

			}
			else if (ret == CONMENU[1].key)//删除
			{
				int lllen = LL.Length();
				int pos;
				char messa[50] = { 0 };
				sprintf(messa, "请输入你要删除的考生的位置[1,%d]\n", lllen);
				pos=NumberInput(messa, 1, lllen);
				TestStudent inpuStudent;
				LL.Remove(pos, inpuStudent);
				cout << "你删除的考生信息是:"<< inpuStudent<<endl;
			}
			else if (ret == CONMENU[2].key)//查找
			{
				int lllen = LL.Length();
				int pos;
				char messa[50] = { 0 };
				sprintf(messa, "请输入你要查找的考生的位置[1,%d]\n", lllen);
				pos = NumberInput(messa, 1, lllen);
				TestStudent inpuStudent;
				inpuStudent =(LL.Locate(pos))->getdata();
				display_student();
				cout << endl;
				cout << inpuStudent<<endl;
			}
			else if (ret == CONMENU[3].key)//修改
			{
				int lllen = LL.Length();
				int pos;
				char messa[50] = { 0 };
				sprintf(messa, "请输入你要修改的考生的位置[1,%d]\n", lllen);
				pos = NumberInput(messa, 1, lllen);
				TestStudent inpuStudent;
				cout << "请依次输入要修改的考生的考号，姓名，性别，年龄与报考类别" << endl;
				cin >> inpuStudent;
				LL.setData(pos, inpuStudent);
			}
			else if (ret == CONMENU[4].key)//统计
			{
				cout << "啥是统计" << endl;
			}



		}//while


	}//if(1)
	

















	if (0)
	{
		menu ME(AMOUNT_OF_MUNE);
		for (int i = 0; i < AMOUNT_OF_MUNE; i++)
			ME.menu_add(CONMENU[i]);
		int ret = ME.menu_choose();
		cout << ret;

	}







	if (0)
	{
		
		TestStudent stu;

		LinkedList<TestStudent> LL;
		//LL.input();
		cout << "输入插入元素" << endl;
		cin >> stu;
		LL.Insert(1, stu);
		//LL.getData(1, stu);
		display_student();
		LL.output();
		
		cout << "输入插入元素" << endl;
		cin >> stu;
		LL.Insert(2, stu);
		display_student();
		LL.output();
	}



	if (0)
	{
		TestStudent TStu;
		TStu.setage(18);
		TStu.setgender(GENDER[0]);
		TStu.setname("张三");
		TStu.setnumber(2000000);
		TStu.setocup("学生qwq");
		display_student();
		cout << TStu;
		system("pause");
	}
	
}