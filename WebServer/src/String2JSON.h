#ifndef WEB_STRING2JSON
#define WEB_STRING2JSON
#include <string>
#include "thirdparty/json.hpp"
using namespace std;
using json = nlohmann::json;

class String2Json
{
public:
	String2Json();
	~String2Json();
	void setResponse(const string str) { m_response = str; }
	const string& getResponse() const { return m_response; }
	vector <string> split(const string &str, const string &seperator);
	virtual string str2json() {};


private:
	string m_response, m_string;
};

class Login2Json : public String2Json
	
{
public:
	Login2Json();
	~Login2Json();
	string str2json();
private:
	string m_response;
};


String2Json::String2Json():m_response("")
{
	
}

String2Json::~String2Json()
{
}

Login2Json::Login2Json() {}
Login2Json::~Login2Json(){}


#endif // !WEB_STRING2JSON
#pragma once
