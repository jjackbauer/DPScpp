#ifndef DPSCPP_DELAY_HPP_
#define DPSCPP_DELAY_HPP_
#include "signal.hpp"
class delay : public signal
{
	public:
		delay(long long int delay,signal x);
		delay(const delay &toCopy) noexcept;
		delay& operator=(const delay &toCopy) noexcept;
		delay(delay &&toMove) noexcept;
		delay& operator=(delay &&toMove) noexcept;
		~delay();
		long long int getDelay() const;
		void setDelay(long long int delay);
		const signal& getX() const;
		void setX(const signal &x);
		std::complex<double> get(long long int n);

	private:
		long long int k;
		signal x;
};




#endif /* DPSCPP_DELAY_HPP_ */
