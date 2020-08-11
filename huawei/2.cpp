/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: 考生实现代码
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr auto MAX_IP_NUM = 256;

class MiniDhcpServer {
public:
    MiniDhcpServer()
    {
        for (int i = 0; i < MAX_IP_NUM; i++) {
            unusedIpPool.insert(i);
        }
    }

    string Request(const string &mac)
    {
        auto id = -1;
        if (hasApplyIp(mac)) {
            id = getIpFromRecentlyUsed(mac);
        }

        if (id == -1) {
            id = getNewIp();
        }

        return getFullIp(id);
    }

    void Release(const string &mac)
    {
        if (hasApplyIp(mac)) {
            auto id = getUsedIp(mac);
            if (id != -1) {
                recentlyUsedIps[mac].second = false;
                usedIps.erase(id);
                freeAfterUsedIpPool.insert(id);
            }
        }
    }

    std::string getFullIp(int ip)
    {
        if (ip != -1) {
            return "192.168.0" + std::to_string(ip);
        }
        else {
            return "NA";
        }
    }

    int getNewIp()
    {
        auto ip = getIpFromFAU();
        if (ip == -1) {
            ip = getIpFromUnused();
        }

        return ip;
    }

    int getIpFromUnused()
    {
        return getIpFromPool(unusedIpPool);
    }
    int getIpFromFAU()
    {
        return getIpFromPool(freeAfterUsedIpPool);
    }
    int getIpFromPool(std::set<int> ipPool)
    {
        auto id = -1;
        if (!ipPool.empty()) {
            id = *(ipPool.begin());
        }
        ipPool.erase(ipPool.begin());
        usedIps.insert(id);
        return id;
    }
    int getIpFromRecentlyUsed(const string &mac)
    {
        auto [recentIp, isUsed] = recentlyUsedIps[mac];
        auto ip                 = -1;
        if (isUsed || isFree(recentIp)) {
            ip = recentIp;
            freeAfterUsedIpPool.erase(ip);
            usedIps.insert(ip);
        }
        return ip;
    }
    int getUsedIp(const string &mac)
    {
        return recentlyUsedIps[mac].second ? recentlyUsedIps[mac].first : -1;
    }
    bool hasApplyIp(const string &mac)
    {
        return recentlyUsedIps.count(mac) != 0;
    }
    bool isFree(int ip)
    {
        return usedIps.count(ip) == 0;
    }

private:
    std::set<int> unusedIpPool;
    std::set<int> freeAfterUsedIpPool{};
    std::unordered_map<std::string, std::pair<int, bool>> recentlyUsedIps{};
    std::unordered_set<int> usedIps{};
};

int main()
{
    int line;
    cin >> line;

    MiniDhcpServer dhcp;
    for (int loop = 0; loop < line; loop++) {
        string str;
        cin >> str;
        string opration = str.substr(0, str.find_first_of("="));
        string mac      = str.substr(str.find_first_of("=") + 1);

        if (opration == "REQUEST") {
            cout << dhcp.Request(mac) << endl;
        }
        else if (opration == "RELEASE") {
            dhcp.Release(mac);
        }
    }

    return 0;
}
