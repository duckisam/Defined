#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann\json.hpp>

using json = nlohmann::json;

std::string lowerString(std::string word);
std::string define(std::string word);
bool isInString(char c, std::string inString);

int main(int argc, char *argv[]){
    if(argc <= 1){
        throw std::runtime_error("No Word Given");
    }
    
    std::string word = argv[1];
    std::string toReturn = define(word);
    
    return 0;
}

std::string define(std::string word){
    word = lowerString(word);
    std::string fileName = "wordset-dictionary/data/" + std::string(1, word[0]) + ".json";
    std::ifstream data(fileName);
    json wordDict;
    data >> wordDict;
    std::string def = wordDict[word]["meanings"][0]["def"];
    data.close();

    return def;
}


std::string lowerString(std::string word){
    for(char& c : word){
        c = std::tolower(c);
    }
    return word;
}

bool isInString(char c, std::string inString){
    for(char i : inString){
        if(c == i){
            return true;
        }
    }
    return false;
}