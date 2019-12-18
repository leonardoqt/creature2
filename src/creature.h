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
public:
	std::vector<double> re_in;
	std::vector<double> re_out;
	double life;
	double max_size;
	double spawn_rate;
	double mutation;
	double age;
	double size;
	double status;

	void init(rule r0, code& c0);	// get all initial state
	creature spawn(rule r0, code& c0);
	int if_defect(rule r0);

	void print();
};
#endif
