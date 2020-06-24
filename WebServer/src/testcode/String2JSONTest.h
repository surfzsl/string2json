#pragma once
#ifndef __TEST_STRING2JSONTEST__
#define __TEST_STRING2JSONTEST__
#include <map>
#include <string>
#include<utility>
#include "../String2JSON.h"
#include <vector>
using namespace std;
class String2JSONTest
{
public:
	void init();
	string get_response();
	int runtest();
	void set_casenum(string num);
	string get_casenum();
	void set_casenmae();
	string get_casename();
private:
	map<string, String2Json *> m_funcmap;
	vector< pair<string, string> > m_testresult;
	string m_casenum, m_casename;
	void get_case(const string line);
};
#endif
