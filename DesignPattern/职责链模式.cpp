#include "职责链模式.h"
#include <string>
using namespace std;

#pragma region 请求
// 请求类
class SwitchState
{
public:
	SwitchState() {}
	SwitchState(int iId, string iName, double iAuthority) {
		id = iId;
		name = iName;
		authority = iAuthority;
	}
	double GetAuthority() {
		return this->authority;
	}
	void Print() {
		printf("\nID:\t%d\n", id);
		printf("Name:\t%s\n", name.c_str());
		printf("Authority:\t%f\n", authority);
	}
private:
	int id;
	string name;
	double authority;//请求权限
};
#pragma endregion

#pragma region 处理者
// 抽象处理者
class Approver
{
public:
	Approver() {}
	Approver(string iName) {
		SetName(iName);
	}
	// 添加上级
	void SetSuperior(Approver* iSuperior) {
		this->superior = iSuperior;
	}
	// 处理请求
	virtual void HandleRequest(SwitchState*) = 0;

	string GetName() {
		return name;
	}
	void SetName(string iName) {
		name = iName;
	}
protected:
	Approver* superior;
private:
	string name;
};

// 具体处理者：Level_1(权限1)
class Level_1 :public Approver
{
public:
	Level_1() {}
	Level_1(string iName) {
		SetName(iName);
	}
	// 处理请求
	void HandleRequest(SwitchState* req) {
		if (req->GetAuthority() < 1) {
			printf("Level_1 %s 处理了该请求，请求信息:", this->GetName().c_str());
			req->Print();
		}
		else {
			printf("Level_1无权处理，转交上级……\n");
			this->superior->HandleRequest(req);
		}
	}
};

// 具体处理者：Level_2(权限2)
class Level_2 :public Approver
{
public:
	Level_2() {}
	Level_2(string iName) {
		SetName(iName);
	}
	// 处理请求
	void HandleRequest(SwitchState* req) {
		if (req->GetAuthority() >= 1 && req->GetAuthority() < 2) {
			printf("Level_2 %s 处理了该请求，请求信息:", this->GetName().c_str());
			req->Print();
		}
		else {
			printf("Level_2无权处理，转交上级……\n");
			this->superior->HandleRequest(req);
		}
	}
};
// 具体处理者：Admin(权限<=3)
class Admin :public Approver
{
public:
	Admin() {}
	Admin(string iName) {
		SetName(iName);
	}
	// 处理请求
	void HandleRequest(SwitchState* req) {
		if (req->GetAuthority() < 3) {
			printf("Admin %s 处理了该请求，请求信息:", this->GetName().c_str());
			req->Print();
		}
		else {
			printf("Admin无权处理，转交上级……\n");
			this->superior->HandleRequest(req);
		}
	}
};

// 具体处理者：SuperAdmin(所有权限)
class SuperAdmin :public Approver
{
public:
	SuperAdmin() {}
	SuperAdmin(string iName) {
		SetName(iName);
	}
	// 处理请求
	void HandleRequest(SwitchState* req) 
	{
		printf("SuperAdmin %s 处理了该请求，请求信息:", this->GetName().c_str());
		req->Print();
	}
};
#pragma endregion

void 职责链模式::运行()
{
	std::cout << "********************职责链模式********************" << std::endl;
	// 请求处理者：用户，组长，管理员，超管
	Approver* user, * teamLeader, * admin, * superAdmin;
	user = new Level_1("用户");
	teamLeader = new Level_2("组长");
	admin = new Admin("管理员");
	superAdmin = new SuperAdmin("超管");

	//设置上级
	user->SetSuperior(teamLeader);
	teamLeader->SetSuperior(admin);
	admin->SetSuperior(superAdmin);

	// 创建请求
	SwitchState* req1 = new SwitchState(1, "请求_0.5", 0.5);
	SwitchState* req2 = new SwitchState(2, "请求_1.7", 1.7);
	SwitchState* req3 = new SwitchState(3, "请求_2.6", 2.6);
	SwitchState* req4 = new SwitchState(4, "请求_3.3", 3.3);

	// 全部先交给用户处理
	user->HandleRequest(req1); printf("\n");
	user->HandleRequest(req2); printf("\n");
	user->HandleRequest(req3); printf("\n");
	user->HandleRequest(req4);

	std::cout << "************************************************" << std::endl;
}
