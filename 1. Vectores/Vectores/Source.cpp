#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include<stdlib.h>
#include <chrono>
#include <algorithm>

using namespace std;

class Cexperimento
{
private:
	int sizeVector;
	int ncomparaciones;
	vector<double> a1;
	vector<vector<double>> b1;

public:

	Cexperimento(vector<double> a, vector<vector<double>> b, int _sizeVector, int _ncomparaciones)
	{
		a1 = a;
		b1 = b;
		sizeVector = _sizeVector;
		ncomparaciones = _ncomparaciones;
	}

	double distancia(vector<double> a, vector <double> b)
	{
		int suma = 0;

		for (int i = 0; i < sizeVector; i++)
		{
			int pot;
			pot = pow(b[i] - a[i], 2);
			suma = suma + pot;
		}

		return sqrt(suma);
	}


	void execute()
	{
		for (int i = 0; i < ncomparaciones; i++)
		{
			distancia(a1, b1[i]);
		}
	}

};

int f()
{
	int randnum;
	randnum = 1 + rand() % (1001 - 1);
	return randnum;
}

int main()
{
	// --------------------- VALORES ---------------------------
	int sizeVector = 50;
	int ncomparaciones = 50000;

	// ----------------- CREAMOS VARIABLES ----------------------
	vector<double> a(sizeVector);
	vector<vector<double>> b(ncomparaciones);

	std::generate(a.begin(), a.end(), f); // Damos valores a el vector a

	for (int i = 0; i < ncomparaciones; i++)
	{
		vector<double> aux(sizeVector);
		std::generate(aux.begin(), aux.end(), f);
		b[i] = aux;
	}

	// ----------------- INICIALIZAMOS EL OBJETO ----------------------
	Cexperimento exp1(a,b,sizeVector,ncomparaciones);

	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();

	exp1.execute();

	end = std::chrono::high_resolution_clock::now();
	int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); // duration is holding the elapsed time

	cout << duration << endl;

	return 0;
}