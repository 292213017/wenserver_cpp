#ifndef _CONNECTION_POOL_
#define _CONNECTION_POOL_

#include <string.h>
#include <iostream>
#include <string>
#include <list>
#include <mysql/mysql.h>

#include "../log/log.h"

using namespace std;

class connection_pool
{
public:
    static connection_pool * GetInstance();

    void init(string url, string User, string PassWord, string DataBaseName, int Port, int MaxConn, int close_log); 

private:
	connection_pool();
	~connection_pool();

	int m_MaxConn;  //最大连接数
	int m_CurConn;  //当前已使用的连接数
	int m_FreeConn; //当前空闲的连接数
	// locker lock;
	list<MYSQL *> connList; //连接池
	// sem reserve;

public:
	string m_url;			 //主机地址
	string m_Port;		 //数据库端口号
	string m_User;		 //登陆数据库用户名
	string m_PassWord;	 //登陆数据库密码
	string m_DatabaseName; //使用数据库名
	int m_close_log;	//日志开关
};

#endif