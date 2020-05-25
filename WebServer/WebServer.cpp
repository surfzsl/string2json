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

	String2Json *str = new Login2Json();
	str->str2json();


	if (ifile)
	{
		while (getline(ifile, line))  
		{
			cout << line << endl;
		}
	}
	else 
	{
		cout << "no such file" << endl;
	}
    std::cout << "Hello World!\n";
}

