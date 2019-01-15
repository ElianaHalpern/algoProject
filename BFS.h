//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_BFS_H
#define ALGOPROJECT_BFS_H

#include "Searcher.h"

using namespace std;

template<class T>
class BFS : public Searcher<T> {
public:
    vector<State<T> *> search(Searchable<T> *searchable) override;

    int getNumberOfNodesEvaluated() override;

    double getCost() override;
};

#endif //ALGOPROJECT_BFS_H
