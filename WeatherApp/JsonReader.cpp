#include "JsonReader.h"
#include <iostream>

bool JsonReader::isCorrect()
{
	return (_j["cod"] == 200) ? true : false;
}

void JsonReader::readValue()
{
		cout << "Weahter in your city: " << endl << endl;
		cout << "County: " << _j["sys"]["country"] << endl;
		cout << "Temperature: " << _j["main"]["temp"] << "\370C" << endl;
		cout << "Description: " << _j["weather"][0]["description"] << endl;
		cout << "Pressure: " << _j["main"]["pressure"] << " hPa" << endl;
		cout << "Wind: " << _j["wind"]["speed"] << "m/s" << endl;
		cout << "Humidity: " << _j["main"]["humidity"] << " %" << endl << endl;
}
