//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SOLVERHANDLER_H
#define ALGOPROJECT_SOLVERHANDLER_H

#include <string>
#include "Solver.h"
#include "Point.h"
#include "Searcher.h"
#include "Lexer.h"
#include "MatrixSearchable.h"

class SolverHandler : public Solver {
    Searcher<Point> *searcher;
    Lexer *lex;
public:
    SolverHandler(Searcher<Point> *searcher1) {
        this->searcher = searcher1;
    }

    string getSolution(string problem) {
        vector<vector<double> > vec = this->lex->splitByLines(problem, ',');
        vector<double> first = vec.at(0);
        auto *matrix = new MatrixSearchable(vec.size() - 2, first.size());
        matrix->setValues(vec);
        Searchable<Point> *searchable = matrix;
        vector<State<Point> *> solution = searcher->search(searchable);
        string final = "";
        for (int i = 0; i < solution.size() - 1; i++) {
            int x1 = solution.at(i)->getState()->getX();
            int y1 = solution.at(i)->getState()->getY();
            int x2 = solution.at(i + 1)->getState()->getX();
            int y2 = solution.at(i + 1)->getState()->getY();
            if (y1 < y2) {
                final += "Right, ";
                continue;
            }
            if (y1 > y2) {
                final += "Left, ";
                continue;
            }
            if (x1 < x2) {
                final += "Down, ";
                continue;
            }
            if (x1 > x2) {
                final += "Up, ";
                continue;
            }
        }
        final.erase(final.length() - 2, 2);
        delete matrix;
        return final;
    }
};
#endif //ALGOPROJECT_SOLVERHANDLER_H
