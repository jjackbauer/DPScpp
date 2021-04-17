#include "product.hpp"
product::product(signal *x,signal *y)
{
	setX(x);
	setY(y);
}
product::product( product &toCopy) noexcept : x{toCopy.getX()},y{toCopy.getY()}
{

}
product& product::operator=( product &toCopy) noexcept
{
	setX(toCopy.getX());
	setY(toCopy.getY());
	return *this;
}
product::product(product &&toMove) noexcept : x{std::move(toMove.getX())},y{std::move(toMove.getY())}
{

}
product& product::operator=(product &&toMove) noexcept
{
	setX(std::move(toMove.getX()));
	setY(std::move(toMove.getY()));
	return *this;
}
product::~product()
{

}
std::complex<double>	product::get(long long int n)
{
	return x->get(n)*y->get(n);
}

signal* product::getX()
{
	return x;
}

void product::setX(signal *x)
{
	this->x = x;
}

signal* product::getY()
{
	return y;
}

void product::setY( signal *y)
{
	this->y = y;
}
