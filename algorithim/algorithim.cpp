// algorithim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "simple.h"
#include "bowling.h"//������
#include <array>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <sstream>
#include <tuple>
#include <random>
#include <fstream>

#include <boost\variant.hpp>
//#include <afxwin.h>
//#include <atlconv.h>
#include <Windows.h>

using namespace std;

struct CFG {
	//int nSize;
	TCHAR* szName = nullptr;
	int ccName = 0;
	int nValue = 0;

	CFG() {}
	CFG(/*int sz,*/TCHAR* pName,int nLen,int nValue)
		:szName(pName), ccName(nLen),nValue(nValue){}
};
ostream& operator<<(ostream& wos, const CFG& cfg);
istream& operator>>(istream& wis, CFG& cfg);


int main()
{
	cout << "hello,world!" << endl;

	vector<CFG> vec = { 
		CFG(_T("a"), 1, 1),
		CFG(_T("ab"), 2, 2),
		CFG(_T("���˴�"), 3, 3)
	};

	ofstream ofs("���˴�", ios::binary);
	//TCHAR* p = _T("���,���磡");
	char* p = "mao";
	ofs << p;
	ofs.close();

	ifstream ifs("������", ios::binary);
	//int l = strlen(p);
	//char* p2 = new char[6];
	char p2[6] = { 0 };
	//p2[5] = 0;
	//ifs.read(p2,5);
	string line;
	getline(ifs, line);

	ifs.close();

	//ofstream ofs("struct_ptr2file", ios::binary);
	//if (ofs.fail())
	//	return -1;
	//const auto& cfg = vec[0];
	//ofs << cfg;
	//ofs.close();

	//ifstream ifs("struct_ptr2file", ios::binary);
	//if (ifs.fail())
	//	return -1;
	//CFG cfg2;
	//ifs >> cfg2;
	//ifs.close();


    return 0;
}


ostream& operator<<(ostream& os, const CFG& cfg)
{
	os << cfg.ccName << cfg.nValue;
	int charlen = 2 * cfg.ccName;
	char* p = new char[charlen + 1];
	wcstombs_s(nullptr, p, charlen, cfg.szName, charlen);
	os << p;
	return os;
}

istream& operator >> (istream& is, CFG& cfg)
{
	is >> cfg.ccName >> cfg.nValue;
	//TCHAR* p = new TCHAR[cfg.cbName]; //����\0
	//char* p = new char[2 * cfg.ccName + 1];
	//is >> p;
	//mbstowcs(cfg.szName,p,)
	return is;
}