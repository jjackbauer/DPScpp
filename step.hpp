#ifndef DPSCPP_STEP_HPP_
#define DPSCPP_STEP_HPP_
#include "signal.hpp"

class step : public signal
{
	public:
	step();
	step(const step &toCopy) noexcept;
	step& operator=(const step &toCopy) noexcept;
	step(step &&toMove) noexcept;
	step& operator=(step &&toMove) noexcept;
		std::complex<double> get(long long int n);
};




#endif /* DPSCPP_STEP_HPP_ */
