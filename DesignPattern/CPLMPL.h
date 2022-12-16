#pragma once
#include <iostream>

class CImpl;

class CPLMPL
{
public:
	CPLMPL();
	CPLMPL(std::string, double);
	~CPLMPL();
	/*私有成员为指针，禁止使用C++默认浅拷贝*/
	CPLMPL(const CPLMPL&) = delete;
	CPLMPL& operator=(const CPLMPL&) = delete;
	//移动拷贝构造
	CPLMPL(CPLMPL&&);
	CPLMPL& operator=(CPLMPL&&);

	void Display();

private:
	std::unique_ptr<CImpl> pCImpl;

};

