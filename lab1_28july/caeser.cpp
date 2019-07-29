#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
	int key;
	ifstream fio;
	ofstream of;
	//cout<<s.length();
	int flag;
	cout<<"Enter 0 for encryption and 1 for decryption: ";
	cin>>flag;
	if(flag==0)
	{
		cout<<"Enter the key value: ";
		cin>>key;
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
			s[i] = s[i] + key;
			if(s[i] > 122)
			{
				s[i] = 97 + (s[i] - 122);
			}
		}
		transform(s.begin(), s.end(), s.begin(),::toupper);
		of.open("ans.txt");
		of<<s;
		cout<<s<<endl;
		of.close();
	}
	
	else if(flag == 1)
	{
		cout<<"Enter the key value: ";
		cin>>key;
		fio.open("ans.txt");
		string s;
		getline(fio,s);
		//cout<<s<<endl;
		for(int j = 0;j <= s.length(); j++)
		{
			if(s[j] == ' ')
			{j++;
			continue;}
			s[j] = s[j] - key;
			if(s[j] < 65)
			{
				s[j] = 90 - (65 - s[j] - 1);
			}
		}
		transform(s.begin(), s.end(), s.begin(),::tolower);
		of.open("file.txt");
		of<<s;
		cout<<s<<endl;
		of.close();
	}
	return 0;
}
