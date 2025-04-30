#pragma once
#include <string>
#include <memory>
#include "query_base.h"
#include "query.h"
class QueryResult;
class TextQuery;
class NotQuery: public Query_base {
    // operator need to return the NotQuery to Query
    friend Query operator~(const Query &);
    // NotQuery needs the right Query besides ~ to get rep() and result of eval()
    NotQuery(const Query &q): query(q) { }
    // rep() is easy since we save the right Query besides ~
    std::string rep() const { return "~(" + query.rep() + ")"; }

    // eval is done by calc. the complement set of the right Query
    // TestQuery is passed from the Query who has this NotQuery
    QueryResult eval(const TextQuery&) const;
    // we save the right query for cap() and eval()
    Query query; // query is the Query besides ~
};
