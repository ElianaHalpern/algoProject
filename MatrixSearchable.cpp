//
// Created by eliana on 1/14/19.
//
#include <complex>
#include "MatrixSearchable.h"

State<Point> *MatrixSearchable::getInitialState() {
    return this->start;
}

State<Point> *MatrixSearchable::getGoalState() {
    return this->goal;
}

void MatrixSearchable::setValues(vector<vector<double> > vec) {
    int startI = vec.at(vec.size() - 2).at(0);
    int startJ = vec.at(vec.size() - 2).at(1);
    int goalI = vec.at(vec.size() - 1).at(0);
    int goalJ = vec.at(vec.size() - 1).at(1);
    vec.erase(vec.end());
    vec.erase(vec.end());
    int i = 0, j = 0;
    for (vector<double> line: vec) {
        for (double num: line) {
            auto *p = new Point(i, j);
            matrix[i][j] = new State<Point>(num, p);
            if (i == startI && j == startJ) {
                setStart(matrix[i][j]);
            }
            if (i == goalI && j == goalJ) {
                setGoal(matrix[i][j]);
            }
            j++;
        }
        j = 0;
        i++;
    }
    this->current = matrix[0][0];
}

list<State<Point> *> MatrixSearchable::getAllPossibleStates(State<Point> *s, char type) {
    list<State<Point> *> adj;
    int x = s->getState()->getX();
    int y = s->getState()->getY();
    State<Point> *left = nullptr;
    State<Point> *right = nullptr;
    State<Point> *up = nullptr;
    State<Point> *down = nullptr;
    if (y - 1 >= 0 && matrix[x][y - 1]->getCurrCost() >= 0) {
        left = matrix[x][y - 1];
    }
    if (y + 1 <= col - 1 && matrix[x][y + 1]->getCurrCost() >= 0) {
        right = matrix[x][y + 1];
    }
    if (x - 1 >= 0 && matrix[x - 1][y]->getCurrCost() >= 0) {
        up = matrix[x - 1][y];
    }
    if (x + 1 <= row - 1 && matrix[x + 1][y]->getCurrCost() >= 0) {
        down = matrix[x + 1][y];
    }
    if (right != nullptr) {
        adj.push_back(right);
    }
    if (down != nullptr) {
        adj.push_back(down);
    }
    if (left != nullptr) {
        adj.push_back(left);
    }
    if (up != nullptr) {
        adj.push_back(up);
    }
    return adj;
}

void MatrixSearchable::setCurr(State<Point> *curr) {
    this->current = curr;
}

double MatrixSearchable::calculateHValue(State<Point> *cur) {
    State<Point> *goal = this->getGoalState();
    int xCur = cur->getState()->getX();
    int yCur = cur->getState()->getY();
    int xGoal = this->getGoalState()->getState()->getX();
    int yGoal = this->getGoalState()->getState()->getY();
    double disMan = abs(xCur - xGoal) +
                    abs(yCur - yGoal);
    double total = disMan + cur->getCurrCost() + cur->getCameFrom()->getTotalCost();
    return total;

}