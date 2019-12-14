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
	for(auto& m1:resource)
		m1.resize(r0.res_k);
	// generate table
	for(size_t t1=0; t1<entry_num; t1++)
	{
		switch(rand()%4)
		{
		// resource gene
		case 0:
		{
			for(auto& m2:resource[t1])
				m2 = (rand()/(double)RAND_MAX)*2-1;
			break;
		}
		// life gene
		case 1:
		{
			life[t1] = (rand()/(double)RAND_MAX)*10-5;
			break;
		}
		// size gene
		case 2:
		{
			size[t1] = (rand()/(double)RAND_MAX)*2-1;
			break;
		}
		// spawn gene
		case 3:
		{
			spawn[t1] = (rand()/(double)RAND_MAX)*0.4-0.2;
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
		cout<<endl<<'\t'<<life[t1]<<'\t'<<size[t1]<<'\t'<<spawn[t1]<<endl;
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
}

void dna :: translate(rule r0, code& c0)
{
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
