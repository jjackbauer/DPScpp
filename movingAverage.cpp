#include "movingAverage.hpp"
movingAverage::movingAverage(long long int nMean,signal *x)
{
	setNMean(nMean);
	setX(x);
}
movingAverage::movingAverage(movingAverage &toCopy) noexcept : nMean{toCopy.getNMean()}, x{toCopy.getX()}
{

}
movingAverage& movingAverage::operator=(movingAverage &toCopy) noexcept
{
	setNMean(toCopy.getNMean());
	setX(x);
	return *this;
}
movingAverage::movingAverage(movingAverage &&toMove) noexcept : nMean{std::move(toMove.getNMean())},x{std::move(toMove.getX())}
{

}
movingAverage& movingAverage::operator=(movingAverage &&toMove) noexcept
{
	setNMean(std::move(toMove.getNMean()));
	setX(std::move(toMove.getX()));
	return *this;
}
std::complex<double> movingAverage::get(long long int n)
{
	std::complex<double> average(0,0);

	for(int k=n-getNMean() ; k <=n ; k++ )
		average+=x->get(k);

	return average/(double)getNMean();
}
long long int movingAverage::getNMean() const
{
	return nMean;
}

void movingAverage::setNMean(long long int nMean)
{
	this->nMean = nMean;
}

signal* movingAverage::getX()
{
	return x;
}

void movingAverage::setX(signal *x)
{
	this->x = x;
}
