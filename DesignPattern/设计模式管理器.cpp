#include "设计模式管理器.h"
#include <iostream>

#include "单例模式.h"
#include "简单工厂模式.h"
#include "工厂方法模式.h"
#include "抽象工厂模式.h"
#include "原型模式.h"
#include "建造者模式.h"

#include "适配器模式.h"
#include "桥接器模式.h"
#include "组合模式.h"
#include "装饰模式.h"
#include "外观模式.h"
#include "享元模式.h"
#include "代理模式.h"

#include "职责链模式.h"
#include "命令模式.h"
#include "解释器模式.h"
#include "迭代器模式.h"
#include "中介者模式.h"
#include "备忘录模式.h"
#include "观察者模式.h"
#include "状态模式.h"
#include "策略模式.h"
#include "模板方法模式.h"
#include "访问者模式.h"

#include "PIMPL模式.h"

void 设计模式管理器::运行(枚举_设计模式 设计模式)
{
	设计模式基类* 模式=NULL;
	switch (设计模式)
	{

/*创建型*/
	case 单例:
	{
		模式 = new 单例模式;
	}
		break;
	case 简单工厂:
	{
		模式 = new 简单工厂模式;
	}
		break;
	case 工厂方法:
	{
		模式 = new 工厂方法模式;
	}
	break;
	case 抽象工厂:
	{
		模式 = new 抽象工厂模式;
	}
		break;
	case 原型:
	{
		模式 =new 原型模式;
	}
		break;
	case 建造者:
	{
		模式 =new 建造者模式;
	}
		break;
/*结构型*/
	case 适配器:
	{
		模式 = new 适配器模式;
	}
		break;
	case 桥接器:
	{
		模式 = new 桥接器模式;
	}
		break;
	case 组合:
	{
		模式 = new 组合模式;
	}
		break;
	case 装饰:
	{
		模式 = new 装饰模式;
	}
		break;
	case 外观:
	{
		模式 = new	外观模式;
	}
		break;
	case 享元:
	{
		模式 = new 享元模式;
	}
		break;
	case 代理:
	{
		模式 = new 代理模式;
	}
	break;
/*行为型*/
	case 职责链:
	{
		模式 = new 职责链模式;
	}
		break;
	case 命令:
	{
		模式 = new 命令模式;
	}
	break;
	case 解释器:
	{
		模式 = new 解释器模式;
	}
		break;
	case 迭代器:
	{
		模式 = new 迭代器模式;
	}
		break;
	case 中介者:
	{
		模式 = new 中介者模式;
	}
		break;
	case 备忘录:
	{
		模式 = new 备忘录模式;
	}
		break;
	case 观察者:
	{
		模式 = new 观察者模式;
	}
		break;
	case 状态:
	{
		模式 = new 状态模式;
	}
		break;
	case 策略:
	{
		模式 = new 策略模式;
	}
		break;
	case 模板方法:
	{
		模式 = new 模板方法模式;
	}
		break;
	case 访问者:
	{
		模式 = new 访问者模式;
	}
		break;
/*特殊型*/
	case PIMPL:
	{
		模式 = new PIMPL模式;
	}
		break;
	default:
	{
		return;
	}
		break;
	}
	if (模式)
	{
		模式->运行();
		delete 模式;
		模式 = NULL;
	}
}
