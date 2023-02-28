#pragma once
class Student{
public:
	char* name;
	float gradeMath, gradeHistory, gradeEnglish, gradeAverage;
	void SetName(const char* s);
	char* GetName();
	void SetGradeMath(float x);
	float GetGradeMath();
	void SetGradeEnglish(float x);
	float GetGradeEnglish();
	void SetGradeHistory(float x);
	float GetGradeHistory();
	float AverageGrade();
};