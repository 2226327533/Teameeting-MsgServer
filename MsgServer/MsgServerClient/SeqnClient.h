#ifndef __SeqnClient_SEQN_CLIENT_H__
#define __SeqnClient_SEQN_CLIENT_H__

#include <iostream>
#include <map>

class SeqnClient
{
protected:
	SeqnClient(void);
public:

	virtual ~SeqnClient(void);

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
	static SeqnClient* Inst();

public:
	int		Start(const char* pUserid, const char*pIp, unsigned short usPort);
	void	DoTick();
	void	Stop();

private:

};

#endif	// __SeqnClient_SEQN_CLIENT_H__
