#ifndef __CREATURE__
#define __CREATURE__

#include "rule.h"
#include "dna.h"
#include <vector>

class creature;

class creature
{
private:
	dna dna_in;		// control in type
	dna dna_out;	// control out type
	dna dna_param;	// control creature status
	std::vector<double> re_in;
	std::vector<double> re_out;
	double life;
	double max_size;
	double spawn_rate;
	double age;
	double size;
	double status;
};
#endif
