#include "Fixed.hpp"

int main( void ) {
Fixed  a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );


std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;


Fixed num1(3.5f), num2(2.0f);
std::cout << "Min: " << Fixed::min(num1, num2).toFloat() << "\n";
std::cout << "Max: " << Fixed::max(num1, num2).toFloat() << "\n";


std::cout << "== Arithmetic Tests ==\n";

	// operator+
	Fixed addA(5.5f), addB(2.5f);
	Fixed addResult = addA + addB;
	std::cout << "5.5 + 2.5 = " << addResult.toFloat() << "\n";

	// operator-
	Fixed subA(7.0f), subB(3.0f);
	Fixed subResult = subA - subB;
	std::cout << "7.0 - 3.0 = " << subResult.toFloat() << "\n";

	// operator*
	Fixed mulA(4.0f), mulB(2.5f);
	Fixed mulResult = mulA * mulB;
	std::cout << "4.0 * 2.5 = " << mulResult.toFloat() << "\n";

	// operator/
	Fixed divA(10.0f), divB(3.5f);
	Fixed divResult = divA / divB;
	std::cout << "10.0 / 3.5 = " << divResult.toFloat() << "\n";

	std::cout << "\n== Comparison Tests ==\n";

	// operator>
	Fixed gtA(5), gtB(3);
	std::cout << "5 > 3: " << (gtA > gtB) << "\n";

	// operator<
	Fixed ltA(1), ltB(4);
	std::cout << "1 < 4: " << (ltA < ltB) << "\n";

	// operator>=
	Fixed geA(6), geB(6);
	std::cout << "6 >= 6: " << (geA >= geB) << "\n";

	// operator<=
	Fixed leA(3), leB(9);
	std::cout << "3 <= 9: " << (leA <= leB) << "\n";

	// operator==
	Fixed eqA(7.25f), eqB(7.25f);
	std::cout << "7.25 == 7.25: " << (eqA == eqB) << "\n";

	// operator!=
	Fixed neA(2), neB(5);
	std::cout << "2 != 5: " << (neA != neB) << "\n";


	return 0;
}
