#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int x;
	cout << "Enter x: ";
	cin >> x;
	int res = x;
	int zal = 0;
	while (x != 0)
	{
		res = x;
		zal = x % 2;
		x = x / 2;
		cout << res << " / " << 2 << " = " << x << " Залишок: " << zal << endl;
		
	}
}
