//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_STATE_H
#define ALGOPROJECT_STATE_H

#include <list>

using namespace std;

template<class T>
class State {
    T *state;
    State<T> *cameFrom;
    double currCost;
    double totalCost;
    bool isVisited = false;
    double heuristicCost;
public:

    State(double cost, T *state) {
        this->currCost = cost;
        this->totalCost = cost;
        this->cameFrom = nullptr;
        this->state = state;
        this->heuristicCost = 0;
    }

    T *getState() {
        return this->state;
    }

    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    void setCameFrom(State<T> *parent) {
        this->cameFrom = parent;
    }

    bool equals(State<T> *s) {
        return this == s;
    }

    double getTotalCost() {
        return this->totalCost;
    }

    void setVisited() {
        this->isVisited = true;
    }

    bool getIsVisited() {
        return this->isVisited;
    }

    void setCurrCost(double x) {
        this->currCost = x;
    }

    double getCurrCost() {
        return this->currCost;
    }

    double getCost(State<T> *s) {
        return s->currCost;
    }

    void setTotalCost(double d) {
        this->totalCost += d;
    }

    double getHeuristicCost() {
        return this->heuristicCost;
    }

    void setHeuristicCost(double h) {
        this->heuristicCost = h;
    }

    ~State() {
        delete this->state;
    }
};

#endif //ALGOPROJECT_STATE_H
