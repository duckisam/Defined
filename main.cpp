#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <nlohmann\json.hpp>

using json = nlohmann::json;

std::string lowerString(std::string word);
std::string difine(std::string word);


int main(){
    std::cout << difine("World");
    return 0;
}

std::string difine(std::string word){
    word = lowerString(word);
    std::string fileName = "wordset-dictionary/data/" + std::string(1, word[0]) + ".json";
    std::ifstream data(fileName);
    
    json wordDict;

    data >> wordDict;
    
    std::string def = wordDict["world"]["meanings"][0]["def"];


    data.close();

    return def;
}


std::string lowerString(std::string word){
    for(std::__cxx11::basic_string<char>::size_type i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
    return word;
}