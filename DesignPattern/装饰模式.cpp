#include "装饰模式.h"

//抽象构件
class Component
{
public:
	Component() {}
	virtual void Operation() = 0;
};


#pragma region 构件
//具体实现构件类
class ConcreteComponent :public Component
{
public:
	ConcreteComponent() {}
	void Operation() {
		printf("具体组件操作\n");
	}
};
#pragma endregion

#pragma region 装饰

//抽象装饰类
class Decorator :public Component
{
public:
	Decorator() {}
	Decorator(Component* c) {
		this->component = c;
	}
	void Operation() {
		this->component->Operation();
	}
	Component* GetComponent() {
		return this->component;
	}
	void SetComponent(Component* c) {
		this->component = c;
	}
private:
	Component* component;
};

//具体装饰类:DecoratorA
class DecoratorA :public Decorator
{
public:
	DecoratorA() {}
	DecoratorA(Component* c) {
		this->SetComponent(c);
	}
	void Operation() {
		this->GetComponent()->Operation();
		this->NewBehavior();
	}
	void NewBehavior() {
		printf("进行装饰行为A\n");
	}
};

//具体装饰类:DecoratorB
class DecoratorB :public Decorator
{
public:
	DecoratorB() {}
	DecoratorB(Component* c) {
		this->SetComponent(c);
	}
	void Operation() {
		this->GetComponent()->Operation();
		this->NewBehavior();
	}
	void NewBehavior() {
		printf("进行装饰行为B\n");
	}
};

//具体装饰类：DecoratorC
class DecoratorC :public Decorator
{
public:
	DecoratorC() {}
	DecoratorC(Component* c) {
		this->SetComponent(c);
	}
	void Operation() {
		this->GetComponent()->Operation();
		this->NewBehavior();
	}
	void NewBehavior() {
		printf("进行装饰行为C\n");
	}
};

#pragma endregion

/*
Component构件
|
|
ConcreteComponent具体构件----Decorator装饰器

Decorator装饰器
|
|
DecoratorA----DecoratorB----DecoratorC

cctCom=new ConcreteComponent
A=DecoratorA(cctCom)
B=DecoratorA(B)
C=DecoratorA(C)
C.opt()→B.opt()→A.opt()→cctCom.opt()
可以进行链式操作
*/
void 装饰模式::运行()
{
	std::cout << "********************装饰模式********************" << std::endl;

	printf("\n第一个具体组件\n");
	Component* cctCom1;
	Component* com_A1;
	cctCom1 = new ConcreteComponent();
	com_A1 = new DecoratorA(cctCom1);
	com_A1->Operation();

	printf("\n第二个具体组件\n");
	Component* cctCom2;
	Component* com_A2; 	Component* com_B2;
	cctCom2 = new ConcreteComponent();
	com_A2 = new DecoratorA(cctCom2);
	com_B2 = new DecoratorB(com_A2);
	com_B2->Operation();

	printf("\n第三个具体组件\n");
	Component* cctCom3;
	Component* com_A3; 	Component* com_B3; Component* com_C3;
	cctCom3 = new ConcreteComponent();
	com_A3 = new DecoratorA(cctCom3);
	com_B3 = new DecoratorB(com_A3);
	com_C3 = new DecoratorC(com_B3);
	com_C3->Operation();

	printf("\n");
	std::cout << "**************************************************" << std::endl;
}
