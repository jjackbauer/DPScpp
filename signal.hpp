#ifndef DPSCPP_SIGNAL_HPP_
#define DPSCPP_SIGNAL_HPP_
#include <vector>
#include <complex>
class signal
{

	public:
		signal();
		virtual	~signal();
		virtual std::complex<double>	get(long long int n);
		std::vector< std::complex<double> > getSequence(long long int begin, long long int end);

};



#endif /* DPSCPP_SIGNAL_HPP_ */
