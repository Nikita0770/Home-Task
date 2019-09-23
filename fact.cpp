#include <iostream>
#include <fstream>
// додаткова бібліотека 
#include <time.h>
#include <cmath>

using namespace std;

fstream inf, otf;

int fact(int m);

int main()
{
	// генератор випадкових чисел
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	double a, b, x, y, h;
	//a = 0.5; b = 7.5;

	inf.open("data.txt", ios::in);
	if (!inf) {
		return 0;
	}

	otf.open("res.txt",ios::out);
	if (!otf) return 0;

	inf >> a;
	inf >> b;

	h = fabs(a - b) / 10;
	otf << "\t------------------------------------------1";
	for (x = a; x <= b+h; x += h) {
		y = expf(x);
		printf("\n\tx=%4.1f\ty=%12.8f",x,y);
		otf<<"\n\tx="<<x<<"\ty="<< y;

	}

	cout << "\n\n";
	//h = 0.15;
	inf >> h;
	otf << "\n\t------------------------------------------2";
	x = a;
	while (x <= b) {
		y = expf(x);
		printf("\n\tx=%4.1f\ty=%12.8f", x, y);
		x += h;
		otf << "\n\tx=" << x << "\ty=" << y;
	}

	otf.close();
	otf.flush();
	
	inf.close();


	cout << "\n\n";
	int n = 12; double sum = 1;

	for (x = a; x <= b+h; x += h) {
		for (int i = 1; i <= n; i++) {


			sum += powf(x,i) / fact(i);
		}
		printf("\n\tx=%4.1f\ty=%12.8f", x, sum);

	}

	cout << endl << endl << "\t";
	system("pause");
	return 0;
}




int fact(int m) {
	
	int res;

	if (m < 0) return 0;
	if (m == 1) return 1;
	else return m * fact(m - 1);
}
