// WebServer.cpp 


#include <iostream>
#include <fstream>
#include <string>
#include"src/String2JSON.h"
#include "src/testcode/String2JSONTest.h"
using namespace std;

int main()
{
	ifstream ifile("./config/urls.txt");
	string filename;
	string line;
	ofstream ofile("./test/output.txt", ios::trunc);
	ofile.close();
	//String2JSONTest test;
	//String2Json *str = new Login2Json();
	//String2Json *str = new Domainlist2Json();
	//String2Json *str = new PermissionVariable2Json();
	//String2Json *str = new ContentList2Json();
	//String2Json *str = new SubscriptionList2Json();
	//String2Json *str = new PublicationList2Json();
	//String2Json *str = new UserSubServiceList2Json();
	//String2Json *str = new PeCheck2Json();
	//String2Json *str = new PeToSubserviceList2Json();
	//String2Json *str = new RepermissionTest2Json();
	//String2Json *str = new RepermissionReset2Json();
	//String2Json *str = new DaemonStatus2Json();
	//String2Json *str = new GetServiceAttributes2Json();
	//String2Json * str = new GetAuthorizationDictionaryChecksum2Json();
	//String2Json * str = new Statistics2Json();
	//String2Json * str = new CacheLoad2Json();
	//String2Json * str = new ItemToPe2Json();
	//str->str2json();
	//String2Json *str = test["login"];
	string content = "";
	/***
	if (ifile)
	{
		while (getline(ifile, line))  
		{
			content += line;
			content += "\n";
		}
		//content[content.size() - 1] = '\0';
		//cout << content <<"=="<< endl;
	}
	else 
	{
		cout << "no such file" << endl;
	}
	//str->setResponse("SUCCESS:");
	str->setResponse(content);
	string response;
	response = str->str2json();
    std::cout << response<<endl;
	
	***/
	String2JSONTest test;
	test.init();
	test.runtest();
}

