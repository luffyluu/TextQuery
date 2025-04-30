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
#include "query.h"

void runQueries(std::ifstream &infile){
    TextQuery tq(infile); 
    while (true){
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s));
    }
}
void runQueries_test(std::ifstream &file){
    TextQuery tq(file);
    std::cout << "#######";
    Query q = Query("he");
    QueryResult result = q.eval(tq);
    print(std::cout, result);  

    std::cout << "#######";
    q = Query("you");
    result = q.eval(tq);
    print(std::cout, result);  

    std::cout << "#######";
    q = Query("he") & Query("you");
    result = q.eval(tq);
    print(std::cout, result);

    std::cout << "#######";
    q = Query("he") | Query("you");
    result = q.eval(tq);
    print(std::cout, result);

    std::cout << "#######";
    q = ~Query("he") & Query("you");
    result = q.eval(tq);
    print(std::cout, result);
    
    std::cout << "#######";
    q = ~Query("he") & Query("you") | Query("I");
    result = q.eval(tq);
    print(std::cout, result);
}
void runQueries_class(std::ifstream &file){
    TextQuery tq(file);
    while (true){
        std::cout << "enter words to look for, or q to quit\n";
        std::cout << "your word(s) should be seperate by & or precede by ~: ";
        std::string s;
        if(!(std::cin >> s) || s == "q") break;
        Query q = ~Query("he");
        QueryResult result = q.eval(tq);
        print(std::cout, result);  
    }
}
int main(){
    std::ifstream file("../test/the_old_man_and_the_sea.txt");
    if (!file.is_open()){
        std::cerr << "file open failed" << std::endl;
    }
    //runQueries(file);
    runQueries_test(file);
    return 0;
}
