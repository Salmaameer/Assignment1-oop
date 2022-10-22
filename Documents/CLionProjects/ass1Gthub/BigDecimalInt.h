//Created By: Salma Ameer Jalal
//            Marwa Sameh Taha Mostafa
//            Shaimaa Mohammed Hassanin Afifi
// Created On:
// Project Purpose:

#ifndef ASS1GTHUB_BIGDECIMALNT_H
#define ASS1GTHUB_BIGDECIMALNT_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
class BigDecimalInt {
private:
    char sign;
    vector<int> intNum;

public:

    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt );
    bool checkValid(string decstr);
    void setSign(char s );
    char getSign();
    bool operator< (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);


};



#endif //ASS1GTHUB_BIGDECIMALNT_H
