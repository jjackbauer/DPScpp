#ifndef DPSCPP_POWERSERIES_HPP_
#define DPSCPP_POWERSERIES_HPP_
#include "signal.hpp"

class powerSeries : public signal// k*n*(a)^n
{
	public:
		powerSeries(std::complex<double> k, std::complex<double> a);
		powerSeries(const powerSeries &toCopy) noexcept;
		powerSeries& operator=(const powerSeries &toCopy) noexcept;
		powerSeries(powerSeries &&toMove) noexcept;
		powerSeries& operator=(powerSeries &&toMove) noexcept;
		~powerSeries();
		std::complex<double>	get(long long int n);
		const std::complex<double>& getA() const;
		void setA(const std::complex<double> &a);
		const std::complex<double>& getK() const;
		void setK(const std::complex<double> &k);

	private:
		std::complex<double> k;
		std::complex<double> a;
};




#endif /* DPSCPP_POWERSERIES_HPP_ */
