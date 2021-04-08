#ifndef DPSCPP_NOISE_HPP_
#define DPSCPP_NOISE_HPP_
#include "signal.hpp"

class noise : public signal // scale*rand()+verticalDisplacement
{
	public:
		noise(std::complex<double> scale, std::complex<double> verticalDisplacement);
		noise(const noise &toCopy) noexcept;
		noise& operator=(const noise &toCopy) noexcept;
		noise(noise &&toMove) noexcept;
		noise& operator=(noise&&toMove) noexcept;
		~noise();
		std::complex<double>	get(long long int n);
	private:
		std::complex<double> scale;
		std::complex<double> verticalDisplacement;
};




#endif /* DPSCPP_NOISE_HPP_ */
