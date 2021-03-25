#include "signal.hpp"
signal::signal()
{

}
signal::~signal()
{

}
std::complex<double>	signal::get(long long int n)
{
	return 0;
}
std::vector<std::complex<double>> signal::getSequence(long long int begin, long long int end)
{
	std::vector<std::complex<double>> sequence;

	for(long long int i=begin; i<=end;i++)
		sequence.push_back((std::complex<double>)(this->get(i)));

	return sequence;
}
