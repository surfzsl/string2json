#ifndef WEB_STRING2JSON
#define WEB_STRING2JSON
#include <string>
//#include "thirdparty/json.hpp"
using namespace std;
//using json = nlohmann::json;
#include <vector>

class String2Json
{
public:
	void setResponse(const string str) { m_response = str; }
	const string& getResponse() const { return m_response; }
	vector <string> split(const string &str, const string &seperator);
	virtual string str2json() = 0;


private:
	string m_response, m_string;
};

class Login2Json : public String2Json
	
{
public:
	string str2json();
};

class Logout2Json : public String2Json
{
public:
	string str2json();
};

class Domainlist2Json : public String2Json
{
public:
	string str2json();
};

class PermissionVariable2Json : public String2Json
{
public:
	string str2json();
};

class ContentList2Json : public String2Json
{
public:
	string str2json();
};

class SubscriptionList2Json : public String2Json
{
public:
	string str2json();
};

class PublicationList2Json : public String2Json
{
public:
	string str2json();
};

class UserSubServiceList2Json :public String2Json
{
public:
	string str2json();
};

class PeCheck2Json :public String2Json
{
public:
	string str2json();
};

class ItemCheck2Json :public String2Json
{
public:
	string str2json();
};

class PublicationPeCheck :public String2Json
{
public:
	string str2json();
};

class PeToSubserviceList2Json :public String2Json
{
public:
	string str2json();
};

class RepermissionTest2Json :public String2Json
{
public:
	string str2json();
};

class RepermissionReset2Json:public String2Json
{
public:
	string str2json();
};

class DaemonStatus2Json :public String2Json
{
public:
	string str2json();
};

class GetServiceAttributes2Json : public String2Json
{
public:
	string str2json();
};
class GetAuthorizationDictionaryChecksum2Json :public String2Json
{
public:
	string str2json();
};

class Statistics2Json :public String2Json
{
public:
	string str2json();
};

class ResetStatistics2Json :public String2Json
{
public:
	string str2json();
};

class CacheLoad2Json :public String2Json
{
public:
	string str2json();
};

class CacheDump2Json :public String2Json
{
public:
	string str2json();
};
#endif // !WEB_STRING2JSON
#pragma once
