#include "StdAfx.h"
#include "LogFile.h"


CLogFile::CLogFile(const char * str):LogSwitch(0),outPutSwitch(0)  //默认开启日志和输出窗口功能
{
	fileName = str;
	createFile();
	file<<endl<<endl<<getTime();
}

CLogFile::CLogFile():fileName("log.txt"),LogSwitch(0),outPutSwitch(0)
{
	createFile();  //创建文件  检测文件是否存在&检测文件大小 定位到最后一行 插入日期 
	file<<endl<<endl<<getTime();
}


CLogFile::~CLogFile(void)
{
}

time_t CLogFile::getTime()
{
	time_t now_time;
	now_time = time(NULL);
	return now_time;
}

bool CLogFile::closeLogSwitch(bool i)
{
	if( i==1 )
	{
		LogSwitch=1;  //关闭log功能  
		return 1;
	}
	else if(i == 0)  //开启
	{
		LogSwitch=0;
		return 1;
	}
	return 0;//设置失败
}

void CLogFile::createFile()
{
//	if(file.)
	if(LogSwitch == 1)  //日志功能未开启 不必创建文件
		return;

	file.open(fileName,ios_base::app);
	if (file.fail())
	{
		file.open(fileName,ios_base::out);
	}
}


