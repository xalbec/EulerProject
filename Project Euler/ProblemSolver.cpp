#include "ProblemSolver.h"

//Correct Solution
int ProblemSolver::Problem1() {

	int sum = 0;

	for (int i = 1; i < 1000; i++) {

		if (i % 3 == 0 || i % 5 == 0) {

			sum += i;

		}

	}

	return sum;

}

//Correct Solution
int ProblemSolver::Problem2() {

	int firstnum = 1;
	int secondnum = 1;
	int thirdnum = 0;
	int sum = 0;

	while (thirdnum < 4000000) {

		thirdnum = firstnum + secondnum;
		sum += thirdnum;
		firstnum = secondnum;
		secondnum = thirdnum;
		thirdnum = firstnum + secondnum;
		firstnum = secondnum;
		secondnum = thirdnum;
		thirdnum = firstnum + secondnum;
		firstnum = secondnum;
		secondnum = thirdnum;
	}

	return sum;

}

//Correct Solution
int ProblemSolver::Problem3() {

	//600851475143
	//This is a long long but "auto" will assess what type it would be best suited for and apply that.

	auto bigNum = 600851475143;
	int biggestFactor;

	for (int i = 2; bigNum != 1; i++) {

		if (bigNum % i == 0) {
			bigNum /= i;
			biggestFactor = i;
			i--;
		}

	}

	return biggestFactor;

}

//Correct Solution
int ProblemSolver::Problem4() {

	int possibleNum = 0;
	int biggestPal = 0;

	//Answer lies between 10,000 ~ 1,000,000
	for (int i = 999; i > 99; i--) {

		for (int j = 999; j > 99; j--) {

			possibleNum = i * j;
			if (possibleNum == Utilities::ReverseInt(possibleNum))
				if (biggestPal < possibleNum)
					biggestPal = possibleNum;

		}

	}

	return biggestPal;

}

//Correct Solution
int ProblemSolver::Problem6() {

	int sumOfSquares = 0;
	int squareOfSum = 0;

	for (int i = 1; i <= 100; i++) {

		sumOfSquares += i*i;
		squareOfSum += i;

	}

	return squareOfSum * squareOfSum - sumOfSquares;

}

//Correct Solution (0.39 seconds)
int ProblemSolver::Problem7() {

	int primeCount = 2;
	int biggestPrime = 0;
	int i = 1;

	
	while (primeCount < 10001) {

		//left prime
		if (Utilities::IsPrime(6 * i - 1)) {
			primeCount += 1;
			biggestPrime = 6 * i - 1;
		}
			
		if (primeCount == 10001)
			break;

		//right prime
		if (Utilities::IsPrime(6 * i + 1)) {
			primeCount += 1;
			biggestPrime = 6 * i + 1;
		}

		i++;
	}
	

	return biggestPrime;
}

//TODO: Incorrect Solution
int ProblemSolver::Problem10() {

	int sumOfPrimes = 5;
	int range = 2000000;

	for (int i = 1; i < 333333; i++) {

		if (Utilities::IsPrime(6 * i - 1)) {
			sumOfPrimes += 6 * i - 1;
		}

		if (Utilities::IsPrime(6 * i + 1)) {
			sumOfPrimes += 6 * i + 1;
		}

	}

	return sumOfPrimes;

}

//Correct Solution (0.001 seconds)
int ProblemSolver::Problem11() {

	string given = 
		"08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
		"49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
		"81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
		"52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
		"22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
		"24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
		"32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
		"67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
		"24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
		"21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
		"78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
		"16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
		"86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
		"19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
		"04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
		"88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
		"04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
		"20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
		"20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
		"01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 ";

	istringstream givenStream(given);

	int givenArr[20][20];
	int biggestProd = 0;
	int tempVar = 0;
	
	//Form the array
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {

			givenStream >> givenArr[i][j];

		}

	}

	//Check Rows
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 16; j++) {

			tempVar = givenArr[i][j] * givenArr[i][j + 1] * givenArr[i][j + 2] * givenArr[i][j + 3];
			if (tempVar > biggestProd)
				biggestProd = tempVar;

		}

	}

	//Check Columns
	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 20; j++) {

			tempVar = givenArr[i][j] * givenArr[i + 1][j] * givenArr[i + 2][j] * givenArr[i + 3][j];
			if (tempVar > biggestProd)
				biggestProd = tempVar;

		}

	}
	
	//Diagonals to the right "\"
	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			tempVar = givenArr[i][j] * givenArr[i + 1][j + 1] * givenArr[i + 2][j + 2] * givenArr[i + 3][j + 3];
			if (tempVar > biggestProd)
				biggestProd = tempVar;

		}

	}

	//Diagons to the left "/"
	for (int i = 3; i < 20; i++) {
	
		for (int j = 0; j < 16; j++) {

			tempVar = givenArr[i][j] * givenArr[i - 1][j + 1] * givenArr[i - 2][j + 2] * givenArr[i - 3][j + 3];
			if (tempVar > biggestProd)
				biggestProd = tempVar;

		}

	}

	return biggestProd;

}

//Correct Solution (0.072 seconds)
int ProblemSolver::Problem12() {

	int num = 28;
	for (int i = 8; Utilities::CountDivisors(Utilities::PrimeFactorize(num)) < 500; i++) {

		num += i;

	}
	
	return num;

}

//Correct Solution (0.459 seconds)
int ProblemSolver::Problem14() {

	int chainLength = 1;
	int maxChainLength = 1;
	int maxChainNum;
	long long n;
	
	for (int i = 1; i < 1000000; i++) {

		n = i;

		for (int j = 1; n > 1; j++) {

			if (n < 0) {
				cout << "Rollover Error!";
			}

			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = 3 * n + 1;
			}

			chainLength = j;

		}

		if (maxChainLength < chainLength) {

			maxChainLength = chainLength;
			maxChainNum = i;

		}
			
	}

	return maxChainNum;

}

//Correct Solution (0.005 seconds)
int ProblemSolver::Problem16() {

	//This is going to act as our big num that we can't directly calculate
	//Also pretend the array is set up like [5th, 4th, 3rd, 2nd, 1st, 0th] 
	std::vector<int> bigNum(302,0);
	bool carryOver = false;
	bigNum[0] = 1;

	for (int i = 0; i < 1000; i++) {

		for (int j = 0; j < bigNum.size(); j++) {

			bigNum[j] *= 2;
			if (carryOver) {
				bigNum[j] += 1;
				carryOver = false;
			}
			if (bigNum[j] > 9) {
				bigNum[j] -= 10;
				carryOver = true;
			}


		}

	}

	int sum = 0;

	for (int i = 0; i < bigNum.size(); i++) {
		sum += bigNum[i];
	}

	return sum;

}