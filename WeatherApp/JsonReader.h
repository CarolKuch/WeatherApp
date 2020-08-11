#pragma once
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class JsonReader
{
public:
	JsonReader(json j) { _j = j; }
	void readValue();
private:
	json _j;
	JsonReader();
	bool isCorrect();
};
