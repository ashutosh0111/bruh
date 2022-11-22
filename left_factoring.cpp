#include <bits/stdc++.h>
using namespace std;
int main()
{
	int mat = 0;
	cout << "enter the production : ";
	string s;
	cin >> s;
	char c = s[0];
	s.erase(0, 2);
	vector<string> vt;
	string w = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '/')
		{
			vt.push_back(w);
			w = "";
		}
		else
		{
			w += s[i];
		}
	}

	vt.push_back(w);
	int count = 1;
	vector<string> nn;
	for (int i = 0; i < vt.size() - 1; i++)
	{
		string s1 = vt[i];
		string s2 = vt[i + 1];
		int j = min(s1.size(), s2.size());
		int match = 0;
		for (int x = 0; x < j; x++)
		{
			if (s1[x] == s2[x])
			{
				match++;
			}
		}

		if (match > 0)
		{
			count++;
			mat = max(match, mat);
		}
	}

	//cout<<"\n"<<mat<<endl;
	if (count > 1)
	{
		vector<string> nn;
		cout << "new production : \n" << c << "- ";
		for (int j = 0; j < count; j++)
		{
			string s3 = vt[j];
			string s4 = s3.substr(mat, s3.size() - mat);
			//cout<<s4<<endl;
			nn.push_back(s4);
		}

		string s5 = "";
		for (int i = 0; i < mat; i++)
		{
			s5 += vt[0][i];
		}

		cout << s5 << "Z/";

		for (int i = count; i < vt.size(); i++)
		{
			cout << vt[i] << "/";
		}

		cout << endl;
		cout << "Z-";
		for (int i = 0; i < nn.size(); i++)
		{
			cout << nn[i] << "/";
		}
	}
}

