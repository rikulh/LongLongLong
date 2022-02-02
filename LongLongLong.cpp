#include "LongLongLong.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

LongLongLong::LongLongLong() {
    this->value.clear();
}

void LongLongLong::setDecimal(int c) {
    int dec = c;
    while (dec != 0){
        this->value.push_back((dec % 2 == 0) ? false : true);
        dec /= 2;
    }
}
void LongLongLong::setBi(string str) {
    reverse(str.begin(), str.end());
    for (int i=0;i<str.size();i++) {
        this->value.push_back((str.substr(i, 1) == "0") ? false : true);
    }
}

LongLongLong LongLongLong::ply(LongLongLong c) {
    LongLongLong result;
    for (int i=0;i<this->value.size();i++) {
        if (this->value[i]) {
            result = result.plus(c.twoTimes(i));
        }
    }
    return result;
}

LongLongLong LongLongLong::plus(LongLongLong ope) {
    LongLongLong result;
    vector<bool> a,b;
    a = this->value;
    b = ope.value;
    if (a.size()>b.size()) {
        for (int i = b.size();i < a.size();i++) {
            b.push_back(false);
        }
    }
    else if (b.size()>a.size()) {
        for (int i = a.size();i < b.size();i++) {
            a.push_back(false);
        }
    }
    bool up = false;
    for (int i = 0;i < a.size();i++) {
        result.value.push_back(a[i]^b[i]^up);
        up = (a[i]&&b[i]) || (up&&b[i]) || (a[i]&&up);
    }
    if (up) {
        result.value.push_back(true);
    }
    return result;
}

LongLongLong LongLongLong::minus(LongLongLong ope) {
    LongLongLong result;
    vector<bool> a,b;
    a = this->value;
    b = ope.value;
    if (a.size()>b.size()) {
        for (int i = b.size();i < a.size();i++) {
            b.push_back(false);
        }
    }
    else if (b.size()>a.size()) {
        for (int i = a.size();i < b.size();i++) {
            a.push_back(false);
        }
    }
    bool up = false;
    for (int i = 0;i < a.size();i++) {
        result.value.push_back(a[i]^b[i]^up);
        up = (a[i]&&b[i]) || (up&&b[i]) || (a[i]&&up);
    }
    if (up) {
        result.value.push_back(true);
    }
    return result;
}

LongLongLong LongLongLong::twoTimes(int times) const {
    LongLongLong result;
    for (int i=0;i<times;i++) {
        result.value.push_back(false);
    }
    for (int i=0;i<this->value.size();i++) {
        result.value.push_back(this->value[i]);
    }
    return result;
}
string LongLongLong::toBiString() {
    string str;
    for (int i=0;i<this->value.size();i++) {
        str += this->value[i] ? "1" : "0";
    }
    reverse(str.begin(), str.end());
    return str;
}
string LongLongLong::toDecString() {
    string decimal;
    vector<string> binaries;
    vector<int> decimals;
    string binary = this->toBiString();
    reverse(binary.begin(),binary.end());
    while(this->value.size() % 8 != 0) {
        value.push_back(false);
    }
    for (int i = 0;i < (int)(this->value.size() / 8);i++) {
        binaries.push_back(binary.substr(i*8,8));
        reverse(binaries[i].begin(), binaries[i].end());
        decimals.push_back(stoi(binaries[i],nullptr,2));
    }
    reverse(decimals.begin(),decimals.end());
    vector<int> filled(decimals.size(),0);
    while (decimals != filled) {
        int prev = decimals[0] % 10;
        decimals[0] = (int)(decimals[0] / 10);
        for (int i = 1;i < binaries.size();i++) {
            prev = prev * std::pow(2,8) + decimals[i];
            decimals[i] = (int)(prev / 10);
            prev = prev % 10;
        }
        decimal += to_string(prev);
    }
    reverse(decimal.begin(),decimal.end());
    return decimal;
}
LongLongLong LongLongLong::pow(int times) {
    LongLongLong current = *this;
    LongLongLong result;
    result.setBi("1");
    LongLongLong powa;
    powa.setDecimal(times);
    vector<bool> pows = powa.value;
    for (int i = 0;i < pows.size();i++) {
        if (pows[i]) {
            result = current.ply(result);
        }
        current = current.ply(current);
    }
    return result;
}