#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "rule.h"
#include "dna.h"
#include "creature.h"

using namespace std;

int main ()
{
	chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
	srand(now.time_since_epoch().count());

	rule r0;
	code c0;
	creature ccc;
	int len_in = 10, len_out = 10, len_param = 10;

	c0.init(r0);
	for(size_t t1=0; t1<24; t1++)
	{
		ccc.init(r0,c0,len_in,len_out,len_param);
		if(ccc.life > 0 && ccc.max_size > 0 && ccc.spawn_rate > 0)
		{
			cout<<"============================================"<<endl;
			ccc.print();
		}
	}
	return 0;
}
