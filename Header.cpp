#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "Header.h"
using namespace std;
int tree::zeroSite()
{
	for (int i = 0; i < num.length(); i++)
		if (num[i] == '0')
			return i;
}
