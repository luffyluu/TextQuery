#include "orquery.h"
#include <memory>
#include <set>
#include "utils.h"
#include "queryresult.h"
using namespace std;
QueryResult
OrQuery::eval(const TextQuery& text) const {
    // because OrQuery has two operands, we eval() them both
    // they can be either WordQuery or compounds
    auto right = rhs.eval(text), left = lhs.eval(text);

    // we use the lines set of the left result for a base
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());

    // we insert the lines of the right result to the base
    // insert will ignore the same value. we can also use:
    // std::merge(s1.begin(),s1.end(),s2.begin(),s2.end(),
    //       std::inserter(merged,merged.begin()));
    // std::set_union or set::merge(c++17) are also alternates
    ret_lines->insert(right.begin(), right.end());

    // now the result is sharing the same pointer with the left operand
    // we wont change any of the result, so it is safe.
    return QueryResult(rep(), ret_lines, left.get_file());
}
