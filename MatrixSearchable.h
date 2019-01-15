//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_MATRIXSEARCHABLE_H
#define ALGOPROJECT_MATRIXSEARCHABLE_H

#include <list>
#include <vector>
#include "Searchable.h"
#include "Point.h"
#include <complex>

class MatrixSearchable : public Searchable<Point> {
    State<Point> *current;
    State<Point> *start;
    State<Point> *goal;
    int row;
    int col;
    State<Point> ***matrix;
public:
    MatrixSearchable(int r, int c) {
        this->row = r;
        this->col = c;

        //create the matrix by the size we got
        this->matrix = new State<Point> **[row];
        for (int i = 0; i < row; ++i) {
            matrix[i] = new State<Point> *[col];
        }
    }

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

    void setValInMatrix(vector<vector<double >> vec) override;

    list<State<Point> *> getAllPossibleStates(State<Point> *s) override;

    double calculateHValue(State<Point> *cur) override;

    ~MatrixSearchable() {
        for (int j = 0; j < row; j++) {
            for (int i = 0; i < row; ++i) {
                delete matrix[j][i];
            }
            delete matrix[j];
        }
        delete matrix;
    }
};


#endif //ALGOPROJECT_MATRIXSEARCHABLE_H
