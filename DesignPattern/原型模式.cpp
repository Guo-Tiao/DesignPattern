#include "原型模式.h"

//WorkModel类
class WorkModel
{
public:
	char* modelName;
	void SetWorkModelName(char* iName) {
		this->modelName = iName;
	}
};

//抽象原型类PrototypeWork
class PrototypeWork
{
public:
	PrototypeWork() {}
	//进行克隆
	virtual PrototypeWork* Clone() = 0;

private:

};

//具体原型类ConcreteWork
class ConcreteWork :public PrototypeWork
{
public:
	ConcreteWork() {}
	ConcreteWork(char* iName, int iIdNum, char* modelName) {
		this->name = iName;
		this->idNum = iIdNum;
		this->workModel = new WorkModel();
		this->workModel->SetWorkModelName(modelName);
	}

	ConcreteWork* Clone() {
		ConcreteWork* work = new ConcreteWork();
		work->SetName(this->name);
		work->SetIdNum(this->idNum);
		work->workModel = this->workModel;
		return work;
	}

	void SetName(char* iName) {
		this->name = iName;
	}
	void SetIdNum(int iIdNum) {
		this->idNum = iIdNum;
	}
	void setModel(WorkModel* iWorkModel) {
		this->workModel = iWorkModel;
	}
	//打印work信息
	void PrintWorkInfo() {
		printf("name:%s\t\n", this->name);
		printf("idNum:%d\t\n", this->idNum);
		printf("modelName:%s\t\n", this->workModel->modelName);
	}
private:
	char* name;
	int idNum;
	WorkModel* workModel;
};

void 原型模式::运行()
{
	std::cout << "********************原型模式********************\n" << std::endl;
	
	{ //浅拷贝:不使用Clone接口
		std::cout << "*******浅拷贝*******\n" << std::endl;


		ConcreteWork* XWork = new ConcreteWork("X", 1001, "X_Model");
		printf("\nX的作业：\n");
		XWork->PrintWorkInfo();

		printf("\nY直接复制作业……\n");
		ConcreteWork* YWork = XWork;
		printf("\nY的作业：\n");
		YWork->PrintWorkInfo();

		//复制完需要修改改名字和ID
		printf("\nY复制完修改名字和ID，否则会出错……\n");
		YWork->SetName("Y");
		YWork->SetIdNum(1002);

		WorkModel* YModel = new WorkModel();
		YModel->SetWorkModelName("Y_Model");
		YWork->setModel(YModel);

		//检查下是否改对了
		printf("\nX的作业：\n");
		XWork->PrintWorkInfo();
		printf("\nY的作业：\n");
		YWork->PrintWorkInfo();


		std::cout << "*****************\n" << std::endl;
	}
	{ //深拷贝:使用克隆接口
		std::cout << "*******深拷贝*******\n" << std::endl;


		ConcreteWork* XWork = new ConcreteWork("X", 1001, "X_Model");
		printf("\nX的作业：\n");
		XWork->PrintWorkInfo();
		ConcreteWork* YWork = XWork->Clone();//#重点
		printf("\nY的作业：\n");
		YWork->PrintWorkInfo();
		//复制完需要修改改名字和ID
		printf("\nY复制完修改名字和ID，否则会出错……\n");
		YWork->SetName("Y");
		YWork->SetIdNum(1002);
		WorkModel* YModel = new WorkModel();
		YModel->SetWorkModelName("Y_Model");
		YWork->setModel(YModel);

		//检查下是否改对了
		printf("\nX的作业：\n");
		XWork->PrintWorkInfo();
		printf("\nY的作业：\n");
		YWork->PrintWorkInfo();


		std::cout << "*****************\n" << std::endl;
	}
	std::cout << "************************************************" << std::endl;
}
