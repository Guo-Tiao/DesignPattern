#include "模板方法模式.h"

// 基类
class FingerprintModule
{
public:
	FingerprintModule() {}
	void getImage() {
		printf("采指纹图像\n");
	}
	void output() {
		printf("指纹图像处理完成!\n");
	}
	virtual bool isSafeMode() = 0;
	virtual void processImage() = 0;
	// 加解密
	virtual void encrypt() = 0;
	virtual void decrypt() = 0;

	// 模板方法
	void algorithm() {
		// 1.采图
		getImage();
		// 2.安全模式下加密和解密
		if (isSafeMode()) {
			// 2.1. 加密
			encrypt();
			// 2.2. 解密
			decrypt();
		}
		// 3.处理Image
		processImage();
		// 4.处理结果
		output();
	}
};

// 派生类A
class FingerprintModuleA :public FingerprintModule
{
public:
	FingerprintModuleA() {}
	void processImage() {
		printf("使用 第一代版本算法 处理指纹图像\n");
	}
	bool isSafeMode() {
		printf("安全模式\n");
		return true;
	}
	void encrypt() {
		printf("使用RSA密钥加密\n");
	}
	void decrypt() {
		printf("使用RSA密钥解密\n");
	}
};

// 派生类B
class FingerprintModuleB :public FingerprintModule
{
public:
	FingerprintModuleB() {}
	void processImage() {
		printf("使用 第二代版本算法 处理指纹图像\n");
	}
	bool isSafeMode() {
		printf("非安全模式\n");
		return false;
	}
	void encrypt() {}
	void decrypt() {}
};

// 派生类C
class FingerprintModuleC :public FingerprintModule
{
public:
	FingerprintModuleC() {}
	void processImage() {
		printf("使用 第一代版本算法 处理指纹图像\n");
	}
	bool isSafeMode() {
		printf("安全模式\n");
		return true;
	}
	void encrypt() {
		printf("使用DH密钥加密\n");
	}
	void decrypt() {
		printf("使用DH密钥解密\n");
	}
};



void 模板方法模式::运行()
{
	std::cout << "********************模板方法模式********************" << std::endl;
	printf("\n");
	FingerprintModule* fp = new FingerprintModuleA();
	fp->algorithm();
	printf("\n");
	fp = new FingerprintModuleB();
	fp->algorithm();
	printf("\n");
	fp = new FingerprintModuleC();
	fp->algorithm();
	printf("\n");
	std::cout << "****************************************************" << std::endl;
}
