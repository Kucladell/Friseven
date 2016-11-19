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
	~LinkedList();

	void AddBack(int value); //�� �ڿ� ��带 ���� 
	void RemoveValue(int value); //���� �ִ� ��带 �����
	void RemoveLast(); //������ ��带 �����
	bool Find(int value);//�ش� ���� ����ִ��� ã�´�
	void Print(int value); //���ΰ� �� �ϳ��� ã�Ƽ� ����Ѵ�
	void PrintLast(); //���ΰ� �� ������ ���� ����Ѵ�
	void PrintAll(); //���ΰ��� ������� ����Ѵ�
	void Clear(); //��� ��带 �����
	int Length() { return count; } //����
	bool Empty(); //������� T á���� F����
private:
	Node* head;
	int count; //������ ����


};