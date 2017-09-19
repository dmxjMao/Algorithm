#include "stdafx.h"
#include "factory.h"


//Maze* MazeGame::CreateMaze()
//{
	//创建一个迷宫
	//Maze* aMaze = new Maze;
	//Room* r1 = new Room(1);
	//Room* r2 = new Room(2);
	//Door* theDoor = new Door(r1, r2);

	//aMaze->AddRoom(r1);
	//aMaze->AddRoom(r2);

	//r1->SetSide(North, new Wall);
	//r1->SetSide(East, theDoor);
	//r1->SetSide(South, new Wall);
	//r1->SetSide(West, new Wall);

	////r2...
	//return aMaze;

	/*
	错误示例：这仅仅是创建一个两个房间的迷宫！典型的硬编码
	假设你想在一个包含施了魔法的迷宫的新游戏中重用一个已有的迷宫布局。施了魔法的迷宫游戏有新的构件，像DoorNeedingSpell，它是一扇仅随着一个咒语才能被锁上和打开的门；以及EnchantedRoom，一个可以有不寻常东西的房间，比如魔法钥匙或是咒语。你怎样才能较容易的改变CreateMaze以让它用这些新类型的对象创建迷宫呢？
	*/

//}