//
// Created by Salma ameer on 12/10/2022.
//

#include "Bigdecimalnt.h"

BigDecimalnt::BigDecimalnt(string decStr) {
    if (checkValid(decStr)) {
        vector<char> intNum;

        if (decStr[0] == '-' or decStr[0] == '+') {
            sign = decStr[0];
            for (int i = 1; i < decStr.size(); ++i) {
                intNum.push_back(decStr[i]);
            }

        } else {
            sign = '+';
            for (int i = 0; i < decStr.size(); ++i) {
                intNum.push_back(decStr[i]);
            }
        }

        for (int i = 0; i < intNum.size(); ++i) {
            cout << intNum[i] << " ";
        }
    }else {cout << "Invalid number ;)";
    }


}

void BigDecimalnt::setSign(char s) {
sign = s;
}

char BigDecimalnt::getSign() {
    return sign;
}

bool BigDecimalnt::checkValid(string decstr) {
    regex temp("[-+]?[0-9]+");
    bool valid = regex_match(decstr,temp);
    if (valid){
        return true;
    }else return false;
}
