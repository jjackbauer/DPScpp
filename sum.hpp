#ifndef DPSCPP_SUM_HPP_
#define DPSCPP_SUM_HPP_
#include "signal.hpp"

class sum : public signal
{
	public:
		sum(signal *x, signal *y);
		sum(sum &toCopy) noexcept;
		sum& operator=(sum &toCopy) noexcept;
		sum(sum &&toMove) noexcept;
		sum& operator=(sum &&toMove) noexcept;
		~sum();
		std::complex<double>	get(long long int n);
		signal* getX() ;
		void setX(signal *x);
		signal* getY() ;
		void setY(signal *y);

	private:
		signal *x;
		signal *y;
};





#endif /* DPSCPP_SUM_HPP_ */
