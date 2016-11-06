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

	pBloger->publish("���ͷ������ģʽ");
	cout << endl;

	pPortal->publish("�Ż��������ģʽ");
	cout << endl;

	pPortal->detach(pMailReader);
	cout << "Portal Detached MailReader" << endl;

	cout << "Portal ObserversCount:" << pPortal->getObserversCount() << endl;

	pPortal->publish("�Ż��������ģʽ");
	
	system("pause");

	return 0;
}