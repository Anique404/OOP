//#pragma once
#include <iostream>
using namespace std;

class Matrix {
private:
	
    int rows, cols;
    int **matrix;
    
    friend istream &operator>>(istream &input, Matrix &w);
    friend ostream &operator<<(ostream &output, const Matrix &w);

public:
	
    Matrix();
    Matrix(int r, int c);
    Matrix(int r, int c,int **array);
    Matrix(const Matrix &w);
    ~Matrix();

    const int& operator()(int row, int col) const;
    int& operator()(int row, int col);
    
    Matrix operator+(const Matrix &r) const;
    Matrix operator-(const Matrix &r) const;
    Matrix operator*(const Matrix &r) const;
    Matrix& operator=(const Matrix &r);
    Matrix& operator+=(const Matrix& r);
    Matrix& operator-=(const Matrix& r);
    Matrix& operator*=(const Matrix& r);

    
};

//#include"Matrix.h"

Matrix::Matrix() {
    rows = 0;
    cols = 0;
    matrix = NULL;
    cout << "The Default Constructor is called" << endl;
}

Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    cout << "The Parameterized Constructor with 2 parameter is called" << endl;
}

Matrix::Matrix(int r, int c,int **array){
	rows = r;
    cols = c;
    matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    for (int j=0;j<cols;j++){
    	matrix[i][j]=array[i][j];	
	}
    }
    cout << "The Parameterized Constructor with 3 parameter is called" << endl;
}

Matrix::Matrix(const Matrix &w) {
    
    rows=0;
    cols=0;
    matrix=NULL;
	
        rows = w.rows;
        cols = w.cols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = w.matrix[i][j];
            }
        }
        cout<<"Copy constructor is called"<<endl;
    }

Matrix::~Matrix() {
if(matrix!=NULL){
	
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    cout <<"Destructor is called"<<endl;
    	}


const int& Matrix::operator()(int row, int col) const {
    return matrix[row][col];
    }


int& Matrix::operator()(int row, int col) {
return matrix[row][col];
    }




Matrix Matrix::operator+(const Matrix &r) const {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix addition is not possible." << endl;
        return Matrix();
    }

    Matrix newmatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newmatrix.matrix[i][j] = matrix[i][j] + r.matrix[i][j];
        }
    }
    return newmatrix;
}

Matrix Matrix::operator-(const Matrix &r) const {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix subtraction is not possible." << endl;
        return Matrix();
    }

    Matrix newmatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newmatrix.matrix[i][j] = matrix[i][j] - r.matrix[i][j];
        }
    }
    return newmatrix;
}

Matrix Matrix::operator*(const Matrix &r) const {
    if (cols != r.rows) {
        cerr << "Matrix multiplication is not possible." << endl;
        return Matrix();
    }

    Matrix newmatrix(rows, r.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < r.cols; ++j) {
            newmatrix.matrix[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                newmatrix.matrix[i][j] += matrix[i][k] * r.matrix[k][j];
            }
        }
    }
    return newmatrix;
}

Matrix& Matrix::operator=(const Matrix &r) {
    if (this != &r) {
        if (matrix != NULL) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        rows = r.rows;
        cols = r.cols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = r.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& r) {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix addition is not possible." << endl;
    } else {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] += r.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& r) {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix subtraction is not possible." << endl;
    } else {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] -= r.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& r) {
    if (cols != r.rows) {
        cerr << "Matrix multiplication is not possible." << endl;
    } else {
        Matrix result(rows, r.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < r.cols; ++j) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * r.matrix[k][j];
                }
            }
        }
        *this = result;
    }
    return *this;
}


istream &operator>>(istream &input, Matrix &w) {
 if (w.matrix == NULL) {
        cout << "Enter the number of rows: ";
        input >> w.rows;
        cout << "Enter the number of columns: ";
		input >> w.cols;
		
      }
      
        w.matrix = new int *[w.rows];
        for (int i = 0; i < w.rows; ++i) {
            w.matrix[i] = new int[w.cols];
            for (int j = 0; j < w.cols; ++j) {
            	cout << "Enter elements for row " << i + 1 <<"and cols"<<j+1 <<": ";
                input >> w.matrix[i][j];
            }
        }
    
    return input;
    
}



ostream &operator<<(ostream &output, const Matrix &w) {
   for (int i = 0; i < w.rows; ++i) {
        for (int j = 0; j < w.cols; ++j) {
            output << w.matrix[i][j] << " ";
        }
        output << endl;
    }
    return output;
}



//#include"Matrix.h"

int main() {
	
	Matrix m;
	cout<<endl;
	cin>>m;
	cout<<endl;
	cout<<"********** Marix M ***********"<<endl;
	cout<<m;
	cout<<endl;
	
	Matrix m1(2,2);
	cout<<endl;
	cin>>m1;
	cout<<endl;
	cout<<"********** Marix M1 ************* "<<endl;
	cout<<m1;
	cout<<endl;
	
	cout<<"********** Copy Marix From M to M2 ***********"<<endl;
	cout<<endl;
	Matrix m2=m;
	cout<<endl;
	cout<<m2;
	cout<<endl;
	
    cout << "Element at (1, 1) of M2: " << m2(1, 1) << endl;
    cout<<endl;
    m2(1, 0) = 10;
    cout << "Modified element at m2(1, 0): " << m2(1, 0) << endl;
    cout<<endl;
    
    cout<<"*********** Modify Marix M2 *************"<<endl;
    cout<<endl;
    cout << m2;
    cout<<endl;
    
    cout<<"********** Addition of Matrix M and M1 **********"<<endl;
    cout<<endl;
    Matrix m3=m+m1;
    cout<<endl;
    cout<<m3;
    cout<<endl;
    
    
}





