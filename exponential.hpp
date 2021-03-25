#ifndef DPSCPP_EXPONENTIAL_HPP_
#define DPSCPP_EXPONENTIAL_HPP_
#define _USE_MATH_DEFINES
#include "signal.hpp"
#include <cmath>


class exponential : public signal
{
	public:
		exponential(std::complex<double> c);
		std::complex<double> get(long long int n);
	const std::complex<double>& getC() const;
	void setC(const std::complex<double> &c);

	private:
		std::complex<double> c;

};



#endif /* DPSCPP_EXPONENTIAL_HPP_ */
