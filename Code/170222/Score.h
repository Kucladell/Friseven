#pragma once

#include <iostream>
#include <string>

struct Score
{
	std::string name;
	int credit;
	float grade;
	std::string gradeText;
	bool isMajor;
};

class ScoreCalculator
{
public:
	void input(LinkedList<Score>& data);
	void output(LinkedList<Score>& data);
	void calculate(LinkedList<Score>& data);
	void saveHTML(LinkedList<Score>& data);
};