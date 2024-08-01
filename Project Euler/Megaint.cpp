#include "Megaint.h"

int Megaint::size() {

	return num.size();

}

std::vector<int> Megaint::getNum() {

	return num;

}

int Megaint::getIntAt(int index){

	return num[index];

}

void Megaint::push_back(int n) {

	num.push_back(n);

}

void Megaint::printString()
{
	
	for (int i = num.size() - 1; i > -1; i--) {

		cout << num[i];

	}

	cout << "\n";

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

int Megaint::sumDigits() {

	int sum = 0;

	for (int i = 0; i < num.size(); i++) {

		sum += num[i];

	}

	return sum;

}

void Megaint::add(Megaint a) {

	int carryOver = 0;
	while (num.size() < a.size()) {
		num.push_back(0);
	}

	for (int i = 0; i < a.size(); i++) {

		num[i] += a.getNum()[i] + carryOver;

		if (num[i] > 9) {
			carryOver = num[i] / 10;
			num[i] %= 10;
		}
		else {
			carryOver = 0;
		}

	}

	if (num.size() == a.size() && carryOver > 0) {
		num.push_back(carryOver);
	}
	else {
		num[num.size() - 1] += carryOver;
		if (num[num.size() - 1] > 9) {
			carryOver = num[num.size() - 1] / 10;
			num[num.size() - 1] %= 10;
		}
	}

	
	
}
