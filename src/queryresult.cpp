#include "queryresult.h"
#include "utils.h"
using namespace std;

ostream& print(ostream& os, const QueryResult& qr){
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}
