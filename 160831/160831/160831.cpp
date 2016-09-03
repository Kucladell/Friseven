#include <string>
#include <iostream>
using namespace std;

void main(void)
{
	string user_name;

	cout << "Hello World!" << endl;

	cout << "What's your name?" << endl;
	cin >> user_name;
	cout << "Hello, " + user_name + "." << endl;
}