#ifndef __MsgServerRTRedis_RRTRTREDIS_H__
#define __MsgServerRTRedis_RRTRTREDIS_H__
#include "TCPListenerSocket.h"
#include "RRTRTRedisListener.h"

#include <iostream>
#include <map>

class RRTRTRedis
{
protected:
	RRTRTRedis(void);
public:

	virtual ~RRTRTRedis(void);

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
	static RRTRTRedis* Inst();

public:
	int		Start(const char*pRTRedisIp, unsigned short usRTRedisPort);
	void	DoTick();
	void	Stop();

private:

    RRTRTRedisListener    *m_pRTRedisListener;

};

#endif	// __MsgServerRTRedis_RRTRTREDIS_H__
