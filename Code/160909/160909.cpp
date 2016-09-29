#include <iostream>
#include <math.h>
using namespace std;

void main(void)
{
	//음수 시프트 계산
	int input = -64;
	int output = input << 3;

	cout << output << endl;

	cout << endl;

	//Array 버블 정렬
	int array[10];

	for (int i = 0; i < 10; i++) {
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}
	cout << endl << endl;

	int temp;
	for (int i = 10; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}