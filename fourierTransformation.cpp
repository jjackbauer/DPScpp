#include "fourierTransformation.hpp"
fourierTransformation::fourierTransformation(long long int k,signal *x)
{
	setK(k);
	setSeq(x->getSequence(0, getK()));
}
std::vector<std::complex<double>> fourierTransformation::getFourierSampling(long long int N)
{
	std::vector<std::complex<double>> out;

	for(long long int n=0; n < N ; n++)
	{	out.push_back(std::complex<double> (0,0));

		for(long long int i=0; i< getK(); i++)
		{
			std::complex<double> wn(0,2*M_PI*((double)n/N)*i);
			out[n]+=seq[i]*exp(wn);
		}
	}
	return out;
}
fourierTransformation::fourierTransformation(const fourierTransformation &toCopy) noexcept : k{toCopy.getK()}, seq{toCopy.getSeq()}
{

}
fourierTransformation& fourierTransformation::operator=(const fourierTransformation &toCopy) noexcept
{
	setK(toCopy.getK());
	setSeq(toCopy.getSeq());
	return *this;
}
fourierTransformation::fourierTransformation(fourierTransformation &&toMove) noexcept : k{std::move(toMove.getK())}, seq{std::move(toMove.getSeq())}
{

}
fourierTransformation& fourierTransformation::operator=(fourierTransformation &&toMove) noexcept
{
	setK(std::move(toMove.getK()));
	setSeq(std::move(toMove.getSeq()));
	return *this;
}
fourierTransformation::~fourierTransformation()
{

}
std::complex<double>	fourierTransformation::get(long long int n)
{
	return n>=0 && n < getK()? seq.at(n): 0;
}

long long int fourierTransformation::getK() const
{
	return k;
}

void fourierTransformation::setK(long long int k)
{
	this->k = k;
}

const std::vector<std::complex<double> >& fourierTransformation::getSeq() const
{
	return seq;
}

void fourierTransformation::setSeq(const std::vector<std::complex<double> > &seq)
{
	this->seq = seq;
}
