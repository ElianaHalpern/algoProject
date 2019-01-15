//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_DFS_H
#define ALGOPROJECT_DFS_H

#include "Searcher.h"

using namespace std;

template<class T>
class DFS : public Searcher<T> {
public:
    vector<State<T> *> search(Searchable<T> *searchable) override;

    int getNumberOfNodesEvaluated() override;

    double getCost() override;
};

#endif //ALGOPROJECT_DFS_H
