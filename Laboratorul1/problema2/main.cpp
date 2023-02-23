#include <iostream>
#include <fstream>
using namespace std;
int stringToNumber(char s[])
{
	int number=0;
	for (int i = 0; s[i]!=0 && s[i]!='\n'; i++)//s[i] sfarsit de fisier sau s[i] eol
		number = number*10 + (s[i] - '0');
	return number;
}
int main()
{
	FILE* fp;
	char buffer[200];
	int nr=0, S = 0;
	bool rez = fopen_s(&fp,"ini.txt","r");//fopen_s returneaza 0 if successful
	if (rez != NULL)
	{
		printf("Fisierul nu poate fi deschis.");
		return 0;
	}
	while (fgets(buffer, 200, fp) != NULL)
	{
		nr = 0;
		nr = stringToNumber(buffer);
		S = S + nr;
	}
	printf("Suma numerelor din fisier este %d", S);
	return 0;
}