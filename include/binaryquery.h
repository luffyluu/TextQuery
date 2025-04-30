#pragma once
#include "utils.h"
#include <string>
#include "query.h"
#include "query_base.h"
class QueryResult;
class TextQuery;

class BinaryQuery: public Query_base {
protected:
    // binary query needs to save the two operands for eval() and rep()
    BinaryQuery(const Query &l, const Query &r, std::string s):
          lhs(l), rhs(r), opSym(s) { }
    // rep() is easy, eval() will be defined in the non-virtual classes
    std::string rep() const { return "(" + lhs.rep() + " "
                                         + opSym + " "
                                         + rhs.rep() + ")"; }
    // save the two operands
    Query lhs, rhs;
    // because we define the rep() here, we need the operator (| or &)
    // why, because we can define the constructor and rep() here, those 
    // two members are almost the same among binary queries.
    std::string opSym;
};
