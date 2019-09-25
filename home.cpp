#include <iostream>

#include <fstream>


using namespace std;


fstream inf, otf;

int main()
{
	
	setlocale(LC_ALL, ".1251");
	system("color 1F");
	
	int n = 17; int m = 6;
	int A[25][25],C[25], R[25]; 
	int p = 0;
	inf.open("data.txt", ios::in);
	if (!inf) return 0;

	for (int k = 0; k < n; k++) {
		R[k] = k + 1;
		cout << "\tRecord["<<R[k]<<"]\t";
		C[p] = 0;
		for (int i = 0; i < m; i++) {
			inf >> A[k][i]; C[p] += A[k][i];
			cout << A[k][i] << "\t";
		}
		cout << "C[" << k + 1 << "]=" << C[p] / m; p++;
		cout << "\n\n";
	}

	int max, g, sw;

	for (int k = 0; k < n - 1; k++) {
		max = C[k]; g = k;
		for (int i = k + 1; i < n; i++) {
			if (max < C[i]) {
				max = C[i];
				g = i;
			}
		}
		sw = C[k];
		C[k] = C[g];
		C[g] = sw;
		sw = R[k];
		R[k] = R[g];
		R[g] = sw;
	}
	cout << "\n\n";
	for (int k = 0; k < n; k++) {
		cout << "\tRecord[" <<R[k] <<"]\tC["<< k + 1 << "]=" << C[k]/m<<"\n";

	}
	inf.close();
	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
