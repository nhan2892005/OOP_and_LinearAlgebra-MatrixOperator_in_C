#ifndef SolveOneMatrix_h
#define SolveOneMatrix_h

#include "process.h"
#include "handleFile.h"
#include <functional>

unordered_map<string, function<bool(Matrix*)>> checkFunctions = {
    {"transformEchelon",  [](Matrix* matrix) { return matrix->transformEchelon();   }},
    {"det",               [](Matrix* matrix) { return matrix->det();                }},
    {"rank",              [](Matrix* matrix) { return matrix->rank();               }},
    {"trace",             [](Matrix* matrix) { return matrix->trace();              }},
    {"transpose",         [](Matrix* matrix) { return matrix->transpose();          }},
    {"inverse",           [](Matrix* matrix) { return matrix->inverse();            }}
};

#endif /* SolveOneMatrix_h */