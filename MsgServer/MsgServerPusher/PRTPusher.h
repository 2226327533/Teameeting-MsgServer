#ifndef __MsgServerPusher_PRTPUSHER_H__
#define __MsgServerPusher_PRTPUSHER_H__
#include "TCPListenerSocket.h"
#include "PRTPusherListener.h"
#include "MsConfigParser.h"

#include <iostream>
#include <map>
#include <vector>

class PRTPusher
{
protected:
	PRTPusher(void);
public:

	virtual ~PRTPusher(void);

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
	static PRTPusher* Inst();

public:
	int		Start(const MsConfigParser& conf);
	void	DoTick();
	void	Stop();

private:

    PRTPusherListener    *m_pModuleListener;

};

#endif	// __MsgServerPusher_PRTPUSHER_H__
