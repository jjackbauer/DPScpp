#include "impulse.hpp"
std::complex<double>	impulse::get(long long int n)
{
	return n==0 ? 1.0 : 0.0;
}
