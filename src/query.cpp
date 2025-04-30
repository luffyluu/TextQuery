#include "query.h"
#include "andquery.h"
std::ostream &
operator<<(std::ostream &os, const Query &query){
    return os << query.rep();
}

