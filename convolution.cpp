#include "convolution.hpp"
convolution::convolution(long long int k,signal *x, signal *h)
{
	setK(k);
	sequence auxX(-k,k,x),auxH(-k,k,h);
	setX(auxX);
	setH(auxH);
	/*std::cout<<"AuxX-Size: "<<auxX.getS().size()<<std::endl;
	std::cout<<"AuxH-Size: "<<auxH.getS().size()<<std::endl;
	std::cout<<"x-Size: "<<this->x.getS().size()<<std::endl;
	std::cout<<"h-Size: "<<this->h.getS().size()<<std::endl;//*/

}
convolution::~convolution()
{

}
convolution::convolution(convolution &toCopy) noexcept : k{toCopy.getK()}, x{toCopy.getX()}, h{toCopy.getH()}
{

}
convolution& convolution::operator=(convolution &toCopy) noexcept
{
	setK(toCopy.getK());
	setX(toCopy.getX());
	setH(toCopy.getH());
	return *this;
}
convolution::convolution(convolution &&toMove) noexcept : k{std::move(toMove.getK())}, x{std::move(toMove.getX())}, h{std::move(toMove.getH())}
{

}
convolution& convolution::operator=(convolution &&toMove) noexcept
{
	setK(std::move(toMove.getK()));
	setX(std::move(toMove.getX()));
	setH(std::move(toMove.getH()));
	return *this;
}
std::complex<double> convolution::get(long long int n)
{
	//std::cout<<"GET 1"<<std::endl;
	std::complex<double> value(0,0);
	//std::cout<<"GET 2"<<std::endl;
	for(long long int i=-k;i<=k;i++)
	{
		/*std::cout<<"Value"<<value<<std::endl;
		std::cout<<"i"<<i<<std::endl;
		std::cout<<"x[i]"<<x.get(i)<<std::endl;
		std::cout<<"h[n-i]"<<h.get(n-i)<<std::endl;//*/
		value+=(x.get(i))*(h.get(n-i));
	}
	//std::cout<<"GET 3"<<std::endl;

	return value;
}
long long int convolution::getK() const
{
	return k;
}

void convolution::setK(long long int k)
{
	this->k = k;
}

const sequence& convolution::getH() const {
	return h;
}

void convolution::setH(const sequence &h) {
	this->h = h;
}

const sequence& convolution::getX() const {
	return x;
}

void convolution::setX(const sequence &x) {
	this->x = x;
}
