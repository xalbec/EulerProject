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