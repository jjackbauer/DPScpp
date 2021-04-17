#ifndef DPSCPP_PRODUCT_HPP_
#define DPSCPP_PRODUCT_HPP_
#include "signal.hpp"

class product : public signal
{

	public:
		product(signal *x,signal *y);
		product( product &toCopy) noexcept;
		product& operator=( product &toCopy) noexcept;
		product(product &&toMove) noexcept;
		product& operator=(product &&toMove) noexcept;
		~product();
		std::complex<double>	get(long long int n);
		signal* getX() ;
		void setX( signal *x);
		signal* getY() ;
		void setY( signal *y);

	private:
		signal *x;
		signal *y;
};

#endif /* DPSCPP_PRODUCT_HPP_ */
