//This is program for calculate sum of two matrix or multiple of two matrix.
#include <iostream>
#include <vector>

using namespace std;
class Matrix {//This our matrix class that it has some member class
public:
	Matrix(int _row, int _col);//constractor
	void Set_matrix_num();
	Matrix operator+(const Matrix& b)const;//When we want to calculate sum of two object of Matrix class we can use this overloading.
	Matrix operator*(const Matrix& b)const;//When we want to calculate multiple of two object of Matrix class we can use this overloading.
	Matrix& operator=(const Matrix& b);//When we want to calculate attribute one object of Matrix class with another we can use this overloading.
	int Get_row()const { return row; }
	int Get_col()const { return col; }
	int Get_mat(int i, int j)const { return mat[i][j]; }
private:
	int row;
	int col;
	vector <vector <int>> mat;
};
Matrix::Matrix(int _row, int _col)
{
	row = _row;
	col = _col;
	mat.resize(row, vector <int>(col, 0));//Resizing 2d vector of object.
}
void Matrix::Set_matrix_num()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			cout << "please enter Deraye (" << i + 1 << ',' << j + 1 << ") :";
			cin >> mat[i][j];
		}

}
Matrix Matrix :: operator+(const Matrix& b)const
{
	Matrix result(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			result.mat[i][j] = mat[i][j] + b.mat[i][j];
	return result;
}
Matrix Matrix :: operator*(const Matrix& b)const
{
	Matrix result(row, b.Get_col());
	for (int i = 0; i < row; i++)
		for (int j = 0; j < b.Get_col(); j++)
			for (int k = 0; k < col; k++)
				result.mat[i][j] += mat[i][k] * b.mat[k][j];
	return result;
}
Matrix& Matrix :: operator=(const Matrix& b)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mat[i][j] = b.mat[i][j];
	return *this;
}
ostream& operator<<(ostream& out, const Matrix& a)
{
	for (int i = 0; i < a.Get_row(); i++)
	{
		for (int j = 0; j < a.Get_col(); j++)
			out << a.Get_mat(i, j) << ' ';
		out << endl;
	}
	return out;
}
int Menu()
{
	int choice;
	cout << " < Please chose the number > " << endl
		<< "1.Sum of two matrix" << endl
		<< "2.Multiple of two matrix" << endl
		<< "3.Exit " << endl;
	cin >> choice;
	return choice;
}
int main()
{
	int iA, jA, iB, jB;
	int choicemenu = Menu();
	system("cls");
	switch (choicemenu)
	{
	case (1):
		cout << "Please enter row of A matrix : ";
		cin >> iA;
		cout << "Please enter col of A matrix : ";
		cin >> jA;
		cout << "Please enter row of B matrix : ";
		cin >> iB;
		cout << "Please enter col of B matrix : ";
		cin >> jB;
		if (iA == iB && jA == jB)
		{
			cout << "Now please enter deraye of A matrix :" << endl;
			Matrix A(iA, jA);
			A.Set_matrix_num();
			cout << "Now please enter deraye of B matrix :" << endl;
			Matrix B(iB, jB);
			B.Set_matrix_num();
			Matrix C = (A + B);
			cout << C;
		}
		else cout << "The rows and cols must be equl ! please try again later." << endl;
		break;
	case (2):
		cout << "Please enter row of A matrix : ";
		cin >> iA;
		cout << "Please enter col of A matrix : ";
		cin >> jA;
		cout << "Please enter row of B matrix : ";
		cin >> iB;
		cout << "Please enter col of B matrix : ";
		cin >> jB;
		if (iB == jA)
		{
			Matrix A(iA, jA);
			cout << "Now please enter deraye of A matrix :" << endl;
			A.Set_matrix_num();
			Matrix B(iB, jB);
			cout << "Now please enter deraye of B matrix :" << endl;
			B.Set_matrix_num();
			Matrix C = (A * B);
			cout << C;
		}
		else cout << "The col of A matrix must be equal to row of B matrix ! please try again later." << endl;
		break;
	}

	return 0;
}