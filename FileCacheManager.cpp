//
// Created by eliana on 1/14/19.
//

#include "FileCacheManager.h"

#include "FileCacheManager.h"

//TODO: למה זה לא מקבל את המיוטקס
bool FileCacheManager::isExist(string problem) {
    try {
        pthread_mutex_lock(&mutex);
        solutions.at(problem);
        pthread_mutex_unlock(&mutex);
        return true;
    } catch (exception &e) {
        pthread_mutex_unlock(&mutex);
        return false;
    }
}

string FileCacheManager::popSolution(string problem) {
    string solution;
    pthread_mutex_lock(&mutex);
    solution = solutions.at(problem);
    pthread_mutex_unlock(&mutex);
    return solution;
}

void FileCacheManager::addSolution(string problem, string solution) {
    pthread_mutex_lock(&mutexFile);
    this->cacheFile.open("cache.txt");
    this->cacheFile << problem + "\n";
    this->cacheFile << solution + "\n";
    this->cacheFile.close();
    pthread_mutex_unlock(&mutexFile);
}