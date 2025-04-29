#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

#include "utils.h"
#include "textquery.h"
#include "queryresult.h"
void runQueries(std::ifstream &infile){
    TextQuery tq(infile); 
    while (true){
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s));
    }
}
int main(){
    /*int x = 4, y = 3;
    std::cout << "Add: " << MathUtils::add(x, y) << std::endl;
    std::cout << "Multiply: " << MathUtils::multiply(x, y) << std::endl;*/
    std::ifstream file("../test/the_old_man_and_the_sea.txt");
    if (!file.is_open()){
        std::cerr << "file open failed" << std::endl;
    }
    runQueries(file);
    return 0;
}
