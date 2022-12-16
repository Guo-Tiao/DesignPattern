#include "桥接器模式.h"

#pragma region 游戏类
//实现游戏类接口基类
class Game
{
public:
	Game() {}
	virtual void Play() = 0;
private:
};

//具体实现类GameA
class GameA :public Game
{
public:
	GameA() {}
	void Play() {
		printf("游戏A启动!\n");
	}
};

//具体实现类GameB
class GameB :public Game
{
public:
	GameB() {}
	void Play() {
		printf("游戏B启动!\n");
	}
};
#pragma  endregion

#pragma region 主机平台类
//抽象类主机平台类
class Platform
{
public:
	Platform() {
	}
	//安装游戏
	virtual void SetupGame(Game* igame) = 0;
	//运行游戏
	virtual void Play() = 0;
private:
	Game* game;
};

//扩充平台类:XBox
class XBox :public Platform
{
public:
	XBox() {
	}

	void SetupGame(Game* igame) {
		this->game = igame;
	}
	void Play() {
		printf("XBox运行游戏:\n");
		this->game->Play();
	}
private:
	Game* game;
};

//扩充平台类:PS5
class PS5 :public Platform
{
public:
	PS5() {
	}
	//安装游戏
	void SetupGame(Game* igame) {
		this->game = igame;
	}
	void Play() {
		printf("PS5运行游戏:\n");
		this->game->Play();
	}
private:
	Game* game;
};
#pragma  endregion

void 桥接器模式::运行()
{
	std::cout << "********************桥接器模式********************" << std::endl;
	Game* game;
	Platform* platform;

	//用户买了Xbox，想玩游戏A
	platform = new XBox();
	game = new GameA();
	platform->SetupGame(game);
	platform->Play();
	//玩游戏B
	game = new GameB();
	platform->SetupGame(game);
	platform->Play();
	printf("========平台切换========\n");
	platform = new PS5();
	game = new GameA();
	platform->SetupGame(game);
	platform->Play();
	std::cout << "**************************************************" << std::endl;
}
