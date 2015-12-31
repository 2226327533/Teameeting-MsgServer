#ifndef __RT_MEETING_H__
#define __RT_MEETING_H__
#include "TCPListenerSocket.h"
#include "RTModuleListener.h"
#include "RTTransferSession.h"
#include <iostream>

class RTMsgQueue
{
protected:
	RTMsgQueue(void);
public:
	virtual ~RTMsgQueue(void);

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
	static RTMsgQueue* Inst();
    

public:
	int		Start(const char*pConnIp, unsigned short usConnPort, const char*pModuleIp, unsigned short usModulePort);
	void	DoTick();
	void	Stop();

private:
    RTModuleListener                *m_pModuleListener;
    RTTransferSession               *m_pTransferSession;

	OSMutex							m_MutexRoom;
	OSMutex							m_MutexSession;

};

#endif	// __RT_MEETING_H__