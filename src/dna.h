#ifndef __DNA__
#define __DNA__

#include "rule.h"
#include <vector>

class code;
class dna;

class code
{
private:
	int entry_num;
	std::vector<std::vector<double> > resource;
	std::vector<double> life, size, spawn;
friend dna;
public:
	void init(rule r0);

	void print();
};

class dna
{
private:
	int len;
	std::vector<std::vector<int> > seq;
public:
	std::vector<double> resource;
	double life,size,spawn;

	void init(rule r0, int Len);
	void mutate(code& c0);
	void translate(rule r0, code& c0);

	void print_seq();
};
#endif
