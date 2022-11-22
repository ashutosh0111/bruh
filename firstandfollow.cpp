#include <bits/stdc++.h>
using namespace std;
char sss;
map<char, string> mp;
set<char> st;

set<char> firstt(char t)
{
	string z = mp[t];
	vector<string> vt;
	int i = 0;
	string w = "";
	while (i < z.size())
	{
		if (z[i] == '/')
		{
			vt.push_back(w);
			w = "";
			i++;
		}
		else
		{
			w = w + z[i];
			i++;
		}
	}

	set<char> ans;
	vt.push_back(w);
	for (int i = 0; i < vt.size(); i++)
	{
		string tt = vt[i];
		if (t == tt[0])
			continue;
		else if (st.find(tt[0]) != st.end())
		{
			set<char> ans1 = firstt(tt[0]);
			ans.insert(ans1.begin(), ans1.end());
		}
		else
		{
			ans.insert(tt[0]);
		}
	}

	// for(auto y : ans)
	// cout<<y<<", ";
	// }

	return ans;
}

set<char> follow(char ttt)
{
	set<char> anss;
	if (ttt == sss)
	{
		anss.insert('$');
	}

	for (auto u: mp)
	{
		string ss = u.second;
		for (int i = 0; i < ss.size(); i++)
		{
			if (ss[i] == ttt)
			{
				if (i == ss.size() - 1)
				{
					set<char> ans2 = follow(u.first);
					anss.insert(ans2.begin(), ans2.end());
				}
				else
				{
					if (ss[i + 1] == '/')
					{
						set<char> ans2 = follow(u.first);
						anss.insert(ans2.begin(), ans2.end());
						//return follow(u.first);
					}
					else if (st.find(ss[i + 1]) != st.end())
					{
						set<char> ans2 = firstt(ss[i + 1]);
						anss.insert(ans2.begin(), ans2.end());
						// return follow(ss[i+1]);
					}
					else
					{
						anss.insert(ss[i + 1]);
					}
				}
			}
		}
	}

	return anss;
}

int main()
{
	cout << "enter the number of productions : ";
	int n;
	cin >> n;
	cout << "enter the productions ";
	while (n--)
	{
		string s;
		cin >> s;
		char x = s[0];
		st.insert(x);
		s.erase(0, 2);
		mp[x] = s;
	}

	cout << "enter the starting symbol ";
	cin >> sss;

	for (auto x: mp)
	{
		cout << "first(" << x.first << "] -> ";
		set<char> sttt = firstt(x.first);
		for (auto x: sttt)
			cout << x << ",";
		cout << endl;
	}

	cout << endl;
	for (auto x: mp)
	{
		cout << "follow (" << x.first << "] -> ";
		set<char> sttt = follow(x.first);
		for (auto x: sttt)
			cout << x << ",";
		cout << endl;
	}
}

