#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "rule.h"
#include "dna.h"
#include "creature.h"
#include "ecology.h"

using namespace std;

int main ()
{
	chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
	srand(now.time_since_epoch().count());

	rule r0;
	code c0;
	ecology sys1;


	c0.init(r0);
	sys1.init(r0,c0);
	sys1.print();
	return 0;
}
