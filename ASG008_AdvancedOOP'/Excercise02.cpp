#include <iostream>

using namespace std;

class Matrix
{
private:
    int numCol, numRow;
    int **matrix;

public:
    Matrix()
    {
        matrix = nullptr;
        numCol = 0;
        numRow = 0;
    };

    Matrix(int m, int n)
    {
        numRow = m;
        numCol = n;

        matrix = new int *[numRow];
        for (int i = 0; i < numRow; i++)
        {
            matrix[i] = new int[numCol];
        }
    }

    void input()
    {
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                cout << "Nhap phan tu matrix[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(Matrix &other)
    {
        Matrix newMatrix(numRow, numCol);

        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                newMatrix.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return newMatrix;
    }

    Matrix operator-(Matrix &other)
    {
        Matrix newMatrix(numRow, numCol);

        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                newMatrix.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return newMatrix;
    }

    Matrix operator*(Matrix &other)
    {
        Matrix newMatrix(numRow, other.numCol);

        if(numCol != other.numRow)
        {
            return newMatrix;
        }

        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < other.numCol; j++)
            {
                newMatrix.matrix[i][j] = 0;
                for(int k =0; k < numCol; k++)
                {
                    newMatrix.matrix[i][j] += matrix[i][k] * other.matrix[k][j];               
                }
            }
        }
        return newMatrix;
    }

    Matrix operator/(Matrix &other)
    {
        Matrix newMatrix(numRow, numCol);

        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                newMatrix.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return newMatrix;
    }

};

int main()
{
    Matrix mt1(2,3), mt2(3,2);
    mt1.input();

    cout << "Ma tran" << endl;
    mt1.display();

    mt2.input();

    cout << "Ma tran" << endl;
    mt2.display();

    cout << "Cong 2 ma tran" << endl;

    Matrix mt3 = mt1 + mt2;
    mt3.display();

    cout << "Nhan 2 ma tran" << endl;

    Matrix mt4= mt1 * mt2;
    mt4.display();


    return 0;
}