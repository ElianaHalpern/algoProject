//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_LEXER_H
#define ALGOPROJECT_LEXER_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Lexer {
public:
    static const vector<vector<double>> splitByLines(string &s, const char &delimiter) {

        string buff{""};
        vector<vector<double>> matrixVec;
        vector<double> tempVec;

        for (auto n:s) {
            if (n == ' ' || (n == delimiter && buff.empty())) {
                continue;
            }
            //while n!=to the delimiter add to buffer
            if (n != delimiter) {
                buff += n;
                continue;
            }
            //if we finished reading a line
            if (n == '\n') {
                //if the first val is neg, make it a neg double
                if (buff[0] == '-') {
                    buff.erase(0, 1);
                    double num;
                    try {
                        num = -1 * stod(buff);
                    } catch (exception &e) {
                        cout << "a";
                    }
                    tempVec.push_back(num);
                    matrixVec.push_back(tempVec);
                    tempVec.clear();
                    buff = "";
                } else {
                    double num;
                    try {
                        num = stod(buff);
                    } catch (exception &e) {
                        cout << "a";
                    }
                    tempVec.push_back(num);
                    matrixVec.push_back(tempVec);
                    tempVec.clear();
                    buff = "";
                    continue;
                }
                //if we met a dlimiter
                //check if the first val is neg
            }
            if (buff[0] == '-') {
                buff.erase(0, 1);
                double num;
                try {
                    num = -1 * stod(buff);
                } catch (
                        exception &e
                ) {
                    cout << "a";
                }
                tempVec.push_back(num);
                buff = "";
                continue;
            }
            double num;
            try {
                num = stod(buff);
            } catch (exception &e) {
                cout << "a";
            }
            tempVec.push_back(num);
            buff = "";
        }
        return matrixVec;
    }
};

#endif //ALGOPROJECT_LEXER_H
