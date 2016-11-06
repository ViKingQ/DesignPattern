#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <set>
#include <string>

using namespace std;

class CObserver;

//////////////////////////////////////////////////////////////////////////
class CSubject
{
public:
	CSubject() : m_bChanged(false){}
	virtual ~CSubject(){}

public:
	void attach(CObserver* pObserver);
	void detach(CObserver* pObserver);
	void detachAll();
	void notify(void* pArg = NULL);
	bool hasChanged();
	int getObserversCount();

protected:
	void setChanged();
	void clearChanged();

private:
	bool m_bChanged;
	std::set<CObserver*> m_setObservers;
};
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
class CBloger : public CSubject
{
public:
	void publish(const string& strContent);
};
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
class CPortal : public CSubject
{
public:
	void publish(const string& strContent);
};
//////////////////////////////////////////////////////////////////////////

#endif	//__SUBJECT_H__