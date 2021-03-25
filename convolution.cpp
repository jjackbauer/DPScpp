#include "convolution.hpp"
convolution::convolution(long long int k,signal &x, signal &h)
{
	setK(k);
	setX(x);
	setH(h);
}
convolution::~convolution()
{

}
convolution::convolution(const convolution &toCopy) noexcept : k{toCopy.getK()}, x{toCopy.getX()}, h{toCopy.getH()}
{

}
convolution& convolution::operator=(const convolution &toCopy) noexcept
{
	setK(toCopy.getK());
	setX(toCopy.getX());
	setH(toCopy.getH());
	return *this;
}
convolution::convolution(convolution &&toMove) noexcept : k{std::move(toMove.getK())}, x{std::move(toMove.getX())}, h{std::move(toMove.getH())}
{

}
convolution& convolution::operator=(convolution &&toMove) noexcept
{
	setK(std::move(toMove.getK()));
	setX(std::move(toMove.getX()));
	setH(std::move(toMove.getH()));
	return *this;
}
std::complex<double> convolution::get(long long int n)
{
	std::complex<double> value(0,0);

	for(long long int i=-k;i<=k;k++)
		value+=x.get(k)*h.get(n-k);

	return value;
}
const signal& convolution::getH() const
{
	return h;
}

void convolution::setH(const signal &h)
{
	this->h = h;
}

long long int convolution::getK() const
{
	return k;
}

void convolution::setK(long long int k)
{
	this->k = k;
}

const signal& convolution::getX() const
{
	return x;
}

void convolution::setX(const signal &x)
{
	this->x = x;
}
