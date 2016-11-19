#pragma once
#include "..\LinkedList\LinkedList.h"

class ListStack
{
public: 
	ListStack();
	~ListStack();
	void Push(int value); //value�� �ִ´�
	int Pop(); //�� ������ �����ϰ� ���ÿ��� ����
	int Count() { return size; } // ���ÿ� ��� �ִ� ���� ������ �����Ѵ�
	int Top(); // �� �� ���� ���ϸ� �Ѵ�
	bool Empty(); // ������ ����ִ��� �˻��Ѵ�
private:
	int size;
	LinkedList list;
};