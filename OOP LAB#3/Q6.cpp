#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> elements;

public:
    Matrix(int r, int c) : rows(r), cols(c), elements(r, vector<int>(c, 0)) {}

    int getRows() { 
	return rows; 
	}
  
    int getCols() {
		return cols; 
		}
	
	
    void setElement(int i, int j, int value) 
	{
        if (i >= 0 && i < rows && j >= 0 && j < cols) 
		{
            elements[i][j] = value;
        } else {
            cout << "Invalid index!\n";
        }
    }

    Matrix add(Matrix& other)
	{
        if (rows != other.getRows() || cols != other.getCols()) 
		{
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) 
		{
            for (int j = 0; j < cols; j++) 
			{
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix& other) 
	{
        if (cols != other.getRows()) 
		{
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.getCols());
        for (int i = 0; i < rows; i++)
			{
            for (int j = 0; j < other.getCols(); j++) 
			{
                for (int k = 0; k < cols; k++)
					{
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }

    void display()
	{
        for (const auto& row : elements) 
		{
            for (int val : row) 
			{
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    
    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(1, 0, 3);
    mat1.setElement(1, 1, 4);
    
    mat2.setElement(0, 0, 5);
    mat2.setElement(0, 1, 6);
    mat2.setElement(1, 0, 7);
    mat2.setElement(1, 1, 8);
    
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();
    
    Matrix sum = mat1.add(mat2);
    cout << "Sum of matrices:" << endl;
    sum.display();
    
    Matrix product = mat1.multiply(mat2);
    cout << "Product of matrices:" << endl;
    product.display();
    
    return 0;
}
