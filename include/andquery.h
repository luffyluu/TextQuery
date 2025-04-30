#pragma once
#include "binaryquery.h"
class Query;
class TextQuery;
class QueryResult;
//Query operator& (const Query&, const Query&);

// And is just like Or, see also OrQuery
class AndQuery: public BinaryQuery {
    friend Query operator& (const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
                         BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery&) const;
};
