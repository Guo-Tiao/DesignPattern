#include "外观模式.h"

//子系统：A
class SubSys_A
{
public:
	SubSys_A() {}
	void SelfCheckA() {
		printf("…………A自检……\n");
	}
};

//子系统：B
class SubSys_B
{
public:
	SubSys_B() {}
	void Exec() {
		printf("…………B执行……\n");
	}
};

//子系统：硬盘
class SubSys_C
{
public:
	SubSys_C() {}
	void Read() {
		printf("…………C读取……\n");
	}
};

//子系统：操作系统
class SubSys_D
{
public:
	SubSys_D() {}
	void Load() {
		printf("…………D加载……\n");
	}
};

//外观类
class Facade
{
public:
	Facade() {
		A = new SubSys_A();
		B = new SubSys_B();
		C = new SubSys_C();
		D = new SubSys_D();
	}
	void Run() {
		printf("正在启动……\n");
		A->SelfCheckA();
		B->Exec();
		C->Read();
		D->Load();
		printf("启动完成!\n");
	}
private:
	SubSys_A* A;
	SubSys_B* B;
	SubSys_C* C;
	SubSys_D* D;
};

void 外观模式::运行()
{
	std::cout << "********************外观模式********************" << std::endl;

	Facade* facade = new Facade();
	facade->Run();

	std::cout << "**************************************************" << std::endl;
}
