#include "sum.hpp"
sum::sum(signal *x, signal *y)
{
	setX(x);
	setY(y);
}
sum::sum(sum &toCopy) noexcept : x{toCopy.getX()}, y{toCopy.getY()}
{

}
sum& sum::operator=(sum &toCopy) noexcept
{
	this->setX(toCopy.getX());
	this->setY(toCopy.getY());
	return *this;
}
sum::sum(sum &&toMove) noexcept : x{std::move(toMove.getX())}, y{std::move(toMove.getY())}
{

}
sum& sum::operator=(sum &&toMove) noexcept
{
	setX(std::move(toMove.getX()));
	setY(std::move(toMove.getY()));
	return *this;
}
sum::~sum()
{

}
std::complex<double>	sum::get(long long int n)
{
	return x->get(n)+y->get(n);
}
signal* sum::getX()
{
	return x;
}

void sum::setX(signal *x)
{
	this->x = x;
}

signal* sum::getY()
{
	return y;
}

void sum::setY( signal *y)
{
	this->y = y;
}
