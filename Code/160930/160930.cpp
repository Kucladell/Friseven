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

	cout << "--메 뉴------------------------------" << endl;
	cout << "명령에 해당하는 숫자를 입력하십시오." << endl;
	cout << "1. 성적 입력" << endl;
	cout << "2. 입력된 자료 확인" << endl;
	cout << "3. 계산결과 출력" << endl;
	cout << "4. 종료" << endl;
	cout << "-------------------------------------" << endl;
	cout << ">";
	cin >> selected;

	return selected;
}

//메뉴 1번
void insert(Score input[], int& count) //QUESTION &는 왜 필요한가
{
	float score;
	string score_raw;
	char is_major;

	if (input != nullptr)
	{
		cout << "--새 성적 입력-----------------------" << endl;

		cout << "- 과목명" << endl;
		cout << ">";
		cin >> input[count].name;

		cout << "- 단위(1학점, 2학점, 3학점 등)" << endl;
		cout << ">";
		cin >> input[count].credit;

		cout << "- 획득한 학점(A+, A, B 등)" << endl;
		cout << ">";
		cin >> score_raw;
		//QUESTION 왜 switch문으로 처리할 수 없는가
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
				cout << "입력값이 잘못되었습니다. 학점을 다시 입력하십시오." << endl;
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

		cout << "전공 여부(Y, N)" << endl;
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
				cout << "입력값이 잘못되었습니다. 전공 여부를 다시 입력하십시오." << endl;
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

//메뉴 2번
void viewInput(Score input[], int count)
{
	cout << "-------------------------------------" << endl;
	if (count <= 0)
	{
		cout << "아직 입력된 성적이 없습니다." << endl;
		return; //QUESTION 왜 필요한가
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
					type = "전공";

				}
				else
				{
					type = "교양";
				}
				cout << input[i].name << "(" << input[i].credit << "학점, " << type << "): " << input[i].score_raw << endl;
			}
		}
	}
	cout << "-------------------------------------" << endl;
}

//메뉴 3번
void viewCalculation(Score input[], int count)
{
	int credit_all_sum = 0;
	float score_all_sum = 0.0f;
	int credit_major_sum = 0;
	float score_major_sum = 0.0f;

	if (count <= 0)
	{
		cout << "아직 입력된 성적이 없습니다." << endl;
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
		cout << "총 이수 학점: " << credit_all_sum << endl;
		cout << "총 평점평균: " << score_all_sum / (float)credit_all_sum << endl << endl;
		cout << "전공 이수 학점: " << credit_major_sum << endl;
		cout << "전공 평점평균: " << score_major_sum / (float)credit_major_sum << endl;
		cout << "-------------------------------------" << endl;
	}
}

int main(void) //QUESTION 왜 void가 아닌가
{
	Score data[MAX_SUBJECT_NUMBER];
	int data_count = 0;
	string command;
	bool exit = false;
	//QUESTION 변수명은 일부러 다르게 설정한 것인가

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
			cout << "잘못된 명령어입니다." << endl;
		}
		}
	}

	return 0;
}