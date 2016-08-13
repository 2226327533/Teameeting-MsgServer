#ifndef __MsgServerRTLive_LRTRTLIVE_H__
#define __MsgServerRTLive_LRTRTLIVE_H__
#include "TCPListenerSocket.h"
#include "LRTRTLiveListener.h"
#include "LRTGroupListener.h"
#include "MsConfigParser.h"

#include <iostream>
#include <map>
#include <vector>

class LRTRTLive
{
protected:
	LRTRTLive(void);
public:

	virtual ~LRTRTLive(void);

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
	static LRTRTLive* Inst();

public:
	int		Start(const MsConfigParser& conf);

	void	DoTick();
	void	Stop();

private:

    LRTRTLiveListener    *m_pRTLiveListener;
    LRTGroupListener    *m_pGroupListener;

};

#endif	// __MsgServerRTLive_LRTRTLIVE_H__
