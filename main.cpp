#include <iostream>
#include <string>
#include <time.h>
#include "LongLongLong.h"

using namespace std;

int main (int argc,char** argv) {
    string x;
    string n;
    cout << "Number(decimal):";
    cin >> x;
    cout << "Pow(decimal):";
    cin >> n;
    LongLongLong xn = LongLongLong(x,10);
    clock_t start = clock();
    cout << xn.pow(n).toDecString() << endl;
    clock_t end = clock();
    cout << (double)((end - start) / 10000) / 100 << "sec." << endl;
} 