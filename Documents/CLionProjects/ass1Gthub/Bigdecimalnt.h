//
// Created by Salma ameer on 12/10/2022.
//

#ifndef ASS1GTHUB_BIGDECIMALNT_H
#define ASS1GTHUB_BIGDECIMALNT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BigDecimalnt {
private:
    char sign;
public:

    BigDecimalnt(string decStr);
    BigDecimalnt(int decInt );
    bool checkValid(string decstr);
    void setSign(char s );
    char getSign();


};


#endif //ASS1GTHUB_BIGDECIMALNT_H
