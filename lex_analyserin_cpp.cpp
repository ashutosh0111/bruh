// 2019BCSE025 ASHUTOSH RANA
#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<string> keyw
	{
		"asm", "double", "new", "switch", "else", "break", "float", "char", "for", "return", "unsigned", "if", "void", "int", "static", "while" };

	set<string> oper
	{
		"<", ">", "=", "+", "-", "/", "+", "%" };

	set<string> ss
	{
		"{", "}", "(", ")", ";" };

	set<string> iden
	{
		"a", "b", "c", "x", "printf", "main" };

	set<string> keywans;
	set<string> operans;
	set<string> ssans;
	set<string> idenans;
	set<string> lit;
	set<string> cons;
	vector<string> str;
	string s;
	cout << " enter the program :  ";
	getline(cin, s);
	int i = 0;
	string ll;
	while (i < s.size())
	{
		if (isspace(s[i]))
		{
			str.push_back(ll);
			ll = "";
		}
		else
		{
			ll = ll + s[i];
		}

		i++;
	}

	str.push_back(ll);
	for (i = 0; i < str.size(); i++)
	{
		if (keyw.find(str[i]) != keyw.end())
			keywans.insert(str[i]);
		else if (oper.find(str[i]) != oper.end())
			operans.insert(str[i]);
		else if (ss.find(str[i]) != ss.end())
			ssans.insert(str[i]);
		else if (iden.find(str[i]) != iden.end())
			idenans.insert(str[i]);
		else
			cons.insert(str[i]);
	}

	cout << "keywords are : " << endl;
	for (auto x: keywans)
		cout << x << endl;

	cout << "operators are :" << endl;
	for (auto x: operans)
		cout << x << endl;

	cout << "special symbols are " << endl;
	for (auto x: ssans)
		cout << x << endl;

	cout << " identifiers are " << endl;
	for (auto x: idenans)
		cout << x << endl;

	cout << "literals are :" << endl;
	for (auto x: lit)
		cout << x << endl;

	cout << "constants are " << endl;
	for (auto x: cons)
		cout << x << endl;

	return 0;
}

