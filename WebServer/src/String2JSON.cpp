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
	else {
		response = "{}";
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

string PermissionVariable2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";
	//permissionVariable response message
	//SUCCESS:
	//(XXX)
	//UNKNOWN
	if (strtmp.find("SUCCESS") != string::npos) {
		response += "\"SUCCESS\",  \"DATA\":{\"variable\": ";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			response += "\"" + vec[1] + "\"}}";
		}
		else {
			response += "\"\"}}";
		}
	}
	//else if (strtmp.find("UNKNOWN") != string::npos) {
	else {
		response += "\"UNKNOWN\"}";
	}
	return response;

}

string ContentList2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;

	response = "{\"STATUS\":";
	if (strtmp.find("SUCCESS") != string::npos) {
		response = "\"SUCCESS\", \"DATA\":{\"contentlist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			for (; i < vec.size() - 1; i++) {
				response += "\"" + vec[i] + "\",";
			}
			response += "\"" + vec[i] + "\"]}}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"DENIED\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string SubscriptionList2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"subscriptionlist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			for (; i < vec.size() - 1; i++) {
				response += "\"" + vec[i] + "\",";
			}
			response += "\"" + vec[i] + "\"]}}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos) {
		
		vec = split(strtmp, ":");
		response += "\"DENIED\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string PublicationList2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"publicationlist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			for (; i < vec.size() - 1; i++) {
				response += "\"" + vec[i] + "\",";
			}
			response += "\"" + vec[i] + "\"]}}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos) {

		vec = split(strtmp, ":");
		response += "\"DENIED\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string UserSubServiceList2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"usersubservicelist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			vector<string> v;
			for (; i < vec.size() - 1; i++) {
				v = split(vec[i], ":");
				if (v.size() > 1) {
					response += "{\"name\":\"" + v[0] + "\", \"value\":\""+ v[1] +"\"},";
				}
			}
			v = split(vec[i], ":");
			response += "{\"name\":\"" + v[0] + "\", \"value\":\"" + v[1] + "\"}";
			response += "]}}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos) {

		vec = split(strtmp, ":");
		response += "\"DENIED\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string PeCheck2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"pelist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			vector<string> v;
			for (; i < vec.size(); i++) {
				v = split(vec[i], ",");
				if (v.size() > 1) {
					response += "{\"name\":\"" + v[0] + "\", \"value\":[";
					int n = 1;
					for (; n < v.size() - 1; n++) {
						response += v[n] + ",";
					}
					response += v[n];
					response += "]},";
				}
			}
			response[response.size() - 1] = '\0';
			response += "]}}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos || strtmp.find("FAILURE") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"" + vec[0] + "\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string ItemCheck2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"itemlist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			vector<string> v;
			for (; i < vec.size(); i++) {
				v = split(vec[i], ",");
				if (v.size() > 1) {
					response += "{\"name\":\"" + v[0] + "\", \"value\":[";
					int n = 1;
					for (; n < v.size() - 1; n++) {
						response += v[n] + ",";
					}
					response += v[n];
					response += "]},";
				}
			}
			response[response.size() - 1] = '\0';
			response += "]}}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos || strtmp.rfind("FAILURE") != string::npos) {

		vec = split(strtmp, ":");
		response += "\"" + vec[0] + "\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string PublicationPeCheck::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"pelist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			vector<string> v;
			for (; i < vec.size(); i++) {
				v = split(vec[i], ",");
				if (v.size() > 1) {
					response += "{\"name\":\"" + v[0] + "\", \"value\":[";
					int n = 1;
					for (; n < v.size() - 1; n++) {
						response += v[n] + ",";
					}
					response += v[n];
					response += "]},";
				}
			}
			response[response.size() - 1] = '\0';
			response += "]}}";
		}
	}
	else if (strtmp.find("DENIED:") != string::npos || strtmp.find("FAILURE") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"" + vec[0] + "\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string PeToSubserviceList2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"mappingruleslist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			vector<string> v;
			for (; i < vec.size(); i++) {
				v = split(vec[i], ":");
				if (v.size() < 4)
					continue;
				response += "{\"pe\":\"" + v[0] +"\",";
				response += "\"subserviceType\":\"" + v[1] + "\",";
				response += "\"operator\":\"" + v[2] + "\",";
				response += "\"subserviceName\":\"" + v[3] + "\"},";
				}
			}
			response[response.size() - 1] = '\0';
			response += "]}}";
	}
	else if (strtmp.find("DENIED:") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"" + vec[0] + "\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string RepermissionTest2Json::str2json() {
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
		response += "\"SUCCESS\", \"RESULT\":";
		vec = split(strtmp, ":");
		if (vec.size() > 1) {
			response += "\"" + vec[1] + "\"}";
		}
		else {
			response += "\"\"}";
		}
	}
	else if (strtmp.find("FAILURE:") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"FAILURE\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string RepermissionReset2Json::str2json() {
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
		response += "\"SUCCESS\"}";
	}
	else if (strtmp.find("FAILURE:") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"FAILURE\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string DaemonStatus2Json::str2json() {
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
		response += "\"SUCCESS\", \"RESULT\":";
		vec = split(strtmp, ":");
		if (vec.size() > 1) {
			response += "\"" + vec[1] + "\"}";
		}
		else {
			response += "\"\"}";
		}
	}
	else if (strtmp.find("DENIED") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"DENIED\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string GetServiceAttributes2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"servicelist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 1) {
			int i = 1;
			vector<string> v;
			for (; i < vec.size(); i++) {
				v = split(vec[i], ":");
				if (v.size() < 5)
					continue;
				response += "{\"serviceID\":\"" + v[0] + "\",";
				response += "\"serviceName\":\"" + v[1] + "\",";
				response += "\"vendorService\":\"" + v[2] + "\",";
				response += "\"QoSForTheService\":\"" + v[3] + ":" + v[4] +"\",";
				response += "\"ServicePermissionType\":\"" + v[5] + "\"},";
			}
		}
		response[response.size() - 1] = '\0';
		response += "]}}";
	}
	else if (strtmp.find("DENIED:") != string::npos || strtmp.find("FAILURE") != string::npos) {
		vec = split(strtmp, ":");
		response += "\"" + vec[0] + "\",\"reason\":\"";
		if (vec.size() > 1) {
			response += vec[1] + "\"}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string GetAuthorizationDictionaryChecksum2Json::str2json() {
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
		response += "\"SUCCESS\", \"RESULT\":";
		vec = split(strtmp, ":");
		if (vec.size() > 1) {
			response += "\"" + vec[1] + "\"}";
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
	else {
		response = "{}";
	}
	return response;
}

string Statistics2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"statisticslist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 2) {
			int i = 2;
			vector<string> v;
			for (; i < vec.size() - 1; i++) {
				v = split(vec[i], ":");
				if (v.size() > 1) {
					response += "{\"name\":\"" + v[0] + "\", \"value\":\"" + v[1] + "\"},";
				}
			}
			v = split(vec[i], ":");
			response += "{\"name\":\"" + v[0] + "\", \"value\":\"" + v[1] + "\"}";
			response += "]}}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string ResetStatistics2Json::str2json() {
	string response, strtmp;
	strtmp = getResponse();
	vector<string> vec;
	if (strtmp.empty())
		return strtmp;
	response = "{\"STATUS\":";

	if (strtmp.find("SUCCESS") != string::npos) {
		response = "{\"STATUS\":\"SUCCESS\", \"DATA\":{\"statisticslist\": [";
		vec = split(strtmp, "\n");
		if (vec.size() > 2) {
			int i = 2;
			vector<string> v;
			for (; i < vec.size() - 1; i++) {
				v = split(vec[i], ":");
				if (v.size() > 1) {
					response += "{\"name\":\"" + v[0] + "\", \"value\":\"" + v[1] + "\"},";
				}
			}
			v = split(vec[i], ":");
			response += "{\"name\":\"" + v[0] + "\", \"value\":\"" + v[1] + "\"}";
			response += "]}}";
		}
	}
	else {
		response = "{}";
	}
	return response;
}

string CacheLoad2Json::str2json() {
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
		response += "\"SUCCESS\"}";
	}
	else {
		response = "{}";
	}
	return response;
}

string CacheDump2Json::str2json() {
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
		response += "\"SUCCESS\"}";
	}
	else {
		response = "{}";
	}
	return response;
}
