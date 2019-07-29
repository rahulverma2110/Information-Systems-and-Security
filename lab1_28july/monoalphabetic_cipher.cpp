#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
	string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
	
	ifstream fio;
	ofstream of;
	//cout<<s.length();
	int flag;
	cout<<"Enter 0 for encryption and 1 for decryption: ";
	cin>>flag;
	if(flag==0)
	{
		fio.open("file.txt");
		string s;
		getline(fio,s);
	//	cout<<s<<endl;
		fio.close();
		for(int i = 0;i < s.length();i++)
		{
			if(s[i] == ' ')
			{
			i++;
			continue;
			}
			s[i] = key[s[i] - 97];
		}
		transform(s.begin(), s.end(), s.begin(),::toupper);
		of.open("ans.txt");
		of<<s;
		cout<<s<<endl;
		of.close();
	}
	
	else if(flag == 1)
	{
		fio.open("ans.txt");
		string s;
		getline(fio,s);
		//cout<<s<<endl;
		for(int j = 0;j <= s.length(); j++)
		{
			if(s[j] == ' ')
			{j++;
			continue;}
			int k;
			for(k = 0; k<key.length(); k++)
			{
				if(s[j] == key[k])
				{
					break;
				}
			}
			s[j] = 97 + k;
		}
		transform(s.begin(), s.end(), s.begin(),::tolower);
		of.open("file.txt");
		of<<s;
		cout<<s<<endl;
		of.close();
	}

	return 0;
}
