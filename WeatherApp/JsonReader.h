#pragma once
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class JsonReader
{
public:
	JsonReader(json j) { _j = j; }
	bool isCorrect();
	void readValue();
private:
	json _j;
	JsonReader();
	
};
