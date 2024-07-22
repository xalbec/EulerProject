#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Megaint
{

private:
	std::vector<int> num = {};

public:
	Megaint(int n) {

		for (int i = 0; n > 0; i++) {
			num.push_back(n % 10);
			n /= 10;
		}

	}
	
	void printString();
	void multiply(int m);
	void add(Megaint a);
	int sumDigits();

};

