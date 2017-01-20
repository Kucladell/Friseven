#pragma once

//int singular linked list
struct Node 
{
	int value;
	Node* next;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(Node* _head) : head(_head)
	{

	}
	LinkedList(int initalvalue);
	
	~LinkedList();

	void add(int value, int index); //������ ��ġ�� ��带 �߰�
	void addFirst(int value); //�� �տ� ��带 �߰�
	void addLast(int value); //�� �ڿ� ��带 �߰�
	void remove(int value); //������ ���� ��带 ����
	void removeFirst(); //�� ���� ��带 ����
	void removeLast(); //�� ���� ��带 ����
	void removeAll(); //��� ��带 ����
	bool find(int value); //������ ���� ���翩�θ� ��ȯ
	int findIndex(int value); //������ ���� �ε����� ��ȯ
	int print(int index); //������ �ε����� ���� ��ȯ
	int printFirst(); //�� ���� ���� ��ȯ
	int printLast(); //�� ���� ��带 ��ȯ
	int printValue(int value); //������ ���� ��ȯ
	void printAll(); //��� ��带 ���
	int length(); //����� ������ ��ȯ
	bool isEmpty(); //��ũ�帮��Ʈ�� ����ִ��� ���θ� ��ȯ
private:
	Node* head;
	int count; //������ ����


};