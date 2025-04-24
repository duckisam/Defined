#include <iostream>
#include <C:\curtis\Define\include\nlohmann\json.hpp>

using json = nlohmann::json;

std::string define(std::string word){
    return word;
}

int main(){
    std::cout << define("Hello");
    return 0;
}


