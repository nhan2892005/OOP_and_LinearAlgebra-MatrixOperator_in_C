#ifndef SOLVEONEMATRIX_H
#define SOLVEONEMATRIX_H
#include "process.h"
#include "handleFile.h"
#include <functional>

void solveOne(    string ofilename,
                  vector<Matrix*> matrices,
                  unordered_map<string, int> MatrixName,
                  string Name,
                  string operatorSolve){
    fstream resultSolve(ofilename, ios::app);
    if (resultSolve.is_open())
    {
        auto it = MatrixName.find(Name);
        if (it != MatrixName.end()) {
            const int index = it->second;
            Matrix* matrix = new Matrix("ANS", 0, 0, vector<vector<double>>());
            *matrix = *matrices[index];
            if (operatorSolve == "det"){
                resultSolve << operatorSolve << "(" << Name << ")" << " = " << matrix->det() << endl;
            }
            else if (operatorSolve == "rank"){
                resultSolve << operatorSolve << "(" << Name << ")" << " = " << matrix->rank() << endl;
            }
            else if (operatorSolve == "trace"){
                resultSolve << Name << " = " << matrix->trace() << endl;
            }
            else if (operatorSolve == "transformEchelon"){
                *matrix = matrix->transformEchelon();
                matrix->getMatrix(ofilename);
            }else if (operatorSolve == "transpose"){
                *matrix = matrix->transpose();
                matrix->getMatrix(ofilename);
            }
            else{
                return;
            }
            delete matrix;
        }
    }
    else
    {
        return;
    }
}

void readInputSolveOne( string ifilename,
                        string ofilename,
                        vector<Matrix*> matrices,
                        unordered_map<string, int> MatrixName){
    ifstream needToSolve(ifilename);
    if (needToSolve.is_open())
    {  
        while (!needToSolve.eof())
        {
            string Name, operatorSolve;
            needToSolve >> Name >> operatorSolve;
            solveOne(ofilename, 
                     matrices, 
                     MatrixName, 
                     Name, 
                     operatorSolve);
        }
    }
    else
    {
        return;
    }
}

// HCMUT
// Check Done 11:41 23/01/2024

#endif /*SOLVEONEMATRIX_H*/