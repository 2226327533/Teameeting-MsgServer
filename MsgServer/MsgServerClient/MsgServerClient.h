#ifndef __MsgServerClient_SEQN_CLIENT_H__
#define __MsgServerClient_SEQN_CLIENT_H__

#include <iostream>
#include <map>

class MsgServerClient
{
protected:
	MsgServerClient(void);
public:

	virtual ~MsgServerClient(void);

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
	static MsgServerClient* Inst();

public:
	int		Start(const char* pUserid, const char*pIp, unsigned short usPort);
	void	DoTick();
	void	Stop();

private:

};

#endif	// __MsgServerClient_SEQN_CLIENT_H__
