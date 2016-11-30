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

	//수정 코드 시작
	void add(int value, int index); //지정한 위치에 노드를 추가
	void addFirst(int value); //맨 앞에 노드를 추가
	void addLast(int value); //맨 뒤에 노드를 추가
	void remove(int value); //지정한 노드를 삭제
	void removeFirst(); //맨 앞의 노드를 삭제
	void removeLast(); //맨 뒤의 노드를 삭제
	void removeAll(); //모든 노드를 삭제
	bool find(int value); //지정한 값의 존재여부를 반환
	int findIndex(int value); //지정한 값의 인덱스를 반환
	int print(int value); //지정한 값을 출력
	int printFirst(); //맨 앞의 값을 출력
	int printLast(); //맨 뒤의 노드를 출력
	void printAll(); //모든 노드를 출력
	int length() { return count; } //노드의 갯수를 반환
	bool isEmpty(); //링크드리스트가 비어있는지 여부를 반환
	//수정 코드 끝
private:
	Node* head;
	int count; //갯수를 센다


};