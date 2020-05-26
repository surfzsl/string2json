#include "String2JSON.h"
#include <iostream>

vector<string> String2Json::split(const string &str, const string &seperator) {
	string::size_type pos1, pos2;
	vector<string> result;
	pos2 = str.find(seperator);
	pos1 = 0;
	while (string::npos != pos2) {
		result.push_back(str.substr(pos1, pos2 - pos1));
		pos1 = pos2 + seperator.size();
		pos2 = str.find(seperator, pos1);
	}
	if (pos1 != str.length())
		result.push_back(str.substr(pos1));
	return result;
}

string Login2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";
	//login response message
	//SUCCESS:
	//(XXX)
	//DENIED:xxxxxxx
	if (strtmp.find("SUCCESS") != string::npos) {
		response += "\"SUCCESS\", \"domain\":";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			response += "\"" + vec[1] +"\"}";
		}
		else {
			response += "\"\"}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"DENIED\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	return response;
}

string Logout2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	if (strtmp.find("SUCCESS") != string::npos || strtmp.find("DENIED") != string::npos) {
		Login2Json json;
		json.setResponse(getResponse());
		return json.str2json();
	}
	response = getResponse();
	return response;
}

string Domainlist2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	
	
	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"domainlist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			for (; i < vec.size()-1; i++) {
				response += "\"" + vec[i] + "\",";
			}
			response += "\"" + vec[i] + "\"]}}";
		}
	}
	return response;
}