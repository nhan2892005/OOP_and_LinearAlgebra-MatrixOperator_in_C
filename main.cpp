/*
    *Solve Matrix

    *HO CHI MINH CITY UNIVERSTY OF TECHNOLOGY
    *FACULTY OF COMPUTER SCIENCE AND ENGINEERING
    *Author: 
        NGUYEN PHUC NHAN (Founder)
*/

#include "process.h"
// Các hàm được sử dụng để tính toán ma trận
/*
    //Các hàm lấy dữ liệu ma trận
    getname: lấy tên ma trận (string getName())                     success
    getrow: lấy số hàng (int getRow())                              success
    getcol: lấy số cột (int getCol())                               success
    getmatrix: lấy ma trận (vector<vector<int>> getMatrix())        success

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
    transpose: chuyển vị ma trận (Matrix transpose())
    trace: tính đường chéo chính (double trace())
    operator +: cộng hai ma trận (Matrix operator +())
    operator -: trừ hai ma trận (Matrix operator -())
    operator *: nhân hai ma trận (Matrix operator *())
    operator *: nhân ma trận với một số thực (Matrix operator *())
    operator =: gán ma trận (Matrix operator =())
    operator ^: lũy thừa ma trận (Matrix operator ^())
    print: in ma trận (void print())
    identity: tạo ma trận đơn vị (Matrix identity())
*/

#include "handleFile.h"
//readFileInit(filename, matrices): đọc file và lưu vào vector<Matrix*> matrices
//clearOldOutput(filename): xóa nội dung file cũ
//checkReadfile(bool isRead): kiểm tra đọc được file không
#include "SolveCheckMatrix.h"


int main(int argc, char* argv[]){
    
    //store Matrix
    vector<Matrix*> matrices;
    unordered_map<string, int> MatrixName;
////////////////////////////////////////////////////////////////////////
    //store file input
    string initFile = "insert-n-print-data/initMatrix.inp";
    string questionCheck = "check_matrix/want_to_check.inp";
    //store file output
    string printMatrix = "insert-n-print-data/printMatrix.out";
    string resultCheck = "check_matrix/result_of_check.out";
    //check input
    bool isRead = readFileInit(initFile, matrices, MatrixName);
    checkReadfile(isRead);
         isRead = readFile(questionCheck, resultCheck);
    checkReadfile(isRead);
    //Clear old output
    clearOldOutput(resultCheck);
    clearOldOutput(printMatrix);
                //Success check input & output
                //HCMUT 11:54 22/01/2024

    //Test Input (Done 11:56 22/01/2024)
    for (int i = 0; i < matrices.size(); i++) {
        matrices[i]->getMatrix(printMatrix);
    }
////////////////////////////////////////////////////////////////////// (HCMUT 12:19 23/01/2024)
    readInputCheck(questionCheck, 
                   resultCheck, 
                   matrices, 
                   MatrixName);

    Matrix* A = new Matrix("Ans",3,3,{{1,2,3},{4,5,6},{7,8,9}});
    *A = matrices[0]->operator+(*matrices[1]);
    A->getMatrix(printMatrix);
    return 0;
}