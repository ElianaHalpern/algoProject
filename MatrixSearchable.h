//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_MATRIXSEARCHABLE_H
#define ALGOPROJECT_MATRIXSEARCHABLE_H



#include <vector>
#include "Searchable.h"
#include "Point.h"
#include "State.h"

class MatrixSearchable: public Searchable<Point> {
    int row;
    int col;
    State<Point>* **matrix;
public:
    MatrixSearchable(int r, int c) {
        this->row = r;
        this->col = c;
        this->matrix = new State<Point>**[row];
        for(int i = 0; i < row; ++i) {
            matrix[i] = new State<Point> *[col];
        }
    }

    void setValues(vector<vector<double >> vec);
    State<Point>* getInitialState() override;

    State<Point>* getGoalState() override;

    list<State<Point>*> getAllPossibleStates(State<Point>* s, char type) override;

    void setCurr(State<Point>* curr);
    double calculateHValue(State<Point>* cur);

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
