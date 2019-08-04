#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
	string key;
	ifstream fio;
	ofstream of;
	//cout<<s.length();
	int flag;
	//checking the length of the string and repitition of characters in the string
	int f = 1;
	while(f == 1)
	{
		
		cout<<"Enter 0 for Encryption and 1 for Decryption: ";
		cin>>flag;
		cout<<"Enter the key string with distinct 26 alphabets:"<<endl;
		cin>>key;
		if(key.length() != 26)
		{
			cout<<"Invalid string!!! Please input a valid string with exactly 26 alphabets"<<endl;
			f = 1;
		}
		else 
		{
			int arr[26];
			int i;
			int g;
			for(i = 0; i<26; i++)
			{
				arr[i] = 0;
			}

			for(i = 0; i<26; i++)
			{
				g = key[i] - 65;
			
				if (arr[g] == 0)
				{
					arr[g] = 1;
					f = 0;
				}
				else
				{
					cout<<"Invalid string!!! Please input a valid string with no repetition of alphabets\n";
					f = 1;
					break;
				}
			
			}		
		}
	}
	
	if(flag==0)
	{
		fio.open("file.txt");
		string s;
		getline(fio,s);
	//	cout<<s<<endl;
		fio.close();
		for(i = 0;i < s.length();i++)
		{
			if(s[i] == ' ')
			{
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
		for(j = 0;j <= s.length(); j++)
		{
			if(s[j] == ' ')
			{
				continue;
			}
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
