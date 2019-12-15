#include "creature.h"
#include <iostream>
#include <vector>

using namespace std;

void creature :: init(rule r0, code& c0, int len_in, int len_out, int len_param)
{
	dna_in.init(r0,len_in);
	dna_out.init(r0,len_out);
	dna_param.init(r0,len_param);
	
	dna_in.translate(r0,c0);
	dna_out.translate(r0,c0);
	dna_param.translate(r0,c0);

	dna_in.m_res(re_in);
	dna_out.m_res(re_out);
	dna_param.m_param(life,max_size,spawn_rate);

	age = 0;
	size = 0;
	status = 1.0;
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
	cout<<"Spawn rate: "<<spawn_rate<<endl;
	cout<<"Overall status: "<<status<<endl;
}
