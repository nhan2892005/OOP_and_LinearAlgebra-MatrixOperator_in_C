#ifndef handleFile_h
#define handleFile_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

//Initialize the matrix
int readFileInit(string filename, 
                 vector<Matrix*> &matrices, 
                 unordered_map<string, int> &MatrixName) {

    ifstream myFile(filename);
    int count = 0;
    if (myFile.is_open()) {
        while (!myFile.eof()) 
        {
            string matrixName;
            int row, col;
            myFile >> matrixName >> row >> col;
            MatrixName[matrixName] = count++;
            vector<vector<int>> matrix(row, vector<int>(col));
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    myFile >> matrix[i][j];
                }
            }
            matrices.push_back(new Matrix(matrixName, row, col, matrix));
        }
        myFile.close();
        return 1;
    }
    else return 0;
}

//Clear the old output file
void clearOldOutput(string filename){
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();
}

void checkReadfile(bool isRead){
    if (isRead){
        cout << "Read file successfully!" << endl;
    }
    else cout << "Read file failed!" << endl;
}

int readFile(string ifilename, string ofilename){
    ifstream needToCheck(ifilename);
    ofstream resultCheck(ofilename, ios::app);
    if (needToCheck.is_open() && resultCheck.is_open())
    {
        return 1;
    }
    else return 0;
}

#endif /* handleFile_h */