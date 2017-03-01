#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

struct Score
{
	std::string name;
	int credit;
	float grade;
	std::string gradeText;
	bool isMajor;
	Score(std::string name, int credit, float grade, std::string gradetext, bool isMajor);
	void Print();
	void input(LinkedList<Score>& data);
	void output(const LinkedList<Score>& data );
	void calculate(LinkedList<Score>& data);
	void saveHTML(const LinkedList<Score>& data, std::string fileName);
};