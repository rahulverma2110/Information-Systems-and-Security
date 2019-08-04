#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

string en(int key, string s, string enfile, string defile)
{
	ifstream fio;
	ofstream of;
	cout<<"Enter the key value: ";
	cin>>key;
	fio.open(enfile);
	getline(fio,s);
	fio.close();
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] == ' ')
		{
			continue;
		}
		s[i] = s[i] + key;
		if(s[i] > 122)
		{
			s[i] = 96 + (s[i] - 122);
		}
	}
	transform(s.begin(), s.end(), s.begin(),::toupper);
	of.open(defile);
	of<<s;
	//cout<<s<<endl;
	of.close();
	
	return s;
}

string de(int key, string s, string enfile, string defile)
{
	ifstream fio;
	ofstream of;
	cout<<"Enter the key value: ";
	cin>>key;
	fio.open(defile);
	getline(fio,s);
	for(int j = 0;j <= s.length(); j++)
	{
		if(s[j] == ' ')
		{
			continue;
		}
		s[j] = s[j] - key;
		if(s[j] < 65)
		{
			s[j] = 90 - (65 - s[j] - 1);
		}
	}
	transform(s.begin(), s.end(), s.begin(),::tolower);
	of.open(enfile);
	of<<s;
	//cout<<s<<endl;
	of.close();
	
	return s;
}

int main()
{
	int key,flag;
	ifstream fio;
	ofstream of;
	//int flag;
	string enfile, defile, s, C, P;
	cout<<"Enter the file name in which you want to save the encrypted code: ";
	cin>>enfile;
	cout<<"Enter the file name in which you want to save the decrypted code: ";
	cin>>defile;
	cout<<"Enter 0 for Encryption and 1 for Decryption: ";
	cin>>flag;
	
	if(flag == 0)
	{
		C = en(key,s,enfile,defile);
		cout<<"Encrypted text is:"<<endl<<C;
	}
	
	else if(flag == 1)
	{
		P = de(key,s,enfile,defile);
		cout<<"Decrypted text is:"<<endl<<P;
	}
	return 0;
}
