#ifndef __RT_CONNECTOR_H__
#define __RT_CONNECTOR_H__
#include "TCPListenerSocket.h"
#include "RTConnListener.h"
#include "RTModuleListener.h"
#include "RTConnTcpListener.h"

#include <iostream>
#include <map>

class RTConnector
{
protected:
	RTConnector(void);
public:
    
	virtual ~RTConnector(void);

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
	static RTConnector* Inst();
    
public:
	int		Start(const char*pLanIP, unsigned short usConnPort
                  , const char*pModuleAddr, unsigned short usModulePort
                  , const char*pConnTcpAddr, unsigned short usConnTcpPort
                  , const char*pHttpAddr, unsigned short usHttpPort);
	void	DoTick();
	void	Stop();

private:
    
	RTConnListener		*m_pConnListener;
    RTModuleListener    *m_pModuleListener;
    RTConnTcpListener   *m_pConnTcpListener;

	OSMutex				m_MutexRoom;
	OSMutex				m_MutexSession;

};

#endif	// __RT_CONNECTOR_H__