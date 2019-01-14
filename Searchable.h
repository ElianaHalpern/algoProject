//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SEARCHABLE_H
#define ALGOPROJECT_SEARCHABLE_H
#include "State.h"
#include <list>

using namespace std;

template<class T>
class Searchable {
public:
    State<T> *current;
    State<T> *start;
    State<T> *goal;

    void setStart(State<T> *start) {
        this->start = start;
    }

    void setGoal(State<T> *goal) {
        this->goal = goal;
    }

    virtual State<T> *getInitialState() = 0;

    virtual State<T> *getGoalState() = 0;

    virtual list<State<T> *> getAllPossibleStates(State<T> *s, char type) = 0;

    virtual State<T> *getCurrent() {
        return current;
    }

    virtual void setCurrVisited() {
        current->setVisited();
    }

    virtual bool getCurrVisited() {
        return current->getVisited();
    }

    virtual void setCurr(State<T> *curr) = 0;

    virtual double calculateHValue(State<T> *cur) = 0;
};
#endif //ALGOPROJECT_SEARCHABLE_H
