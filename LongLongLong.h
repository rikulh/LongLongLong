#ifndef _LONGLONGLONG_H_
#define _LONGLONGLONG_H_

#include <vector>
#include <string>

using namespace std;

class LongLongLong {
public:
    LongLongLong();
    LongLongLong(string,int);
    vector<bool> value;
    LongLongLong ply(LongLongLong);
    LongLongLong plus(LongLongLong);
    LongLongLong minus(LongLongLong);
    LongLongLong pow(string);
    LongLongLong twoTimes(int) const;
    string toBiString();
    string toDecString();
};

#endif