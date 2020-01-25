//
// Created by shmuelsuna on 13/01/2020.
//

#include <fstream>
#include <cstring>
#include <sstream>
#include "FileCacheManager.h"

#define FILE_OF_FILE_NAMES "fileOfFileNames_and_probloms.txt"

FileCacheManager::FileCacheManager() {
    initializeMaps();
}

string FileCacheManager::getSolution(string problem) {
    string solution;
    string name_of_file = this->problem_fileName_map[problem];

    string item_name;
    ifstream nameFileout;
    nameFileout.open(name_of_file + ".txt");
    string line;
    while (std::getline(nameFileout, line)) {
        solution += line;
        // TODO: assign item_name based on line (or if the entire line is
        // the item name, replace line with item_name in the code above)
    }

    return solution;
}


//void FileCacheManager::loadFromFile(){

//}


//void FileCacheManager::saveToFile() {

//}


void FileCacheManager::initializeMaps() {

    string problom;
    string name_of_file;
    bool flag = true;
    ifstream nameFileout;
    nameFileout.open(FILE_OF_FILE_NAMES);
    string line;
    while (std::getline(nameFileout, line)) {
        if (line == "") {
            flag = false;

            continue;
        }
        if (flag) {//reading problom
            problom += line + "\n";
        } else {
            name_of_file += line;
            this->problem_fileName_map[problom] = name_of_file;
            this->fileName_problom_map[name_of_file] = problom;
            problom = "";
            name_of_file = "";
            flag = true;
        }


    }

}

void FileCacheManager::save(string problem, string solution) {

    string name_of_file = getFileNameFromHash(problem);

    this->problem_fileName_map[problem] = name_of_file;//save to map
    this->fileName_problom_map[name_of_file] = problem;

    //write to file
    std::ofstream out(name_of_file + ".txt");
    out << solution;
    out.close();

    //write to file

    std::fstream out2;
    out2.open(FILE_OF_FILE_NAMES, fstream::app);
    out2 << problem << endl;
    out2 << name_of_file << endl;
    out2.close();

}

bool FileCacheManager::isThereASolution(string problem) {

    bool f = this->problem_fileName_map.find(problem) != this->problem_fileName_map.end();
    return f;
}

unsigned int FileCacheManager::fnv_hash(string key, int len) {
    unsigned int h = 2166136261;
    int i;

    for (i = 0; i < len; i++)
        h = (h * 16777619) ^ key[i];

    return h;
}

string FileCacheManager::getFileNameFromHash(string problem) {

    int n = problem.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, problem.c_str());

    unsigned int digit = fnv_hash(problem, n + 1);
    // declaring output string stream
    ostringstream str1;
    // Sending a number as a stream into output
    // string
    str1 << digit;
    // the str() coverts number into string
    string geek = str1.str();
    string file_name = "file" + geek;
    return file_name;
}
