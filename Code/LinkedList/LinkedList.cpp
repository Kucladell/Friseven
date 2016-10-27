#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
	count = 0;

}
LinkedList::~LinkedList()
{
	Clear();
}

