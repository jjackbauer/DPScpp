#include "delay.hpp"
delay::delay(long long int k,signal *x)
{
	setDelay(k);
	setX(x);
}
delay::delay(delay &toCopy) noexcept : k{toCopy.getDelay()},x{toCopy.getX()}
{
}
delay& delay::operator=(delay &toCopy) noexcept
{
	setDelay(toCopy.getDelay());
	setX(toCopy.getX());
	return *this;
}
delay::delay(delay &&toMove) noexcept :  k{std::move(toMove.getDelay())}, x{std::move(toMove.getX())}
{

}
delay& delay::operator=(delay &&toMove) noexcept
{
	setDelay(std::move(toMove.getDelay()));
	setX(std::move(toMove.getX()));
	return *this;
}
delay::~delay()
{

}
std::complex<double> delay::get(long long int n)
{
	return x->get(n-getDelay());
}
long long int delay::getDelay() const {
	return k;
}

void delay::setDelay(long long int k) {
	this->k = k;
}

signal* delay::getX()
{
	return x;
}
void delay::setX( signal *x)
{
	this->x = x;
}
