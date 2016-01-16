#ifndef __MsgServerMeeting_MRT_MEETING_H__
#define __MsgServerMeeting_MRT_MEETING_H__
#include "TCPListenerSocket.h"
#include "MRTTransferSession.h"
#include <iostream>


class MRTMeeting
{
protected:
	MRTMeeting(void);
public:
	virtual ~MRTMeeting(void);

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
	static MRTMeeting* Inst();

public:
	int		Start(const char* pConnAddr, unsigned short usConnPort, const char*pQueueAddr, unsigned short usQueuePort, const char* pHttpAddr, unsigned short usHttpPort);
	void	DoTick();
	void	Stop();

private:

	OSMutex							m_MutexRoom;
	OSMutex							m_MutexSession;

};

#endif	// __MsgServerMeeting_MRT_MEETING_H__