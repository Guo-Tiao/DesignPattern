#include "备忘录模式.h"
#include <string>
#include <vector>
///使用备忘录模式构建一个版本控制器

using namespace std;

//备忘录
class Memento
{
public:
	Memento() {}
	Memento(int iVersion, string iDate, string iLabel) {
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	int version;
	string date;
	string label;
};


// 原生器：CodeVersion
class CodeVersion
{
public:
	CodeVersion() {
		version = 0;
		date = "1900-01-01";
		label = "none";
	}
	CodeVersion(int iVersion, string iDate, string iLabel) {
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	// 保存代码
	Memento* save() {
		return new Memento(this->version, this->date, this->label);
	}
	// 回退版本
	void restore(Memento* memento) {
		setVersion(memento->getVersion());
		setDate(memento->getDate());
		setLabel(memento->getLabel());
	}
	void setVersion(int iVersion) {
		version = iVersion;
	}
	int getVersion() {
		return version;
	}
	void setLabel(string iLabel) {
		label = iLabel;
	}
	string getLabel() {
		return label;
	}
	void setDate(string iDate) {
		date = iDate;
	}
	string getDate() {
		return date;
	}
private:
	// 代码版本
	int version;
	// 代码提交日期
	string date;
	// 代码标签
	string label;
};


// 管理者
class CodeManager
{
public:
	CodeManager() {}
	void commit(Memento* m) {
		printf("提交：版本-%d, 日期-%s, 标签-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
		mementoList.push_back(m);
	}
	// 切换到指定的版本，即回退到指定版本
	Memento* switchToPointedVersion(int index) {
		mementoList.erase(mementoList.begin() + mementoList.size() - index, mementoList.end());
		return mementoList[mementoList.size() - 1];
	}
	// 打印历史版本
	void codeLog() {
		for (int i = 0; i < mementoList.size(); i++) {
			printf("[%d]：版本-%d, 日期-%s, 标签-%s\n", i, mementoList[i]->getVersion(),
				mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
		}
	}
private:
	vector<Memento*> mementoList;
};

void 备忘录模式::运行()
{
	std::cout << "********************备忘录模式********************" << std::endl;
	CodeManager* codeMgr = new CodeManager();

	CodeVersion* codeVer = new CodeVersion(1001, "2019-11-03", "Initial version");

	// 提交初始版本
	printf("提交初始版本:\n");
	codeMgr->commit(codeVer->save());

	// 修改一个版本，增加了日志功能
	printf("\n提交一个版本，增加了日志功能:\n");
	codeVer->setVersion(1002);
	codeVer->setDate("2019-11-04");
	codeVer->setLabel("Add log funciton");
	codeMgr->commit(codeVer->save());

	// 修改一个版本，增加了Qt图片浏览器
	printf("\n提交一个版本，增加了Qt图片浏览器:\n");
	codeVer->setVersion(1003);
	codeVer->setDate("2019-11-05");
	codeVer->setLabel("Add Qt Image Browser");
	codeMgr->commit(codeVer->save());

	// 查看提交历史
	printf("\n查看提交历史\n");
	codeMgr->codeLog();

	// 回退到上一个版本
	printf("\n回退到上一个版本\n");
	codeVer->restore(codeMgr->switchToPointedVersion(1));

	// 查看提交历史
	printf("\n查看提交历史\n");
	codeMgr->codeLog();

	std::cout << "**************************************************" << std::endl;
}
