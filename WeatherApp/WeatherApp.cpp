#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "HttpConnector.h"
#include "CreateHttpAddress.h"
#include "JsonReader.h"

using namespace std;

static string GetACity();

HANDLE color;

int main()
{
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 10);
	cout << "=== WEATHER FORECAST ===" << endl << endl;

	//get a city name
	string city = GetACity();
	cout << endl;
	//create an url
	string url = CreateHttpAddress::HttpConcate(city);
	//get a web response
	string answer = HttpConnector::getHttp(url);
	//string to json-object
	json j = json::parse(answer);

	JsonReader jsonReader(j);

	// get the weather info
	SetConsoleTextAttribute(color, 2);
	jsonReader.readValue();

	_getch();
	return 0;
}

static string GetACity()
{
	string city;
	SetConsoleTextAttribute(color, 15);
	cout << "Enter city name: ";
	cin >> city;
	return city;
}
