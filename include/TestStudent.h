#include<string>
#include<iostream>
#include<iomanip>
using namespace std;





//报考的学生类(TestStudent)，由学生类(Student)继承而来（未添加）
//缺乏复制构造函数，“=”,"=="的重载
class TestStudent{
protected:
	unsigned int number;//考号
	string name;//姓名
	string gender;//性别
	unsigned int age;//年龄
	string occupation;//报考类别
public:
	TestStudent(){number=0;name="";gender="";age=0;occupation="";};
	TestStudent(unsigned int xnumber, string xname, string xgender, unsigned int xage, string xocc);
	TestStudent(const TestStudent& x);
	bool setnumber(const int& xNum){number=xNum;return 0;};
	bool setname(const char * xName){name=xName;return 0;};
	bool setgender(const char * xGend){gender=xGend;return 0;};
	bool setage(const int& xAge){age=xAge;return 0;};
	bool setocup(const char * xOccp){occupation=xOccp;return 0;};
	unsigned int getnumber()const{return number;};
	string getname()const{return name;};
	string getgender()const{return gender;};
	unsigned int getage()const{return age;};
	string getocup()const{return occupation;};
	friend ostream& operator<<(ostream&out,TestStudent& stu);
	friend istream& operator>>(istream&in,TestStudent& stu);
};


/*
	函数功能:用在输出TestStudent类时作为中文的说明
	类似如下：
	考号    姓名    性别    年龄    报考类别
	xxx     xxx     xxx     xxx     xxx
*/
void display_student()
{
	cout<<setiosflags(ios::left);
	cout<<setw(8)<<"考号";
	cout<<setw(8)<<"姓名";
	cout<<setw(8)<<"性别";
	cout<<setw(8)<<"年龄";
	cout<<setw(8)<<"报考类别";
	cout<<endl;
	cout<<resetiosflags(ios::left);
}
/*

	instruction:最好检查一下函数的声明
	ps：输出时无回车
*/
ostream& operator<<(ostream&out,TestStudent& stu){
	out<<setiosflags(ios::left);
	out<<setw(8)<<stu.getnumber();
	out<<setw(8)<<stu.getname();
	out<<setw(8)<<stu.getgender();
	out<<setw(8)<<stu.getage();
	out<<setw(8)<<stu.getocup();

	//在回到右对齐时不知道用那一句起作用
	out<<resetiosflags(ios::left);
	//cout.flags(ios::right);
	return out;
}


/*
	instruction:最好检查一下函数的声明
	instructiuon:未确保输入的正确性
				 需要增加健壮性
*/
istream& operator>>(istream&in,TestStudent& stu){
	in>>stu.number>>stu.name>>stu.gender>>stu.age>>stu.occupation;
	return in;
}



TestStudent::TestStudent(const TestStudent& x)
{
	number = x.number; 
	name = x.name; 
	gender = x.gender; 
	age = x.age; 
	occupation = x.occupation;
}


TestStudent::TestStudent(unsigned int xnumber, string xname, string xgender, unsigned int xage, string xocc)
{
	number = xnumber;
	name = xname;
	gender = xgender;
	age = xage;
	occupation = xocc;
}