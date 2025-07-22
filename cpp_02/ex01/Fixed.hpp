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
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif