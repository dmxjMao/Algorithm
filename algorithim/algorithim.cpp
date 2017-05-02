// algorithim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "simple.h"
#include "bowling.h"//±£¡‰«Ú

using namespace std;

int main()
{
	cout << "hello,world!" << endl;

	int a[] = { 1,2,3,4,5,6,7,8,9,10,123 };
	cout << "c:" 
		<< Subset_SumEqualToal(a, sizeof(a) / sizeof(a[0]), 9)
		<< endl;


    return 0;
}

