#include "StdAfx.h"
#include "DataBaseAdo.h"

//"Provider=SQLOLEDB;SERVER=server;DATABASE=samp;UID=admin;PWD=admin
//"Data Source=8PDYMQCADPLRIDS;Initial Catalog=MyData;User ID=lily;Pwd=123
CDataBaseAdo::CDataBaseAdo(void)
:strConnection("Provider=SQLOLEDB;Data Source=8PDYMQCADPLRIDS;Initial Catalog=MyData;UID=lily;PWD=123")
{
	::CoInitialize(NULL);
	m_pConnection = NULL;
}


CDataBaseAdo::~CDataBaseAdo(void)
{
	//if (m_pConnection)
	//{
	//	m_pConnection->Close();
	////	m_pConnection = NULL;
	//}
	//::CoUninitialize();
}

bool CDataBaseAdo::Open()
{
	if (FAILED(m_pConnection.CreateInstance(__uuidof(Connection))))
	{
		return false;

	}
	else
	{
		try
		{
			m_pConnection->Open(strConnection,"","",0);
		}
		catch (_com_error e)
		{
			AfxMessageBox( e.Description() );
			return false;
		}
		int i=m_pConnection->State;
		return true;
	}
}

void CDataBaseAdo::Close()
{
	try
	{
		if (m_pConnection)
		{
	//		m_pConnection->Close();
		//	m_pConnection = NULL ;
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	::CoUninitialize();
}

vector< vector<_variant_t> > CDataBaseAdo::Select(BSTR strSql, vector<_variant_t> strName)
{
	_RecordsetPtr  pRecordset;
	vector< vector<_variant_t> > vRecord;
	if(FAILED(pRecordset.CreateInstance(__uuidof(Recordset))))
	{
		return vector< vector<_variant_t> >();
	}
	try
	{
		//adOpenDynamic：动态 adLockOptimistic乐观封锁法 adCmdText：文本查询语句 
		//"server=8PDYMQCADPLRIDS;database=MyData;Truster_Connection=SSPI"
		pRecordset->Open(strSql, (IDispatch*)m_pConnection,adOpenDynamic,adLockOptimistic,adCmdText);
	//	pRecordset->Open(strSql, (IDispatch*)m_pConnection,adOpenDynamic,adLockOptimistic,adCmdText);
		pRecordset->MoveFirst();
		while (!pRecordset->adoEOF)
		{
			vector<_variant_t> vTheValue;
			for (int i=0;i<strName.size();++i)
			{
				vTheValue.push_back(pRecordset->GetCollect(strName.at((i))));
			}
			vRecord.push_back(vTheValue);
			pRecordset->MoveNext();
		}
		pRecordset->Close();
		pRecordset = NULL;
	}
	catch(_com_error &e)
	{
		AfxMessageBox(e.Description());
	}
	return vRecord;
}

CString CDataBaseAdo::VariantToCString(_variant_t var)
{ 
	CString str; //转换以后的字符串 
	switch(var.vt) 
	{ 
	case VT_BSTR: //var is BSTR type 
		str=var.bstrVal; 
		break; 
	case VT_I2: //var is short int type 
		str.Format(L"%d",(int)var.iVal); 
		break; 
	case VT_I4: //var is long int type 
		str.Format(L"%d",var.lVal); 
		break; 
	case VT_R4: //var is float type 
		str.Format(L"%10.6f",(double)var.fltVal); 
		break; 
	case VT_R8: //var is double type 
		str.Format(L"%10.6f",var.dblVal); 
		break; 
	case VT_CY: //var is CY type 
		str=COleCurrency(var).Format(); 
		break; 
	case VT_DATE: //var is DATE type 
		str=COleDateTime(var).Format(); 
		break; 
	case VT_BOOL: //var is VARIANT_BOOL 
		str= (var.boolVal==0) ?L"FALSE": L"TRUE"; 
		break; 
	default: 
		str.Format(L"Unk type %d\n",var.vt); 
		TRACE(L"Unknown type %d\n",var.vt); 
	} 
	return str; 
}

int CDataBaseAdo::ExcuteSQL(_bstr_t commandTest, bool IsText)
{
	_variant_t recordsAffected;
	try
	{
		if (IsText)
		{
			m_pConnection->Execute(commandTest,&recordsAffected,adCmdText);
		} 
		else
		{
			m_pConnection->Execute(commandTest,&recordsAffected,adCmdStoredProc);
		}
	}
	catch (_com_error e)
	{
		return -1;
	}
	return recordsAffected.intVal;
}






