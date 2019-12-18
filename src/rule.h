#ifndef __RULE__
#define __RULE__
#include <vector>

class rule
{
public:
	int dna_k;
	int dna_l;
	int res_k;	// kind of resource
	int len_in, len_out, len_param;	// length of gene
	double rand_max_life, rand_max_size, rand_max_spawn, rand_max_mutation;
	std::vector<double> ini_res;	// initial value of each resource
	int dim;						// dimension of the world
	std::vector<int> len_land;		// size of the world
	rule();
	int index(std::vector<int> i1);
	double norm(std::vector<double> B);
	std::vector<double>& renorm(std::vector<double>& B);
};

#endif
