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

	void add(int value, int index); //지정한 위치에 노드를 추가
	void addFirst(int value); //맨 앞에 노드를 추가
	void addLast(int value); //맨 뒤에 노드를 추가
	void remove(int value); //지정한 값의 노드를 삭제
	void removeFirst(); //맨 앞의 노드를 삭제
	void removeLast(); //맨 뒤의 노드를 삭제
	void removeAll(); //모든 노드를 삭제
	bool find(int value); //지정한 값의 존재여부를 반환
	int findIndex(int value); //지정한 값의 인덱스를 반환
	int print(int index); //지정한 인덱스의 값을 반환
	int printFirst(); //맨 앞의 값을 반환
	int printLast(); //맨 뒤의 노드를 반환
	int printValue(int value); //지정한 값을 반환
	void printAll(); //모든 노드를 출력
	int length(); //노드의 갯수를 반환
	bool isEmpty(); //링크드리스트가 비어있는지 여부를 반환
private:
	Node* head;
	int count; //갯수를 센다


};