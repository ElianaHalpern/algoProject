//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_BESTFIRSTSEARCH_H
#define ALGOPROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"

using namespace std;

template<class T>
class BestFirstSearch : public Searcher<T> {
public:
    vector<State<T> *> search(Searchable<T> *searchable) override;

    int getNumberOfNodesEvaluated() override;

    double getCost() override;
};

#endif //ALGOPROJECT_BESTFIRSTSEARCH_H
