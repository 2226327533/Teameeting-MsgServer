#ifndef __MsgServerMeeting_MRT_HTTP_SVR_CONN_H__
#define __MsgServerMeeting_MRT_HTTP_SVR_CONN_H__
#include "OSMutex.h"
#include "RTMessage.h"
#include "refcount.h"
#include "scoped_ref_ptr.h"
#include "RTHttpSender.h"
#include "RTHttpSvrConn.h"

#define M_HTTP_CMD_INVALID              (0)
#define M_HTTP_CMD_GET_MEETING_INFO     (1)
#define M_HTTP_CMD_GET_MEMBER_LIST      (2)

#define DEF_PROTO 1
#include "MsgServer/proto/common_msg.pb.h"
#include "MsgServer/proto/meet_msg.pb.h"
#include "MsgServer/proto/meet_msg_type.pb.h"
#include "MsgServer/proto/sys_msg.pb.h"
#include "MsgServer/proto/sys_msg_type.pb.h"

class MRTHttpSvrConn : public RTHttpSvrConn
{
public:
	MRTHttpSvrConn(void);
	virtual ~MRTHttpSvrConn(void);

public:
    void SetHttpHost(const std::string& addr, const unsigned short port, const std::string& host) {
        m_httpIp = addr;
        m_httpPort = port;
        m_httpHost = host;
        RTConnHttp::SetHttpHost(host);
    }

    //* HTTP_POST
    void HttpInsertMeetingMsg(const char* sign, const char* meetingid, const char* messagetype, const char* sessionid, const char* strMsg, const char* userid);
    void HttpInsertSessionMeetingInfo(const char* sign, const char* meetingid, const char* sessionid, const char* sessionstatus, const char* sessiontype, const char* sessionnumber);
    void HttpUpdateSessionMeetingEndtime(const char* sign, const char* sessionid);
    void HttpUpdateSessionMeetingNumber(const char* sign, const char* sessionid, const char* sessionnumber, const char* meetingid);
    void HttpUpdateUserMeetingJointime(const char* sign, const char* meetingid);
    void HttpUpdateSessionMeetingStatus(const char* sign, const char* sessionid, const char* sessionstatus);

    //* HTTP_GET
    void HttpGetMeetingInfo(pms::RelayMsg& rmsg, pms::MeetMsg& msg);
    void HttpGetMeetingInfo(pms::RelayMsg& rmsg, pms::MeetMsg& msg) const;
    void HttpGetMeetingMemberList(pms::RelayMsg& rmsg, pms::MeetMsg& msg);
    void HttpGetMeetingMemberList(pms::RelayMsg& rmsg, pms::MeetMsg& msg) const;

public:
    //* For RCHttp
    virtual int  OnWriteEvent(const char*pData, int nLen, int* nOutLen);

public:
    class MSender : public RTHttpSender{
        //* For RTConnHttp
    public:
        MSender():RTHttpSender(){}
        MSender(int cmd, pms::RelayMsg& rmsg, pms::MeetMsg& msg):RTHttpSender(cmd, rmsg, msg){}
        virtual void OnResponse(const char*pData, int nLen);
    };

private:
    std::string           m_httpIp;
    unsigned short        m_httpPort;
    std::string           m_httpHost;
    //
};

#endif	// __MsgServerMeeting_MRT_HTTP_SVR_CONN_H__
