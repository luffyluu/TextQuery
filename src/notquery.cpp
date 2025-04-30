#include "notquery.h"
#include "utils.h"
#include "queryresult.h"
using namespace std;
// <file>	<right Query>	<~(right Query)>	why or why not adding
// line_0			r_0			*beg(2) != 0
// line_1			r_1			*beg(2) != 1
// line_2	x_0-begin()				*beg(2) == 2
// line_3			r_2			*beg(4) != 3
// line_4	x_1[-begin()]				*beg(4) == 4
// line_5	x_2[-begin()]				*beg(5) == 5
// line_6	end()[-begin()]	r_3			beg(p6) == end(p6)
// line_7			r_4			beg(p6) == end(p6)
QueryResult
NotQuery::eval(const TextQuery& text) const {
    // get the result of the right Query
    // if the right Query is a compound then it was calculated by recursing calls
    // if the right Query has a WordQuery the it was calculated by WordQuery
    auto result = query.eval(text);
    // result lines which is empty currently
    auto ret_lines = make_shared<set<line_no>> ();
    // begin and end of lines of the right Query
    auto beg = result.begin(), end = result.end();
    // total lines number of the Text
    auto sz = result.get_file()->size();
    // iterate the total set of the text line by line
    for (size_t n = 0; n != sz; ++n){
        // if the line is not the begin of the right Query or the right Query is empty
        if (beg == end || *beg != n)
           ret_lines->insert(n); // add the line number to the result
        // if the right Query is not empty and the begin line is the iterating line
        else if (beg != end)
            ++beg; // move the begin pointer to the next 
    }
    // return the result, rep() and pass the file vector
    return QueryResult(rep(), ret_lines, result.get_file());
}

