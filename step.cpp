#include "step.hpp"
step::step()
{

}
step::step(const step &toCopy) noexcept
{

}
step& step::operator=(const step &toCopy) noexcept
{
	return *this;
}
step::step(step &&toMove) noexcept
{

}
step& step::operator=(step &&toMove) noexcept
{
	return *this;
}
std::complex<double> step::get(long long int n)
{
	return n>=0 ? 1.0 : 0.0;
}
