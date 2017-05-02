#include "stdafx.h"
#include "simple.h"
#include <iostream>
#include <vector>
//#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


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


/*试探法+回溯
逐个尝试，直到不满足条件，然后回到错误的地方继续下一个，是一种暴力的解法
*/
int Subset_SumEqualToal(int a[], int n, int total)
{
	int c = 0;
	std::vector<int> s;
	for (int i = 0; i < n; ++i) {
		int T = total;
		bool b = false;
		s.clear();

		for (int j = i; j < n;) {
			++c;
			if (a[j] > T) {
				++j;
				if (j == n) {
					//开始回溯
					int len = s.size() - 1;
					if (len >= 0) {
						j = s[len] + 1;//最后一个候选前进
						T += a[s[len]];//回溯状态
						s.erase(s.begin() + s.size() - 1);
					}
				}
				continue;
			}

			T -= a[j];
			s.push_back(j);
			++j;

			if (0 == T) {
				for (size_t k = 0; k < s.size(); ++k) {
					cout << a[s[k]] << ' ';
				}
				cout << endl;
				b = true;
			}
			
			if (b) {
				break;
			}
		}
	}
	
	return c;
}