#include<iostream>
#include <fstream>
#include <string>
#include "String2JSONTest.h"
using namespace std;

void String2JSONTest::init() {
	m_funcmap["login"] = new Login2Json();
	m_funcmap["logout"] = new Logout2Json();
	m_funcmap["domainlist"] = new Domainlist2Json();
	m_funcmap["permissionvariable"] = new PermissionVariable2Json();
	m_funcmap["contentlist"] = new ContentList2Json();
	m_funcmap["subscriptionlist"] = new SubscriptionList2Json();
	m_funcmap["publicationlist"] = new PublicationList2Json();
	m_funcmap["usersubservicelist"] = new UserSubServiceList2Json();
	m_funcmap["pecheck"] = new PeCheck2Json();
	m_funcmap["itemcheck"] = new ItemCheck2Json();
	m_funcmap["publicationpecheck"] = new PublicationPeCheck2Json();
	m_funcmap["petosubservicelist"] = new PeToSubserviceList2Json();
	m_funcmap["repermissiontest"] = new RepermissionTest2Json();
	m_funcmap["repermissionreset"] = new RepermissionReset2Json();
	m_funcmap["daemonstatus"] = new DaemonStatus2Json();
	m_funcmap["getserviceattributes"] = new GetServiceAttributes2Json();
	m_funcmap["getauthorizationdictionarychecksum"] = new GetAuthorizationDictionaryChecksum2Json();
	m_funcmap["statistics"] = new Statistics2Json();
	m_funcmap["resetstatistics"] = new ResetStatistics2Json();
	m_funcmap["cacheload"] = new CacheLoad2Json();
	m_funcmap["cachedump"] = new CacheDump2Json();
	m_funcmap["cacheremove"] = new CacheRemove2Json();
	m_funcmap["itemtope"] = new ItemToPe2Json();
}

void String2JSONTest::get_case(string line) {
	if (line[0] == '#') {
		size_t n = 1, first = 1;
		for (; n < line.size(); n++) {
			if (line[n] == '#') {
				first++;
				continue;
			}
				
			if (line[n] == ' ') {
				m_casenum = line.substr(first, n - first);
				m_casename = line.substr(n+1, line.size() - n);
				cout << "casename=" << m_casename << "; casenum=" << m_casenum << endl;
				break;
			}

				
		}
	}
}
int String2JSONTest::runtest() {
	ifstream ifile("./config/urls.txt");
	ofstream outfile("./test/output.txt", ios::app);
	string temp;
	if (!outfile.is_open())
	{
		cout << "open output.txt file failed" << endl;
	}
	string filename;
	string line;
	string content = "";
	if (ifile)
	{
		map<string, String2Json *>::iterator it;
		while (getline(ifile, line))
		{
			//line start with # is case number and case name
			//#1 login(format of the case number line, '#'+ number + ' ' + casename
			//string casenum, casename;
			if (line.size() > 1 && line[0] == '#') {
				if (!content.empty()) {
					if (it != m_funcmap.end()) {
						it->second->setResponse(content);
						temp = it->second->str2json();
						content = "";
						outfile << temp << "\n";
					}
				}
				outfile << line << "\n";
				get_case(line);
				it = m_funcmap.find(m_casename);
					
				if (it != m_funcmap.end()) {
					cout << "find case " << m_casename << endl;
				}
 				continue;
			}
			content += line;
			content += "\n";
		}
		if (!content.empty()  && it != m_funcmap.end()) {
			it->second->setResponse(content);
			temp = it->second->str2json();
			outfile << temp << "\n";
		}
		//content[content.size() - 1] = '\0';
		//cout << content <<"=="<< endl;
	}
	else
	{
		cout << "no such file" << endl;
	}
	outfile.close();
	return 0;
}

int String2JSONTest::testreport() {
	ifstream iout("./test/output.txt");
	ifstream igolden("./goldenfile/output.golden.txt");
	ofstream outfile("./test/report.txt", ios::app);
	string line1, line2;
	int count = 0;
	if (iout && igolden) {
		while (getline(iout, line1) && getline(igolden, line2)) {
			if (line1.compare(line2) == 0) {
				if (line1[0] == '#') {
					outfile << line1 << "\n";
				}
				else {
					outfile << "SUCCESS" << "\n";
				}
			}
			else {
				if (line1[0] == '#') {
					iout.close();
					igolden.close();
					outfile.close();
					return count;
				}				else {
					outfile << "FAILED" << "\n";
					count++;
				}
					
			}
		}
	}
	iout.close();
	igolden.close();
	outfile.close();
	return count;
}