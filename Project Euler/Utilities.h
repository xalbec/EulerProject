#pragma once
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Utilities
{
public:
	static int ReverseInt(int num);
	static bool IsPrime(int num);
	static std::vector<int> PrimeFactorize(int num);
	static int CountDivisors(std::vector<int>);
};

