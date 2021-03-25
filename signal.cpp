#include "signal.hpp"
signal::signal()
{

}
signal::~signal()
{

}
double	signal::get(long long int n)
{
	return 0;
}
std::vector<double> signal::getSequence(long long int begin, long long int end)
{
	std::vector<double> sequence;

	for(long long int i=begin; i<=end;i++)
		sequence.push_back((double)(this->get(i)));

	return sequence;
}
