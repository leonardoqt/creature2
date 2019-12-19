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
	else
		bio.push_back(bio.back().spawn(r0,c0));
}

void land :: feed()
{
	double tmp;
	for(auto& m1:bio)
	{
		// find available food
		tmp = dot(res,m1.re_out);
		if(tmp > 0)
			tmp = dot(res,m1.re_in) - tmp*dot(m1.re_in,m1.re_out);
		else
			tmp = dot(res,m1.re_in);
		// adjust with size
		if(tmp > m1.size)
			tmp = m1.size;
		else if(tmp < 0)
			tmp = 0;
		// food are consumed and products are produced
		for(size_t t2=0; t2<res.size(); t2++)
			res[t2] -= tmp*(m1.re_in[t2]-m1.re_out[t2]);
		// how healty the creature is
		m1.status = tmp/m1.size;
	}
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

void land :: print(ofstream& out)
{
	out<<"Resource:"<<endl;
	for(auto& m1:res)
		out<<'\t'<<m1<<endl;
	out<<"------------------------------------"<<endl;
	out<<"Creatures:"<<endl;
	for(auto& m1:bio)
	{
		m1.print(out);
		out<<"------------------"<<endl;
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

void ecology :: evolve(rule r0, code& c0)
{
	int tmp;
	// death affair
	for(auto& m1:terr)
	for(size_t t2=0; t2<m1.bio.size(); t2++)
	{
		if(rand()/(double)RAND_MAX > m1.bio[t2].status || m1.bio[t2].age > m1.bio[t2].life)
		{
			m1.bio[t2] = m1.bio.back();
			m1.bio.pop_back();
		}
	}
	// eat and produce
	for(auto& m1:terr)
		m1.feed();
	// add age
	// change size
	for(auto& m1:terr)
	for(auto& m2:m1.bio)
	{
		m2.age++;
		m2.size = m2.age / m2.life * m2.max_size;
	}
	// spawn
	for(size_t t1=0; t1<num_land; t1++)
	for(auto& m2:terr[t1].bio)
	if(m2.age!=1.0)
	{
		tmp = 1;
		if(rand()/(double)RAND_MAX < m2.status*m2.spawn_rate)
			terr[(t1+tmp)%num_land].bio.push_back(m2.spawn(r0,c0));
		if(rand()/(double)RAND_MAX < m2.status*m2.spawn_rate)
			terr[(t1-tmp)%num_land].bio.push_back(m2.spawn(r0,c0));
		for(size_t t3=len_land.size()-1; t3>0; t3--)
		{
			tmp*=len_land[t3];
			if(rand()/(double)RAND_MAX < m2.status*m2.spawn_rate)
				terr[(t1+tmp)%num_land].bio.push_back(m2.spawn(r0,c0));
			if(rand()/(double)RAND_MAX < m2.status*m2.spawn_rate)
				terr[(t1-tmp)%num_land].bio.push_back(m2.spawn(r0,c0));
		}
	}
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

void ecology :: print(ofstream& out)
{
	vector<int> tmp_index;
	for(size_t t1=0; t1<num_land; t1++)
	{
		tmp_index = index(t1);
		out<<"Terr";
		for(auto& m2:tmp_index)
			out<<'\t'<<m2;
		out<<" :"<<endl;
		terr[t1].print(out);
		out<<"================================================"<<endl;
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
