#pragma once
#include "..\LinkedList\LinkedList.h"

class ListStack
{
public: 
	ListStack();
	~ListStack();

	void push(int value); //�� ���� �� �߰�
	int pop(); //�� �� ���� ��ȯ�ϰ� �ش� �� ����
	int top(); //�� �� ���� ��ȯ
	int count(); //�� ������ ��ȯ
	bool isEmpty(); //������ ����ִ��� ���θ� ��ȯ
	
private:
	int size;
	LinkedList list;
};