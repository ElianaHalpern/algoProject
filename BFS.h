//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_BFS_H
#define ALGOPROJECT_BFS_H

#include "Searcher.h"

using namespace std;

template<class T>
class BFS : public Searcher<T> {
private:
    int evaluated;
    double cost;
public:

    BFS() {
        this->evaluated = 0;
        this->cost = 0;
    }

    vector<State<T> *> search(Searchable<T> *searchable) {
        list<State<T> *> myList;
        vector<State<T> *> path;

        //put the start state in the front of the list, mark as visited, and increase the evaluated
        myList.push_back(searchable->getInitialState());
        this->evaluated++;
        searchable->setCurrVisited();

        while (myList.size() > 0) {
            State<T> *n = myList.front();
            myList.pop_front();

            //check if we got to the goal of the path
            if (n->equals(searchable->getGoalState())) {
                evaluated++;
                while (n->getParent() != nullptr) {
                    trace.push_back(n);
                    pathCost += n->getCost();
                    n = n->getParent();
                }
                pathCost += n->getCost();
                trace.push_back(n);
                vector<State<T> *> back;
                for (int i = trace.size() - 1; i >= 0; i--) {
                    back.push_back(trace.at(i));
                }
                return back;
            }
            list<State<T> *> succerssors = searchable->getAllPossibleStates(n, 'b');
            for (State<T> *state : succerssors) {
                bool visited = state->getVisited();
                if (!visited) {
                    state->setVisited();
                    state->setParent(n);
                    openList.push_back(state);
                    evaluated++;
                    searchable->setCurr(state);
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() override {
        return this->evaluated;
    }

    double getCost() override {
        return this->cost;
    }
};

#endif //ALGOPROJECT_BFS_H
