#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <fstream>
#include "rule.h"
#include "dna.h"
#include "creature.h"
#include "ecology.h"

using namespace std;

int main ()
{
	chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
	srand(now.time_since_epoch().count());
//	srand(0);

	ofstream out_i,out_f;
	rule r0;
	code c0;
	ecology sys1;

	out_i.open("ini.dat");
	out_f.open("fin.dat");

	c0.init(r0);
	sys1.init(r0,c0);
	sys1.print(out_i);

	int n_tot = 50;
	cout<<'['<<0<<'/'<<n_tot<<']'<<endl;
	for(size_t t1=0; t1<n_tot; t1++)
	{
		sys1.evolve(r0,c0);
		cout<<"\e[A"<<'['<<t1+1<<'/'<<n_tot<<']'<<endl;
	}
	sys1.print(out_f);
	return 0;
}
