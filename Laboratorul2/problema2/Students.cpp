#include <iostream>
#include "Student.h"
#include "Students.h"
using namespace std;
int CompareName(Student S1, Student S2)
{
	for (int i = 0; S1.name[i] != NULL; i++)
		for (int j = 0; S2.name[j] != NULL; j++)
			if (S1.name[i] > S2.name[j])
				return 1;
			else if (S1.name[i] < S2.name[j])
				return -1;
	return 0;
}
int CompareGradeMath(Student S1,Student S2)
{
	if (S1.gradeMath > S2.gradeMath)
		return 1;
	else if (S1.gradeMath < S2.gradeMath)
		return -1;
	else
		return 0;
}
int CompareGradeEnglish(Student S1, Student S2)
{
	if (S1.gradeEnglish > S2.gradeEnglish)
		return 1;
	else if (S1.gradeEnglish < S2.gradeEnglish)
		return -1;
	else
		return 0;
}
int CompareGradeHistory(Student S1, Student S2)
{
	if (S1.gradeHistory > S2.gradeHistory)
		return 1;
	else if (S1.gradeHistory < S2.gradeHistory)
		return -1;
	else
		return 0;
}
int CompareAverage(Student S1, Student S2)
{
	if (S1.gradeAverage > S2.gradeAverage)
		return 1;
	else if (S1.gradeAverage < S2.gradeAverage)
		return -1;
	else
		return 0;
}