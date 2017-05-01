#pragma once

/*
保龄球的计分:  流程图
每一局总共有十格，每一格里面有两球，共有十支球瓶，我们要尽量在两球之内把球瓶全部击倒如果第一球就把全部的球瓶都击倒了，也就是“STRIKE”，画面出现“X”，就算完成一格了，所得分数就是10分再加下一格两球的倒瓶数，但是如果第一球没有全倒时，就要再打一球了，如果剩下的球瓶全都击倒，也就是“SPARE”，画面出现“/”，也算完成一格，所得分数为10分再加下一格第一球的倒瓶数，但是如果第二球也没有把球瓶全部击倒的话，那分数就是第一球加第二球倒的瓶数，再接着打下一格。依此类推直到第十格。但是第十格有三球，第十格时如果第一球或第二球将球瓶全部击倒时，可再加打第三球，如此就完成一局
*/

//游戏主逻辑
int bowling();

//输出积分板
void display();

//随机生成一球,m是上限
int randHit(int m);

//每一局
class CBowlingRound
{
public:
	int ball[3] = { 0 };//第1/2/3球的分数
	int score = 0;//总分
	int idx;//第几局

	enum BOWLING_STATUS {
		STRIKE,//1球十分
		SPARE,//2球十分
		NORMAL//没有十分
	};

	BOWLING_STATUS status = NORMAL;

	CBowlingRound(int i) : idx(i) {}

	void Notify();//通知上一局改变分数
};