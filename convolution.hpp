#ifndef DPSCPP_CONVOLUTION_HPP_
#define DPSCPP_CONVOLUTION_HPP_
#include "signal.hpp"

class convolution : public signal
{
	public:
		std::complex<double> get(long long int n);
	private:
		signal x;
		signal h;


};




#endif /* DPSCPP_CONVOLUTION_HPP_ */
