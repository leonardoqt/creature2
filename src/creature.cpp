#include "creature.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void creature :: init(rule r0, code& c0)
{
	dna_in.init(r0,r0.len_in);
	dna_out.init(r0,r0.len_out);
	dna_param.init(r0,r0.len_param);
	
	dna_in.translate(r0,c0);
	dna_out.translate(r0,c0);
	dna_param.translate(r0,c0);

	dna_in.m_res(re_in);
	dna_out.m_res(re_out);
	dna_param.m_param(life,max_size,spawn_rate,mutation);

	if(!if_defect(r0))
	{
		r0.renorm(re_in);
		r0.renorm(re_out);
		age = 1.0;
		size = age/life*max_size;
		status = 1.0;
	}
	else
		status = 0;
}

creature creature :: spawn(rule r0, code& c0)
{
	creature baby;
	int num_mutation;
	int num_in = r0.len_in*r0.dna_l;
	int num_out = r0.len_out*r0.dna_l;
	int num_param = r0.len_param*r0.dna_l;

	baby.dna_in = dna_in;
	baby.dna_out = dna_out;
	baby.dna_param = dna_param;
	//
	num_mutation = 0;
	for(size_t t1=0; t1<num_in; t1++)
		if(rand()/(double)RAND_MAX < fabs(mutation))
			num_mutation++;
	baby.dna_in.mutate(r0,num_mutation);
	//
	num_mutation = 0;
	for(size_t t1=0; t1<num_out; t1++)
		if(rand()/(double)RAND_MAX < fabs(mutation))
			num_mutation++;
	baby.dna_out.mutate(r0,num_mutation);
	//
	num_mutation = 0;
	for(size_t t1=0; t1<num_param; t1++)
		if(rand()/(double)RAND_MAX < fabs(mutation))
			num_mutation++;
	baby.dna_param.mutate(r0,num_mutation);

	baby.dna_in.translate(r0,c0);
	baby.dna_out.translate(r0,c0);
	baby.dna_param.translate(r0,c0);

	baby.dna_in.m_res(baby.re_in);
	baby.dna_out.m_res(baby.re_out);
	baby.dna_param.m_param(baby.life,baby.max_size,baby.spawn_rate,baby.mutation);

	if(!baby.if_defect(r0))
	{
		r0.renorm(baby.re_in);
		r0.renorm(baby.re_out);
		baby.age = 1.0;
		baby.size = baby.age/baby.life*baby.max_size;
		baby.status = 1.0;
	}
	else
		baby.status = 0;
	return baby;
}

int creature :: if_defect(rule r0)
{
	if(life<=0 || max_size <=0 || spawn_rate <=0 || r0.norm(re_in)<=1e-10 || r0.norm(re_out)<=1e-10)
		return 1;
	else
		return 0;
}

void creature :: print()
{
	//
	cout<<"Need type:"<<endl;
	for(auto& m1:re_in)
		cout<<m1<<'\t';
	cout<<endl;
	//
	cout<<"Produce type:"<<endl;
	for(auto& m1:re_out)
		cout<<m1<<'\t';
	cout<<endl;
	//
	cout<<"Life: "<<life<<'\t'<<"Age: "<<age<<endl;
	cout<<"Maximum size: "<<max_size<<'\t'<<"Current size: "<<size<<endl;
	cout<<"Spawn rate: "<<spawn_rate<<'\t'<<"Mutation rate: "<<mutation<<endl;
	cout<<"Overall status: "<<status<<endl;
}
