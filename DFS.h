//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_DFS_H
#define ALGOPROJECT_DFS_H

#include "Searcher.h"
#include "MatrixSearchable.h"
#include <queue>
#include "State.h"
#include "SolverHandler.h"


template <class T>
class DFS : public Searcher<T> {
private:
    int evaluated;
    double pathCost;

public:
    DFS(){
        evaluated =0;
    }
    //the matrix is our "searchable" in this case
    vector<State<T>*> search(Searchable<T>* searchable) override {
        searchable->setCurrVisited();
        vector<State<T>*> path;
        this->DFS_alg(searchable, searchable->getInitialState(), path);
        return path;
    }

    int DFS_alg(Searchable<T>* searchable, State<T>* curr, vector<State<T>*> &trace) {
        if(curr->equals(searchable->getGoalState())){
            evaluated++;
            while (curr->getParent() != nullptr) {
                trace.push_back(curr);
                pathCost += curr->getCost();
                curr = curr->getParent();
            }
            pathCost += curr->getCost();
            trace.push_back(curr);
            vector<State<T>*> back;
            for (int i = trace.size() - 1; i >= 0 ; i--) {
                back.push_back(trace.at(i));
            }
            trace = back;
            return 1;
        }
        curr->setVisited();
        evaluated++;
        searchable->setCurr(curr);
        list<State<T>*> succerssors = searchable->getAllPossibleStates(curr,'b');
        for (State<T>* state : succerssors) {
            bool visited = state->getVisited();
            if (!visited) {
                state->setParent(curr);
                if (DFS_alg(searchable, state, trace) == 1) {
                    return 1;
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }

    double getPathCost() {
        return pathCost;
    }

};

#endif //ALGOPROJECT_DFS_H
