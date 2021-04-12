#ifndef DPSCPP_DIFFERENCEEQUATION_HPP_
#define DPSCPP_DIFFERENCEEQUATION_HPP_
#include <iostream>
#include "signal.hpp"

class differenceEquation : public signal
{
	public:
		differenceEquation(std::vector<std::complex<double>> a,std::vector<std::complex<double>> b);
		differenceEquation(differenceEquation &toCopy) noexcept;
		differenceEquation& operator=(differenceEquation &toCopy) noexcept;
		differenceEquation(differenceEquation &&toMove) noexcept;
		differenceEquation& operator=(differenceEquation &&toMove) noexcept;
		std::complex<double> get(long long int n);
		const std::vector<std::complex<double>>& getA() const;
		void setA(const std::vector<std::complex<double>> &a);
		const std::vector<std::complex<double>>& getB() const;
		void setB(const std::vector<std::complex<double>> &b);
		std::vector<std::complex<double>> impulse(long long int n);
		std::vector<std::complex<double>> step(long long int n);
		const std::vector<std::complex<double> >& getResponse() const;
		void setResponse(const std::vector<std::complex<double> > &response);

	private:
		std::vector<std::complex<double>> a;
		std::vector<std::complex<double>> b;
		std::vector<std::complex<double>> response;
};



#endif /* DPSCPP_DIFFERENCEEQUATION_HPP_ */
