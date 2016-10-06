#include <iostream>
#include <string>
#define MAX_SUBJECT_NUMBER 132
using namespace std;

struct ScoreStruct
{
	string subjectName;
	float score; //받은 점수.  A=4 B=3 이런 식
	int subjectUnit; //과목당 학점
	bool isMajor; //전공인가
};

string printMenu()
{
	string selectedMenuVal;
	cout << "-----------------------------------------------" << endl;
	cout << "원하는 명령어를 입력하십시오" << endl;
	cout << "1. 성적 입력" << endl;
	cout << "2. 전체 성적 출력" << endl;
	cout << "3. 평점평균, 전체 학점, 전공학점 출력" << endl;
	cout << "4. 프로그램 종료" << endl;
	cout << "-----------------------------------------------" << endl;
	cin >> selectedMenuVal;
	return selectedMenuVal;
}

void printScore(ScoreStruct scoreStructs[],int count )
{
	if (count <= 0)
	{
		cout << "과목이 없습니다"<<endl;
		return;
	}
	if (scoreStructs != nullptr)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "학과명 : " << scoreStructs[i].subjectName << endl;
			cout << "받은 학점 : " << scoreStructs[i].score << endl;
			cout << "과목 학점 : " << scoreStructs[i].subjectUnit << endl;
			if (scoreStructs[i].isMajor)
			{
				cout << "전공여부 : 전공" << endl;
			}
			else
			{
				cout << " 전공여부 : 교양 " << endl;
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
		cout << "과목이 없습니다" << endl;
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
		cout << "전체 합산 성적 :" << sumScore<<endl;
		cout << "전체 평점 : " << sumSubjectUnit << endl;
		cout << "평점평균 : " << sumScore / (float)sumSubjectUnit << endl;
		cout << "전공 전체 성적 : " << sumMajorScore << endl;
		cout << "전공 전체 평점 : " << sumMajorSubjectUnit << endl;
		cout << "전공 평점평균 : " << sumMajorScore / (float)sumMajorSubjectUnit << endl;
		cout << "---------------------------------------------" << endl;

	}
}

void insertScore(ScoreStruct scoreStructs[],int& count)
{
	/*string subjectName;
	float score; //받은 점수.  A=4 B=3 이런 식
	int subjectUnit; //과목당 학점
	bool isMajor; //전공인가
	*/
	char isMajor;
	if (scoreStructs != nullptr)
	{
		cout << "과목명을 입력해주세요" << endl;
		cin >> scoreStructs[count].subjectName;
		cout << " 학점을 입력해주세요. A=4,B=3,C=2,D=1,F=0, +는 0.5를 더하면 됩니다" << endl;
		cin >> scoreStructs[count].score;
		cout << "과목의 학점단위를 입력해주세요. " << endl;
		cin >> scoreStructs[count].subjectUnit;
		cout << "전공인지 Y/N으로 입력해주세요" << endl;
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
				cout << "입력값이 틀렸습니다. 다시 입력해주세요." << endl;
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
			cout << "모르는 명령어입니다" << endl;
		}

		}
	}

	return 0;
}

