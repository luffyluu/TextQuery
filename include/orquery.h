#pragma once
#include "binaryquery.h"
class Query;
class QueryResult;
class TextQuery;

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    // only pass | to BinaryQuery to indicate it is an OrQuery
    OrQuery(const Query &left, const Query &right):
                  BinaryQuery(left, right, "|")  { }
    // eval() is called by the Query
    QueryResult eval(const TextQuery&) const;
};

