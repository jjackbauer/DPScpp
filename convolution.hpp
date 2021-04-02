#ifndef DPSCPP_CONVOLUTION_HPP_
#define DPSCPP_CONVOLUTION_HPP_
#include "signal.hpp"
#include "sequence.hpp"
#include "iostream"
class convolution : public signal
{
	public:
		convolution(long long int k,signal *x, signal *h);
		convolution(convolution &toCopy) noexcept;
		convolution& operator=(convolution &toCopy) noexcept;
		convolution(convolution &&toMove) noexcept;
		convolution& operator=(convolution &&toMove) noexcept;
		~convolution();
		std::complex<double> get(long long int n);
		long long int getK() const;
		void setK(long long int k);
		const sequence& getH() const;
		void setH(const sequence &h);
		const sequence& getX() const;
		void setX(const sequence &x);

	private:
		long long int k;
		sequence x;
		sequence h;


};




#endif /* DPSCPP_CONVOLUTION_HPP_ */
