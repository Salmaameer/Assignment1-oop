#include "BigDecimalInt.h"
//Created By: Salma Ameer Jalal
//            Marwa Sameh Taha Mostafa
//            Shaimaa Mohammed Hassanin Afifi
// Created On: 
// Project Purpose: 


BigDecimalInt::BigDecimalInt(string decStr) {


        if (decStr[0] == '-' or decStr[0] == '+') {
           sign = decStr[0];
            for (int i = 1; i < decStr.size(); ++i) {
                intNum.push_back((decStr[i]) - '0');
            }

        }else {
            sign = '+';
            for (int i = 0; i < decStr.size(); ++i) {
                intNum.push_back(decStr[i] - '0');
            }
        }




}

void BigDecimalInt::setSign(char s) {
sign = s;
}

char BigDecimalInt::getSign() {
    return sign;
}

bool BigDecimalInt::checkValid(string decstr) {

    return false;
}
bool BigDecimalInt::operator < (BigDecimalInt anotherDec){
int sz = intNum.size();
int sz2 = anotherDec.intNum.size();
int diffSz = abs(sz - sz2);
// first case when both are with different signs
if(sign == '-' && anotherDec.sign == '+' ){
    return true;
}
else if(sign == '+' && anotherDec.sign == '-'){
    return false;
}
// second case when both are with positive sign
else if (sign == '+' && anotherDec.sign == '+'){
// make both with equal size to compare by adding ZERO from left
    vector<int> tempVec;
    if(sz > sz2){
        for(int i =0 ; i<diffSz ; i++){tempVec.push_back(0);}
        for(int i =0 ; i<sz ; i++){tempVec.push_back(anotherDec.intNum[i]);}
        anotherDec.intNum.clear();
        for(int i =0; i<sz ; i++){anotherDec.intNum.push_back(tempVec[i]);}
    }
   else if(sz2>sz){
        for(int i =0 ; i<diffSz ; i++){tempVec.push_back(0);}
        for(int i =0 ; i<sz2 ; i++){tempVec.push_back(intNum[i]);}
        intNum.clear();
        for(int i =0; i<sz2 ; i++){intNum.push_back(tempVec[i]);}
            }
// by this point , two vectors are in equal size to compare
tempVec.clear();
for (int i; i< max(sz, sz2);){
    if(intNum[i] > anotherDec.intNum[i]){return false ; break;}
    else if(intNum[i] < anotherDec.intNum[i]){return true ; break;}
    else{i++;}
}
}
else if(sign == '-' && anotherDec.sign == '-'){
    // make both with equal size to compare by adding ZERO from left
    vector<int> tempVec;
    if(sz > sz2){
        for(int i =0 ; i<diffSz ; i++){tempVec.push_back(0);}
        for(int i =0 ; i<sz ; i++){tempVec.push_back(anotherDec.intNum[i]);}
        anotherDec.intNum.clear();
        for(int i =0; i<sz ; i++){anotherDec.intNum.push_back(tempVec[i]);}
    }
   else if(sz2>sz){
        for(int i =0 ; i<diffSz ; i++){tempVec.push_back(0);}
        for(int i =0 ; i<sz2 ; i++){tempVec.push_back(intNum[i]);}
        intNum.clear();
        for(int i =0; i<sz2 ; i++){intNum.push_back(tempVec[i]);}
            }
// by this point , two vectors are in equal size to compare
tempVec.clear();
for (int i=0; i< intNum.size();){
    if(intNum[i] > anotherDec.intNum[i]){return true ; break;}
    else if(intNum[i] < anotherDec.intNum[i]){return false; break;}
    else{i++;}

}
}

}

BigDecimalInt BigDecimalInt:: operator- (BigDecimalInt anotherDec){
BigDecimalInt result("");
// fill with zeros
int sz = intNum.size();
int sz2 = anotherDec.intNum.size();
int diffSz = abs(sz - sz2);
 vector<int> tempVec;
    if(sz > sz2){
        for(int i =0 ; i<diffSz ; i++){tempVec.push_back(0);}
        for(int i =0 ; i<sz ; i++){tempVec.push_back(anotherDec.intNum[i]);}
        anotherDec.intNum.clear();
        for(int i =0; i<sz ; i++){anotherDec.intNum.push_back(tempVec[i]);}
    }
   else if(sz2>sz){
        for(int i =0 ; i<diffSz ; i++){tempVec.push_back(0);}
        for(int i =0 ; i<sz2 ; i++){tempVec.push_back(intNum[i]);}
        intNum.clear();
        for(int i =0; i<sz2 ; i++){intNum.push_back(tempVec[i]);}
            }
// at this point the length of both numbers is equal
// subtracting positive from positive
if(sign == '+' && anotherDec.sign == '+'){

    if(intNum < anotherDec.intNum ){
            result.sign ='-';
        //we want to make sure that intnnum.size is the size of both vectors after adding the zeros LATER
        for(int i =intNum.size()-1; i>=0; i--){
            int temp = anotherDec.intNum[i] - intNum[i];
        if(temp<0){
            temp+=10;
            anotherDec.intNum[i-1]-=1;
        }
                result.intNum.push_back(temp);

        }
    }
    else if(!(intNum < anotherDec.intNum)){
        result.sign = '+';
                for(int i =intNum.size()-1; i>=0; i--){
            int temp = intNum[i] - anotherDec.intNum[i];
        if(temp<0){
            temp+=10;
            intNum[i-1]-=1;
        }
                result.intNum.push_back(temp);

        }

    }
}
// subtracting negative from negative
else if(sign == '-' && anotherDec.sign == '-'){
        //which number without the sign is bigger
    if(intNum < anotherDec.intNum ){
        result.sign = '+';
          for(int i =intNum.size()-1; i>=0; i--){
            int temp = anotherDec.intNum[i] - intNum[i];
        if(temp<0){
            temp+=10;
            anotherDec.intNum[i-1]-=1;
        }
                result.intNum.push_back(temp);

        }

    }
    else if(!(intNum < anotherDec.intNum)){
        result.sign = '-';
           for(int i =intNum.size()-1; i>=0; i--){
            int temp = intNum[i] - anotherDec.intNum[i];
        if(temp<0){
            temp+=10;
            intNum[i-1]-=1;
        }
                result.intNum.push_back(temp);

        }
    }
    // HERE WE NEED THE OVERLOADING OF == OPERATOR
    else if(intNum == anotherDec.intNum)
    {result.sign = ' ';result.intNum.push_back(0);}
}
// when one number is positive and the other is negative
else if( sign == '-' && anotherDec.sign == '+'){
    result.sign = '-';
     for(int i =intNum.size()-1; i>=0; i--){
            int temp = anotherDec.intNum[i] + intNum[i];
            if(i!=0){
        if(temp>=10){
            temp-=10;
            anotherDec.intNum[i-1]+=1;
        }
                result.intNum.push_back(temp);

        }
        else if(i==0){
                int temp = anotherDec.intNum[i] + intNum[i];
                result.intNum.push_back(temp);}

     }}
else if(sign == '+' && anotherDec.sign == '-'){
          result.sign = '+';
     for(int i =intNum.size()-1; i>=0; i--){
            int temp = anotherDec.intNum[i] + intNum[i];
            if(i!=0){
        if(temp>=10){
            temp-=10;
            anotherDec.intNum[i-1]+=1;
        }
                result.intNum.push_back(temp);

        }
        else if(i==0){
                int temp = anotherDec.intNum[i] + intNum[i];
                result.intNum.push_back(temp);}

     }
}




reverse(result.intNum.begin(), result.intNum.end());
cout<< result.sign;
for(int i : result.intNum){cout<< i;}
return result;
}
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec) {

    BigDecimalInt result("");
    int sz = intNum.size();
    int sz2 = anotherDec.intNum.size();
    int diffSz = abs(sz - sz2);


// this condition to make them equal each other by fill the difference in sizes with zeros
    if (sz != sz2) {
        if (sz > sz2) {
            for (int i = 0; i < diffSz; ++i) {
                anotherDec.intNum.insert(anotherDec.intNum.begin(), 0);
            }

        } else if (sz2 > sz) {
            for (int i = 0; i < diffSz; ++i) {
                intNum.insert(intNum.begin(), 0);
            }
        }

    }

    int indexSum = 0 ,  carry = 0 ;;

    // signs conditions
    if (anotherDec.sign == '+' && sign == '+') {
        result.sign = '+'; // set the sign of the result

            for (int i = sz - 1; i >= 0; --i) {


                indexSum = intNum[i] + anotherDec.intNum[i] + carry;

                if (indexSum > 9) {

                    carry = indexSum / 10;
                    result.intNum.insert(result.intNum.begin(), (indexSum % 10));
                    if (i == 0 and  carry != 0  ) result.intNum.insert(result.intNum.begin() , carry);
                } else {
                    carry = 0;
                    result.intNum.insert(result.intNum.begin(), indexSum);
                }



        indexSum = 0;
    }




    } else if (anotherDec.sign == '-' && sign == '-') {

        result.sign = '-';

        for (int i = sz - 1 ; i >= 0; --i) {

            indexSum = intNum[i] + anotherDec.intNum[i] + carry;

            if (indexSum > 9) {
                carry = indexSum / 10;
                result.intNum.insert(result.intNum.begin(), (indexSum % 10));
            } else {
                carry = 0;
                result.intNum.insert(result.intNum.begin(), indexSum);
            }
            indexSum = 0;

        }


    } else if (sign == '+' && anotherDec.sign == '-'  ) {
        BigDecimalInt temp(""); // made this object to put the main obj in it to substitute

        for (int i = 0; i < intNum.size(); ++i) {
            temp.intNum.push_back(intNum[i]);
            //cout << temp.intNum[i] ;
        }

        if ( anotherDec.intNum < temp.intNum ){

            result.sign = '+';
            result = temp  - anotherDec;


        }else if (temp.intNum < anotherDec.intNum) {
            result.sign = '-';
            result = anotherDec - temp;

        } else{
            result.sign =' ';
            result.intNum = {0};
        }

    } else if (sign == '-' && anotherDec.sign == '+'  ) {                     //this statement if the both sign are +
        BigDecimalInt temp("") ;

        for (int i = 0; i < intNum.size(); ++i) {
            temp.intNum.push_back(intNum[i]);
        }

        if ( anotherDec.intNum < intNum ){

            result.sign = '-';
            result = temp  - anotherDec;


        } else if (intNum < anotherDec.intNum){
            result.sign = '+';
            result = anotherDec  - temp;
        } else{
            result.sign =' ';
            result.intNum = {0};
        }


    }
    cout<< result.sign;
    for(int i : result.intNum){cout<< i;}
   return result;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {
    bool flag = false;
    if(intNum.size() == anotherDec.intNum.size()){
        for (int i = 0; i < intNum.size(); ++i) {
            if(intNum[i] > anotherDec.intNum[i]){
                flag = true;
                break;
            }
            else if(intNum[i] < anotherDec.intNum[i]){
                flag = false;
                break;
            }
        }
    }
    if(intNum.size() > anotherDec.intNum.size() || flag)
        return true;
    else
        return false;
}
