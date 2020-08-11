#include "CreateHttpAddress.h"

string CreateHttpAddress::HttpConcate(string city)
{
	return "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=e343961e1ef7641f85fcda1be77f9f11&units=metric";
}
