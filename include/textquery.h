#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <memory>
#include "utils.h"

class QueryResult;
class TextQuery{
public:
    TextQuery(std::ifstream &infile);
    // queryresult as a object, different from my defination
    QueryResult query(const std::string &s) const; 

private:
    // use shared_ptr for std::vector and std::set, diff from my def
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,
            std::shared_ptr<std::set<line_no>>> wm;
};
