#ifndef DPSCPP_SCALAR_HPP_
#define DPSCPP_SCALAR_HPP_
#include "signal.hpp"
#include <complex>

class scalar : public signal
{
	public:
		scalar(std::complex<double> k,signal *x);
		scalar(scalar &toCopy) noexcept;
		scalar& operator=(scalar &toCopy) noexcept;
		scalar(scalar &&toMove) noexcept;
		scalar& operator=(scalar &&toMove) noexcept;
		~scalar();
		std::complex<double>	get(long long int n);
		const std::complex<double>& getK() const;
		void setK(const std::complex<double> &k);
		signal* getX();
		void setX(signal *x);

	private:
		std::complex<double> k;
		signal *x;


};




#endif /* DPSCPP_SCALAR_HPP_ */
