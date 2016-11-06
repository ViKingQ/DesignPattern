#include <string>
#include <iostream>
#include "observer.h"
#include "subject.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
CRSSReader::CRSSReader(const string& strName)
	: m_strName(strName)
{

}

void CRSSReader::update(CSubject* pSubject, void* pArg /*= NULL*/)
{
	char* pContent = static_cast<char*>(pArg);
	if (NULL != dynamic_cast<CBloger*>(pSubject))
	{
		cout << m_strName << "Updated From Bloger, Content:" << pContent << endl;
	}
	else if (NULL != dynamic_cast<CPortal*>(pSubject))
	{
		cout << m_strName << "Updated From Portal, Content:" << pContent << endl;
	}
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
CMailReader::CMailReader(const string& strName)
	: m_strName(strName)
{

}

void CMailReader::update(CSubject* pSubject, void* pArg /*= NULL*/)
{
	char* pContent = static_cast<char*>(pArg);
	if (NULL != dynamic_cast<CBloger*>(pSubject))
	{
		cout << m_strName << "Updated From Bloger, Content:" << pContent << endl;
	}
	else if (NULL != dynamic_cast<CPortal*>(pSubject))
	{
		cout << m_strName << "Updated From Portal, Content:" << pContent << endl;
	}
}
//////////////////////////////////////////////////////////////////////////
