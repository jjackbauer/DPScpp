#ifndef DPSCPP_SEQUENCE_HPP_
#define DPSCPP_SEQUENCE_HPP_
#include "signal.hpp"
#include <vector>
#include <complex>
class sequence : public signal
{
	public:
		sequence();
		sequence(long long int lowerLimit,long long int upperLimit,signal *x);
		sequence(long long int lowerLimit,long long int upperLimit,std::vector<std::complex<double>> seq);
		sequence(const sequence &toCopy) noexcept;
		sequence& operator=(const sequence &toCopy) noexcept;
		sequence(sequence &&toMove) noexcept;
		sequence& operator=(sequence &&toMove) noexcept;
		~sequence();
		long long int getLowerLimit() const;
		void setLowerLimit(long long int lowerLimit);
		const std::vector<std::complex<double> >& getS() const;
		void setS(const std::vector<std::complex<double> > &s);
		long long int getUpperLimit() const;
		void setUpperLimit(long long int upperLimit);
		std::complex<double> get(long long int n);
	private:
		long long int lowerLimit;
		long long int upperLimit;
		std::vector<std::complex<double>> seq;


};



#endif /* DPSCPP_SEQUENCE_HPP_ */
