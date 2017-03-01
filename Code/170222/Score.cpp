#include "LinkedList.h"
#include "Score.h"

void capitalize(std::string& string);
inline void printLine();

void Score::Print()
{

	printLine();
	if (this->isMajor)
	{
		std::cout << this->name + "(" + std::to_string(this->credit) + "학점, 전공): " + data.print(i).gradeText << std::endl;
	}
	else
	{
		std::cout << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "학점, 교양): " + data.print(i).gradeText << std::endl;
	}
	printLine();
}

void Score::input(LinkedList<Score>& data)
{
	Node<Score>* addNode = new Node<Score>;
	std::string gradeText_temp;
	std::string isMajor_temp;
	std::string value_temp;

	printLine();

	//과목명 입력

	std::cout << "- 과목명" << std::endl;
	std::cout << ">";
	std::getline(std::cin, addNode->value.name);

	//단위 입력
	std::cout << "- 단위(1학점, 2학점, 3학점 등)" << std::endl;
	std::cout << ">";
	std::getline(std::cin, value_temp);
	addNode->value.credit = atoi(value_temp.c_str());

	while (true)
	{
		std::cout << "- 획득한 성적(A+, A, B 등)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, gradeText_temp);
		capitalize(gradeText_temp);

		if (gradeText_temp.length()>3)
		{
			std::cout << "입력값이 잘못되었습니다." << std::endl;
		}
		else
		{
			//첫번째 문자에서 숫자를 산출(Keycode 이용)
			addNode->value.grade = 4.0f - (gradeText_temp[0] - 'A');

			//성적이 F일 경우
			if (addNode->value.grade == -1.0f && gradeText_temp.length() == 1)
			{
				addNode->value.grade = 0.0f;
				addNode->value.gradeText = gradeText_temp;
				break;
			}
			//성적이 A에서 D 사이일 경우
			if (addNode->value.grade < 1.0f || addNode->value.grade>4.0f)
			{
				std::cout << "입력값이 잘못되었습니다." << std::endl;
			}
			else if (gradeText_temp[1] == '+') //+가 붙은 경우
			{
				addNode->value.grade += 0.5;
				addNode->value.gradeText = gradeText_temp;
				break;
			}
			else //+가 붙지 않은 경우
			{
				addNode->value.gradeText = gradeText_temp;
				break;
			}
		}
	}

	//전공 여부 입력
	while (true)
	{
		std::cout << "전공 여부(Y, N)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, isMajor_temp);
		capitalize(isMajor_temp);

		if (isMajor_temp == "Y")
		{
			addNode->value.isMajor = true;
			break;
		}
		else if (isMajor_temp == "N")
		{
			addNode->value.isMajor = false;
			break;
		}
		else
		{
			std::cout << "입력값이 잘못되었습니다." << std::endl;
		}
	}

	addNode->next = NULL;

	data.add(addNode);

	printLine();
}

void ScoreCalculator::output(LinkedList<Score>& data)
{
	printLine();

	for (int i = 1; i < data.length() + 1; i++)
	{
		if (data.print(i).isMajor)
		{
			std::cout << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "학점, 전공): " + data.print(i).gradeText << std::endl;
		}
		else
		{
			std::cout << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "학점, 교양): " + data.print(i).gradeText << std::endl;
		}
	}

	printLine();
}

void ScoreCalculator::calculate(LinkedList<Score>& data)
{
	int credit_all_sum = 0;
	float grade_all_sum = 0.0f;
	int credit_major_sum = 0;
	float grade_major_sum = 0.0f;

	printLine();

	if (data.length() <= 0)
	{
		std::cout << "아직 입력된 성적이 없습니다." << std::endl;
	}
	else
	{
		for (int i = 1; i < data.length() + 1; i++)
		{
			credit_all_sum += data.print(i).credit;
			grade_all_sum += data.print(i).grade * data.print(i).credit;

			if (data.print(i).isMajor)
			{
				credit_major_sum += data.print(i).credit;
				grade_major_sum += data.print(i).grade * data.print(i).credit;
			}
		}

		std::cout << "수강 강의 수: " << data.length() << std::endl << std::endl;
		std::cout << "총 이수 학점: " << credit_all_sum << std::endl;
		std::cout << "총 평점평균: " << grade_all_sum / (float)credit_all_sum << std::endl << std::endl;
		std::cout << "전공 이수 학점: " << credit_major_sum << std::endl;
		std::cout << "전공 평점평균: " << grade_major_sum / (float)credit_major_sum << std::endl;
	}

	printLine();
}

void ScoreCalculator::saveHTML(LinkedList<Score>& data, std::string fileName)
{
	std::ofstream file;
	int credit_all_sum = 0;
	float grade_all_sum = 0.0f;
	int credit_major_sum = 0;
	float grade_major_sum = 0.0f;

	printLine();

	if (data.length() <= 0)
	{
		std::cout << "아직 입력된 성적이 없습니다." << std::endl;
	}
	else
	{
		file.open(fileName.c_str());

		file << "<HTML>\
			<HEAD><TITLE>성적표</TITLE></HEAD><BODY>성적표<br><br>";

		for (int i = 1; i < data.length() + 1; i++)
		{
			if (data.print(i).isMajor)
			{
				file << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "학점, 전공): " + data.print(i).gradeText + "<br>";
			}
			else
			{
				file << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "학점, 교양): " + data.print(i).gradeText + "<br>";
			}
		}
		file << "<br>";

		for (int i = 1; i < data.length() + 1; i++)
		{
			credit_all_sum += data.print(i).credit;
			grade_all_sum += data.print(i).grade * data.print(i).credit;

			if (data.print(i).isMajor)
			{
				credit_major_sum += data.print(i).credit;
				grade_major_sum += data.print(i).grade * data.print(i).credit;
			}
		}

		file << "수강 강의 수: " << data.length() << "<br><br>";
		file << "총 이수 학점: " << credit_all_sum << "<br>";
		file << "총 평점평균: " << grade_all_sum / (float)credit_all_sum << "<br><br>";
		file << "전공 이수 학점: " << credit_major_sum << "<br>";
		file << "전공 평점평균: " << grade_major_sum / (float)credit_major_sum << "<br>";

		file << "</BODY></HTML>";
		file.close();

		std::cout << "성적표를 " << fileName << "로 출력했습니다." << std::endl;
	}

	printLine();
}

void capitalize(std::string& string)
{
	for (int i = 0; i < (int)string.length(); i++)
	{
		string[i] = toupper(string[i]);
	}
}

void printLine()
{
	std::cout << "-------------------------------------" << std::endl;
}
