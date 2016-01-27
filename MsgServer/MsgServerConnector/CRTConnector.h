#ifndef __MsgServerConnector_CRTCONNECTOR_H__
#define __MsgServerConnector_CRTCONNECTOR_H__
#include "TCPListenerSocket.h"
#include "CRTConnListener.h"
#include "CRTModuleListener.h"
#include "CRTConnTcpListener.h"

#include <iostream>
#include <map>

class CRTConnector
{
protected:
	CRTConnector(void);
public:

	virtual ~CRTConnector(void);

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
	static CRTConnector* Inst();

public:
	int		Start(const char*pWebConIp, unsigned short usWebConPort
                  , const char*pModuleIp, unsigned short usModulePort
                  , const char*pCliConIp, unsigned short usCliConPort
                  , const char*pHttpIp, unsigned short usHttpPort);
	void	DoTick();
	void	Stop();

private:

	CRTConnListener		*m_pConnListener;
    CRTModuleListener    *m_pModuleListener;
    CRTConnTcpListener   *m_pConnTcpListener;

};

#endif	// __MsgServerConnector_CRTCONNECTOR_H__
