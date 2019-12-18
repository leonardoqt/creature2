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
	std::vector<double> life, size, spawn, mutation;		// later may consider to include mutation rate
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
	std::vector<double> resource;
	double life,size,spawn,mutation;
public:
	void init(rule r0, int Len);
	void mutate(rule r0,int num);
	void translate(rule r0, code& c0);

	void m_res(std::vector<double>& Res);
	void m_param(double& Life, double& Size, double& Spawn, double& Mutation);

	void print_seq();
	void print_param();
};
#endif
