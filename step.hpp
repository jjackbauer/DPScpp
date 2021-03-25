#ifndef DPSCPP_STEP_HPP_
#define DPSCPP_STEP_HPP_
#include "signal.hpp"

class step : public signal
{
	public:
		double get(long long int n);
};




#endif /* DPSCPP_STEP_HPP_ */
