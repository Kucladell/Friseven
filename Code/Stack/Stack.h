#pragma once
#include "..\LinkedList\LinkedList.h"

class ListStack
{
public: 
	ListStack();
	~ListStack();

	void push(int value); //맨 위에 값 추가
	int pop(); //맨 위 값을 반환하고 해당 값 삭제
	int top(); //맨 위 값을 반환
	int count(); //값 개수를 반환
	bool isEmpty(); //스택이 비어있는지 여부를 반환
	
private:
	int size;
	LinkedList list;
};