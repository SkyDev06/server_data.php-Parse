/*
Made By SkyDev#1111 (Adip
*/

#include <iostream>
#include <httplib.h>
#include <regex>

using namespace std;
using namespace httplib;

vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

int main() { //Copyright To SrMotion
	SetConsoleTitleA("server_data.php Reader In C++");
	Client cli("http://growtopia2.com");
	string y_oke;
	auto response = cli.Post("/growtopia/server_data.php");
	y_oke = response->body;
	string fnc = "|";
	vector<string> y = split(y_oke.c_str(), fnc);
	std::string strings(y[1].c_str());
	strings = std::regex_replace(strings, std::regex("\nport"), "");
	cout << "[LOGS]server_data.php Has Parse\n";
	cout << "[IP]" + strings + "\n";
	cout << "[PORT]" + to_string(stoi(y[2])) + "\n";
	system("PAUSE");
}