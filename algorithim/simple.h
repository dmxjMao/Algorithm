#pragma once


//求两个数的最大公约数（流程图）
int  CommonDivisor(int a, int b);

//两数的最小公倍数
int CommonMultiple(int a, int b);

/* 流程图 试探法+回溯
有一个集合，集合中有 n 个元素，每个集合元素都是正整数，它们存放在一维数组A中。对给定的整数 total（假定集合中每个元素的值均小于 total），求出所有满足下列条件的子集：子集中各元素之和等于 total。
*/
int Subset_SumEqualToal(int a[], int n, int total);