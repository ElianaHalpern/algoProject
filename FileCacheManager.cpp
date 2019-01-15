//
// Created by eliana on 1/14/19.
//

#include "FileCacheManager.h"

bool FileCacheManager::isExist(string problem) {
    try {
        pthread_mutex_lock(&mutexMap);
        solutions.at(problem);
        pthread_mutex_unlock(&mutexMap);
        return true;
    } catch (exception &e) {
        pthread_mutex_unlock(&mutexMap);
        return false;
    }
}

string FileCacheManager::popSolution(string problem) {
    string solution;
    try {
        pthread_mutex_lock(&mutexMap);
        solutions.at(problem) = solution;
        pthread_mutex_unlock(&mutexMap);
        return solution;
    } catch (exception &e) {
        pthread_mutex_unlock(&mutexMap);
        return nullptr;
    }
}

void FileCacheManager::addSolution(string problem, string solution) {
    pthread_mutex_lock(&mutexFile);
    this->cacheFile.open("cacheFile.txt");
    this->cacheFile << problem + "\n";
    this->cacheFile << solution + "\n";
    this->cacheFile.close();
    pthread_mutex_unlock(&mutexFile);
}