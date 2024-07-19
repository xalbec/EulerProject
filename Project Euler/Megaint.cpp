#include "Megaint.h"

void Megaint::toString()
{
	
	for (int i = num.size() - 1; i > -1; i--) {

		cout << num[i];

	}

}

void Megaint::multiply(int m)
{
	int carryOver = 0;

	for (int j = 0; j < num.size(); j++) {

		num[j] *= m;
		num[j] += carryOver;
		

		if (num[j] > 9) {
			carryOver = num[j] / 10;
			num[j] %= 10;
		}
		else {
			carryOver = 0;
		}


	}

	for (int i = 0; carryOver > 0; i++) {
		num.push_back(carryOver);
		num[num.size() - 1] = carryOver % 10;
		carryOver /= 10;
	}

}
