#include <iostream>
#include <vector>
using namespace std;

int fibonaciExp(int x)
{

	if (x == 1 || x == 0)
	{
		return x;
	}
	
	return fibonaciExp(x - 1) + fibonaciExp(x - 2);
}

int fibonaciLineal(int x)
{
	int a = 0;
	int b = 1;
	int c;

	for (int i = 0; i < x-1; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

void multiplicacionMatrizes(int matA[2][2], int matB[2][2], int matRes[2][2])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matRes[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				matRes[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}
}

void multiplicacionMatF(int matA[2][2], int matB[2][1], int matRes[2][1])
{	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matRes[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				matRes[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}
}

int fibonaciLogn(int n)
{
	// Multiplicar n-1 veces la matriz 
	int a[2][2] = { {0,1},
				    {1,1} };
	int b[2][2] = { {0,1},
				    {1,1} };
	int aRes[2][2];

	for(int contador = 0; contador < n - 2; contador++)
	{
		multiplicacionMatrizes(a,b,aRes);
		//colocamos el resultado de a x b en a
		for(int i = 0; i < 2;i++)
		{
			for(int j = 0; j < 2; j++)
			{
				a[i][j] = aRes[i][j]; 
			}
		}
	}

	// Mostramos MATRIX^N
	/*
	cout<<"Matriz Exponencial" << endl;
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// Hacemos la ultima multiplicacion:
	int matB[2][1] = { {0},
					   {1} };
	int matRes[2][1];

	multiplicacionMatF(a, matB, matRes);
	/*
	cout << "Matriz Resultante" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			cout << matRes[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return matRes[0][1];
}


int main()
{
	int numero = 8;

	cout << "--- Fibo - Exponencial ----" << endl;
	cout << fibonaciExp(numero) << endl;
	
	cout << "--- Fibo - Lineal ----"<< endl;
	cout << fibonaciLineal(numero) << endl;

	cout << "--- Fibo - log(n) ---" << endl;
	cout << fibonaciLogn(numero) << endl;

	return 0;
}