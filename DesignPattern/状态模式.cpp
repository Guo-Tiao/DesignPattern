#include "状态模式.h"


#pragma region 状态抽象类
class Context;
class State { // 抽象状态类，定义一个接口以封装与Context的一个特定状态相关的行为
public:
	virtual void Handle(Context* c) = 0;
	virtual void GetName() = 0;
	virtual ~State() {}
};
#pragma endregion 

#pragma region 上下文类
class Context { // 维护一个ConcreteState子类的实例，这个实例定义为当前状态
private:
	State* state;
public:
	Context(State* s) { state = s; }
	void SwitchState() { // // 对请求做处理，并设置下一状态
		if (state == NULL) return;
		state->GetName();
		state->Handle(this);
	}
	void SetState(State* s) { state = s; }
	virtual ~Context() {
		if (state != NULL) {
			delete state;
			state = NULL;
		}
	}
};
#pragma endregion 

#pragma region 具体状态类
// 具体状态类，每一个字类实现与Context的一个状态相关行为
class ConcreteStateA : public State {
public:
	void Handle(Context* c);
	void GetName();
};

class ConcreteStateB : public State {
public:
	void Handle(Context* c);
	void GetName();
};

class ConcreteStateC : public State {
public:
	void Handle(Context* c);
	void GetName();
};

void ConcreteStateA::Handle(Context* c) {
	printf("当前:ConcreteStateA→切换为:ConcreteStateB\n");
	c->SetState(new ConcreteStateB());
}

void ConcreteStateA::GetName()
{
	printf("当前状态为:ConcreteStateA\n");
}

void ConcreteStateB::Handle(Context* c) {
	printf("当前:ConcreteStateB→切换为:ConcreteStateC\n");
	c->SetState(new ConcreteStateC());
}

void ConcreteStateB::GetName()
{
	printf("当前状态为:ConcreteStateB\n");
}

void ConcreteStateC::Handle(Context* c) {
	printf("当前:ConcreteStateC→切换为:ConcreteStateA\n");
	c->SetState(new ConcreteStateA());
}

void ConcreteStateC::GetName()
{
	printf("当前状态为:ConcreteStateC\n");
}

#pragma endregion 

void 状态模式::运行()
{
	std::cout << "********************状态模式********************" << std::endl;

	State* s = new ConcreteStateA();
	Context* c = new Context(s);
	c->SwitchState();  // ConcreteStateA 切换状态
	c->SwitchState();  // ConcreteStateB
	c->SwitchState();  // ConcreteStateC
	delete s;
	delete c;

	std::cout << "************************************************" << std::endl;
}
