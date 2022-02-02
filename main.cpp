#include <iostream>
#include <string>
#include <time.h>
#include "LongLongLong.h"

using namespace std;

int main (int argc,char** argv) {
    int an;
    int b;
    cout << "Number(decimal):";
    cin >> an;
    cout << "Pow(decimal):";
    cin >> b;
    LongLongLong a;
    a.setDecimal(an);
    clock_t start = clock();
    cout << a.pow(b).toDecString() << endl;
    clock_t end = clock();
    cout << (double)((end - start) / 10000) / 100 << "sec." << endl;
} 