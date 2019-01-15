//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SEARCHABLE_H
#define ALGOPROJECT_SEARCHABLE_H

#include "State.h"

using namespace std;

template<class T>
class Searchable {
    State<Point> *current;
    State<Point> *start;
    State<Point> *goal;
public:
    virtual State<Point> *getCurrent() {
        return this->current;
    }

    virtual State<Point> *getInitialState() {
        return this->start;
    }

    virtual State<Point> *getGoalState() {
        return this->goal;
    }

    virtual bool getCurrVisited() {
        return current->getIsVisited();
    }

    void setCurrent(State<Point> *c) {
        this->current = c;
    }

    void setStart(State<Point> *s) {
        this->start = s;
    }

    void setGoal(State<Point> *g) {
        this->goal = g;
    }

    virtual void setCurrVisited() {
        this->current->setIsVisited();
    }

    virtual void setValInMatrix(vector<vector<double >> vec) = 0;

    virtual list<State<T> *> getAllPossibleStates(State<T> *s) = 0;

    virtual double calculateHValue(State<T> *cur) = 0;
};

#endif //ALGOPROJECT_SEARCHABLE_H
