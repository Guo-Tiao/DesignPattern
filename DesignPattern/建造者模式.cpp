#include "建造者模式.h"
#include <string>
using namespace std;

#pragma region 产品House
//产品类House
class House
{
public:
	House() {}
	void SetFloor(string iFloor) {
		this->floor = iFloor;
	}
	void SetWall(string iWall) {
		this->wall = iWall;
	}
	void SetRoof(string iRoof) {
		this->roof = iRoof;
	}
	//打印House信息
	void PrintfHouseInfo() {
		printf("Floor:%s\t\n", this->floor.c_str());
		printf("Wall:%s\t\n", this->wall.c_str());
		printf("Roof:%s\t\n", this->roof.c_str());
	}
private:
	string floor;
	string wall;
	string roof;
};
#pragma endregion

#pragma region 建造者
//抽象建造者AbstractBuilder
class AbstractBuilder
{
public:
	AbstractBuilder() {
		house = new House();
	}
	//抽象方法：
	virtual void BuildFloor() = 0;
	virtual void BuildWall() = 0;
	virtual void BuildRoof() = 0;
	virtual House* GetHouse() = 0;

	House* house;
};

//具体建造者ConcreteBuilderA
class ConcreteBuilderA :public AbstractBuilder
{
public:
	ConcreteBuilderA() {
		printf("ConcreteBuilderA\n");
	}
	//具体实现方法
	void BuildFloor() {
		this->house->SetFloor("Floor_A");
	}
	void BuildWall() {
		this->house->SetWall("Wall_A");
	}
	void BuildRoof() {
		this->house->SetRoof("Roof_A");
	}
	House* GetHouse() {
		return this->house;
	}
};

//具体建造者ConcreteBuilderB
class ConcreteBuilderB :public AbstractBuilder
{
public:
	ConcreteBuilderB() {
		printf("ConcreteBuilderB\n");
	}
	//具体实现方法
	void BuildFloor() {
		this->house->SetFloor("Floor_B");
	}
	void BuildWall() {
		this->house->SetWall("Wall_B");
	}
	void BuildRoof() {
		this->house->SetRoof("Roof_B");
	}
	House* GetHouse() {
		return this->house;
	}
};
#pragma endregion

#pragma region 指挥者
//指挥者Director
class Director
{
public:
	Director() {}
	//具体实现方法
	void SetBuilder(AbstractBuilder* iBuilder) {
		this->builder = iBuilder;
	}
	//封装组装流程，返回建造结果
	House* Construct() {
		builder->BuildFloor();
		builder->BuildWall();
		builder->BuildRoof();
		return builder->GetHouse();
	}
private:
	AbstractBuilder* builder;
};
#pragma endregion
/*
House-房子类

AbstractBuilder-抽象建造者
|
建造者A-建造者B

Director-指挥者

new Director
Director→Set不同建造者
Director→进行构建

*/
void 建造者模式::运行()
{
	std::cout << "********************建造者模式********************\n" << std::endl;

	//抽象建造者
	AbstractBuilder* builder;
	//指挥者
	Director* director = new Director();
	//产品：House
	House* house;

	//指定具体建造者A
	builder = new ConcreteBuilderA();
	director->SetBuilder(builder);//设置建造者
	house = director->Construct();//指挥者使用建造者进行建造
	house->PrintfHouseInfo();
	printf("\r\n");
	//指定具体建造者B
	builder = new ConcreteBuilderB();
	director->SetBuilder(builder);
	house = director->Construct();
	house->PrintfHouseInfo();

	std::cout << "\n************************************************" << std::endl;
}
