#include "访问者模式.h"
#include <string>
#include <list>

class Product;

#pragma region 访问者

// 抽象访问者
class Vistor {
public:
	void SetName(std::string name) {
		name_ = name;
	}

	virtual void Visit(Product* prd) = 0;
protected:
	std::string name_;
};


// 具体访问者类: Customer_1
class Vistor_1 : public Vistor {
public:
	void Visit(Product* prd);

};


// 具体访问者类： 收银员
class User_1 : public Vistor {
public:
	void Visit(Product* prd);
	
};

#pragma endregion

#pragma region 产品
// 抽象元素类
class Product {
public:
	virtual void Accept(Vistor* vistor) = 0;
	int m_type = 0;
};

// 具体产品类: A类
class Product_A : public Product {
public:
	Product_A()
	{
		m_type = 1;
	}
	void Accept(Vistor* vistor) override {
		vistor->Visit(this);
	}
};

// 具体产品类: B类
class Product_B : public Product {
public:
	Product_B()
	{
		m_type = 2;
	}
	void Accept(Vistor* vistor) override {
		vistor->Visit(this);
	}
};

// 产品/访问者容器
class ProductContainer {
public:
	void Accept(Vistor* vistor) {
		for (auto prd : prd_list_) {
			prd->Accept(vistor);
		}
	}

	void AddProduct(Product* product) {
		prd_list_.push_back(product);
	}

	void RemoveProduct(Product* product) {
		prd_list_.remove(product);
	}

private:
	std::list<Product*> prd_list_;
};
#pragma endregion


void Vistor_1::Visit(Product* prd)
{
	std::cout << "Vistor_1:" << name_ << "访问产品:" << prd->m_type << std::endl;
}

void User_1::Visit(Product* prd)
{
	std::cout << "User_1:" << name_ << "使用产品:" << prd->m_type << std::endl;
}


void 访问者模式::运行()
{
	std::cout << "********************访问者模式********************" << std::endl;


	Product_A prd_A;
	Product_B prd_B;
	ProductContainer prdContainer;

	prdContainer.AddProduct(&prd_B);
	prdContainer.AddProduct(&prd_A);

	Vistor_1 v1;
	v1.SetName("访问者1号");
	prdContainer.Accept(&v1);

	User_1 v2;
	v2.SetName("使用者1号");
	prdContainer.Accept(&v2);


	std::cout << "**************************************************" << std::endl;
}
