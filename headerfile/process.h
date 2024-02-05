#ifndef process_h
#define process_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Matrix 
{
    private:
        string nameofMatrix;
        int row;
        int col;
        vector<vector<double>> matrix;
    public:
        void rename(string name)
        {
            nameofMatrix = name;
        }
        Matrix(string name, int r, int c, vector<vector<double>> m)
            : nameofMatrix(name), row(r), col(c), matrix(m) {}
        void getName(string fileName)
        {
            ofstream file(fileName, ios::app);
            file << "Name: " << nameofMatrix << endl;
        }
        void getRow(string fileName)
        {
            ofstream file(fileName, ios::app);
            file << "Rows: " << row << endl;
        }
        void getCol(string fileName)
        {
            ofstream file(fileName, ios::app);
            file << "Column:" << col << endl;
        }
        void getMatrix(string fileName)
        {
            ofstream file(fileName, ios::app);
            getName(fileName);
            getRow(fileName);
            getCol(fileName);
            for (int i = 0; i < row; i++)
            {
                file << "    ";
                for (int j = 0; j < col; j++)
                {
                    if (matrix[i][j] - static_cast<int>(matrix[i][j]) == 0)
                    {
                        file << setw(8) << static_cast<int>(matrix[i][j]);
                    }
                    else
                    {
                        file << fixed << setprecision(3) << setw(8) << matrix[i][j];
                    }
                }
                file << endl;
            }
        }
           

        //check if the matrix is square
        bool isSquare()
        {
            return row == col;
        }
        //check if the matrix is diagonal (ma trận đường chéo)
        bool isDiagonal()
        {
            if (isSquare())
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if ((i != j) && (matrix[i][j] != 0))
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is identity
        bool isIdentity()
        {
            if (isDiagonal())
            {
                for (int i = 0; i < row; i++)
                {
                    if (matrix[i][i] != 1)
                    {
                        return false;
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is symmetric (ma trận đối xứng)
        bool isSymmetric()
        {
            if (isSquare())
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = i + 1; j < col; j++)
                    {
                        if (matrix[i][j] != matrix[j][i])
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is skew-symmetric (ma trận lệch xứng)
        bool isSkewSymmetric()
        {
            if (isSquare())
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = i + 1; j < col; j++)
                    {
                        if (matrix[i][j] != -matrix[j][i])
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is upper triangular
        bool isUpperTriangular()
        {
            if (isSquare())
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is lower triangular
        bool isLowerTriangular()
        {
            if (isSquare())
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = i + 1; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is orthogonal (ma trận chuyển vị A^T = A^-1)
        bool isOrthogonal()
        {
            if (isSquare())
            {
                if (isSymmetric())
                {
                    for (int i = 0; i < row; i++)
                    {
                        for (int j = 0; j < col; j++)
                        {
                            if (i != j)
                            {
                                if (matrix[i][j] != 0)
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                if (matrix[i][j] != 1)
                                {
                                    return false;
                                }
                            }
                        }
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is involutory (ma trận A^2 = I)
        bool isInvolutory()
        {
            if (isSquare())
            {
                if (isOrthogonal())
                {
                    for (int i = 0; i < row; i++)
                    {
                        if (matrix[i][i] != 1)
                        {
                            return false;
                        }
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is idempotent (ma trận luỹ đẳng A^2 = A)
        bool isIdempotent()
        {
            if (isSquare())
            {
                vector<vector<double>> temp(row, vector<double>(col, 0));
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        for (int k = 0; k < row; k++)
                        {
                            temp[i][j] += matrix[i][k] * matrix[k][j];
                        }
                    }
                }
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (temp[i][j] != matrix[i][j])
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //check if the matrix is nilpotent (ma trận bậc lũy thừa A^k = 0)
        bool isNilpotent()
        {
            if (isSquare())
            {
                vector<vector<double>> temp(row, vector<double>(col, 0));
                for (int i = 0; i < row; i++)
                {
                    temp[i][i] = 1;
                }
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col - 1; j++)
                    {
                        for (int k = 0; k < row; k++)
                        {
                            temp[i][j] += matrix[i][k] * temp[k][j];
                        }
                    }
                }
                for (int i = 0; i < row; i++)
                {
                    if (temp[i][col - 1] != 0)
                    {
                        return false;
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        //Check if the matrix is triangular (ma trận tam giác)
        bool isTriangular()
        {
            return (isUpperTriangular() || isLowerTriangular());
        }
        //Transpose of a matrix (ma trận chuyển vị A^T)
        Matrix transpose()
        {
            vector<vector<double>> temp(col, vector<double>(row, 0));
            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    temp[i][j] = matrix[j][i];
                }
            }
            return Matrix(nameofMatrix+"transpose", col, row, temp);
        }
        //Trace of a matrix (Vết của ma trận)
        double trace()
        {
            if (isSquare())
            {
                int temp = 0;
                for (int i = 0; i < row; i++)
                {
                    temp += matrix[i][i];
                }
                return temp;
            }
            else
            {
                return 0;
            }
        }
        //Operator with matrix

        //Addition of two matrices (Cộng hai ma trận)
        //If the two matrices are not the same size, print "Error!"
        //    and return a matrix with 0 row and 0 column
        Matrix operator+(const Matrix & m)
        {
            if ((row == m.row) && (col == m.col))
            {
                vector<vector<double>> temp(row, vector<double>(col, 0));
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        temp[i][j] = matrix[i][j] + m.matrix[i][j];
                    }
                }
                return Matrix("Ans", row, col, temp);
            }
            else
            {
                cout << "Error!" << endl;
                return Matrix("Ans", 0, 0, vector<vector<double>>(0, vector<double>(0, 0)));
            }
        }

        //Multiplication of a matrix with a number (Nhân ma trận với một số)
        Matrix operator*(double n)
        {
            vector<vector<double>> temp(row, vector<double>(col, 0));
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    temp[i][j] = matrix[i][j] * n;
                }
            }
            return Matrix("Ans", row, col, temp);
        }

        //Subtraction of two matrices (Trừ hai ma trận)
        //If the two matrices are not the same size, print "Error!"
        //    and return a matrix with 0 row and 0 column
        Matrix operator-(const Matrix & m)
        {
            if ((row == m.row) && (col == m.col))
            {
                vector<vector<double>> temp(row, vector<double>(col, 0));
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        temp[i][j] = matrix[i][j] - m.matrix[i][j];
                    }
                }
                return Matrix("Ans", row, col, temp);
            }
            else
            {
                cout << "Error!" << endl;
                return Matrix("Ans", 0, 0, vector<vector<double>>(0, vector<double>(0, 0)));
            }
        }

        //Multiplication of two matrices (Nhân hai ma trận)
        //If the two matrices don't have valid size, print "Error!"
        //    and return a matrix with 0 row and 0 column
        Matrix operator*(Matrix m)
        {
            if (col == 1 && row == 1){
                int temp = matrix[0][0];
                return m * temp;
            }
            if (m.row == 1 && m.col == 1){
                return (*this).operator*(m.matrix[0][0]);
            }
            if (col == m.row)
            {
                vector<vector<double>> temp(row, vector<double>(m.col, 0));
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < m.col; j++)
                    {
                        for (int k = 0; k < col; k++)
                        {
                            temp[i][j] += matrix[i][k] * m.matrix[k][j];
                        }
                    }
                }
                return Matrix("Ans", row, m.col, temp);
            }
            else
            {
                cout << "Error!" << endl;
                return Matrix("Ans", 0, 0, vector<vector<double>>(0, vector<double>(0, 0)));
            }
        }

        //Assignment operator (Toán tử gán)
        Matrix operator=(const Matrix & m)
        {
            nameofMatrix = m.nameofMatrix;
            row = m.row;
            col = m.col;
            matrix = m.matrix;
            return (*this);
        }

        Matrix operator/(Matrix m)
        {
            if (m.row == 1 && m.col == 1 && col ==1 && row == 1){
                return (*this).operator*(1/m.matrix[0][0]);
            }else{
                cout << "Error!" << endl;
                return Matrix("Ans", 0, 0, vector<vector<double>>(0, vector<double>(0, 0)));
            }
        }

        //Exponentiation of a matrix (Lũy thừa ma trận)
        //If the matrix is not square, print "Error!"
        //    and return a matrix with 0 row and 0 column
        Matrix operator^(const int & n)
        {
            if (isSquare())
            {
                if (n == 0)
                {
                    return identity(row);
                }
                else if (n > 0)
                {
                    Matrix temp = (*this);
                    for (int i = 1; i < n; i++)
                    {
                        temp = temp * (*this);
                    }
                    return temp;
                }
            }
            else
            {
                cout << "Error!" << endl;
                return Matrix("Ans", 0, 0, vector<vector<double>>(0, vector<double>(0, 0)));
            }
            return identity(row);
        }
        //Create Identity matrix (Tạo ma trận đơn vị)
        Matrix identity(int n)
        {
            vector<vector<double>> temp(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++)
            {
                temp[i][i] = 1;
            }
            return Matrix("Identity", n, n, temp);
        }

        //Transform to echelon form (Chuyển về dạng bậc thang)
        Matrix transformEchelon()
        {
            vector<vector<double>> temp(row, vector<double>(col, 0));
            temp = matrix;
    
            for (int k = 0; k < row; k++){
                // Find element != 0
                int i = k;
                while (i < row && temp[i][k] == 0){
                    i++;
                }
                if (i == row){
                    break;
                }
                if (i != k){
                    swap(temp[i], temp[k]);
                }
                double divNoChange = temp[k][k];
                for (int i = k; i < row; i++){
                    if (i !=  k && temp[i][k] != 0){
                        double divChange = temp[i][k];
                        for (int j = 0; j < col; j++){
                            temp[i][j] = temp[i][j] - temp[k][j] * (divChange/divNoChange);
                        }
                    }
                } 
            }
            return Matrix("Echelon form of " + nameofMatrix, row, col, temp);
        }
        double det() {
            if (isSquare()) {
                Matrix temp = transformEchelon();

                // Check for division by zero
                for (int i = 0; i < row; i++) {
                    if (temp.matrix[i][i] == 0) {
                        return 0;  
                    }
                }

                double determinant = 1;
                for (int i = 0; i < row; i++) {
                    determinant *= temp.matrix[i][i];
                }
                return determinant;
            } else {
                cout << nameofMatrix << " is not square matrix" << endl;
                return 0; 
            }
        }

        int rank() {
            Matrix temp = transformEchelon();
            int rank = 0;
            for (int i = 0; i < row; i++) {
                bool isZero = true;
                for (int j = 0; j < col; j++) {
                    if (temp.matrix[i][j] != 0) {
                        isZero = false;
                        break;
                    }
                }
                if (!isZero) {
                    rank++;
                }
            }
            return rank;
        }
        bool isInvertible() {
            return det() != 0;
        }
        Matrix inverse() {
            if (isInvertible()) {
                vector<vector<double>> temp(row, vector<double>(col, 0));
                temp = matrix;
                Matrix I = identity(row);
                //transform to echelon form both matrix and identity matrix
                for (int k = 0; k < row; k++){
                // Find element != 0
                    int i = k;
                    while (i < row && temp[i][k] == 0){
                        i++;
                    }
                    if (i == row){
                        break;
                    }
                    if (i != k){
                        swap(temp[i], temp[k]);
                        swap(I.matrix[i], I.matrix[k]);
                    }
                    double divNoChange = temp[k][k];
                    for (int i = 0; i < row; i++){
                        if (i !=  k && temp[i][k] != 0){
                            double divChange = temp[i][k];
                            for (int j = 0; j < col; j++){
                                temp[i][j] = temp[i][j] * divNoChange - temp[k][j] * divChange;
                                I.matrix[i][j] = I.matrix[i][j] * divNoChange - I.matrix[k][j] * divChange;
                            }
                        }
                    }
                }
                for (int i = 0; i < row; i++){
                    for (int j = 0; j < col; j++){
                        if (temp[i][i] != 0 || temp[i][i] != 1){
                                I.matrix[i][j] = I.matrix[i][j] / temp[i][i];
                        }
                    }
                } 
                return Matrix("Inverse of " + nameofMatrix, row, col, I.matrix);
            } else {
                cout << nameofMatrix << " is not invertible" << endl;
                return Matrix("Inverse of " + nameofMatrix, 0, 0, vector<vector<double>>(0, vector<double>(0, 0)));
            }
        }
};

// HCMUT
// Check Done 11:41 23/01/2024

#endif /* process_h */
