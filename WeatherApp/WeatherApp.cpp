#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include "HttpConnector.h"
#include "CreateHttpAddress.h"
#include "JsonReader.h"


using namespace std;

static wstring GetACity();

int licznik;
HANDLE color;

int main()
{
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 10);
	cout << "=== WEATHER FORECAST ===" << endl << endl;
	
	int counter = 0;

	do
	{
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
		if (jsonReader.isCorrect() == true)
		{
			jsonReader.readValue();
			counter=4;
		}
		else
		{
			cout << "City doesn't exist..." << endl << endl;
			counter++;
		}
	} while (counter < 4);

	SetConsoleTextAttribute(color, 15);
	cout << "Press any key to exit.";
	_getch();
	return 0;
}

static wstring GetACity()
{
	wstring city;
	SetConsoleTextAttribute(color, 15);
	cout << "Enter city name: ";
	getline(wcin, city);
	return city;
}
