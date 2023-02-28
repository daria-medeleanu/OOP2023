#include <iostream>
#include "Student.h"
void Student::SetName(const char *s)
{
	int i;
	for (i = 0; s[i] != NULL; i++)
		this->name[i] = s[i];
	this->name[i] = NULL;
}
char* Student::GetName()
{
	return this->name;
}
void Student::SetGradeMath(float x)
{
	this->gradeMath = x;
}
float Student::GetGradeMath()
{
	return this->gradeMath;
}
void Student::SetGradeEnglish(float x)
{
	this->gradeEnglish = x;
}
float Student::GetGradeEnglish()
{
	return this->gradeEnglish;
}
void Student::SetGradeHistory(float x)
{
	this->gradeHistory = x;
}
float Student::GetGradeHistory()
{
	return this->gradeHistory;
}
float Student::AverageGrade()
{
	this->gradeAverage = (this->gradeMath + this->gradeHistory + this->gradeEnglish) / 3.0;
	return this->gradeAverage;
}