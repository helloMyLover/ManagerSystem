#pragma once
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
#include <vector>
using namespace std;
class CDataBaseAdo
{
public:
	CDataBaseAdo(void);
	~CDataBaseAdo(void);
public:
	_ConnectionPtr m_pConnection;  //通常被用来创建一个数据连接或执行一条不返回任何结果的SQL
	
public://外部接口
	bool Open();
	void Close(void);
	bool addOne(_variant_t str);
	bool deleteOne(_variant_t str);
	bool query(_variant_t str);
	CString VariantToCString(_variant_t var);
	int ExcuteSQL(_bstr_t commandTest, bool IsText);
	vector< vector<_variant_t> > Select(BSTR strSql, vector<_variant_t> strName);

private:
	_bstr_t strConnection;
};

