#include "工厂方法模式.h"

#pragma region 产品类
//抽象产品类AbstractProduct
class AbstractIntProduct
{
public:
	AbstractIntProduct() {

	}
	virtual ~AbstractIntProduct() {}
	//抽象方法：
	virtual void PrintName() = 0;
	virtual void Play()  = 0;
};
//具体产品类IntA
class IntA :public AbstractIntProduct
{
public:
	IntA() {
		PrintName();
		Play();
	}
	//具体实现方法
	void PrintName() {
		printf("Get IntA\n");
	}
	void Play() {
		printf("Play IntA\n\n");
	}
};

//具体产品类IntB
class IntB :public AbstractIntProduct
{
public:
	IntB() {
		PrintName();
		Play();
	}
	//具体实现方法
	void PrintName() {
		printf("Get IntB\n");
	}
	void Play() {
		printf("Play IntB\n\n");
	}
};

//具体产品类IntC
class IntC :public AbstractIntProduct
{
public:
	IntC() {
		PrintName();
		Play();
	}
	//具体实现方法
	void PrintName() {
		printf("Get IntC\n");
	}
	void Play() {
		printf("Play IntC\n\n");
	}
};
#pragma endregion

#pragma region 工厂类
//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractIntProduct* GetProduct() = 0;
	virtual ~AbstractFactory() {}
};

// 具体工厂类Int_A
class Factory_IntA :public AbstractFactory
{
public:
	Factory_IntA() {
		printf("Factory_IntA\n");
	}
	AbstractIntProduct* GetProduct() {
		return new IntA();
	}
};

//具体工厂类Int_B
class Factory_IntB :public AbstractFactory
{
public:
	Factory_IntB() {
		printf("Factory_IntB\n");
	}
	AbstractIntProduct* GetProduct() {
		return new IntB();
	}
};

//具体工厂类Int_C
class Factory_IntC :public AbstractFactory
{
public:
	Factory_IntC() {
		printf("Factory_IntC\n");
	}
	AbstractIntProduct* GetProduct() {
		return new IntC();
	}
};

#pragma endregion

/*

#抽象产品
|
产品A-产品B-产品C


#抽象工厂
|
工厂A-工厂B-工厂C

#使用
new 工厂A
工厂A→(生产)→产品A

*/
void 工厂方法模式::运行()
{
	std::cout << "********************工厂方法模式********************\n" << std::endl;

	//定义工厂类对象和产品类对象
	AbstractFactory* fac = nullptr;
	AbstractIntProduct* product = nullptr;

	fac = new Factory_IntA();
	product = fac->GetProduct();
	delete fac;
	fac = nullptr;
	delete product;
	product = nullptr;

	fac = new Factory_IntB();
	product = fac->GetProduct();
	delete fac;
	fac = nullptr;
	delete product;
	product = nullptr;

	fac = new Factory_IntC();
	product = fac->GetProduct();
	delete fac;
	fac = nullptr;
	delete product;
	product = nullptr;

	std::cout << "\n************************************************" << std::endl;
}
