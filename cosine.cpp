#include "cosine.hpp"

cosine::cosine(double frequency, double phase)
{
	setFrequency(frequency);
	setPhase(phase);
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
