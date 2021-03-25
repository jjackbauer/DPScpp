#include "step.hpp"

std::complex<double> step::get(long long int n)
{
	return n>=0 ? 1.0 : 0.0;
}
