#include "stdafx.h"
#include "bowling.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>

using std::cout;
using std::endl;
using std::cin;

const int ROUND_NUM = 10;
const int MAX_SCORE = 10;
CBowlingRound* arrRound[ROUND_NUM];


int bowling()
{
	//��ʼ��
	for (int i = 0; i < ROUND_NUM + 1; ++i) {
		arrRound[i] = new CBowlingRound(i);
	}

	int round = 0/*�ڼ���*/;
	int total = 0/*�ܷ�*/;

	cout << "start bowling..." << endl;
	//��ʼ��Ϸ
	while (round <= ROUND_NUM) {
		if (ROUND_NUM == round) {
			//��ʮ����������
			CBowlingRound* br = arrRound[round - 1];
			int b3 = 0;
			if (CBowlingRound::STRIKE == br->status) {
				b3 = randHit(MAX_SCORE);
				if (MAX_SCORE == b3) {
					br->score += MAX_SCORE;
					b3 = randHit(MAX_SCORE);
					br->score += b3;
				}
				else {
					b3 = randHit(MAX_SCORE - b3);
					br->score += b3;
				}
			}
			else if(CBowlingRound::SPARE == br->status){
				b3 = randHit(MAX_SCORE);
				br->score += b3;
			}
			else {
				b3 = randHit(MAX_SCORE - br->score);
				br->score += b3;
			}
			++round;
		}
		else {//���ǵ�ʮ��
			CBowlingRound* br = arrRound[round];
			int& b1 = br->ball[0], &b2 = br->ball[1], &b3 = br->ball[3];

			b1 = randHit(ROUND_NUM);//�������һ������
			cout << "round :" << round + 1 << ",first ball :" << b1 << endl;
			if (MAX_SCORE == b1) {
				cout << "strike!" << endl;
				br->status = CBowlingRound::STRIKE;
			}
			else {
				cout << "not good, sweep the rest!" << endl;
				b2 = randHit(MAX_SCORE - b1);
				cout << "round :" << round + 1 << ",second ball :" << b2 << endl;
				if (MAX_SCORE == b1 + b2) {
					br->status = CBowlingRound::SPARE;
				}
			}
			//ͳ����ַ���
			br->score = b1 + b2 + b3;

			//�ı���һ�ַ���
			br->Notify();
			++round;
		}
		//����Ʒְ�
		display();
		getchar();
	}
	return 1;
}

void display()
{
	std::ostringstream oss;
	
	for (int i = 0; i < ROUND_NUM; ++i) {
		oss.str("");
		oss << "round_" << i + 1;
		cout << std::setw(10) << std::left << oss.str();
	}
	cout << endl;
	
	for (int i = 0; i < ROUND_NUM; ++i) {
		CBowlingRound* p = arrRound[i];
		const CBowlingRound::BOWLING_STATUS& s = p->status;
		const int score = p->score;
		if(CBowlingRound::STRIKE == s && 10 == score)
			cout << std::setw(10) << std::left << 'X';
		else if(CBowlingRound::SPARE == s && 10 == score)
			cout << std::setw(10) << std::left << '/';
		else
			cout << std::setw(10) << std::left<< arrRound[i]->score;
	}
	cout << endl;
}


void CBowlingRound::Notify()
{
	if (0 == idx) {
		//��һ�ֲ���֪ͨ
		return;
	}
	else {
		CBowlingRound* br = arrRound[idx - 1];
		if (STRIKE == br->status) {
			br->score += ball[0] + ball[1];
		}	
		if (SPARE == br->status) {
			br->score += ball[0];
		}
	}
}

int randHit(int m)
{
	//�����
	std::default_random_engine e;
	e.seed((unsigned)time(0));//����̫���ˣ�����getchar()

	std::uniform_int_distribution<unsigned> u(1, m);//1-m�ľ��ȷֲ�
	return(u(e));
}