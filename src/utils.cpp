#include "../include/utils.h"
#include <memory>
#include "query.h"
#include "andquery.h"
#include "notquery.h"
#include "orquery.h"
#include "query_base.h"
using namespace std;
int MathUtils::add(int a, int b){
    return a + b;
}

int MathUtils::multiply(int a, int b){
    return a * b;
}
Query operator&(const Query &lhs, const Query & rhs){
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
Query operator~(const Query &operand){
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
Query operator|(const Query &lhs, const Query &rhs){
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
