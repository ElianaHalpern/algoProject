//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_FILECHACHEMANAGER_H
#define ALGOPROJECT_FILECHACHEMANAGER_H




#include <fstream>
#include <iostream>
#include "CacheManager.h"
#include <map>
#include "MyParallelServer.h"

using namespace std;

class FileCacheManager : public CacheManager {
private:
    fstream cacheFile;
    map<string, string> solutions;

public:
    FileCacheManager() {
        cacheFile.open("cache.txt", fstream::in | fstream::out | fstream::app);
        string problem;
        string solution;
        while (getline(this->cacheFile, problem)) {
            getline(this->cacheFile, solution);
            solutions.insert(pair<string, string>(problem, solution));
        }
        cacheFile.close();
    }

    bool isExist(string problem) override;

    string popSolution(string problem) override;

    void addSolution(string problem, string solution) override;

    ~FileCacheManager() = default;

};




#endif //ALGOPROJECT_FILECHACHEMANAGER_H
