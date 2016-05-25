//该文件记录程序运行的事项 包括记录时间，当前运行到的步骤，当该文件满足一定大小之后自动清空，以及将运行条例输出到vs输出窗口调试使用
//设置当不需要时屏蔽其功能
#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
class CLogFile
{
public:
	CLogFile(void);
	CLogFile(const char *);
	~CLogFile(void);
	time_t getTime();
	bool   closeOutPutSwitch(bool i=1);  //默认关闭
	bool   closeLogSwitch(bool i=1);     

	void   createFile();

private:
	const char * fileName;
	BOOL    outPutSwitch;
	BOOL    LogSwitch;
	fstream  file;

public:
	template <typename T> void write(T str)
	{
		if(file.fail())
		{
			std::cout<<"log文件未打开或者日志功能未开启"<<endl;
		}
		else if(outPutSwitch == 0)   //日志功能开启
		{
			file<<endl<<str;
		}
	}

	template <typename T> void writeOutPutWindow(T str)
	{
		if (outPutSwitch == 1 )
		{
			return;
		} 
		else
		{
			OutputDebugString(str);
		}
	}
};



