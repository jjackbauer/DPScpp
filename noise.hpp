#ifndef DPSCPP_NOISE_HPP_
#define DPSCPP_NOISE_HPP_
#include "signal.hpp"
#include "random.hpp"
using Random = effolkronium::random_static;

class noise : public signal // scale*rand()+verticalDisplacement
{
	public:
		noise(double scale, double verticalDisplacement);
		noise(const noise &toCopy) noexcept;
		noise& operator=(const noise &toCopy) noexcept;
		noise(noise &&toMove) noexcept;
		noise& operator=(noise&&toMove) noexcept;
		~noise();
		std::complex<double>	get(long long int n);
		const double& getScale() const;
		void setScale(const double &scale);
		const double& getVerticalDisplacement() const;
		void setVerticalDisplacement(const double &verticalDisplacement);

	private:
		double scale;
		double verticalDisplacement;
};




#endif /* DPSCPP_NOISE_HPP_ */
