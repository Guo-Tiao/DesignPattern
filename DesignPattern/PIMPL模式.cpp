#include "PIMPL模式.h"
#include "CPLMPL.h"

void PIMPL模式::运行()
{
	std::cout << "********************PIMPL模式********************" << std::endl;

	CPLMPL plmpl("PIMPL模式", 666.666);
	plmpl.Display();

	std::cout << "**************************************************" << std::endl;
}
