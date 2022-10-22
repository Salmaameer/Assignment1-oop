//Created By: Salma Ameer Jalal
//            Marwa Sameh Taha Mostafa
//            Shaimaa Mohammed Hassanin Afifi
// Created On: 
// Project Purpose: 
#include <iostream>
#include "BigDecimalInt.h"
using namespace std;

ostream& operator <<(ostream &out, BigDecimalInt b){
    for (int i = 0; i < b.intNum.size(); ++i) {
        cout << b.intNum[i];
    }
    return out;
}

int main() {
    BigDecimalInt num1("155567888880013"), num2("153");
    cout << num1 << "\n" << num2;



    return 0;
}
