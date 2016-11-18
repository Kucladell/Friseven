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

	void AddBack(int value); //맨 뒤에 노드를 더함 
	void RemoveValue(int value); //값이 있는 노드를 지운다
	void RemoveLast(); //마지막 노드를 지운다
	bool Find(int value);//해당 값이 들어있는지 찾는다
	void Print(int value); //내부값 중 하나만 찾아서 출력한다
	void PrintLast(); //내부값 중 마지막 값을 출력한다
	void PrintAll(); //내부값을 순서대로 출력한다
	void Clear(); //모든 노드를 지운다
	int Length() { return count; } //갯수
	bool Empty(); //비었으면 T 찼으면 F리턴
private:
	Node* head;
	int count; //갯수를 센다


};