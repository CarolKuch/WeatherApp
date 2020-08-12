#include "CreateHttpAddress.h"
#include <iostream>

CreateHttpAddress::CreateHttpAddress(wstring city)
{
	_city = city;
	RemovePolishMarks();
	HttpConcate();
}

string CreateHttpAddress::HttpConcate()
{
	wstring wAPI = L"http://api.openweathermap.org/data/2.5/weather?q=" + _city + L"&appid=e343961e1ef7641f85fcda1be77f9f11&units=metric";
	string API(wAPI.begin(), wAPI.end());
	return API;
}

void CreateHttpAddress::RemovePolishMarks()
{
	
	for (int i = 0; i < _city.length(); i++)
	{
		switch (_city[i])
		{
			case 165:
				_city[i] = 'a';
				break;
			case 134:
				_city[i] = 'c';
				break;
			case 169:
				_city[i] = 'e';
				break;
			case 136:
				_city[i] = 'l';
				break;
			case 228:
				_city[i] = 'n';
				break;
			case 162:
				_city[i] = 'o';
				break;
			case 152:
				_city[i] = 's';
				break;
			case 171:
				_city[i] = 'z';
				break;
			case 190:
				_city[i] = 'z';
				break;

			case 164:
				_city[i] = 'A';
				break;
			case 143:
				_city[i] = 'C';
				break;
			case 168:
				_city[i] = 'E';
				break;
			case 157:
				_city[i] = 'L';
				break;
			case 227:
				_city[i] = 'N';
				break;
			case 224:
				_city[i] = 'O';
				break;
			case 151:
				_city[i] = 'S';
				break;
			case 141:
				_city[i] = 'Z';
				break;
			case 189:
				_city[i] = 'Z';
				break;
		}
	}
}
