#include "命令模式.h"
#include <vector>

// 抽象命令类 Command
class Command
{
public:
	Command() {}
	// 声明抽象接口：发送命令
	virtual void Exec() = 0;
private:
	Command* m_Command;
};
// 命令队列类
class CommandQueue
{
public:
	CommandQueue() {
	}
	void AddCommand(Command* cmd) {
		m_CommandQueue.push_back(cmd);
	}
	void ExecCmd() {
		for (int i = 0; i < m_CommandQueue.size(); i++)
		{
			m_CommandQueue[i]->Exec();
		}
	}
private:
	std::vector<Command*>m_CommandQueue;

};
// 调用者
class CmdUser
{
public:
	CmdUser() {}
	// 注入具体命令队列类对象
	void SetCommandQueue(CommandQueue* cmdQueue) {
		this->cmdQueue = cmdQueue;
	}
	// 发送命令
	void SendCmd() {
		printf("开始执行命令:\n");
		cmdQueue->ExecCmd();
	}
private:
	CommandQueue* cmdQueue;
};

//命令具体实现类
// 具体命令类 X_Command
class X_Command :public Command
{
public:
	X_Command() 
	{

	}
	// 实现execute()
	void Exec() {
		if (m_State) 
		{
			printf("执行X命令:True\n");
			m_State = false;
		}
		else 
		{
			printf("执行X命令:False\n");
			m_State = true;
		}
	}
private:
	bool m_State = false;
};

// 具体命令类 Y_Command
class Y_Command :public Command
{
public:
	Y_Command() 
	{
	}
	// 实现execute()
	void Exec() 
	{
		printf("执行Y命令:%d\n", m_nCount);
		m_nCount++;
		if (m_nCount > 3)
		{
			m_nCount = 0;
		}
	}
private:
	int m_nCount=0;
};


void 命令模式::运行()
{
	std::cout << "********************命令模式********************" << std::endl;
	CmdUser cmdUser;
	CommandQueue* cmdQueue = new CommandQueue;
	X_Command *xCmd=new X_Command;
	Y_Command *yCmd = new Y_Command;

	cmdQueue->AddCommand(xCmd);
	cmdQueue->AddCommand(yCmd);
	cmdQueue->AddCommand(yCmd);
	cmdQueue->AddCommand(yCmd);
	cmdQueue->AddCommand(xCmd);

	cmdUser.SetCommandQueue(cmdQueue);
	cmdUser.SendCmd();

	std::cout << "************************************************" << std::endl;
}
