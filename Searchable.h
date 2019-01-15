//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SEARCHABLE_H
#define ALGOPROJECT_SEARCHABLE_H

#include "State.h"

using namespace std;

template<class T>
class Searchable {
public:
    virtual void setValInMatrix(vector<vector<double >> vec) = 0;

    virtual list<State<T> *> getAllPossibleStates(State<T> *s) = 0;

    virtual double calculateHValue(State<T> *cur) = 0;
};

#endif //ALGOPROJECT_SEARCHABLE_H
