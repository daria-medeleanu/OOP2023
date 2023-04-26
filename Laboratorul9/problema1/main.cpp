#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;
class Compare
{
public:
	bool operator()(const pair<string, unsigned int>& lhs, const pair<string, unsigned int>& rhs)
	{
		if (lhs.second < rhs.second)
			return true;
		if (lhs.second > rhs.second)
			return false;

		if (lhs.first > rhs.first)
			return true;
		if (lhs.first < rhs.first)
			return false;
		return true;
	}
};
void construct_map(string input, map<string, unsigned int>& out)
{
	//transform din upperCase in lowerCase
	for (char& c : input)
	{
		if (c >= 'A' && c <= 'Z')
			c = c + 32;
	}
	//cout << "input after replacement: " << input << endl;
	string delimiters[] = { " ", ",", ".", "!", "?" };
	string replacement = "<sep>";

	for (auto delimiter : delimiters)
	{
		auto pos = input.find(delimiter);
		while (pos != string::npos)
		{
			input.replace(pos, 1, replacement);
			pos = input.find(delimiter);
		}
	}
	//cout << "input after replacement: " << input << endl;
	size_t start = 0, end;
	string word;
	while ((end = input.find(replacement, start)) != string::npos)
	{
		word = input.substr(start, end - start);
		if (not word.empty())
		{
			out[word]++;
		}
		start = end + replacement.length();
	}
}

int main()
{
	string input;
	ifstream f(R"(hello.txt)");
	if (!f)
	{
		printf("error la deschiderea fisierului:hello.txt");
		return 0;
	}
	if (not getline(f, input))
	{
		printf("error la citirea din fisier:hello.txt");
		return 0;
	}
	//cout << "Received input:" << input << endl;
	map<string, unsigned int> counts;
	//printf("Sirul de caracatere citit este: %s\n", input.c_str());
	//counts["cuvant"] = 0;
	construct_map(input, counts);
	/*for (const auto& pair : counts)
	{
		cout << pair.first << ": " << pair.second << endl;
	}*/
	priority_queue<pair<string,unsigned int>, vector<pair<string, unsigned int>>, Compare> myQueue;
	for (auto mapIterator = counts.begin(); mapIterator != counts.end(); mapIterator++)
	{
		myQueue.push(pair<string, unsigned int>(mapIterator->first, mapIterator->second));
	}
	
	//golim coada
	while (!myQueue.empty())
	{
		printf("%s => %d\n", myQueue.top().first.c_str(), myQueue.top().second);
		myQueue.pop();
	}
	return 0;
}