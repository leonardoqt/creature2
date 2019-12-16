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
	std::vector<double> ini_res;	// initial value of each resource
	int dim;
	std::vector<int> len_land;
	rule();
	int index(std::vector<int> i1);
	double norm(std::vector<double> B);
	std::vector<double>& renorm(std::vector<double>& B);
};

#endif
