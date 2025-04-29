#pragma once
#include <string>
#include <vector>
class MathUtils{
public:
    static int add(int a, int b); // add
    static int multiply(int a, int b); // multiply
};

inline std::string make_plural(size_t ctr, const std::string& word,
                              const std::string& ending="s"){
    return (ctr > 1) ? word + ending : word;
}
using line_no = std::vector<std::string>::size_type; 
