#include "组合模式.h"
#include <string>
#include <vector>

using namespace std;

//抽象的树节点
class Node
{
public:
	Node() {}
	Node(string iName) {
		this->name = iName;
	}
	//增加一个子节点
	virtual void Add(Node*) = 0;
	//撤销一个子节点
	virtual void Remove(Node*) = 0;
	//获取子节点
	virtual Node* GetChildNode(int) = 0;
	//各节点操作
	virtual void Operation() = 0;
	string GetName() {
		return name;
	}
private:
	string name;
};


//分支节点:支持添加子节点
class Branch :public Node
{
public:
	Branch(string iName) {
		this->name = iName;
	}
	void Add(Node* sub) {
		m_listSubNode.push_back(sub);
	}
	void Remove(Node* sub) {
		for (int i = 0; i < m_listSubNode.size(); i++) {
			if (m_listSubNode[i]->GetName() == sub->GetName()) {
				m_listSubNode.erase(m_listSubNode.begin() + i);
				break;
			}
		}
	}
	Node* GetChildNode(int i) {
		return (Node*)m_listSubNode[i];
	}
	void Operation() {
		printf("---Branch:%s\n", this->name.c_str());
		for (int i = 0; i < m_listSubNode.size(); i++) {
			((Node*)m_listSubNode[i])->Operation();
		}
	}
private:
	string name;

	//构件列表
	vector<Node*> m_listSubNode;
};



//叶子节点:不支持添加子节点
class Leaf :public Node
{
public:
	Leaf(string iName) {
		this->name = iName;
	}
	Leaf() {}
	void Add(Node* sub) {
		printf("Leaf:Not support!\n");
	}
	void Remove(Node* sub) {
		printf("Leaf:Nupport!\n");
	}
	Node* GetChildNode(int i) {
		printf("Leaf:Not support!\n");
		return NULL;
	}
private:
	string name;
};


//叶子节点实现:X类型叶子节点
class X_Leaf :public Leaf
{
public:
	X_Leaf(string iName) {
		this->name = iName;
	}
	void Operation() {
		printf("-----X_Leaf:%s\n", name.c_str());
	}
private:
	string name;
};

//叶子节点实现:Y类型叶子节点
class Y_Leaf :public Leaf
{
public:
	Y_Leaf(string iName) {
		this->name = iName;
	}
	void Operation() {
		printf("-----Y_Leaf:%s\n", name.c_str());
	}
private:
	string name;
};

/*
* 实现以下树节点:
Root
|
B1-------B2-------B3
|                 |
X1-X2-Y1          Y2-Y3-X3-B4
						   |
						   X4-Y4
*/
void 组合模式::运行()
{
	std::cout << "********************组合模式********************" << std::endl;

	Node* Root, 
		*B1, *B2, * B3, *B4, 
		*X1, * X2, * X3, * X4,
		*Y1, * Y2, * Y3, * Y4;

	Root = new Branch("Root");

	B1 = new Branch("B1");
	B2 = new Branch("B2");
	B3 = new Branch("B3");
	B4 = new Branch("B4");

	X1 = new X_Leaf("X1");
	X2 = new X_Leaf("X2");
	X3 = new X_Leaf("X3");
	X4 = new X_Leaf("X4");

	Y1 = new Y_Leaf("Y1");
	Y2 = new Y_Leaf("Y2");
	Y3 = new Y_Leaf("Y3");
	Y4 = new Y_Leaf("Y4");

	Root->Add(B1);
	Root->Add(B2);
	Root->Add(B3);
	
	B1->Add(X1);
	B1->Add(X2);
	B1->Add(Y1);


	B3->Add(Y2);
	B3->Add(Y3);
	B3->Add(X3);
	B3->Add(B4);

	B4->Add(X4);
	B4->Add(Y4);

	Root->Operation();

	std::cout << "**************************************************" << std::endl;
}
