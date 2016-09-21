#ifndef __MsgServerLogical_LRTLOGICAL_H__
#define __MsgServerLogical_LRTLOGICAL_H__
#include "TCPListenerSocket.h"
#include "LRTLogicalListener.h"
#include "MsConfigParser.h"

#include <iostream>
#include <map>
#include <vector>

class LRTLogical
{
protected:
	LRTLogical(void);
public:

	virtual ~LRTLogical(void);

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
	static LRTLogical* Inst();

public:
	int		Start(const MsConfigParser& conf);
	void	DoTick();
	void	Stop();

private:

    LRTLogicalListener    *m_pLogicalListener;

};

#endif	// __MsgServerLogical_LRTLOGICAL_H__
