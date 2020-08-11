#pragma once
#include <curl/curl.h>
#include <string>

using namespace std;

class HttpConnector
{
public:
	static string getHttp(string url);
private:
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};
