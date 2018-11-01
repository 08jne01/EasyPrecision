#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctype.h>
#include <math.h>

class pNum

{

private:

	std::vector<char> charArr;
	int decLoc; // decimal location

	void splitDec()

	{

		int decimal = -1;

		for (int i = 0; i < num.length(); i++)

		{

            // Check if num at index is "."
            // '0' ASCII value is 48
            // '.' ASCII value is 46
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
        // didnt find any decimal ... must be implied at the end
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
    
    pNum operator=(const pNum& b)
    {
        pNum object;
        object.precision = b.precision;
        object.num = b.num;
        object.decLoc = b.decLoc;
        object.charArr = b.charArr;
        return object;
    }

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
        
        if (a.charArr.empty())
        {
            charArr = b.charArr;
            return;
        }
        else if (b.charArr.empty())
        {
            charArr = a.charArr;
            return;
        }

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

        // make same number of zeroes on right side of decimal point
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
        int total = 0;
        int product = 0;
        int carry = 0;
        int ans_DecLoc = 0;
        int ans = 0;
        
        // check if paramters are empty
        if (a.charArr.empty())
        {
            std::cout << "ERROR: First parameter is empty" << std::endl;
            return;
        }
        if (b.charArr.empty())
        {
            std::cout << "ERROR: Second parameter is empty" << std::endl;
            return;
        }
        
        // Check if parameters are valid numbers
        for (int i = 0; i < a.charArr.size(); i++)
        {
            if (isdigit(a.charArr[i]))
                continue;
            else
            {
                std::cout << "ERROR: First parameter is not a number." << std::endl;
                return;
            }
        }
        for (int i = 0; i < b.charArr.size(); i++)
        {
            if (isdigit(b.charArr[i]))
                continue;
            else
            {
                std::cout << "ERROR: Second parameter is not a number." << std::endl;
                return;
            }
        }
        
        ///////////////// long multiplication ///////////////////
        int result = 0;
        int offset = 0;
        int tens = 0;
        pNum answer, intermediate;
        
        // multiply all digits from both operands against each other
        for (int i = b.charArr.size()-1; i > -1; i--)
        {
            // check if multiplier is zero
            if (b.charArr[i] == 48)
            {
                offset++;
                continue;
            }
            
            // add zeroes according to long multi
            for (int zeroes = 0; zeroes < offset; zeroes++)
                intermediate.charArr.push_back('0');
            
            // multiply digit by every digit in other operand
            for (int j = a.charArr.size()-1; j >-1; j--)
            {
                // multiply two digits
                product = (b.charArr[i] - '0')*(a.charArr[j] - '0') + carry;
                
                // get carry and resulting digit
                if (product >= 10)
                {
                    result = product % 10;
                    if (result == 0)
                        carry = product/10;
                }
                else
                    result = product;
                if (result)
                    carry = (product - result)/10;
                
                // insert result digit into vector and use carry next iteration
                intermediate.charArr.insert(intermediate.charArr.begin(), static_cast<char>(result + '0'));
            }
            
            offset++;
            
            std::cout << "start print char" << std::endl;
            for (int i = 0; i < intermediate.charArr.size(); i++)
                std::cout << "char: " << intermediate.charArr[i] << std::endl;
            
            // add intermediate to running total and then clear
            add(*this, intermediate);
            intermediate.charArr.clear();
        }
        ////////////////////////////////////////////////////////
        
        // new decimal position is additon of # of decimal places of two paramters
        decLoc = charArr.size() - ((a.charArr.size() - a.decLoc)+(b.charArr.size() - b.decLoc));
        
        // add preceding zeroes if necessary
        while (decLoc < 1)
        {
            charArr.insert(charArr.begin(), '0');
            decLoc++;
        }
	}


};
