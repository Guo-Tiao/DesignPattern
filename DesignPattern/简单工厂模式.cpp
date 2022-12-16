#include "简单工厂模式.h"
#include <string>
using namespace std;

#pragma region 产品类
//抽象产品类AbstractProduct
class AbstractProduct
{
public:
	AbstractProduct() {

	}
	//抽象方法：
	void PrintName() {};
	void Play() {};
};
//具体产品类A
class ProductA :public AbstractProduct
{
public:
	ProductA() {
		PrintName();
		Play();
	}
	//具体实现方法
	void PrintName() {
		printf("Get ProductA\n");
	}
	void Play() {
		printf("Play ProductA\n");
	}
};

//具体产品类B
class ProductB :public AbstractProduct
{
public:
	ProductB() {
		PrintName();
		Play();
	}
	//具体实现方法
	void PrintName() {
		printf("Get ProductB\n");
	}
	void Play() {
		printf("Play ProductB\n");
	}
};

//具体产品类C
class ProductC :public AbstractProduct
{
public:
	ProductC() {
		PrintName();
		Play();
	}
	//具体实现方法
	void PrintName() {
		printf("Get ProductC\n");
	}
	void Play() {
		printf("Play ProductC\n");
	}
};
#pragma endregion


#pragma region 工厂类
class Factory
{
public:
	AbstractProduct* getProduct(string productName)
	{
		AbstractProduct* pro = NULL;
		if (productName == "ProductA") {
			pro = new ProductA();
		}
		else if (productName == "ProductB") {
			pro = new ProductB();
		}
		else if (productName == "ProductC") {
			pro = new ProductC();
		}
		return pro;
	}
};
#pragma endregion

void 简单工厂模式::运行()
{
	std::cout << "********************简单工厂模式********************\n" << std::endl;

	//定义工厂类对象
	Factory* fac = new Factory();
	AbstractProduct* product = NULL;

	product = fac->getProduct("ProductA");

	product = fac->getProduct("ProductB");

	product = fac->getProduct("ProductC");

	std::cout << "\n************************************************" << std::endl;
}
