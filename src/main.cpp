#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "rule.h"
#include "dna.h"

using namespace std;

int main ()
{
	chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
	srand(now.time_since_epoch().count());

	rule r0;
	code c0;
	dna d0;

	c0.init(r0);
//	c0.print();
	d0.init(r0,4);
	d0.print_seq();
	d0.translate(r0,c0);
	return 0;
}
