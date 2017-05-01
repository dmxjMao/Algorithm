#include "stdafx.h"
#include "simple.h"


int  CommonDivisor(int a, int b)
{
	int r = 0;
	while (b) {
		r = a%b;
		a = b;
		b = r;
	}

	return a;
}

int CommonMultiple(int a, int b)
{
	return(a*b/CommonDivisor(a,b));
}