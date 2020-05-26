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

class Logout2Json:public String2Json
{
public:
	string str2json();
};

class Domainlist2Json:public String2Json
{
public:
	string str2json();
};
class PermissionVariable2Json :public String2Json
{
public:
	string str2json();
};
#endif // !WEB_STRING2JSON
#pragma once
