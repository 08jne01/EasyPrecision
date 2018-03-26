#include "Header.h"

int main()

{
	pNum p, k, h;
	double x = 10.1;
	double y = 0.2;

	p.init("123456789", x, 3);
	k.init("0.00000000000000000000000000000001", y, 2);

	p.print();
	k.print();

	//char c = '.';

	//int m = (int)(c - '0');

	//std::cout << m << std::endl;


	//std::cout << (int)c - '0' << std::endl;

	h.add(p, k);

	h.print();

	h.subtract(p, k);

	h.print();
	//p.init(x, 20);
	//k.init(y, 20);


	system("PAUSE");
	return 1;

}