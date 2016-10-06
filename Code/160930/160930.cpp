#include <iostream>
#include <string>
#define MAX_SUBJECT_NUMBER 200
using namespace std;

struct Score
{
	string name;
	int credit;
	float score;
	string score_raw;
	bool is_major;
};

string menu()
{
	string selected;

	cout << "--�� ��------------------------------" << endl;
	cout << "��ɿ� �ش��ϴ� ���ڸ� �Է��Ͻʽÿ�." << endl;
	cout << "1. ���� �Է�" << endl;
	cout << "2. �Էµ� �ڷ� Ȯ��" << endl;
	cout << "3. ����� ���" << endl;
	cout << "4. ����" << endl;
	cout << "-------------------------------------" << endl;
	cout << ">";
	cin >> selected;

	return selected;
}

//�޴� 1��
void insert(Score input[], int& count) //QUESTION &�� �� �ʿ��Ѱ�
{
	float score;
	string score_raw;
	char is_major;

	if (input != nullptr)
	{
		cout << "--�� ���� �Է�-----------------------" << endl;

		cout << "- �����" << endl;
		cout << ">";
		cin >> input[count].name;

		cout << "- ����(1����, 2����, 3���� ��)" << endl;
		cout << ">";
		cin >> input[count].credit;

		cout << "- ȹ���� ����(A+, A, B ��)" << endl;
		cout << ">";
		cin >> score_raw;
		//QUESTION �� switch������ ó���� �� ���°�
		if (score_raw == "A+")
		{
			input[count].score = 4.5;
			input[count].score_raw = "A+";
		}
		else if (score_raw == "A")
		{
			input[count].score = 4;
			input[count].score_raw = "A";
		}
		else if (score_raw == "B+")
		{
			input[count].score = 3.5;
			input[count].score_raw = "B";
		}
		else if (score_raw == "B")
		{
			input[count].score = 3;
			input[count].score_raw = "B";
		}
		else if (score_raw == "C+")
		{
			input[count].score = 2.5;
			input[count].score_raw = "C+";
		}
		else if (score_raw == "C")
		{
			input[count].score = 2;
			input[count].score_raw = "C";
		}
		else if (score_raw == "D+")
		{
			input[count].score = 1.5;
			input[count].score_raw = "D+";
		}
		else if (score_raw == "D")
		{
			input[count].score = 1;
			input[count].score_raw = "D";
		}
		else if (score_raw == "F")
		{
			input[count].score = 0;
			input[count].score_raw = "F";
		}
		else
		{
			while (true)
			{
				cout << "�Է°��� �߸��Ǿ����ϴ�. ������ �ٽ� �Է��Ͻʽÿ�." << endl;
				cout << "(A+, A, B+, B, C+, C, D+, D, F)" << endl;
				cout << ">";
				cin >> score_raw;
				if (score_raw == "A+")
				{
					input[count].score = 4.5;
					input[count].score_raw = "A+";
					break;
				}
				else if (score_raw == "A")
				{
					input[count].score = 4;
					input[count].score_raw = "A";
					break;
				}
				else if (score_raw == "B+")
				{
					input[count].score = 3.5;
					input[count].score_raw = "B";
					break;
				}
				else if (score_raw == "B")
				{
					input[count].score = 3;
					input[count].score_raw = "B";
					break;
				}
				else if (score_raw == "C+")
				{
					input[count].score = 2.5;
					input[count].score_raw = "C+";
					break;
				}
				else if (score_raw == "C")
				{
					input[count].score = 2;
					input[count].score_raw = "C";
					break;
				}
				else if (score_raw == "D+")
				{
					input[count].score = 1.5;
					input[count].score_raw = "D+";
					break;
				}
				else if (score_raw == "D")
				{
					input[count].score = 1;
					input[count].score_raw = "D";
					break;
				}
				else if (score_raw == "F")
				{
					input[count].score = 0;
					input[count].score_raw = "F";
					break;
				}
			}
		}

		cout << "���� ����(Y, N)" << endl;
		cout << ">";
		cin >> is_major;
		if (is_major == 'Y' || is_major == 'y')
		{
			input[count].is_major = true;
		}
		else if (is_major == 'N' || is_major == 'n')
		{
			input[count].is_major = false;
		}
		else
		{
			while (true)
			{
				cout << "�Է°��� �߸��Ǿ����ϴ�. ���� ���θ� �ٽ� �Է��Ͻʽÿ�." << endl;
				cout << "(Y, N)" << endl;
				cout << ">";
				cin >> is_major;
				if (is_major == 'Y' || is_major == 'y')
				{
					input[count].is_major = true;
					break;
				}
				else if (is_major == 'N' || is_major == 'n')
				{
					input[count].is_major = false;
					break;
				}
			}
		}

		count++;
		cout << "-------------------------------------" << endl;
	}
}

//�޴� 2��
void viewInput(Score input[], int count)
{
	cout << "-------------------------------------" << endl;
	if (count <= 0)
	{
		cout << "���� �Էµ� ������ �����ϴ�." << endl;
		return; //QUESTION �� �ʿ��Ѱ�
	}
	else
	{
		if (input != nullptr)
		{
			for (int i = 0; i < count; i++)
			{
				string type;
				if (input[i].is_major)
				{
					type = "����";

				}
				else
				{
					type = "����";
				}
				cout << input[i].name << "(" << input[i].credit << "����, " << type << "): " << input[i].score_raw << endl;
			}
		}
	}
	cout << "-------------------------------------" << endl;
}

//�޴� 3��
void viewCalculation(Score input[], int count)
{
	int credit_all_sum = 0;
	float score_all_sum = 0.0f;
	int credit_major_sum = 0;
	float score_major_sum = 0.0f;

	if (count <= 0)
	{
		cout << "���� �Էµ� ������ �����ϴ�." << endl;
		return;
	}

	if (input != nullptr)
	{
		for (int i = 0; i < count; i++)
		{
			credit_all_sum += input[i].credit;
			score_all_sum += input[i].score * input[i].credit;
			if (input[i].is_major)
			{
				credit_major_sum += input[i].credit;
				score_major_sum += input[i].score * input[i].credit;
			}
		}

		cout << "-------------------------------------" << endl;
		cout << "�� �̼� ����: " << credit_all_sum << endl;
		cout << "�� �������: " << score_all_sum / (float)credit_all_sum << endl << endl;
		cout << "���� �̼� ����: " << credit_major_sum << endl;
		cout << "���� �������: " << score_major_sum / (float)credit_major_sum << endl;
		cout << "-------------------------------------" << endl;
	}
}

int main(void) //QUESTION �� void�� �ƴѰ�
{
	Score data[MAX_SUBJECT_NUMBER];
	int data_count = 0;
	string command;
	bool exit = false;
	//QUESTION �������� �Ϻη� �ٸ��� ������ ���ΰ�

	while (!exit)
	{
		command = menu();
		int command_int = atoi(command.c_str());
		if (command_int < 0)
		{
			command_int = 0;
		}
		switch (command_int)
		{
		case 1:
		{
			insert(data, data_count);
			break;
		}
		case 2:
		{
			viewInput(data, data_count);
			break;
		}
		case 3:
		{
			viewCalculation(data, data_count);
			break;
		}
		case 4:
		{
			exit = true;
			break;
		}
		default:
		{
			cout << "�߸��� ��ɾ��Դϴ�." << endl;
		}
		}
	}

	return 0;
}