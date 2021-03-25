#ifndef DPSCPP_IMPULSE_HPP_
#define DPSCPP_IMPULSE_HPP_
#include "signal.hpp"

class impulse : public signal
{
	public:
	impulse();
	impulse(const impulse &toCopy) noexcept;
	impulse& operator=(const impulse &toCopy) noexcept;
	impulse(impulse &&toMove) noexcept;
	impulse& operator=(impulse &&toMove) noexcept;
		std::complex<double>	get(long long int n);

};




#endif /* DPSCPP_IMPULSE_HPP_ */
