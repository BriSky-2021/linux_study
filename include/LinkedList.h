#pragma once
//#include"LinearList.h"


template<typename T>
class LinkedList;

template<typename T>
class LinkNode {

protected:
	T data;
	LinkNode* next;
public:
	const T& getdata() { return data; }
	LinkNode(const LinkNode<T>* x = NULL) { next = NULL; };
	LinkNode(const T& x_data, const LinkNode<T>* x ) { data = x_data; next = x; };

	friend class LinkedList<T>;
};



template<typename T>
class LinkedList {
protected:
	LinkNode<T>* head;
	int LENGTH;
public:
	LinkedList() { head = new LinkNode<T>; LENGTH = 0; };
	LinkedList(const T& x) { head = new LinkNode<T>(x); LENGTH = 1; };
	//LinkedList(const LinkedList& model);
	~LinkedList() { makeEmpty(); };


	void makeEmpty();
	int Size()const ;
	int Length()const ;

	LinkNode<T>* getHead()const { return head; };
	LinkNode<T>* Search(T& x)const ;
	LinkNode<T>* Locate(int i)const ;

	bool getData(int i, T& x)const ;
	void setData(int i, const T& x) ;
	bool Insert(int i, const T& x) ;
	bool Remove(int i, T& x) ;

	bool IsEmpty()const { return head->next == NULL ? true : false; };
	bool IsFull()const { return false; };

	//void Sort() ;
	void input() ;
	void output() ;
	//LinkedList<T>& operator = (const LinkedList<T>& L);
};

template<typename T>
int LinkedList<T>::Size()const {
	return LENGTH;
}

template<typename T>
int LinkedList<T>::Length()const
{
	return LENGTH;
}

template<typename T>
void LinkedList<T>::makeEmpty() {

	LinkNode<T>* q, * p = head;//从头结点开始删除

	/* 从头结点开始依次释放（含头结点） */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		delete p;
		p = q;
	}
	head = 0;	//头指针置NULL

}

template<typename T>
bool LinkedList<T>::getData(int i, T& x)const
{
	if (i <= 0 || i > LENGTH)
		return 1;//超范围

	LinkNode<T>* p = head->next;	//指向首元结点
	int  pos = 1;		//初始位置为1

	/* 链表不为NULL 且 未到第i个元素 */
	while (p  && pos < i) {
		p = p->next;
		pos++;
	}

	if (!p || pos > i)
		return 1;

	x = p->data;
	return 0;


}




template<typename T>
LinkNode<T>* LinkedList<T>::Search(T& x)const
{
	LinkNode<T>* p=head->next;
	while (p&&(p->data!=x.data))
	{
		p = p->next;
	}
	if (p)
		return p;
	else return 0;
}


template<typename T>
LinkNode<T>* LinkedList<T>::Locate(int i)const
{
	if (i <= 0 || i > LENGTH)
		return 0;//超范围
	LinkNode<T>* p = head->next;
	int pos = 1;
	while (p && pos < i)
	{
		p = p->next;
		pos++;
	}
	return (p && (pos == i)) ? p : 0;
}

template<typename T>
void  LinkedList<T>::setData(int i, const T& x)
{
	if (i <= 0 || i > LENGTH)
		return ;//超范围
	LinkNode<T>* p = head->next;
	int pos = 1;
	while (p && pos < i)
	{
		p = p->next;
		pos++;
	}
	if (p && (pos == i))
		p->data = x;
}



/*
	功能:插入到第i个位置
	1<=i<=LENGTH+1

*/
template<typename T>
bool LinkedList<T>::Insert(int i, const T& x)
{
	if (i <= 0 || i > LENGTH + 1)
		return 1;//超范围

	LinkNode<T>* p = head;
	int pos = 1;
	while (p && pos < i)
	{
		p = p->next;
		pos++;
	}
	LinkNode<T>* t = new LinkNode<T>;
	t->data = x;
	t->next = p->next;
	p->next = t;

	LENGTH++;
	return 0;
}

template<typename T>
bool LinkedList<T>::Remove(int i, T& x)
{
	if (i <= 0 || i > LENGTH)
		return 1;//超范围
	LinkNode<T>* p = head;//需要删除的是p指向的下一个元素
	int pos = 1;
	while (p &&p->next&& pos < i)
	{
		p = p->next;
		pos++;
	}
	if (p->next)
	{
		LinkNode<T>* t = p->next;
		p->next = p->next->next;
		x = t->getdata();
		delete t;
		LENGTH--;
	}
	return 0;
}



/*
	未实现输出根据实际情况而定(开始建立“考生信息系统”)
	应实现内存申请错误报告

*/
template<typename T>
void LinkedList<T>::input() {
	cout << "开始建立链表，请输入元素个数" << endl;

	//缺少错误办法
	cin >> LENGTH;
		
	
	cout << "请输入表中元素" << endl;
	LinkNode<T>* p=head;
	for (int i = 1; i <= LENGTH; i++)
	{
		p->next = new LinkNode<T>;
		cin >> p->next->data; 
		p = p->next;
		//cout << "已输入" << i + 1 << "个" << endl;
	}
}




template<typename T>
void LinkedList<T>::output() {
	LinkNode<T>* p = head->next;
	while (p)
	{
		cout << p->data<<endl;
		p = p->next;
	}
	cout << endl;
}