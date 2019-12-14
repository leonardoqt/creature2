#include <vector>
#include "rule.h"

using namespace std;

rule :: rule()
{
	dna_k = 20;
	dna_l = 3;
	res_k = 5;
}

int rule :: index(vector<int> i1)
{
	int i2=i1[0];
	for(size_t t1=1; t1<dna_l; t1++)
		i2=i2*dna_k+i1[t1];
	return i2;
}
