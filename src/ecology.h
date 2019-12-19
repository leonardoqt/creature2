#ifndef __ECOLOGY__
#define __ECOLOGY__

#include "rule.h"
#include "dna.h"
#include "creature.h"
#include <vector>
#include <fstream>

class land;
class ecology;

class land
{
private:
	std::vector<double> res;
	std::vector<creature> bio;
friend ecology;
public:
	void init(rule r0, code& c0);
	void feed();		// creatures take food and produce products

	void print();
	void print(std::ofstream& out);
};

class ecology
{
private:
	std::vector<int> len_land;
	int num_land;
	std::vector<land> terr;
public:
	void init(rule r0, code& c0);
	void evolve(rule r0, code& c0);	// creatures take a whole cycle and grow by one year

	void print();
	void print(std::ofstream& out);
	
	int index(std::vector<int> i1);
	std::vector<int> index(int i1);
};
#endif
