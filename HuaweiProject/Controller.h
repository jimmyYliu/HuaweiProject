#pragma once
#include "definition.h"


//核心控制类（本质是利用数据生成操作列表）
class Controller
{
private:
	//服务器类型列表（按核存比升序）
	vector<ServerType> ratioServerList;
	//可能有空间存放的服务器列表
	vector<unsigned int> usedServerList;
	//购买一台服务器并添加到列表，返回服务器对象引用
	Server& PurchaseServer(string type);
	//删除虚拟机后是否清空的最大内存和CPU
	const unsigned thre = 190;
	//是否迁移的阈值
	const float threMove = logf(25);
	//虚拟机型号对应购买服务器型号的映射
	unordered_map<string, string> vmwareToServer;
	vector<unsigned> waitMoveS;  //储存因为使用度太小而需要清空的服务器列表
	vector<unsigned> waitMoveV;  //储存因为放入服务器后导致服务器剩余核存比过大或过小而需要迁移的虚拟机列表
	void init(void);
public:
	//生成输出所需操作列表
	void CreateList();
	void moveFun(const unsigned vmwareID, pair<int, int>& goal, int day);
	bool myFind(unsigned vmwareID, pair<int, int>& goal, int jumpSeq);
	void update(const unsigned serverID);
	void mySort(vector<unsigned>& list);
};

