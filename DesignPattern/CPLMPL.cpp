#include "CPLMPL.h"
class CImpl
{
public:
	CImpl() {}
	CImpl(std::string name,double val);
	~CImpl();
	void Display();
	void SetVal(double);
	double GetVal();
private:
	std::string _name;
	double _val;
};

CImpl::CImpl(std::string name, double val) :_name(name), _val(val)
{

}

CImpl::~CImpl()
{

}

void CImpl::Display()
{
	std::cout << "CImpl name:" << _name << std::endl;
	std::cout << "CImpl val:" << _val << std::endl;
}

void CImpl::SetVal(double val)
{
	_val = val;
}

double CImpl::GetVal()
{
	return _val;
}

CPLMPL::CPLMPL() :pCImpl(std::make_unique<CImpl>())
{

}

CPLMPL::CPLMPL(std::string name, double val) : pCImpl{ std::make_unique<CImpl>(name,val) }
{

}

CPLMPL::~CPLMPL() = default;

CPLMPL& CPLMPL::operator=(CPLMPL&&) = default;

void CPLMPL::Display()
{
	pCImpl->Display();
}
