#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
#define ll long long
void display(vector<vector<char>>&vect,ll k)
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
void bubble(vector<vector<char>>&vect)
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
void selection(vector<vector<char>>&vect)
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
void insertion(vector<vector<char>>&vect)
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
void merge(vector<vector<char>>&vect, ll start, ll mid, ll end )
{
	vector<vector<char>>sect1(mid-start+1),sect2(end-mid);
	for(ll i=start;i<=mid;i++)
	sect1[i-start]=vect[i];
	for(ll i=mid+1;i<=end;i++)
	sect2[i-mid-1]=vect[i];
	ll i=start,j=0,k=0;
	while(j<sect1.size() && k<sect2.size())
	{
		if(sect1[j].size()<=sect2[k].size())
		{
			vect[i]=sect1[j];
			i++;
			j++;
		}
		else
		{
			vect[i]=sect2[k];
			i++;
			k++;
		}
		display(vect,3);
	}
	while(j<sect1.size())
	{
		vect[i]=sect1[j];
		i++;
		j++;
		display(vect,3);
	}
	while(k<sect2.size())
	{
		vect[i]=sect2[k];
		k++;
		i++;
		display(vect,3);
	}
}
void mergesort(vector<vector<char>>&vect,ll start, ll end )
{
	ll n=vect.size();
	if(start<end)
	{
		ll mid=(start+end)/2;
		mergesort(vect,start,mid);
		mergesort(vect,mid+1,end);
		merge(vect,start,mid,end);
		// display(vect,n);
	}
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
	else if(choice==4)
	mergesort(vect,0,vect.size()-1);
	else
	cout<<"wrong output\n"<<endl;
	// cout<<"1. continue?";
	// cin>>choice;
	// if(choice==1)
	// goto menu;
	// cout<<"After sorting\n";
	// display(vect);
	return 0;
}
//Author: master_sam
