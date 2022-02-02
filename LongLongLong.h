#ifndef _LONGLONGLONG_H_
#define _LONGLONGLONG_H_

#include <vector>
#include <string>

using namespace std;

class LongLongLong {
public:
    LongLongLong();
    vector<bool> value;
    void setDecimal(int);
    void setBi(string);
    LongLongLong ply(LongLongLong);
    LongLongLong plus(LongLongLong);
    LongLongLong minus(LongLongLong);
    LongLongLong pow(int);
    LongLongLong twoTimes(int) const;
    string toBiString();
    string toDecString();
};

#endif