#include "impulse.hpp"
impulse::impulse()
{

}
impulse::impulse(const impulse &toCopy) noexcept
{

}
impulse& impulse::operator=(const impulse &toCopy) noexcept
{
	return *this;
}
impulse::impulse(impulse &&toMove) noexcept
{

}
impulse& impulse::operator=(impulse &&toMove) noexcept
{
	return *this;
}
std::complex<double>	impulse::get(long long int n)
{
	return n==0 ? 1.0 : 0.0;
}
