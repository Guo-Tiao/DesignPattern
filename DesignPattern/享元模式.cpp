#include "享元模式.h"
#include <map>
using namespace std;

//抽象享元类
class FlyWeight
{
public:
	FlyWeight() {};
	virtual ~FlyWeight() {};
	//声明具体享元类共有的方法
	virtual void Operation() = 0;

};

//具体享元类
class ConcreteFlyWeight : public FlyWeight
{
public:
	ConcreteFlyWeight() {};
	ConcreteFlyWeight(int nId) 
	{
		id = nId;
	}
	~ConcreteFlyWeight() {};
	//具体享元类实现了在抽象享元类中声明的方法
	void Operation()
	{
		printf("I'm ConcreteFlyWeight Id=%d!\n",id);
	}
private:
	int id=0;
};



 //享元工厂类
class FlyWeightFactory
{
public:
	FlyWeightFactory()
	{

	}
	~FlyWeightFactory()
	{
		for (auto it = m_flyWeights.begin(); it != m_flyWeights.end(); ++it)
			delete it->second;
	}
	//工厂方法，根据所传入的参数返回享元池中的享元对象
	FlyWeight* GetFlyWeight(int key)
	{
		for (auto it = m_flyWeights.begin(); it != m_flyWeights.end(); ++it)
		{
			if (it->first == key)
				return it->second;
		}

		FlyWeight* flyWeight = new ConcreteFlyWeight(key);
		m_flyWeights.insert(pair<int, FlyWeight*>(key, flyWeight));
		return flyWeight;

	}
	int GetFlyWeightCount()
	{
		return m_flyWeights.size();
	}
private: //定义享元池用于存储多个具体享元对象
	map<int,FlyWeight*> m_flyWeights;//很多时候为了增加效率，使用hash表之类的结构，这里简单的使用vector，

};



void 享元模式::运行()
{
	std::cout << "********************享元模式********************" << std::endl;
	FlyWeightFactory* factory = new FlyWeightFactory(); //实例化享元工厂类
	FlyWeight* flyWeight = factory->GetFlyWeight(0);//通过享元工厂对象的工厂方法返回享元对象
	flyWeight->Operation();//调用享元对象的方法

    flyWeight = factory->GetFlyWeight(1);//通过享元工厂对象的工厂方法返回享元对象
	flyWeight->Operation();//调用享元对象的方法

	std::cout << "************************************************" << std::endl;
}
