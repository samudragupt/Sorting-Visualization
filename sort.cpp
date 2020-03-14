#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
#define ll long long
void display(vector<vector<char>>vect,ll k)
{
	usleep(k*40000);
	system("clear");
	for(auto v:vect)
	{
		for(auto x:v)
			cout<<x;
		cout<<endl;
	}
	return;
}
void bubble(vector<vector<char>>vect)
{
	ll n=vect.size();
	for(ll i=0; i<n-1;i++)
	{
		for(ll j=0;j<n-i-1;j++)
		{
			if(vect[j].size()>vect[j+1].size())
			{
				vector<char>sect;
				sect=vect[j];
				vect[j]=vect[j+1];
				vect[j+1]=sect;
			}
			display(vect,1);
		}
	}
}
void selection(vector<vector<char>>vect)
{
	ll n=vect.size();
	for(ll i=0;i<n-1;i++)
	{
		ll minsize=INT_MAX,pos=-1;
		for(ll j=i;j<n;j++)
		{
			if(vect[j].size()<minsize)
			{
				minsize=vect[j].size();
				pos=j;
			}
		}
		vector<char>sect=vect[i];
		vect[i]=vect[pos];
		vect[pos]=sect;
		display(vect,n);
	}
	//display(vect,n);
}
void insertion(vector<vector<char>>vect)
{
	ll n=vect.size();
	for(ll i=1;i<n;i++)
	{
		for(ll j=i;j>0;j--)
		{
			if(vect[j].size()<vect[j-1].size())
				swap(vect[j],vect[j-1]);
			else
				break;
			display(vect,5);
		}
	}
}
void mergesort(vector<vector<char>>vect)
{
	ll n=vect.size();
	
}
/*
bool comp(vector<char>A, vector<char>B)
{
	if(A.size()>B.size())
		return false;
	else
		return true;
}*/
int main()
{
	ll n;
	cout<<"Enter the number of Input: ";
	cin>>n;
	cout<<endl;
	vector<vector<char>>vect;
	vector<ll>random_int(n);
	for(ll i=0;i<n;i++)
	{
		random_int[i]=i+1;
	}
	for(ll i=0;i<n;i++)
	{
		ll x=((ll)(rand()))%random_int.size();
		/*ll x;
		cin>>x;*/
		vector<char>sect;
		for(ll i=0;i<random_int[x];i++)
		{
			sect.push_back(char(42));
		}
		vect.push_back(sect);
		random_int.erase(random_int.begin()+x);
	}
	menu:
	cout<<"Before sorting:\n";
	display(vect,2);
	ll choice;
	// sort(vect.begin(),vect.end(),comp);
	cout<<"Choose the way to sort:\n";
	cout<<"1. bubble sort\n";
	cout<<"2. selection sort\n";
	cout<<"3. insertion sort\n";
	cout<<"4. merge sort\n";
	cin>>choice;
	if(choice==1)
	bubble(vect);
	else if(choice==2)
	selection(vect);
	else if(choice==3)
	insertion(vect);
	else
	cout<<"wrong output\n"<<endl;
	cout<<"1. continue?";
	cin>>choice;
	if(choice==1)
	goto menu;
	// cout<<"After sorting\n";
	// display(vect);
	return 0;
}
//Author: master_sam
