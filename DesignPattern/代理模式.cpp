#include "代理模式.h"
#include <string>
#include <windows.h>

using namespace std;

// 抽象主题角色
class Subject
{
public:
	Subject() {}
	virtual void Method() = 0;
};
// 真实主题角色
class RealSubject :public Subject
{
public:
	RealSubject() {}
	void Method() {
		printf("调用业务方法\n");
		Sleep(1000);
	}
};
// Log类
class Log
{
public:
	Log() {}
	string GetTime() 
	{
		time_t t = time(NULL);
		char ch[64] = { 0 };
		//年-月-日 时:分:秒
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
		return ch;
	}
};

// 代理类
class Proxy :public Subject
{
public:
	Proxy() 
	{
		realSubject = new RealSubject();
		log = new Log();
	}
	void PreCallMethod() {
		printf("方法method()开始调用，调用时间为%s\n", log->GetTime().c_str());
	}
	void Method() {
		PreCallMethod();
		realSubject->Method();
		PostCallMethod();
	}
	void PostCallMethod() {
		printf("方法method()调用调用成功!调用完成为%s\n", log->GetTime().c_str());
	}
private:
	RealSubject* realSubject;
	Log* log;
};

/*
Subject抽象主题
|
RealSubject真实主题----Proxy代理类

Proxy.Method()→Proxy.RealSubject.Method()

*/
void 代理模式::运行()
{
	std::cout << "********************代理模式********************" << std::endl;
	Subject* subject;
	subject = new Proxy();
	subject->Method();

	printf("\n");
	std::cout << "**************************************************" << std::endl;
}
