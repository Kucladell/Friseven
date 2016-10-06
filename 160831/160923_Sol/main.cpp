#include <iostream>
#include <string>
#define MAX_SUBJECT_NUMBER 132
using namespace std;

struct ScoreStruct
{
	string subjectName;
	float score; //���� ����.  A=4 B=3 �̷� ��
	int subjectUnit; //����� ����
	bool isMajor; //�����ΰ�
};

string printMenu()
{
	string selectedMenuVal;
	cout << "-----------------------------------------------" << endl;
	cout << "���ϴ� ��ɾ �Է��Ͻʽÿ�" << endl;
	cout << "1. ���� �Է�" << endl;
	cout << "2. ��ü ���� ���" << endl;
	cout << "3. �������, ��ü ����, �������� ���" << endl;
	cout << "4. ���α׷� ����" << endl;
	cout << "-----------------------------------------------" << endl;
	cin >> selectedMenuVal;
	return selectedMenuVal;
}

void printScore(ScoreStruct scoreStructs[],int count )
{
	if (count <= 0)
	{
		cout << "������ �����ϴ�"<<endl;
		return;
	}
	if (scoreStructs != nullptr)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "�а��� : " << scoreStructs[i].subjectName << endl;
			cout << "���� ���� : " << scoreStructs[i].score << endl;
			cout << "���� ���� : " << scoreStructs[i].subjectUnit << endl;
			if (scoreStructs[i].isMajor)
			{
				cout << "�������� : ����" << endl;
			}
			else
			{
				cout << " �������� : ���� " << endl;
			}
		}
	}
}

void printAverage(ScoreStruct scoreStructs[], int count)
{
	float average=0.0f;
	int sumSubjectUnit=0;
	float sumScore=0.0f;
	int sumMajorSubjectUnit = 0;
	float sumMajorScore = 0.0f;
	if (count <= 0)
	{
		cout << "������ �����ϴ�" << endl;
		return;
	}
	if (scoreStructs != nullptr)
	{
		for (int i = 0; i < count; i++)
		{
			sumScore += scoreStructs[i].score;
			sumSubjectUnit += scoreStructs[i].subjectUnit;
			if (scoreStructs[i].isMajor)
			{
				sumMajorSubjectUnit += scoreStructs[i].subjectUnit;
				sumMajorScore += scoreStructs[i].score;
			}
		}
		cout << "---------------------------------------------" << endl;
		cout << "��ü �ջ� ���� :" << sumScore<<endl;
		cout << "��ü ���� : " << sumSubjectUnit << endl;
		cout << "������� : " << sumScore / (float)sumSubjectUnit << endl;
		cout << "���� ��ü ���� : " << sumMajorScore << endl;
		cout << "���� ��ü ���� : " << sumMajorSubjectUnit << endl;
		cout << "���� ������� : " << sumMajorScore / (float)sumMajorSubjectUnit << endl;
		cout << "---------------------------------------------" << endl;

	}
}

void insertScore(ScoreStruct scoreStructs[],int& count)
{
	/*string subjectName;
	float score; //���� ����.  A=4 B=3 �̷� ��
	int subjectUnit; //����� ����
	bool isMajor; //�����ΰ�
	*/
	char isMajor;
	if (scoreStructs != nullptr)
	{
		cout << "������� �Է����ּ���" << endl;
		cin >> scoreStructs[count].subjectName;
		cout << " ������ �Է����ּ���. A=4,B=3,C=2,D=1,F=0, +�� 0.5�� ���ϸ� �˴ϴ�" << endl;
		cin >> scoreStructs[count].score;
		cout << "������ ���������� �Է����ּ���. " << endl;
		cin >> scoreStructs[count].subjectUnit;
		cout << "�������� Y/N���� �Է����ּ���" << endl;
		cin >> isMajor;
		if (isMajor == 'y' || isMajor == 'Y')
		{
			scoreStructs[count].isMajor = true;
		}
		else if (isMajor == 'n' || isMajor == 'N')
		{
			scoreStructs[count].isMajor = false;
		}
		else
		{
			while (true)
			{
				cout << "�Է°��� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���." << endl;
				cin >> isMajor;
				if (isMajor == 'y' || isMajor == 'Y')
				{
					scoreStructs[count].isMajor = true;
					break;
				}
				else if (isMajor == 'n' || isMajor == 'N')
				{
					scoreStructs[count].isMajor = false;
					break;
				}
			}
		}

		count++;
	}
}
int main(void)
{
	ScoreStruct subjects[MAX_SUBJECT_NUMBER];
	int subjectCount = 0;
	string command;
	bool exit = false;
	while (!exit)
	{
		command = printMenu();
		int menuVal = atoi(command.c_str());
		if (menuVal < 0)
		{
			menuVal = 0;
		}
		switch (menuVal)
		{
		case 1:
		{
			insertScore(subjects,subjectCount);
			break;
		}
		case 2:
		{
			printScore(subjects, subjectCount);
			break;
		}
		case 3:
		{
			printAverage(subjects, subjectCount);
			break;
		}
		case 4:
		{
			exit = true;
			break;
		}
		default:
		{
			cout << "�𸣴� ��ɾ��Դϴ�" << endl;
		}

		}
	}

	return 0;
}

