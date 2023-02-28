#include <iostream>
#include "Student.h"
#include "Students.h"
using namespace std;
int main()
{
	Student S;
	Student e1, e2;
	S.SetName("daria");
	printf("%s\n", S.GetName());
	S.SetGradeMath(7);
	printf("%f\n", S.GetGradeMath());
	S.SetGradeHistory(6);
	printf("%f\n",S.GetGradeHistory());
	S.SetGradeEnglish(9);
	printf("%f\n",S.GetGradeEnglish());
	e1.SetName("Ana");
	e1.SetGradeMath(7);
	e1.SetGradeHistory(6);
	e1.SetGradeEnglish(9);
	e2.SetName("Maria");
	e2.SetGradeMath(7);
	e2.SetGradeHistory(7);
	e2.SetGradeEnglish(8);
	printf("%d\n",CompareName(e1, e2));
	printf("%d\n",CompareGradeMath(e1, e2));
	printf("%d\n",CompareGradeEnglish(e1, e2));
	printf("%d\n",CompareGradeHistory(e1, e2));
	printf("%d\n",CompareAverage(e1, e2));
}