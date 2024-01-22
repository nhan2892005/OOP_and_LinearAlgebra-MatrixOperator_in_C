#include "process.h"
#include "handleFile.h"

int readFile(string ifilename, string ofilename){
    ifstream needToCheck(ifilename);
    ofstream resultCheck(ofilename);
    if (needToCheck.is_open() && resultCheck.is_open())
    {
        /*///////////////////////////////////////*
        while(!needToCheck.eof()){
            ;
        }
        //////////////////////////////////////*/
        needToCheck.close();
        resultCheck.close();
        return 1;
    }
    else return 0;
}