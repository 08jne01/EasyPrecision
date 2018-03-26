#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class pNum

{

private:

	std::vector<char> charArr;
	int decLoc;

	void splitDec()

	{

		int decimal = -1;

		for (int i = 0; i < num.length(); i++)

		{

			//std::cout << (int)(num[i] - '0') << std::endl;

			if ((int)(num[i] - '0') == -2)

			{

				decimal = 1;
				decLoc = i;


			}

			else

			{

				charArr.push_back(num[i]);

			}

		}

		if (decimal == -1)

		{

			decLoc = num.length();

		}


	}

	void combineDec()

	{




	}

	void addZero(std::vector<char> *ptr, int n)

	{

		std::reverse(ptr->begin(), ptr->end());

		for (int i = 0; i < n; i++)

		{

			ptr->push_back('0');

		}

		std::reverse(ptr->begin(), ptr->end());

	}

public:

	std::string num;
	int precision;

	void print()

	{

		std::cout << "rightDec = ";

		for (int i = 0; i < charArr.size(); i++)

		{

			if (i == decLoc)

			{

				std::cout << '.';

			}

			std::cout << charArr[i];

		}

		std::cout << std::endl;

	}


	void init(std::string s_, double p_, int precision_)

	{

		//precision = precision_;
		if (s_ == "")

		{

			std::ostringstream os;
			os << std::setprecision(precision_) << p_;
			num = os.str();

		}

		else

		{

			num = s_;

		}

		splitDec();

	}

	void subtract(pNum a, pNum b)

	{

		charArr.clear();
		decLoc = 1;

		int remainder = 0;
		int cur;
		int aSize, bSize, aMag, bMag, mag, j, k, m;

		std::vector<char> locA;
		std::vector<char> locB;
		std::vector<char> *ptr;

		locA = a.charArr;
		locB = b.charArr;

		aMag = a.decLoc;
		bMag = b.decLoc;

		if (aMag > bMag)

		{

			ptr = &locB;
			addZero(ptr, aMag - bMag);
			decLoc = aMag;


		}

		else if (bMag > aMag)

		{

			ptr = &locA;
			addZero(ptr, bMag - aMag);
			decLoc = aMag;

		}

		aSize = locA.size();
		bSize = locB.size();

		if (bSize > aSize)

		{

			m = bSize;

		}

		else

		{

			m = aSize;

		}


		for (int i = m - 1; i > -1; i--)

		{

			if (i > bSize - 1)

			{

				j = (int)(locA[i] - '0');
				k = 0;


			}

			else if (i > aSize - 1)

			{

				k = (int)(locB[i] - '0');
				j = 0;


			}

			else

			{

				j = (int)(locA[i] - '0');
				k = (int)(locB[i] - '0');

				//std::cout << j << " " << k << std::endl;


			}

			cur = j - k - remainder;

			if (cur > 0)

			{

				charArr.push_back(('0' + cur));
				remainder = 0;

			}

			else

			{

				charArr.push_back((char)('0' + (cur + 10)));
				remainder = 1;

			}


		}

		std::reverse(charArr.begin(), charArr.end());


	}

	void add(pNum a, pNum b)

	{

		charArr.clear();
		decLoc = 1;

		int remainder = 0;
		int cur;
		int aSize, bSize, aMag, bMag, mag, j, k, m;

		std::vector<char> locA;
		std::vector<char> locB;
		std::vector<char> *ptr;

		locA = a.charArr;
		locB = b.charArr;
		
		aMag = a.decLoc;
		bMag = b.decLoc;

		if (aMag > bMag)

		{

			ptr = &locB;
			addZero(ptr, aMag - bMag);
			decLoc = aMag;


		}

		else if (bMag > aMag)

		{

			ptr = &locA;
			addZero(ptr, bMag - aMag);
			decLoc = aMag;

		}
		
		aSize = locA.size();
		bSize = locB.size();

		if (bSize > aSize)

		{

			m = bSize;

		}

		else

		{

			m = aSize;

		}


		for (int i = m - 1; i > -1; i--)

		{

			if (i > bSize - 1)

			{

				j = (int)(locA[i] - '0');
				k = 0;


			}

			else if (i > aSize - 1)

			{

				k = (int)(locB[i] - '0');
				j = 0;


			}

			else

			{

				j = (int)(locA[i] - '0');
				k = (int)(locB[i] - '0');

				//std::cout << j << " " << k << std::endl;


			}

			cur = j + k + remainder;

			if (cur < 10)

			{

				charArr.push_back(('0' + cur));
				remainder = 0;

			}

			else

			{

				charArr.push_back((char)('0' + (cur - 10)));
				remainder = 1;

			}


		}

		std::reverse(charArr.begin(), charArr.end());

	}


	void divide(pNum a, pNum b)

	{




	}


	void multi(pNum a, pNum b)

	{




	}


};