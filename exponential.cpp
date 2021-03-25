#include "exponential.hpp"
exponential::exponential(std::complex<double> c)
{
	setC(c);
}
std::complex<double> exponential::get(long long int n)
{
	return exp(getC()*((double)n));
}
const std::complex<double>& exponential::getC() const
{
	return c;
}
void exponential::setC(const std::complex<double> &c)
{
	this->c = c;
}
