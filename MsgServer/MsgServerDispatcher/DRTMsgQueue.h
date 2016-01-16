#ifndef __MsgServerDispatcher_DRTMEETING_H__
#define __MsgServerDispatcher_DRTMEETING_H__
#include "TCPListenerSocket.h"
#include "DRTModuleListener.h"
#include "DRTTransferSession.h"
#include <iostream>

class DRTMsgQueue
{
protected:
	DRTMsgQueue(void);
public:
	virtual ~DRTMsgQueue(void);

	/* ��ӡ����汾��
	 * ����:	��
	 */
	static void PrintVersion();
	/* ϵͳ��ʼ��
	 * ����:	evTbSize - ϵͳ��Hash���С������ϵͳ������������仯
	 */
	static void Initialize(int evTbSize);
	/* ϵͳע��
	 * ����:	��
	 */
	static void DeInitialize();

	/*
	 *
	 */
	static DRTMsgQueue* Inst();
    

public:
	int		Start(const char*pConnIp, unsigned short usConnPort, const char*pModuleIp, unsigned short usModulePort);
	void	DoTick();
	void	Stop();

private:
    DRTModuleListener                *m_pModuleListener;
    DRTTransferSession               *m_pTransferSession;

	OSMutex							m_MutexRoom;
	OSMutex							m_MutexSession;

};

#endif	// __MsgServerDispatcher_DRTMEETING_H__