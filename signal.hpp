#ifndef DPSCPP_SIGNAL_HPP_
#define DPSCPP_SIGNAL_HPP_
#include <vector>

class signal
{

	public:
		signal();
	virtual	~signal();
	virtual double	get(long long int n);
	std::vector<double> getSequence(long long int begin, long long int end);

};



#endif /* DPSCPP_SIGNAL_HPP_ */
