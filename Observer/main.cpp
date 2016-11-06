#include <iostream>
#include "observer.h"
#include "subject.h"

using namespace std;

int main()
{
	CBloger *pBloger = new CBloger();
	CPortal *pPortal = new CPortal();

	CRSSReader *pRSSReader = new CRSSReader("RSSReader");
	CMailReader *pMailReader = new CMailReader("MailReader");

	pBloger->attach(pRSSReader);
	pBloger->attach(pMailReader);

	pPortal->attach(pRSSReader);
	pPortal->attach(pMailReader);

	pBloger->publish("博客分享设计模式");
	cout << endl;

	pPortal->publish("门户分享设计模式");
	cout << endl;

	pPortal->detach(pMailReader);
	cout << "Portal Detached MailReader" << endl;

	cout << "Portal ObserversCount:" << pPortal->getObserversCount() << endl;

	pPortal->publish("门户分享设计模式");
	
	system("pause");

	return 0;
}