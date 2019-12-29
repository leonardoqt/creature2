#include <iostream>
#include <stdlib.h>
#include "dna.h"

using namespace std;

void code :: init(rule r0)
{
	// get size of the code
	entry_num = 1;
	for(size_t t1=0; t1<r0.dna_l; t1++)
		entry_num *= r0.dna_k;
	// allocate tables
	resource.resize(entry_num);
	life.resize(entry_num);
	size.resize(entry_num);
	spawn.resize(entry_num);
	mutation.resize(entry_num);
	for(auto& m1:resource)
		m1.resize(r0.res_k);
	// generate table
	for(size_t t1=0; t1<entry_num; t1++)
	{
		switch(rand()%5)
		{
		// resource gene
		case 0:
		{
			for(auto& m2:resource[t1])
				m2 = (rand()/(double)RAND_MAX)*2;
			break;
		}
		// life gene
		case 1:
		{
			life[t1] = ((rand()/(double)RAND_MAX)*2-1)*r0.rand_max_life;
			break;
		}
		// size gene
		case 2:
		{
			size[t1] = ((rand()/(double)RAND_MAX)*2-1)*r0.rand_max_size;
			break;
		}
		// spawn gene
		case 3:
		{
			spawn[t1] = ((rand()/(double)RAND_MAX)*2-1)*r0.rand_max_spawn;
			break;
		}
		// mutation gene
		case 4:
		{
			mutation[t1] = ((rand()/(double)RAND_MAX)*2-1)*r0.rand_max_mutation;
			break;
		}
		}
	}
}

void code :: print()
{
	for(size_t t1=0; t1<entry_num; t1++)
	{
		cout<<t1<<':'<<endl;
		for(auto& m2:resource[t1])
			cout<<'\t'<<m2;
		cout<<endl<<'\t'<<life[t1]<<'\t'<<size[t1]<<'\t'<<spawn[t1]<<'\t'<<mutation[t1]<<endl;
	}
}

//=======================================================================
//=======================================================================

void dna :: init(rule r0, int Len)
{
	len = Len;
	seq.resize(len);
	for(auto& m1:seq)
	{
		m1.resize(r0.dna_l);
		for(auto& m2:m1)
			m2 = rand()%r0.dna_k;
	}
	resource.resize(r0.res_k);
}

void dna :: mutate(rule r0, int num)
{
	for(size_t t1=0; t1<num; t1++)
	{
		int m_ith = rand()%len;
		int m_index = rand()%r0.dna_l;
		seq[m_ith][m_index] = rand()%r0.dna_k;
	}
}

void dna :: translate(rule r0, code& c0)
{
	int index;
	for(auto& m1:resource)
		m1=0;
	life = 0;
	size = 0;
	spawn = 0;
	mutation = 0;
	for(size_t t1=0; t1<len; t1++)
	{
		index = r0.index(seq[t1]);
		for(size_t t2=0; t2<r0.res_k; t2++)
			resource[t2] += c0.resource[index][t2];
		life += c0.life[index];
		size += c0.size[index];
		spawn += c0.spawn[index];
		mutation += c0.mutation[index];
	}
}

void dna :: m_res(vector<double>& Res)
{
	Res = resource;
}

void dna :: m_param(double& Life, double& Size, double& Spawn, double& Mutation)
{
	Life = life;
	Size = size;
	Spawn = spawn;
	Mutation = mutation;
}

void dna :: print_seq()
{
	for(auto& m1:seq)
	{
		for(auto& m2:m1)
			cout<<m2<<'\t';
		cout<<endl;
	}
}

void dna :: print_param()
{
	for(auto& m2:resource)
		cout<<'\t'<<m2;
	cout<<endl<<'\t'<<life<<'\t'<<size<<'\t'<<spawn<<'\t'<<mutation<<endl;
}
