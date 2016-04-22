//
//  RTConnClientManager.hpp
//  dyncRTCMsgClient
//
//  Created by hp on 2/23/16.
//  Copyright © 2016 Dync. All rights reserved.
//

#ifndef RTConnClientManager_hpp
#define RTConnClientManager_hpp

#include <stdio.h>
#include "webrtc/base/thread.h"
#include "webrtc/base/messagequeue.h"

class RTConnClientManager
: public rtc::MessageHandler
, public rtc::Thread{
public:
    RTConnClientManager();
    ~RTConnClientManager();

    void RunTest(int flag);
    virtual void OnMessage(rtc::Message* msg);
public:
    void RunRun();
    void RunOnce();
    void RunThread();
    void RunApplyRoom();
    void RunLoginout();
    void RunSendMsg();
private:
    bool    mIsRun;
    bool    mThreadRun;
    int     mTimes;
};

#endif /* RTConnClientManager_hpp */
