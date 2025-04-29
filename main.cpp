#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string lowerString(std::string word);
std::string define(std::string word, int meaning);
std::string getSynonyms(std::string word, int meaning);
std::string getSpeachPart(std::string word, int meaning);
std::string getExample(std::string word, int meaning);
std::string handleArgs(std::string args, std::string word, int meaning);
std::vector<int> findAllIndexs(std::string, char letterToFind);
bool isInString(char c, std::string inString);

std::string path;

int main(int argc, char *argv[]){
    path = argv[0];
    std::vector ind = findAllIndexs(path, '\\');
    path = path.substr(0, ind[ind.size() - 2]);
    std::string word = argv[1];
    std::string toPrint;


    switch(argc){
        case 3:
            if(argv[2][0] == '-'){
                std::string arg = argv[2];
                toPrint = define(word, 0);
                toPrint += handleArgs(arg, word, 0);
            }else{
                std::string num = argv[2];
                toPrint = define(word, std::stoi(num));
            }
            break;
        case 4:
        if(argv[2][0] == '-'){
            std::string arg = argv[2];
            std::string num = argv[3];
            toPrint = define(word, std::stoi(num));
            toPrint += " " + handleArgs(arg, word, std::stoi(num));
        }else{
            std::string arg = argv[3];
            std::string num = argv[2];
            toPrint = define(word, std::stoi(num));
            toPrint += " " + handleArgs(arg, word, std::stoi(num));
        }
            break;

        default:
            if(argc > 3 && argc == 0){
                throw std::runtime_error("Invaild Arguments");
            }

            toPrint = define(word, 0);
            break;
    }


    std::cout << toPrint;
    return 0;
}

std::string define(std::string word, int meaning){
    word = lowerString(word);
    std::string fileName = path + "/wordset-dictionary/data/" + std::string(1, word[0]) + ".json";
    std::ifstream data(fileName);
    json wordDict;
    data >> wordDict;
    std::string def = wordDict[word]["meanings"][meaning]["def"];
    data.close();

    return "Definition: " + def + ".";
}

std::string getSynonyms(std::string word, int meaning){
    word = lowerString(word);
    std::string fileName = path + "/wordset-dictionary/data/" + std::string(1, word[0]) + ".json";
    std::ifstream data(fileName);
    json wordDict;
    data >> wordDict;
    
    std::vector<std::string> def = wordDict[word]["meanings"][meaning]["synonyms"];
    std::string synonyms = "";
    
    for(int i = 0; i < int(def.size()); i++){
        synonyms += def[i];
        if(int(def.size())  >= 2 && i != int(def.size()) - 1){
            synonyms += ", ";
            if(i == int(def.size()) -2){
                synonyms += "and ";
            }    
        }
        
    }
    data.close();
    return "Synonmys: " + synonyms + ".";
}

std::string getSpeachPart(std::string word, int meaning){
    word = lowerString(word);
    std::string fileName = path + "/wordset-dictionary/data/" + std::string(1, word[0]) + ".json";
    std::ifstream data(fileName);
    json wordDict;
    data >> wordDict;
    std::string sp = wordDict[word]["meanings"][meaning]["speech_part"];
    data.close();

    return "Part of Speach: " + sp + ".";
}

std::string getExample(std::string word, int meaning){
    word = lowerString(word);
    std::string fileName = path + "/wordset-dictionary/data/" + std::string(1, word[0]) + ".json";
    std::ifstream data(fileName);
    json wordDict;
    data >> wordDict;
    std::string example = wordDict[word]["meanings"][meaning]["example"];

    data.close();

    return "Example: " + example + ".";
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

std::vector<int> findAllIndexs(std::string word, char letterToFind){
    std::vector<int> temp = {};
    for(int i = 0; i < int(word.length()); i++){
        if(word[i] == letterToFind){
            temp.push_back(i);
        }

    }
    return temp;
}

std::string handleArgs(std::string args, std::string word, int meaning){
    std::string toReturn = "";
    for(int i = 1; i < int(args.length()); i++){
        switch(args[i]){
            case 's':
                toReturn += getSynonyms(word, meaning);
                break;
            case 'p':
                toReturn += getSpeachPart(word, meaning);
                break;
            case 'e':
            std::cout << "e case reached" << std::endl;
                toReturn += getExample(word, meaning);
                break;
            default:
                throw std::runtime_error(("Invaild argument: " + args[i]));
        }
        toReturn += " ";
    }
    return toReturn;
}