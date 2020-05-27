// WebServer.cpp 


#include <iostream>
#include <fstream>
#include <string>
#include"src/String2JSON.h"
using namespace std;

int main()
{
	ifstream ifile("./config/urls.txt");
	string filename;
	string line;

	//String2Json *str = new Login2Json();
	//String2Json *str = new Domainlist2Json();
	//String2Json *str = new PermissionVariable2Json();
	//String2Json *str = new ContentList2Json();
	//String2Json *str = new SubscriptionList2Json();
	//String2Json *str = new PublicationList2Json();
	//String2Json *str = new UserSubServiceList2Json();
	String2Json *str = new PeCheck2Json();
	//str->str2json();
	string content = "";

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
	str->setResponse("FAILURE:BAD_PESET");
	//str->setResponse(content);
	string response;
	response = str->str2json();
    std::cout << response<<endl;
}

