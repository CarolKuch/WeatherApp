#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "HttpConnector.h"
#include "CreateHttpAddress.h"
#include "JsonReader.h"


using namespace std;

static wstring GetACity();

HANDLE color;

int main()
{
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 10);
	cout << "=== WEATHER FORECAST ===" << endl << endl;
	
	//get a city name
	wstring city = GetACity();
	cout << endl;
	//create an url
	CreateHttpAddress createHttpAddress(city);
	string url = createHttpAddress.HttpConcate();
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

static wstring GetACity()
{
	wstring city;
	SetConsoleTextAttribute(color, 15);
	cout << "Enter city name: ";
	wcin >> city;
	return city;
}
