//
//  main.cpp
//  MsgServerConnector
//
//  Created by hp on 1/16/16.
//  Copyright © 2016 DYNC. All rights reserved.
//

#include <iostream>
#include "rtklog.h"
#include "CRTConnector.h"
#include "RTZKClient.hpp"
#include <google/protobuf/message.h>

#ifndef _TEST_
#define _TEST_ 0
#endif

int main(int argc, const char * argv[]) {
    LI("Hello, Connector!!!");
    CRTConnector::PrintVersion();

    if (argc <= 1) {
        std::cout << "Error: Please usage:$0 {conf_path} " << std::endl;
        std::cout << "Please enter any key to exit ..." << std::endl;
        getchar();
        exit(0);
    }
#if _TEST_
    if (RTZKClient::Instance().InitOnly(argv[1])!=0) {
#else
    if (RTZKClient::Instance().InitZKClient(argv[1])!=0) {
#endif
        std::cout << "Please check the config file ..." << std::endl;
        std::cout << "Please enter any key to exit ..." << std::endl;
        getchar();
        exit(0);
    }

    int level = RTZKClient::Instance().GetServerConfig().Level;
    std::string logpath = RTZKClient::Instance().GetServerConfig().LogPath;
    if (logpath.empty())
        L_Init(level, NULL);
    else
        L_Init(level, logpath.c_str());

    CRTConnector::Initialize(1024);
    CRTConnector* pConnector = CRTConnector::Inst();
    int res = pConnector->Start(RTZKClient::Instance().GetServerConfig().IP.c_str(),
                      RTZKClient::Instance().GetServerConfig().portConfig.connector.ListenWebcon,
                      RTZKClient::Instance().GetServerConfig().IP.c_str(),
                      RTZKClient::Instance().GetServerConfig().portConfig.connector.ListenModule,
                      RTZKClient::Instance().GetServerConfig().IP.c_str(),
                      RTZKClient::Instance().GetServerConfig().portConfig.connector.ListenClicon
                      );
    int test = 0;
    if (res != 0) {
        LI("CRTConnector start failed and goto exit, res:%d\n", res);
        goto EXIT;
    }
    //while (test++ < 120) {
    while (1) {
        pConnector->DoTick();
        sleep(1);
        //break;
    }
        sleep(1);
EXIT:
    pConnector->Stop();
    CRTConnector::DeInitialize();
    L_Deinit();
    RTZKClient::Instance().Unin();
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
