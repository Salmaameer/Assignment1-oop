//
// Created by Salma ameer on 12/10/2022.
//

#include "Bigdecimalnt.h"

BigDecimalnt::BigDecimalnt(string decStr) {

vector<char> intNum;

        if (decStr[0] == '-' or decStr[0] == '+') {
           sign = decStr[0];
            for (int i = 1; i < decStr.size(); ++i) {
                intNum.push_back(decStr[i]);
            }

        }else {
            sign = '+';
            for (int i = 0; i < decStr.size(); ++i) {
                intNum.push_back(decStr[i]);
            }
        }

    for (int i = 0; i < intNum.size(); ++i) {
        cout << intNum[i] << " ";
    }


}

void BigDecimalnt::setSign(char s) {
sign = s;
}

char BigDecimalnt::getSign() {
    return sign;
}

bool BigDecimalnt::checkValid(string decstr) {
    
    return false;
}
