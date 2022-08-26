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

	Cexperimento(int _sizeVector, int _ncomparaciones)
	{

		cout << "iniciando variables " << endl;
		sizeVector = _sizeVector;
		ncomparaciones = _ncomparaciones;

		cout << "sizeV: " << sizeVector << "  and comparations: " << ncomparaciones << endl;

		vector<double> a(sizeVector);
		vector<vector<double>> b(ncomparaciones);

		cout << "Dando valores " << endl;

		std::generate(a.begin(), a.end(), 10);

		/*

		for (int i = 0; i < ncomparaciones; i++)
		{
			vector<double> aux(sizeVector);
			std::generate(aux.begin(), aux.end(), f);
			b[i] = aux;
		}

		copy(a.begin(), a.end(), a1.begin());
		copy(b.begin(), b.end(), b1.begin());

		*/
	}

	int f()
	{
		int randnum;
		randnum = 1 + rand() % (1001 - 1);
		return randnum;
	}
};

int main() {

	int sizeVector = 2;
	int ncomparaciones = 1000;

	Cexperimento exp1(sizeVector, ncomparaciones);

	//exp1.execute();

	cout << "fin del programa" << endl;
	return 0;
}