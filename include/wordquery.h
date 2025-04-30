#pragma once
#include <string>
#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
class WordQuery: public Query_base{
    // Query will call eval and rep which are private.
    friend class Query;
    // A leaf node needs word only for TextQuery.query()
    WordQuery(const std::string &s): query_word(s) { }
    // eval the query and return the result
    QueryResult eval(const TextQuery &t) const
                     { return t.query(query_word); }
    // rep() is super easy since the word is been saved
    std::string rep() const { return query_word; }
private:
    // save the word for rep()
    std::string query_word;
};
