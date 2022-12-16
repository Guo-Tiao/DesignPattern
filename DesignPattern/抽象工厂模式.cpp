#include "抽象工厂模式.h"

#pragma region Int抽象产品

//抽象产品类AbstractInt
class AbstractInt
{
public:
	AbstractInt() {}
	//抽象方法：
	virtual void Play() = 0;
	virtual ~AbstractInt() {}
};
//具体产品类Int_A
class Int_A :public AbstractInt
{
public:
	Int_A() {
		Play();
	}
	//具体实现方法
	void Play() {
		printf("Play Int_A\n\n");
	}
};

//具体产品类Int_B
class Int_B :public AbstractInt
{
public:
	Int_B() {
		Play();
	}
	//具体实现方法
	void Play() {
		printf("Play Int_B\n\n");
	}
};
#pragma endregion


#pragma region Double抽象产品
//抽象产品类AbstractDouble
class AbstractDouble
{
public:
	AbstractDouble() {}
	//抽象方法：
	virtual void Exec() = 0;
	virtual ~AbstractDouble() {}
};
//具体产品类Double_A
class Double_A :public AbstractDouble
{
public:
	Double_A() {
		Exec();
	}
	//具体实现方法
	void Exec() {
		printf("Exec Double_A\n\n");
	}
};

//具体产品类Double_B
class Double_B :public AbstractDouble
{
public:
	Double_B() {
		Exec();
	}
	//具体实现方法
	void Exec() {
		printf("Exec Double_B\n\n");
	}
};

#pragma endregion

#pragma region 抽象工厂
//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractInt* GetInt() = 0;
	virtual AbstractDouble* GetDouble() = 0;
	virtual ~AbstractFactory() {}
};
//具体工厂类Factory_A
class Factory_A :public AbstractFactory
{
public:
	Factory_A() {
		printf("Factory_A\n\n");
	}
	AbstractInt* GetInt() {
		printf("Get IntA\n");
		return new Int_A();
	}
	AbstractDouble* GetDouble() {
		printf("Get DoubleA\n");
		return new Double_A();
	}
};

//具体工厂类Factory_B
class Factory_B :public AbstractFactory
{
public:
	Factory_B() {
		printf("Factory_B\n\n");
	}
	AbstractInt* GetInt() {
		printf("Get IntB\n");
		return new Int_B();
	}
	AbstractDouble* GetDouble() {
		printf("Get DoubleB\n");
		return new Double_B();
	}
};
#pragma endregion
/*
#抽象产品Int
|
产品IntA-产品IntB

#抽象产品Double
|
产品DoubleA-产品DoubleB


#抽象工厂
|
工厂A-工厂B

#使用
new 工厂A
工厂A→(生产)→产品IntA
工厂A→(生产)→产品DoubleA

new 工厂B
工厂B→(生产)→产品IntB
工厂B→(生产)→产品DoubleB

 */
void 抽象工厂模式::运行()
{
	std::cout << "********************抽象工厂模式********************\n" << std::endl;

	//定义工厂类对象和产品类对象
	AbstractFactory* fac = nullptr;
	AbstractInt* _Int = nullptr;
	AbstractDouble* _Double = nullptr;

	//生成一个A类型的工厂,专门生产A类产品
	fac = new Factory_A();
	_Int = fac->GetInt();//生成Int类型的A产品
	_Double = fac->GetDouble();//生成Double类型的A产品
	delete _Int;
	_Int = nullptr;
	delete _Double;
	_Double = nullptr;
	delete fac;
	fac = nullptr;

	//生成一个B类型的工厂,专门生产B类产品
	fac = new Factory_B();
	_Int = fac->GetInt();//生成Int类型的B产品
	_Double = fac->GetDouble();//生成Double类型的B产品
	delete _Int;
	_Int = nullptr;
	delete _Double;
	_Double = nullptr;
	delete fac;
	fac = nullptr;

	std::cout << "\n************************************************" << std::endl;
}
