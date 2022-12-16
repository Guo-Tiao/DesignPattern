#include "观察者模式.h"
#include <map>
#include <vector>
#include <list>

using namespace std;

//监听者(接收者)抽象基类
class Listener
{
public:
	Listener(string name) :_name(name) {}
	//接收消息
	virtual void ReceiveMessage(int msgid) = 0;
protected:
	string _name;
};

//监听者实现类:X监听者
class X_Listener : public Listener
{
public:
	X_Listener(string name) :Listener(name) {}
	void ReceiveMessage(int msgid)
	{
		printf("X_Listener_%s:接受到[%d]消息\n", _name.c_str(), msgid);
	}
};
class Y_Listener : public Listener
{
public:
	Y_Listener(string name) :Listener(name) {}
	void ReceiveMessage(int msgid)
	{
		printf("Y_Listener_%s:接受到[%d]消息\n", _name.c_str(), msgid);
	}
};
class Z_Listener : public Listener
{
public:
	Z_Listener(string name) :Listener(name) {}
	void ReceiveMessage(int msgid)
	{
		printf("Z_Listener_%s:接受到[%d]消息\n", _name.c_str(), msgid);
	}
};

///观察者类 接收转发消息
class Observer
{
public:
	typedef map<int, list<Listener*>> _MAP;
	//注册监听者
	void RegisterListener(Listener* p, int msgid)
	{
		//lock
		// _obMap[msgid].push_back(p);
		_MAP::iterator it = _obMap.find(msgid);
		if (it == _obMap.end())
		{
			list<Listener*> mylist;
			mylist.push_front(p);
			_obMap.insert(make_pair(msgid, mylist));
		}
		else
		{
			it->second.push_front(p);
		}
		//unlock
	}
	//广播消息
	void BroadcastMessage(int msgid)
	{
		_MAP::iterator it = _obMap.find(msgid);
		if (it != _obMap.end())
		{
			list<Listener*>::iterator lit = it->second.begin();
			for (; lit != it->second.end(); ++lit)
			{
				(*lit)->ReceiveMessage(msgid);
			}
		}
	}
private:
	map<int, list<Listener*>> _obMap;
};


void 观察者模式::运行()
{
	std::cout << "********************观察者模式********************" << std::endl;

	Listener* p1 = new X_Listener("X1");
	Listener* p2 = new Y_Listener("Y1");
	Listener* p3 = new Z_Listener("Z1");

	Observer obser;
	obser.RegisterListener(p1, 0);
	obser.RegisterListener(p1, 1);
	obser.RegisterListener(p1, 2);

	obser.RegisterListener(p2, 0);
	obser.RegisterListener(p2, 1);

	obser.RegisterListener(p3, 1);
	obser.RegisterListener(p3, 2);

	int msgid = 0;
	while (true)
	{
		cout << "请输入msgid(范围:0-2,-1退出):";
		cin >> msgid;
		if (msgid == -1)
		{
			break;
		}
		obser.BroadcastMessage(msgid);
		
	}

	std::cout << "************************************************" << std::endl;
}
