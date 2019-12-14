#ifndef __RULE__
#define __RULE__
#include <vector>

class rule
{
public:
	int dna_k;
	int dna_l;
	int res_k;	// kind of resource
	rule();
	int index(std::vector<int> i1);
};

#endif
