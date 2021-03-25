#ifndef DPSCPP_CONVOLUTION_HPP_
#define DPSCPP_CONVOLUTION_HPP_
#include "signal.hpp"

class convolution : public signal
{
	public:
		convolution(long long int k,signal &x, signal &h);
		convolution(const convolution &toCopy) noexcept;
		convolution& operator=(const convolution &toCopy) noexcept;
		convolution(convolution &&toMove) noexcept;
		convolution& operator=(convolution &&toMove) noexcept;
		~convolution();
		std::complex<double> get(long long int n);
		const signal& getH() const;
		void setH(const signal &h);
		long long int getK() const;
		void setK(long long int k);
		const signal& getX() const;
		void setX(const signal &x);

	private:
		long long int k;
		signal x;
		signal h;


};




#endif /* DPSCPP_CONVOLUTION_HPP_ */
