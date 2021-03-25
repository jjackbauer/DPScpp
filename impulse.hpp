#ifndef DPSCPP_IMPULSE_HPP_
#define DPSCPP_IMPULSE_HPP_
#include "signal.hpp"

class impulse : public signal
{
	public:
		std::complex<double>	get(long long int n);

};




#endif /* DPSCPP_IMPULSE_HPP_ */
