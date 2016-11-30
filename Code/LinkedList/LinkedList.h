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

	//���� �ڵ� ����
	void add(int value, int index); //������ ��ġ�� ��带 �߰�
	void addFirst(int value); //�� �տ� ��带 �߰�
	void addLast(int value); //�� �ڿ� ��带 �߰�
	void remove(int value); //������ ��带 ����
	void removeFirst(); //�� ���� ��带 ����
	void removeLast(); //�� ���� ��带 ����
	void removeAll(); //��� ��带 ����
	bool find(int value); //������ ���� ���翩�θ� ��ȯ
	int findIndex(int value); //������ ���� �ε����� ��ȯ
	int print(int value); //������ ���� ���
	int printFirst(); //�� ���� ���� ���
	int printLast(); //�� ���� ��带 ���
	void printAll(); //��� ��带 ���
	int length() { return count; } //����� ������ ��ȯ
	bool isEmpty(); //��ũ�帮��Ʈ�� ����ִ��� ���θ� ��ȯ
	//���� �ڵ� ��
private:
	Node* head;
	int count; //������ ����


};