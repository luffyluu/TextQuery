#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "query_base.h"
#include "queryresult.h"
#include "wordquery.h"
class TextQuery;
class Query{
    // friends because of the private constructor for other true querys beside wordquery
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    // interface to WordQuery
    inline Query(const std::string& s): q(new WordQuery(s)) { } 
    
    // only delegate true query's function - eval
    // notice that Query doesnot save TextQuery which was passed through the tree
    QueryResult eval(const TextQuery &t) const
                             { return q->eval(t); }
    // only delegate true query's function - rep 
    std::string rep() const { return q->rep(); }
private:
    // interface to other *Query
    Query(std::shared_ptr<Query_base> query): q(query) {}

    std::shared_ptr<Query_base> q; // true query is hidden here
};
std::ostream &
operator<<(std::ostream &, const Query &);
