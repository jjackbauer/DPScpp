#include "sequence.hpp"
sequence::sequence()
{
	setLowerLimit(0);
	setUpperLimit(0);
}
sequence::sequence(long long int lowerLimit,long long int upperLimit,signal *x)
{
	std::vector<std::complex<double>> aux;
	setLowerLimit(lowerLimit);
	setUpperLimit(upperLimit);

	for(int n=getLowerLimit();n <= getUpperLimit(); n++)
		aux.push_back(x->get(n));

	setS(aux);
}
sequence::sequence(long long int lowerLimit,long long int upperLimit,std::vector<std::complex<double>> seq)
{
	if(seq.size() == upperLimit-lowerLimit+1)
	{
		setLowerLimit(lowerLimit);
		setUpperLimit(upperLimit);
		setS(seq);
	}
}
sequence::sequence(const sequence &toCopy) noexcept : lowerLimit{toCopy.getLowerLimit()}, upperLimit{toCopy.getUpperLimit()}, seq{toCopy.getS()}
{

}
sequence& sequence::operator=(const sequence &toCopy) noexcept
{
	setLowerLimit(toCopy.getLowerLimit());
	setUpperLimit(toCopy.getUpperLimit());
	setS(toCopy.getS());
	return *this;
}
sequence::sequence(sequence &&toMove) noexcept : lowerLimit{std::move(toMove.getLowerLimit())}, upperLimit{std::move(toMove.getUpperLimit())}, seq{std::move(toMove.getS())}
{

}
sequence& sequence::operator=(sequence &&toMove) noexcept
{
	setLowerLimit(std::move(toMove.getLowerLimit()));
	setUpperLimit(std::move(toMove.getUpperLimit()));
	setS(std::move(toMove.getS()));
	return *this;
}
sequence::~sequence()
{

}
long long int sequence::getLowerLimit() const
{
	return lowerLimit;
}

void sequence::setLowerLimit(long long int lowerLimit)
{
	this->lowerLimit = lowerLimit;
}

const std::vector<std::complex<double> >& sequence::getS() const
{
	return seq;
}

void sequence::setS(const std::vector<std::complex<double> > &s)
{
	this->seq = s;
}

long long int sequence::getUpperLimit() const
{
	return upperLimit;
}

void sequence::setUpperLimit(long long int upperLimit)
{
	this->upperLimit = upperLimit;
}
std::complex<double> sequence::get(long long int n)
{

	return n>=getLowerLimit() && n<=getUpperLimit() ? seq.at(n-getLowerLimit()) : 0;
	/*try
	{
		return n>=getLowerLimit() && n<=getUpperLimit() ? seq.at(n-getLowerLimit()) : 0;
	}catch(...)
	{
		return 0;
	}*/
}
