#include "powerSeries.hpp"
powerSeries::powerSeries(std::complex<double> k, std::complex<double> a)
{
	setA(a);
	setK(k);
}
powerSeries::powerSeries(const powerSeries &toCopy) noexcept : k{toCopy.getA()}, a{toCopy.getA()}
{

}
powerSeries& powerSeries::operator=(const powerSeries &toCopy) noexcept
{
	setA(toCopy.getA());
	setK(toCopy.getK());
	return *this;
}
powerSeries::powerSeries(powerSeries &&toMove) noexcept : k{std::move(toMove.getA())}, a{std::move(toMove.getA())}
{

}
powerSeries& powerSeries::operator=(powerSeries &&toMove) noexcept
{
	setA(std::move(toMove.getA()));
	setK(std::move(toMove.getA()));
	return *this;
}
powerSeries::~powerSeries()
{

}
std::complex<double> powerSeries::get(long long int n)
{
	return getK()*(double)n*pow(getA(),n);
}

const std::complex<double>& powerSeries::getA() const
{
	return a;
}

void powerSeries::setA(const std::complex<double> &a)
{
	this->a = a;
}

const std::complex<double>& powerSeries::getK() const
{
	return k;
}

void powerSeries::setK(const std::complex<double> &k)
{
	this->k = k;
}
