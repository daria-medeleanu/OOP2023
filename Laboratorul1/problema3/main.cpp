#include <iostream>
using namespace std;
int compareStrings(char* c1, char* c2)
{
	int len1 = strlen(c1), len2 = strlen(c2);
	if (len1 < len2)
		return 1;
	else if (len1 > len2)
		return -1;
	for (int i = 0; i < len1 && i < len2; i++)
	{
		if (c1[i] == c2[i])
			continue;
		if (c1[i] < c2[i])
			return 1;
		else
			return -1;
	}
	return 0;
}
int main()
{
	char s[100],v[50][100];
	for (int i = 0; i < 50; i++)
		for (int a=0;a<100;a++ )
			v[i][a] = NULL;
	int line= 1,column = 0;
	fgets(s,100,stdin);//ca sa citeasca si spatiile
	//initializare matrice de cuvinte
	for (int i = 0; i < strlen(s)-1; i++)//parcurgem propozitia
		if (s[i] != ' ')
			v[line][column++] = s[i];
		else
		{
			line++;
			column = 0;
		}
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for(int i=1;i<line;i++)
			if (compareStrings(v[i], v[i + 1]) == 1)
			{
				swap(v[i], v[i + 1]);
				sorted = false;
			}
	}
	for (int i = 1; i <= line; i++)
		printf("%s\n", v[i]);
	return 0;
}