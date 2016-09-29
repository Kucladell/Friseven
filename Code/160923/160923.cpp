#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
using namespace std;

//�ݿø� �Լ�
double round(double value, int decimal) {
	double output;

	output = value * pow(10, decimal);
	output = floor(output + 0.5);
	output = output * pow(10, -decimal);

	return output;
}

//����ü ����
struct input {
	string name;
	int credit;
	int score;
	boolean is_major;
};
struct node {
	input value;
	node *next;
};
struct linkedlist {
	node *head;

	//��ü ������� ��� �Լ�
	int average_all(input user_input, int number) {
		int credit_sum;
		int score_sum;

		for (int i = 1; i < sizeof(user_input) + 1; i++) {
			credit_sum = credit_sum + user_input.credit[i];
			score_sum = score_sum + user_input.credit[i];
		}

		return round(score_sum / credit_sum, 2);
	}

	//���� ������� ��� �Լ�
	int average_major(input user_input, int number) {
		int credit_sum;
		int score_sum;

		for (int i = 1; i < sizeof(user_input) + 1; i++) {
			if (user_input.is_major[i] = 1) {
				credit_sum = credit_sum + user_input.credit[i];
				score_sum = score_sum + user_input.credit[i];
			}
		}
		
		return round(score_sum / credit_sum, 2);
	}
};

void main(void) {
	
}
