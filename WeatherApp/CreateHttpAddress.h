#pragma once
#include <string>

using namespace std;

class CreateHttpAddress
{
	public:
		CreateHttpAddress(wstring city);
		string HttpConcate();

	private:
		void RemovePolishMarks();
		wstring _city;
		CreateHttpAddress() { }
};	
