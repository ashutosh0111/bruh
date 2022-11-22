#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<char, int> mp;
	cout << "enter the number of terminals  :";
	int n;
	cin >> n;
	cout << "enter the terminals ";
	string s;
	cin >> s;
	//cout<<s[0];
	char tab[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char x = s[i];
			char y = s[j];
			cout << "enter the relation between ";
			cout << x;
			cout << " and ";
			cout << y;
			cin >> tab[i][j];
			cout << " ";
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cout << " @ ";
			for (int j = 0; j < n; j++)
			{
				cout << s[j] << " ";
			}

			cout << endl;
		}

		cout << s[i] << " ";
		for (int j = 0; j < n; j++)
		{
			cout << tab[i][j] << " ";
		}

		cout << endl;
	}

	for (int i = 0; i < s.size(); i++)
	{
		mp[s[i]] = i;
	}

	cout << "enter the string : ";
	int flag =0 ;
	
	string ip;
	cin >> ip;
	for(int i =0 ; i< ip.size()-1 ; i++){
	    if(ip[i]==ip[i+1])
	    flag =1;
	}
	string buf = "$";
	cout << "stack \t\t\ buffer \t\taction " << endl;
	while (buf.size() >= 1)
	{
		cout << buf << "\t\t";
		cout << ip << "\t\t";
		char c = buf[buf.size() - 1];
		char d = ip[0];
		int x = mp[c];
		int y = mp[d];
		if (tab[x][y] == '>' || tab[x][y] == '=')
		{
			buf.erase(buf.size() - 1, 1);
			// buf+=ip[0];
			// ip.erase(0,1);
			cout << "reduce pop ";
		}
		else if (tab[x][y] == '<')
		{
			cout << "push " << ip[0];
			buf += ip[0];
			ip.erase(0, 1);
		}
		else
		{
			cout << "error ";
			break;
		}

		cout << endl;
	}
	//cout<<buf<<endl;
	//cout<<" - "<<ip<<endl;

	if (buf.size() == 0 && ip == "$" && flag == 0)
	{
		cout << " string accepted ";
	}
	else
		cout << "string rejected ";
	return 0;
}
