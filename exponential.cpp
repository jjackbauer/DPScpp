#include "exponential.hpp"
exponential::exponential(std::complex<double> c)
{
	setC(c);
}
exponential::exponential(const exponential &toCopy) noexcept : c{toCopy.getC()}
{

}
exponential& exponential::operator=(const exponential &toCopy) noexcept
{
	this->setC(toCopy.getC());
	return *this;
}
exponential::exponential(exponential &&toMove) noexcept: c{std::move(toMove.getC())}
{

}
exponential& exponential::operator=(exponential &&toMove) noexcept
{
	this->setC(std::move(toMove.getC()));
	return *this;
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
