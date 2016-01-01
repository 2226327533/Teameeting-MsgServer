#ifndef __RT_MEETING_H__
#define __RT_MEETING_H__
#include "TCPListenerSocket.h"
#include "RTTransferSession.h"
#include <iostream>


class RTMeeting
{
protected:
	RTMeeting(void);
public:
	virtual ~RTMeeting(void);

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
	static RTMeeting* Inst();

public:
	int		Start(const char* pConnAddr, unsigned short usConnPort, const char*pQueueAddr, unsigned short usQueuePort, const char* pHttpAddr, unsigned short usHttpPort);
	void	DoTick();
	void	Stop();

private:

	OSMutex							m_MutexRoom;
	OSMutex							m_MutexSession;

};

#endif	// __RT_MEETING_H__