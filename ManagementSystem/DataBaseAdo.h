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
	_ConnectionPtr m_pConnection;  //ͨ������������һ���������ӻ�ִ��һ���������κν����SQL
	
public://�ⲿ�ӿ�
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

