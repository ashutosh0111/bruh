#include <bits/stdc++.h>
using namespace std;
int main()
{
	cout << "enter the production ";
	string s;
	cin >> s;
	vector<string> vt;
	char c = s[0];
	s.erase(0, 2);
	string w = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '/')
		{
			vt.push_back(w);
			//  cout<<w<<endl;
			w = "";
		}
		else
		{
			w += s[i];
		}
	}

	vt.push_back(w);
	vector<string> nn;
	vector<string> zz;
	for (int i = 0; i < vt.size(); i++)
	{
		string z = vt[i];
		if (z[0] == c)
		{
			z.erase(0, 1);

			//cout<<z<<endl;
			nn.push_back(z);
		}
		else
		{
			zz.push_back(z);
		}
	}

	nn.push_back("#");
	cout << "new production is  \n" << c << "- ";

	for (int i = 0; i < zz.size(); i++)
	{
		string z = zz[i] + "Z/";
		cout << z;
	}

	cout << "\n Z-";
	for (int i = 0; i < nn.size(); i++)
	{
		cout << nn[i] << "/";
	}
}
