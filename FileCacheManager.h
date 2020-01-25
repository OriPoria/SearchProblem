//
// Created by shmuelsuna on 13/01/2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_

#include <map>
#include "CacheManager.h"

class FileCacheManager : public CacheManager<string, string> {
    map<string, string> problem_fileName_map;//this map  is in ram, helps us fetch less times from files
    map<string, string> fileName_problom_map;
public:
    FileCacheManager();//CTOR

    //void loadFromFile();

    //void saveToFile();

    unsigned int fnv_hash(string key, int len);

    string getFileNameFromHash(string problom);

    void save(string problem, string solution);


    string getSolution(string problem);

    bool isThereASolution(string problem);

    void initializeMaps();


};

#endif //EX4__FILECACHEMANAGER_H_
