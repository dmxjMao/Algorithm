#pragma once

/*
迷宫：
这个迷宫和游戏将随着各种模式不同而略有区别。有时这个游戏将仅仅是找到一个迷宫的出口；在这种情况下，游戏者可能仅能见到该迷宫的局部。有时迷宫包括一些要解决的问题和要战胜的危险，并且这些游戏可能会提供已经被探索过的那部分迷宫地图。我们将忽略许多迷宫中的细节以及一个迷宫游戏中有一个还是多个游戏者。我们仅关注迷宫是怎样被创建的。我们将一个迷宫定义为一系列房间，一个房间知道它的邻居；可能的邻居要么是另一个房间，要么是一堵墙、或者是到另一个房间的一扇门。

我们忽略与创建无关的游戏元素，
Room、Door和Wall等组件，
enum Direction {North, South, East, West};房间方向
MapSite迷宫组件基类


创建型模式提供了多种不同方法从实例化它们的代码中除去对这些具体类的显式引用：
 如果CreateMaze调用虚函数而不是构造器来创建它需要的房间、墙壁和门，那么你可以创建一个MazeGame的子类并重定义这些虚函数，从而改变被例化的类。这一方法是Factory Method（3 . 3）模式的一个例子。
 如果传递一个对象给CreateMaze作参数来创建房间、墙壁和门，那么你可以传递不同的参数来改变房间、墙壁和门的类。这是Abstract Factory（3 . 1）模式的一个例子。
 如果传递一个对象给CreateMaze，这个对象可以在它所建造的迷宫中使用增加房间、墙壁和门的操作，来全面创建一个新的迷宫，那么你可以使用继承来改变迷宫的一些部分或该迷宫被建造的方式。这是Builder（3 . 2）模式的一个例子。
 如果CreateMaze由多种原型的房间、墙壁和门对象参数化，它拷贝并将这些对象增加到迷宫中，那么你可以用不同的对象替换这些原型对象以改变迷宫的构成。这是Prototype（3 . 4）模式的一个例子。
剩下的创建型模式，Singleton（3 . 5），可以保证每个游戏中仅有一个迷宫而且所有的游戏对象都可以迅速访问它—不需要求助于全局变量或函数。


*/



/*
应用：
不同的视感风格为诸如滚动条、窗口和按钮等用户界面“窗口组件”定义不同的外观和行为
在整个应用中实例化特定视感风格的窗口组件类将使得以后很难改变视感风格。（创建型模式提供了多种不同方法从实例化它们的代码中除去对这些具体类的显式引用）

*/

//
//enum Direction { North, South, East, West, Direction_Buff};
//
//class MapSite {
//public:
//	virtual void Enter() = 0;
//};
//
//
//class Room : public MapSite {
//public:
//	Room(int roomNo);
//
//	MapSite* GetSide(Direction) const;
//	void SetSide(Direction, MapSite*);
//
//	virtual void Enter();
//
//private:
//	MapSite* _sides[Direction_Buff];
//	int _roomNumber;
//};
//
//
//class Wall : public MapSite {
//public:
//	Wall();
//	virtual void Enter();
//};
//
//class Door : public MapSite {
//public:
//	Door(Room* = 0, Room* = 0);
//	virtual void Enter();
//	Room* OtherSideFrom(Room*);
//
//private:
//	Room* _room1;
//	Room* _room2;
//	bool _isOpen;
//};
//
////迷宫
//class Maze {
//public:
//	Maze();
//
//	void AddRoom(Room*);
//	Room* RoomNo(int)const;
//
//private:
//};
//
//
////迷宫游戏
//class MazeGame {
//public:
//	/*一个错误示例*/
//	Maze* CreateMaze();
//};