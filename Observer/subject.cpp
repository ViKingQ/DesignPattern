#include <iostream>
#include "subject.h"
#include "observer.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
void CSubject::attach(CObserver* pObserver)
{
	if (NULL == pObserver)
	{
		return;
	}
	m_setObservers.insert(pObserver);
}

void CSubject::detach(CObserver* pObserver)
{
	if (NULL == pObserver)
	{
		return;
	}
	m_setObservers.erase(pObserver);
}

void CSubject::detachAll()
{
	m_setObservers.clear();
}

void CSubject::notify(void* pArg /*= NULL*/)
{
	if (!hasChanged())
	{
		return;
	}
	cout << "Notify Observers..." << endl;
	clearChanged();
	set<CObserver*>::iterator itOb = m_setObservers.begin();
	for (; m_setObservers.end() != itOb; ++itOb)
	{
		(*itOb)->update(this, pArg);
	}
}

bool CSubject::hasChanged()
{
	return m_bChanged;
}

int CSubject::getObserversCount()
{
	return m_setObservers.size();
}

void CSubject::setChanged()
{
	m_bChanged = true;
}

void CSubject::clearChanged()
{
	m_bChanged = false;
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
void CBloger::publish(const string& strContent)
{
	cout << "Bloger Publish, Content:" << strContent.c_str() << endl;
	setChanged();
	notify(const_cast<char*>(strContent.c_str()));
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
void CPortal::publish(const string& strContent)
{
	cout << "Portal Publish, Content:" << strContent.c_str() << endl;
	setChanged();
	notify(const_cast<char*>(strContent.c_str()));
}
//////////////////////////////////////////////////////////////////////////
