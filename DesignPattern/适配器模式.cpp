#include "适配器模式.h"


//适配者类DxfParser
class DataParser
{
public:
	DataParser() {}
	void Parse() {
		printf("解析数据\n");
	}
};

//适配者类PathPlanner
class DataExecer
{
public:
	DataExecer() {}
	void Exec() {
		printf("执行数据\n");
	}
};

//目标抽象类
class Controller
{
public:
	Controller() {}
	virtual void PathPlanning() = 0;

};
//适配器类Adapter
class Adapter :public Controller
{
public:
	Adapter() {
		dataParser = new DataParser();
		dataExecer = new DataExecer();
	}
	void PathPlanning() {
		printf("开始运行数据\n");
		dataParser->Parse();
		dataExecer->Exec();
	}
private:
	DataParser* dataParser;
	DataExecer* dataExecer;
};
/*
Controller
|
Adapter

Adapter.Method()→DxfParser.Method1()&&PathPlanner.Method2()

*/

void 适配器模式::运行()
{
	std::cout << "********************适配器模式********************" << std::endl;
	Controller* controller = new Adapter();
	controller->PathPlanning();
	std::cout << "**************************************************" << std::endl;
}
