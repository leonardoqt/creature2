#include <iostream>
#include "ecology.h"

using namespace std;

void land :: init(rule r0, code& c0)
{
	res = r0.ini_res;
	bio.clear();
	bio.push_back(creature());
	bio.back().init(r0,c0);
	if(bio.back().if_defect(r0))
		bio.pop_back();
}

void land :: print()
{
	cout<<"Resource:"<<endl;
	for(auto& m1:res)
		cout<<'\t'<<m1<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Creatures:"<<endl;
	for(auto& m1:bio)
	{
		m1.print();
		cout<<"------------------"<<endl;
	}
}

//====================================================

void ecology :: init(rule r0, code& c0)
{
	len_land = r0.len_land;
	num_land = 1;
	for(auto& m1:len_land)
		num_land *= m1;
	terr = vector<land> (num_land);
	for(auto& m1:terr)
		m1.init(r0,c0);
}

void ecology :: print()
{
	vector<int> tmp_index;
	for(size_t t1=0; t1<num_land; t1++)
	{
		tmp_index = index(t1);
		cout<<"Terr";
		for(auto& m2:tmp_index)
			cout<<'\t'<<m2;
		cout<<" :"<<endl;
		terr[t1].print();
		cout<<"================================================"<<endl;
	}
}

int ecology :: index(vector<int> i1)
{
	int i2=i1[0];
	for(size_t t1=1; t1<len_land.size(); t1++)
		i2=i2*len_land[t1]+i1[t1];
	return i2;
}

vector<int> ecology :: index(int i1)
{
	vector<int> i2=len_land;
	for(int t1=len_land.size()-1; t1>=0; t1--)
	{
		i2[t1] = i1%len_land[t1];
		i1 = (i1-i2[t1])/len_land[t1];
	}
	return i2;
}
