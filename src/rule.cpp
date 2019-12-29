#include <vector>
#include <math.h>
#include "rule.h"

using namespace std;

rule :: rule()
{
	double tmp_res = 1;
	int tmp_len = 20;
	dna_k = 20;
	dna_l = 3;
	res_k = 2;
	len_in = 100;
	len_out = 100;
	len_param = 400;
	rand_max_life = 2;
	rand_max_size = 1;
	rand_max_spawn = 0.05;
	rand_max_mutation = 0.005;
	max_capacity = 10;
	for(size_t t1=0; t1<res_k; t1++)
		ini_res.push_back(tmp_res);
	dim = 2;
	for(size_t t1=0; t1<dim; t1++)
		len_land.push_back(tmp_len);
}

int rule :: index(vector<int> i1)
{
	int i2=i1[0];
	for(size_t t1=1; t1<dna_l; t1++)
		i2=i2*dna_k+i1[t1];
	return i2;
}

double norm(vector<double> B)
{
	double res=0;
	for(auto& m1:B)
		res += m1*m1;
	return sqrt(res);
}

double dot(vector<double> A, vector<double>B)
{
	double res=0;
	int dim = min(A.size(), B.size());
	for(size_t t1=0; t1<dim; t1++)
		res += A[t1]*B[t1];
	return res;
}

vector<double>& renorm(vector<double>& B)
{
	double tmp_norm = norm(B);
	for(auto& m1:B)
		m1 /= tmp_norm;
	return B;
}
