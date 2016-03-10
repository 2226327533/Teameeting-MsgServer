//
//  RTZKClient.hpp
//  MsgServer
//
//  Created by hp on 3/5/16.
//  Copyright © 2016 DYNC. All rights reserved.
//

#ifndef RTZKClient_hpp
#define RTZKClient_hpp

#include <stdio.h>
#include <unordered_map>
#include "zk_client.h"
#include "zk_watcher.h"
#include "server_status.h"
#include "base/ef_utility.h"
#include "list_watcher.h"
#include "data_watcher.h"
#include "server_config.h"
#include "server_status.h"

class RTZKClient{
public:
    RTZKClient(const std::string& conf);
    ~RTZKClient();

    int InitZKClient();
    int InitStatusNode(gim::ServerConfig& conf);

    static void RTZKLogCallBack(void* ctx, const std::string& l);
    static int RTZKDataCallback(void* ctx, int version, const std::string& data);

    //for list
    int RTZKCallback(int ver, const std::string& data);
    int ChildrenMapCallback(const gim::ChildrenMap& cmap);
    int PathRemoveCallback(const std::string& path);

    typedef std::unordered_map< std::string, gim::ListWatcher<RTZKClient>* > ChildrenWatcherMap;
    typedef ChildrenWatcherMap::iterator ChildrenWatcherMapIt;

    typedef std::vector< gim::ListWatcher<RTZKClient>* > ListWatcherVec;
    typedef std::vector< gim::DataWatcher<RTZKClient>* > DataWatcherVec;

    const gim::ServerConfig& GetServerConfig() const { return m_conf; }
private:
    std::string 		m_conf_path;
    gim::ServerConfig 	m_conf;
    gim::ServerStatus   m_server_status;
    gim::ServerNode		*m_server_node;
    gim::ZKClient 		*m_client;
    ListWatcherVec          m_listWs;
    ChildrenWatcherMap      m_mapChildWs;
    DataWatcherVec          m_dataWs;

};

#endif /* RTZKClient_hpp */
