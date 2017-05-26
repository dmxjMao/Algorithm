// algorithim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "simple.h"
#include "bowling.h"//������
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

	//��ɾ��
	vector<FmtType> v = { INTEGER,ANYCHAR };

	size_t vLen = v.size(), vExistLen = vExist.size();

	/*Ԫ�ز�ƥ���λ�õ���������end(), E �����Ѵ��ڵ�Ԫ�أ�v����̬�仯��Ԫ��*/
	using misPos_vE = pair<decltype(v)::iterator, decltype(vExist)::iterator>;
	//using rmisPos_vE = pair<decltype(v)::reverse_iterator, decltype(vExist)::reverse_iterator>;
	using misPos_Ev = pair<decltype(vExist)::iterator, decltype(v)::iterator>;
	//using rmisPos_Ev = pair<decltype(vExist)::reverse_iterator, decltype(v)::reverse_iterator>;

	using namespace std::placeholders;
	
	//mismatchԪ���ٵķ�ǰ��
	if (vLen > vExistLen) {//����, ��̬Ԫ�ض�
		auto f = bind(MismatchFunc, _2, _1);
		//�鲻ƥ��λ�ã���vExist�й������ӵ�Ԫ��
		misPos_Ev misPos = mismatch(vExist.begin(), vExist.end(), v.begin(), f);
		vExist.erase(misPos.first, vExist.end());
		for (auto it = misPos.second; it != v.end(); ++it) {
			//����յİ�ť
			vExist.emplace_back(make_tuple(*it, nullptr));
		}
		
		//�ĸ�λ�ÿ�ʼ��ƥ��
		//size_t misPos = distance(v.begin(), pEv.second);
		//�������һ�β�ƥ��
		//rmisPos_Ev prEv = mismatch(vExist.rbegin(), vExist.rend(), v.rbegin(), f);
		////�����ĸ�λ�ÿ�ʼ��ƥ��
		//size_t rmisPos = distance(prEv.second, v.rend()) - 1;/*vLen - distance(v.rbegin(), prEv.second) - 1;*/
		//��һ��v=112, vExist=12�����������λ��<����  1234 �� 12334����
		//if (rmisPos < misPos) {
		//	rmisPos = misPos +
		//		distance(vExist.begin(), pEv.first)
		//		- distance(prEv.first, vExist.rend()) - 1 ;
		//}
		/* rmisPos - misPos ��Ҫ����Ԫ�صĸ��� */
		//auto tmpIt = pEv.first;//����ƥ��λ��
		//while (misPos <= rmisPos) {//��������Ҫ�����Ԫ��
		//	tmpIt = vExist.insert(tmpIt, make_tuple(*(v.begin() + rmisPos++),nullptr));
		//	++tmpIt; //vector��ǰ�����,�������ں��������
		//}
	}
	else if(vLen < vExistLen){//ɾ,��̬Ԫ����
		misPos_vE misPos = mismatch(v.begin(), v.end(), vExist.begin(), MismatchFunc);
		vExist.erase(misPos.second, vExist.end());
		for (auto it = misPos.first; it != v.end(); ++it) {
			vExist.emplace_back(make_tuple(*it, nullptr));
		}
		//misPos_vE pvE = mismatch(v.begin(), v.end(), vExist.begin(), MismatchFunc);//�������һ�β�ƥ��
		//size_t pvEpos = distance(vExist.begin(), pvE.second);//�ڼ���Ԫ�ؿ�ʼΪɾ����Ԫ�أ��Ӷ��ȡ
		//rmisPos_vE prvE = mismatch(v.rbegin(), v.rend(), vExist.rbegin(), MismatchFunc);//�������һ�β�ƥ��
		//size_t prvEpos = vExistLen - distance(vExist.rbegin(), prvE.second) - 1;

		//auto eIt1 = pvE.second;
		//auto eIt2 = eIt1 + prvEpos - pvEpos;
		//vExist.erase(eIt1, eIt2);

	}
	else {//��
		//misPair_vm p = mismatch(v.begin(), v.end(), m.begin(), MismatchFunc);
		//FmtType tv = *p.first;
		//FmtType tm = p.second->first;
		//cout << "FmtType add:" << tv << "\tdelete:" << tm << endl;
	}
	


    return 0;
}

