#include <iostream>
#include <fstream>
#include <string>



using namespace std;
fstream inf, otf;
int main()
{
	// генератор випадкових чисел
	
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	// розміри матрицi
	string P[100];
	int n, k, i;
	char z;

	inf.open("data.txt", ios::in);
	if (!inf) return 0;
	inf >> n;
	for (k=0; k <= n; k++) {
		getline(inf,P[k]);
	}



	inf.close();
	int a = 1;
	int b = n;
	
	int m = 0;
	do
	{
		if(m==0) system("cls");
		else cout << "\n\n";
		cout << "\n\n\tВам пропонується побажання на сьогоднi.\n\n";
		int g = a + rand() % (b - a + 1);
		cout << ".\t" << P[g];
		m++;
		if(m==3) cout << "\n\n\tБережiть себе. ";

		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
		if (m > 2) z = 'n';
	} while (z != 'n');

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}
