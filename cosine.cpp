#include "cosine.hpp"

cosine::cosine(double frequency, double phase)
{
	setFrequency(frequency);
	setPhase(phase);
}
cosine::cosine(const cosine &toCopy) noexcept : frequency{toCopy.getFrequency()}, phase{toCopy.getPhase()}
{

}
cosine& cosine::operator=(const cosine &toCopy) noexcept
{
	this->setFrequency(toCopy.getFrequency());
	this->setPhase(toCopy.getPhase());
	return *this;
}
cosine::cosine(cosine &&toMove) noexcept :  frequency{std::move(toMove.getFrequency())}, phase{std::move(toMove.getPhase())}
{

}
cosine& cosine::operator=(cosine &&toMove) noexcept
{
	this->setFrequency(std::move(toMove.getFrequency()));
	this->setPhase(std::move(toMove.getPhase()));
	return *this;
}
double cosine::getFrequency() const
{
	return frequency;
}

void cosine::setFrequency(double frequency)
{
	this->frequency = frequency;
}

double cosine::getPhase() const
{
	return phase;
}

void cosine::setPhase(double phase)
{
	this->phase = phase;
}
std::complex<double>	cosine::get(long long int n)
{
	return cos(2*M_PI*getFrequency()*n+M_PI*getPhase()/180.0);
}
