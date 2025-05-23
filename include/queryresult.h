#pragma once
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <memory>
#include <iterator>
#include "utils.h"
class QueryResult{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
    std::set<line_no>::iterator begin(){ return lines->begin(); }
    std::set<line_no>::iterator end(){ return lines->end(); }
    inline std::shared_ptr<std::vector<std::string>> get_file(){
         return file; }
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
