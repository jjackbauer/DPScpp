#include "noise.hpp"
noise::noise(double scale, double verticalDisplacement)
{
	setScale(scale);
	setVerticalDisplacement(verticalDisplacement);
}
noise::noise(const noise &toCopy) noexcept : scale{toCopy.getScale()}, verticalDisplacement{toCopy.getVerticalDisplacement()}
{

}
noise& noise::operator=(const noise &toCopy) noexcept
{
	setScale(toCopy.getScale());
	setVerticalDisplacement(toCopy.getVerticalDisplacement());
	return *this;
}
noise::noise(noise &&toMove) noexcept : scale{std::move(toMove.getScale())}, verticalDisplacement{std::move(toMove.getVerticalDisplacement())}
{

}
noise& noise::operator=(noise&&toMove) noexcept
{
	setScale(std::move(toMove.getScale()));
	setVerticalDisplacement(std::move(toMove.getVerticalDisplacement()));
	return *this;
}
noise::~noise()
{

}
std::complex<double>	noise::get(long long int n)
{
	double real=getScale()*Random::get(0.l, 1.l)+getVerticalDisplacement();
	double imag=getScale()*Random::get(0.l, 1.l)+getVerticalDisplacement();

	return std::complex<double> (real,imag);
}
const double& noise::getScale() const
{
	return scale;
}

void noise::setScale(const double &scale)
{
	this->scale = scale;
}

const double& noise::getVerticalDisplacement() const
{
	return verticalDisplacement;
}

void noise::setVerticalDisplacement(const double &verticalDisplacement)
{
	this->verticalDisplacement = verticalDisplacement;
}
