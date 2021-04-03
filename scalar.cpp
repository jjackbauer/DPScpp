#include "scalar.hpp"
scalar::scalar(std::complex<double> k,signal *x)
{
	setK(k);
	setX(x);
}
scalar::scalar(scalar &toCopy) noexcept : k{toCopy.getK()}, x{toCopy.getX()}
{

}
scalar& scalar::operator=(scalar &toCopy) noexcept
{
	setK(toCopy.getK());
	setX(toCopy.getX());
	return *this;
}
scalar::scalar(scalar &&toMove) noexcept :k{std::move(toMove.getK())}, x{std::move(toMove.getX())}
{

}
scalar& scalar::operator=(scalar &&toMove) noexcept
{
	setK(std::move(toMove.getK()));
	setX(std::move(toMove.getX()));
	return *this;
}
scalar::~scalar()
{

}
std::complex<double>	scalar::get(long long int n)
{
	return getK()*x->get(n);
}
const std::complex<double>& scalar::getK() const
{
	return k;
}

void scalar::setK(const std::complex<double> &k)
{
	this->k = k;
}

signal* scalar::getX()
{
	return x;
}

void scalar::setX(signal *x)
{
	this->x = x;
}
