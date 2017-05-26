// algorithim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "simple.h"
#include "bowling.h"//保龄球
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

enum FmtType {
	INTEGER,
	FLOAT,
	LOWERCHAR,
	UPPERCHAR,
	ANYCHAR
};

struct CSplitBtn {
	int a = -1;
};

bool MismatchFunc(FmtType t, tuple<FmtType, CSplitBtn*>& p)
{
	return t == get<0>(p);
}

int main()
{
	cout << "hello,world!" << endl;

	vector<tuple<FmtType, CSplitBtn*>> vExist
		= { 
			{ INTEGER,new CSplitBtn },
			{ FLOAT,new CSplitBtn },
			{ ANYCHAR,new CSplitBtn }
		};

	//增删改
	vector<FmtType> v = { INTEGER,ANYCHAR };

	size_t vLen = v.size(), vExistLen = vExist.size();

	/*元素不匹配的位置迭代器，有end(), E 代表已存在的元素，v代表动态变化的元素*/
	using misPos_vE = pair<decltype(v)::iterator, decltype(vExist)::iterator>;
	//using rmisPos_vE = pair<decltype(v)::reverse_iterator, decltype(vExist)::reverse_iterator>;
	using misPos_Ev = pair<decltype(vExist)::iterator, decltype(v)::iterator>;
	//using rmisPos_Ev = pair<decltype(vExist)::reverse_iterator, decltype(v)::reverse_iterator>;

	using namespace std::placeholders;
	
	//mismatch元素少的放前面
	if (vLen > vExistLen) {//增加, 动态元素多
		auto f = bind(MismatchFunc, _2, _1);
		//查不匹配位置，在vExist中构造增加的元素
		misPos_Ev misPos = mismatch(vExist.begin(), vExist.end(), v.begin(), f);
		vExist.erase(misPos.first, vExist.end());
		for (auto it = misPos.second; it != v.end(); ++it) {
			//构造空的按钮
			vExist.emplace_back(make_tuple(*it, nullptr));
		}
		
		//哪个位置开始不匹配
		//size_t misPos = distance(v.begin(), pEv.second);
		//反向查找一次不匹配
		//rmisPos_Ev prEv = mismatch(vExist.rbegin(), vExist.rend(), v.rbegin(), f);
		////反向哪个位置开始不匹配
		//size_t rmisPos = distance(prEv.second, v.rend()) - 1;/*vLen - distance(v.rbegin(), prEv.second) - 1;*/
		//有一种v=112, vExist=12的情况：反向位置<正向  1234 和 12334都是
		//if (rmisPos < misPos) {
		//	rmisPos = misPos +
		//		distance(vExist.begin(), pEv.first)
		//		- distance(prEv.first, vExist.rend()) - 1 ;
		//}
		/* rmisPos - misPos 是要插入元素的个数 */
		//auto tmpIt = pEv.first;//正向不匹配位置
		//while (misPos <= rmisPos) {//遍历所有要插入的元素
		//	tmpIt = vExist.insert(tmpIt, make_tuple(*(v.begin() + rmisPos++),nullptr));
		//	++tmpIt; //vector在前面插入,这样就在后面插入了
		//}
	}
	else if(vLen < vExistLen){//删,动态元素少
		misPos_vE misPos = mismatch(v.begin(), v.end(), vExist.begin(), MismatchFunc);
		vExist.erase(misPos.second, vExist.end());
		for (auto it = misPos.first; it != v.end(); ++it) {
			vExist.emplace_back(make_tuple(*it, nullptr));
		}
		//misPos_vE pvE = mismatch(v.begin(), v.end(), vExist.begin(), MismatchFunc);//正向查找一次不匹配
		//size_t pvEpos = distance(vExist.begin(), pvE.second);//第几个元素开始为删除的元素，从多的取
		//rmisPos_vE prvE = mismatch(v.rbegin(), v.rend(), vExist.rbegin(), MismatchFunc);//反向查找一次不匹配
		//size_t prvEpos = vExistLen - distance(vExist.rbegin(), prvE.second) - 1;

		//auto eIt1 = pvE.second;
		//auto eIt2 = eIt1 + prvEpos - pvEpos;
		//vExist.erase(eIt1, eIt2);

	}
	else {//改
		//misPair_vm p = mismatch(v.begin(), v.end(), m.begin(), MismatchFunc);
		//FmtType tv = *p.first;
		//FmtType tm = p.second->first;
		//cout << "FmtType add:" << tv << "\tdelete:" << tm << endl;
	}
	


    return 0;
}

