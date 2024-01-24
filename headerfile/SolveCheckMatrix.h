#ifndef SOLVECHECKMATRIX_H
#define SOLVECHECKMATRIX_H
#include "process.h"
#include "handleFile.h"
#include <functional>

unordered_map<string, function<bool(Matrix*)>> checkFunctions = {
    {"isSquare",          [](Matrix* matrix) { return matrix->isSquare();           }},
    {"isDiagonal",        [](Matrix* matrix) { return matrix->isDiagonal();         }},
    {"isIdentity",        [](Matrix* matrix) { return matrix->isIdentity();         }},
    {"isSymmetric",       [](Matrix* matrix) { return matrix->isSymmetric();        }},
    {"isSkewSymmetric",   [](Matrix* matrix) { return matrix->isSkewSymmetric();    }},
    {"isUpperTriangular", [](Matrix* matrix) { return matrix->isUpperTriangular();  }},
    {"isLowerTriangular", [](Matrix* matrix) { return matrix->isLowerTriangular();  }},
    {"isTriangular",      [](Matrix* matrix) { return matrix->isTriangular();       }},
    {"isOrthogonal",      [](Matrix* matrix) { return matrix->isOrthogonal();       }},
    {"isInvolutory",      [](Matrix* matrix) { return matrix->isInvolutory();       }},
    {"isNilpotent",       [](Matrix* matrix) { return matrix->isNilpotent();        }},
    {"isIdempotent",      [](Matrix* matrix) { return matrix->isIdempotent();       }},
    {"isTriangular",      [](Matrix* matrix) { return matrix->isTriangular();       }},
    {"isInvertible",      [](Matrix* matrix) { return matrix->isInvertible();       }} 
};

void solveProblem(string ofilename,
                  vector<Matrix*> matrices,
                  unordered_map<string, int> MatrixName,
                  string Name,
                  string operatorCheck){
    fstream resultCheck(ofilename, ios::app);
    if (resultCheck.is_open())
    {
        auto it = MatrixName.find(Name);
        if (it != MatrixName.end()) {
            const int index = it->second;
            Matrix* matrix = matrices[index];

            auto checkFunction = checkFunctions.find(operatorCheck);
            if (checkFunction != checkFunctions.end() && 
                checkFunction->second(matrix)) {
                resultCheck << Name << " is " << operatorCheck << endl;
            } else {
                resultCheck << Name << " is not " << operatorCheck << endl;
            }
        }
    }
    else
    {
        return;
    }
}

void readInputCheck(string ifilename,
                    string ofilename,
                    vector<Matrix*> matrices,
                    unordered_map<string, int> MatrixName){
    ifstream needToCheck(ifilename);
    if (needToCheck.is_open())
    {  
        while (!needToCheck.eof())
        {
            string Name, operatorCheck;
            needToCheck >> Name >> operatorCheck;
            solveProblem(ofilename, 
                         matrices, 
                         MatrixName, 
                         Name, 
                         operatorCheck);
        }
    }
    else
    {
        return;
    }
}

// HCMUT
// Check Done 11:41 23/01/2024

<<<<<<< HEAD
#endif /*SOLVECHECKMATRIX_H*/
=======
#endif /*SOLVECHECKMATRIX_H*/
>>>>>>> refs/remotes/origin/main
