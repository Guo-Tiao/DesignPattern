#include "单例模式.h"

#include <mutex>


#pragma region 加锁懒汉单例
namespace 加锁懒汉
{
class 加锁懒汉单例
{
public:
	// 获取单实例对象
	static 加锁懒汉单例*& GetInstance();

	//释放单实例，进程退出时调用
	static void DeleteInstance();

	// 打印实例地址
	void Print();

private:
	// 将其构造和析构成为私有的, 禁止外部构造和析构
	加锁懒汉单例();
	~加锁懒汉单例();

	// 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
	加锁懒汉单例(const 加锁懒汉单例& signal);
	const 加锁懒汉单例& operator=(const 加锁懒汉单例& signal);

private:
	// 唯一单实例对象指针
	static 加锁懒汉单例* m_SingleInstance;
	static std::mutex m_Mutex;
};

//初始化静态成员变量
加锁懒汉单例* 加锁懒汉单例::m_SingleInstance = nullptr;
std::mutex 加锁懒汉单例::m_Mutex;

// 注意：返回的是指针的引用
加锁懒汉单例*& 加锁懒汉单例::GetInstance()
{

	//  这里使用了两个 if 判断语句的技术称为双检锁；好处是，只有判断指针为空的时候才加锁，
	//  避免每次调用 GetInstance的方法都加锁，锁的开销毕竟还是有点大的。
	if (m_SingleInstance == nullptr)
	{
		std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
		if (m_SingleInstance == nullptr)
		{
			m_SingleInstance = new (std::nothrow) 加锁懒汉单例();
		}
	}

	return m_SingleInstance;
}

void 加锁懒汉单例::DeleteInstance()
{
	std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
	if (m_SingleInstance)
	{
		delete m_SingleInstance;
		m_SingleInstance = nullptr;
	}
}

void 加锁懒汉单例::Print()
{
	std::cout << "加锁懒汉单例_我的实例内存地址是:" << this << std::endl;
}

加锁懒汉单例::加锁懒汉单例()
{
	std::cout << "加锁懒汉单例_构造" << std::endl;
}

加锁懒汉单例::~加锁懒汉单例()
{
	std::cout << "加锁懒汉单例_析构" << std::endl;
}

}
#pragma endregion

#pragma region 静态局部变量懒汉单例
namespace 静态局部变量懒汉
{
	class 静态局部变量懒汉单例
	{

	public:
		// 获取单实例对象
		static 静态局部变量懒汉单例& GetInstance();

		// 打印实例地址
		void Print();

	private:
		// 禁止外部构造
		静态局部变量懒汉单例();

		// 禁止外部析构
		~静态局部变量懒汉单例();

		// 禁止外部拷贝构造
		静态局部变量懒汉单例(const 静态局部变量懒汉单例& signal) {};

		// 禁止外部赋值操作
		const 静态局部变量懒汉单例& operator=(const 静态局部变量懒汉单例& signal) {};
	};
	静态局部变量懒汉单例& 静态局部变量懒汉单例::GetInstance()
	{
		/**
		 * 局部静态特性的方式实现单实例。
		 * 静态局部变量只在当前函数内有效，其他函数无法访问。
		 * 静态局部变量只在第一次被调用的时候初始化，也存储在静态存储区，生命周期从第一次被初始化起至程序结束止。
		 */
		static 静态局部变量懒汉单例 signal;
		return signal;
	}

	void 静态局部变量懒汉单例::Print()
	{
		std::cout << "静态局部变量懒汉单例_我的实例内存地址是:" << this << std::endl;
	}

	静态局部变量懒汉单例::静态局部变量懒汉单例()
	{
		std::cout << "静态局部变量懒汉单例_构造" << std::endl;
	}

	静态局部变量懒汉单例::~静态局部变量懒汉单例()
	{
		std::cout << "静态局部变量懒汉单例_析构" << std::endl;
	}


}
#pragma endregion

#pragma region 饿汉单例
namespace 饿汉
{
	class 饿汉单例
	{
	public:
		// 获取单实例
		static 饿汉单例* GetInstance();

		// 释放单实例，进程退出时调用
		static void DeleteInstance();

		// 打印实例地址
		void Print();

	private:
		// 将其构造和析构成为私有的, 禁止外部构造和析构
		饿汉单例();
		~饿汉单例();

		// 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
		饿汉单例(const 饿汉单例& signal);
		const 饿汉单例& operator=(const 饿汉单例& signal);

	private:
		// 唯一单实例对象指针
		static 饿汉单例* g_pSingleton;
	};
	// 代码一运行就初始化创建实例 ，本身就线程安全
	饿汉单例* 饿汉单例::g_pSingleton = new (std::nothrow) 饿汉单例();

	饿汉单例* 饿汉单例::GetInstance()
	{
		return g_pSingleton;
	}

	void 饿汉单例::DeleteInstance()
	{
		if (g_pSingleton)
		{
			delete g_pSingleton;
			g_pSingleton = nullptr;
		}
	}

	void 饿汉单例::Print()
	{
		std::cout << "饿汉单例_我的实例内存地址是:" << this << std::endl;
	}

	饿汉单例::饿汉单例()
	{
		//xie.y:此处进行注释 防止非单例模式下进行 显示 std::cout << "饿汉单例_构造" << std::endl;
	}

	饿汉单例::~饿汉单例()
	{
		std::cout << "饿汉单例_析构" << std::endl;
	}


}
#pragma endregion

#pragma region 智能指针单例
namespace 智能指针
{
	class 智能指针单例 {

	public:

		static std::shared_ptr<智能指针单例> GetInstance();

		void Print()
		{
			std::cout << "智能指针单例_我的实例内存地址是:" << this << std::endl;
		}

		~智能指针单例() {
			std::cout << "智能指针单例_析构" << std::endl;
		}

	private:

		智能指针单例() {
			std::cout << "智能指针单例_构造" << std::endl;
		}
	};

	static std::shared_ptr<智能指针单例> singleton = nullptr;
	static std::mutex singletonMutex;

	std::shared_ptr<智能指针单例> 智能指针单例::GetInstance() {
		if (singleton == nullptr) {
			std::unique_lock<std::mutex> lock(singletonMutex);
			if (singleton == nullptr) {
				auto temp = std::shared_ptr<智能指针单例>(new 智能指针单例());
				singleton = temp;
			}
		}
		return singleton;
	}
}
#pragma endregion

#pragma region Call_once单例
namespace Call_once
{
	class Call_once单例 {
	public:
		static std::shared_ptr<Call_once单例> GetSingleton();

		void Print() {
			std::cout << "Call_once单例_我的实例内存地址是:" << this << std::endl;
		}

		~Call_once单例() {
			std::cout << "Call_once单例_析构" << std::endl;
		}

	private:
		Call_once单例() {
			std::cout << "Call_once单例_构造" << std::endl;
		}
	};

	static std::shared_ptr<Call_once单例> singleton = nullptr;
	static std::once_flag singletonFlag;

	std::shared_ptr<Call_once单例> Call_once单例::GetSingleton() {
		std::call_once(singletonFlag, [&] {
			singleton = std::shared_ptr<Call_once单例>(new Call_once单例());
			});
		return singleton;
	}

}
#pragma endregion


void 单例模式::运行()
{
	std::cout << "********************单例模式********************\n" << std::endl;

	{
		std::cout << "**********加锁懒汉单例(推荐)**********" << std::endl;
		std::cout << "推荐使用,且线程安全" << std::endl;
		auto instance = 加锁懒汉::加锁懒汉单例::GetInstance();
		instance->Print();
		instance->DeleteInstance();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********静态局部变量懒汉单例**********" << std::endl;
		std::cout << "C++11线程安全" << std::endl;
		静态局部变量懒汉::静态局部变量懒汉单例::GetInstance();
		静态局部变量懒汉::静态局部变量懒汉单例::GetInstance().Print();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********饿汉单例**********" << std::endl;
		std::cout << "饿汉本身线程安全" << std::endl;
		auto instance = 饿汉::饿汉单例::GetInstance();
		instance->Print();
		instance->DeleteInstance();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********智能指针单例**********" << std::endl;
		std::cout << "不推荐使用,智能指针都不线程安全" << std::endl;
		auto instance = 智能指针::智能指针单例::GetInstance();
		instance->Print();
		std::cout << "******************************\n" << std::endl;
	}


	{
		std::cout << "**********Call_once单例**********" << std::endl;
		std::cout << "较少用到,C++11线程安全" << std::endl;
		auto instance = Call_once::Call_once单例::GetSingleton();
		instance->Print();
		std::cout << "******************************\n" << std::endl;
	}

	std::cout << "************************************************" << std::endl;
}
