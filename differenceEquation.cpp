#include "differenceEquation.hpp"
differenceEquation::differenceEquation(std::vector<std::complex<double>> a,std::vector<std::complex<double>> b)
{

	setA(a);
	setB(b);
}
differenceEquation::differenceEquation(differenceEquation &toCopy) noexcept : a{toCopy.getA()}, b{toCopy.getB()}
{

}
differenceEquation& differenceEquation::operator=(differenceEquation &toCopy) noexcept
{
	setA(toCopy.getA());
	setB(toCopy.getB());
	return *this;
}
differenceEquation::differenceEquation(differenceEquation &&toMove) noexcept : a{std::move(toMove.getA())}, b{std::move(toMove.getB())}
{

}
differenceEquation& differenceEquation::operator=(differenceEquation &&toMove) noexcept
{
	setA(std::move(toMove.getA()));
	setB(std::move(toMove.getB()));
	return *this;
}
std::complex<double> differenceEquation::get(long long int n)
{
	return 0;
}
std::vector<std::complex<double>> differenceEquation::impulse(long long int n)
{
	std::vector<std::complex<double>> response;
	std::vector<std::complex<double>> x(b.size());
	std::vector<std::complex<double>> y(a.size());

	for(auto & i : y)//condições iniciais zeradas
		i=0;

	for(auto &i : x)//Impulso
		i=0;

	x[0]=1;


	for(int k=0 ; k < n ; k++)
	{
		response.push_back(std::complex<double> (0,0));

		for(int j=1 ; j < (int) a.size() ; j++)
			response[k]-=a[j]*y[j];

		for(int j=0 ; j < (int) b.size() ; j++)
			response[k]+=b[j]*x[j];


		response[k]/=a[0];
		y.insert(y.begin(),response[k]);
		y.pop_back();
		x.insert(x.begin(),std::complex<double> (0,0));
		x.pop_back();

	}

		return response;

}
std::vector<std::complex<double>> differenceEquation::step(long long int n)
{
	std::vector<std::complex<double>> response;
	std::vector<std::complex<double>> x(b.size());
	std::vector<std::complex<double>> y(a.size());

	for(auto & i : y)//condições iniciais zeradas
		i=0;

	for(auto &i : x)//Degrau
		i=1;


	for(int k=0 ; k < n ; k++)
	{
		response.push_back(std::complex<double> (0,0));

		for(int j=1 ; j < (int) a.size() ; j++)
			response[k]-=a[j]*y[j];

		for(int j=0 ; j < (int) b.size() ; j++)
			response[k]+=b[j]*x[j];


		response[k]/=a[0];
		y.insert(y.begin(),response[k]);
		y.pop_back();

	}

		return response;
}
const std::vector<std::complex<double>>& differenceEquation::getA() const
{
	return a;
}

void differenceEquation::setA(const std::vector<std::complex<double>> &a)
{
	this->a = a;
}

const std::vector<std::complex<double>>& differenceEquation::getB() const
{
	return b;
}

void differenceEquation::setB(const std::vector<std::complex<double>> &b)
{
	this->b = b;
}


