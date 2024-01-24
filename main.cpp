/*
    *Solve Matrix

    *HO CHI MINH CITY UNIVERSITY OF TECHNOLOGY
    *FACULTY OF COMPUTER SCIENCE AND ENGINEERING
    *Author: 
        NGUYEN PHUC NHAN (Founder)
*/

#include "headerfile/process.h"
/*
//Các hàm lấy dữ liệu ma trận
    getname: lấy tên ma trận (string getName())                     success
    getrow: lấy số hàng (int getRow())                              success
    getcol: lấy số cột (int getCol())                               success
    getmatrix: lấy ma trận (vector<vector<int>> getMatrix())        success
//Các hàm check ma trận
    isSquare: kiểm tra ma trận vuông (bool isSquare())
    isDiagonal: kiểm tra ma trận chéo (bool isDiagonal())
    isIdentity: kiểm tra ma trận đơn vị (bool isIdentity())
    isSymmetric: kiểm tra ma trận đối xứng (bool isSymmetric())
    isSkewSymmetric: kiểm tra ma trận chéo phụ (bool isSkewSymmetric())
    isUpperTriangular: kiểm tra ma trận tam giác trên (bool isUpperTriangular())
    isLowerTriangular: kiểm tra ma trận tam giác dưới (bool isLowerTriangular())
    *isTriangular: kiểm tra ma trận tam giác (bool isTriangular())
    isOrthogonal: kiểm tra ma trận trực giao A^T=A^-1 (bool isOrthogonal())
    isInvolutory: kiểm tra ma trận A^2=I (bool isInvolutory())
    isNilpotent: kiểm tra ma trận luỹ linh (bool isNilpotent())
    isIdempotent: kiểm tra ma trận luỹ đẳng (bool isIdempotent())
//Các hàm tính toán ma trận
    trace: tính đường chéo chính (double trace())
    operator+: cộng hai ma trận (Matrix operator +())
    operator-: trừ hai ma trận (Matrix operator -())
    operator*(n): nhân hai ma trận (Matrix operator *())
    operator*(Matrix): nhân ma trận với một số thực (Matrix operator *())
    operator=: gán ma trận (Matrix operator =())
    operator^: lũy thừa ma trận (Matrix operator ^())
    identity: tạo ma trận đơn vị (Matrix identity())
    **** Chưa xử lý input ****
*/

#include "headerfile/handleFile.h"
//readFileInit(filename, matrices): đọc file và lưu vào vector<Matrix*> matrices
//clearOldOutput(filename): xóa nội dung file cũ
//checkReadfile(bool isRead): kiểm tra đọc được file không
//readFile(ifilename, ofilename): kiểm tra đọc được file không

#include "headerfile/SolveCheckMatrix.h"
//readInputCheck(ifilename, ofilename, matrices, MatrixName): đọc file
//solveProblem(ofilename, matrices, MatrixName, Name, operatorCheck): xử lý kiểm tra

#include "headerfile/SolveOneMatrix.h"
//HCMUT 16:58 23/01/2024

int main(int argc, char* argv[]){
    
    //store Matrix
    vector<Matrix*> matrices;
    unordered_map<string, int> MatrixName;

////////////////////////////////////////////////////////////////////////
    //store file input
    string initFile = "insert-n-print-data/initMatrix.inp";
    //store file output
    string printMatrix = "insert-n-print-data/printMatrix.out";
    //check input
    bool isRead = readFileInit(initFile, matrices, MatrixName);
    checkReadfile(isRead);
    //Clear old output
    clearOldOutput(printMatrix);
    //Test Input (Done 11:56 22/01/2024)
    for (int i = 0; i < matrices.size(); i++) {
        matrices[i]->getMatrix(printMatrix);
    }
                                        //Success check input & output
                                        //HCMUT 11:54 22/01/2024
////////////////////////////////////////////////////////////////////// (HCMUT 12:19 23/01/2024)
    //store file input
    string questionCheck = "check_matrix/want_to_check.inp";
    //store file output
    string resultCheck = "check_matrix/result_of_check.out";
    //check input
    isRead = readFile(questionCheck, resultCheck);
    checkReadfile(isRead);
    //Clear old output
    clearOldOutput(resultCheck);
    //Test Check (Done 12:19 23/01/2024)
    readInputCheck(questionCheck, 
                   resultCheck, 
                   matrices, 
                   MatrixName);
                                        //Success check 
                                        //HCMUT 12:19 23/01/2024    
////////////////////////////////////////////////////////////////////// (HCMUT 15:28 23/01/2024)

    //store file input
    string inputSolveOneMatrix = "solve-one-matrix/input-matrix-need-to-solve.inp";
    //store file output
    string outputOneMatrixSolved = "solve-one-matrix/matrix-solved.out";
    //check input
    isRead = readFile(inputSolveOneMatrix, outputOneMatrixSolved);
    checkReadfile(isRead);
    //Clear old output
    clearOldOutput(outputOneMatrixSolved);
    readInputSolveOne(  inputSolveOneMatrix, 
                        outputOneMatrixSolved, 
                        matrices, 
                        MatrixName);
                                        //Success check 
                                        //HCMUT 23:21 23/01/2024
////////////////////////////////////////////////////////////////////// (HCMUT 23:22 23/01/2024)
// HCMUT
// Check Done 11:41 23/01/2024
    return 0;
}
