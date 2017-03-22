#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct inf
{
	string phone_number;
	string fio;
	string address;
};

struct cell
{
	inf data;
	cell *next;
};

cell *table[99];

int f_hash(string phone_number)
{
	int sum = 0;
	for(int i = 0 ; i < phone_number.length(); ++i)
	{
		sum = sum + phone_number[i] - '0';
	}
	sum=sum % 100;	
	return(sum);
}

void out(cell *now)
{
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"����� ��������: "<<now->data.phone_number<<endl;
	cout<<"���: "<<now->data.fio<<endl;
	cout<<"�����: "<<now->data.address<<endl;
	cout<<"---------------------------------------------------------------"<<endl;	
}

cell *search(string phone_number)
{
	int hash = f_hash(phone_number);
	cell *now = new cell;
	now = table[hash];
	if(now != NULL)
	{
		while( (now->data.phone_number != phone_number) && (now->next != NULL) )
		{
			now = now->next;
		}
		if(now->data.phone_number != phone_number)
		{
			return(NULL);
		}
		else
		{
		    return(now);	
		}
	}
	else
	{
		return(NULL);
	}
}

void insert(void)
{
	string temp;
	int hash_now;
	cell *now;
	now=new cell;
	cout<<"������� ����� ��������"<<endl;
	cin.ignore();
	getline(cin , temp);
	hash_now = f_hash(temp);
	if(table[hash_now] == NULL)
	{
		table[hash_now] = new cell;
		table[hash_now]->next = NULL;
	}
	now->next = table[hash_now]->next;
	table[hash_now]->next = now;
	now->data.phone_number = temp;
	cout<<"������� ���"<<endl;
	cin.ignore(0);
	getline(cin , now->data.fio);
	cout<<"������� �����"<<endl;
	cin.ignore(0);
	getline(cin , now->data.address);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	bool trig;
	while(1)
	{
		cout<<"������ ����� ������? 1/0"<<endl;
		cin>>trig;
		if(trig == 0)
		{
			break;
		}
		else
		{
			insert();	
		}
	}
	string s_num;
	int s_hash;
	cell *now;
	while(1)
	{
		cout<<endl<<"������ �������� �� �����? 1/0"<<endl;
		cin>>trig;
		if(trig == 0)
		{
			break;
		}
		else
		{
			cout<<"������� ������� �����"<<endl;
			cin.ignore();
			getline(cin , s_num);
			now=search(s_num);
			if(now != NULL)
			{
				cout<<endl<<"����� ������."<<endl;
				out(now);
			}
			else
			{
				cout<<endl<<"����� �� ������"<<endl;	
			}
		}
	}
	return 0;
}

