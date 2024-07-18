#include "Utilities.h"



int Utilities::ReverseInt(int num) {

    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;

}

bool Utilities::IsPrime(int num) {

    for (int i = 2; i < num/2; i++) {

        if (num % i == 0)
            return false;

    }

    return true;

}

std::vector<int> Utilities::PrimeFactorize(int num) {

    std::vector<int> primeFactors;

    for (int i = 2; i <= num; i++) {

        if (num % i == 0) {
            primeFactors.push_back(i);
            num /= i;
            i--;
        }
        
    }

    return primeFactors;

}

//Calculates number of primes based on the Prime Factors given in the PrimeFactorize function
int Utilities::CountDivisors(std::vector<int> factors) {

    int currentNum = factors[0];
    int divisorCount = 1;
    int duplicates = 1;

    for (int i = 1; i < factors.size(); i++) {

        if (factors[i] == currentNum) {
            duplicates++;
        }
        else {
            divisorCount *= (duplicates + 1);
            duplicates = 1;
            currentNum = factors[i];
        }

    }

    divisorCount *= (duplicates + 1);

    return divisorCount;

}