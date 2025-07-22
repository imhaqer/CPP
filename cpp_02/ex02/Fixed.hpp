#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed {
  private:
	int _rawValue;
	static const int _fractionalBits = 8;

  public:
	Fixed();
	~Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	float toFloat() const;
	int toInt() const;
	Fixed &operator=(const Fixed &obj);
	int getRawBits() const;
	void setRawBits(const int raw);

	Fixed &operator++();   
	Fixed operator++(int);
	Fixed &operator--();   
	Fixed operator--(int);

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	static Fixed &min(Fixed &num1, Fixed &num2);
	static Fixed &max(Fixed &num1, Fixed &num2);
	static const Fixed &min(const Fixed &num1, const Fixed &num2);
	static const Fixed &max(const Fixed &num1, const Fixed &num2);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif