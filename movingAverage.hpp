#ifndef DPSCPP_MOVINGAVERAGE_HPP_
#define DPSCPP_MOVINGAVERAGE_HPP_
#include "signal.hpp"

class movingAverage : public signal
{
	public:
		movingAverage(long long int nMean,signal *x);
		movingAverage(movingAverage &toCopy) noexcept;
		movingAverage& operator=(movingAverage &toCopy) noexcept;
		movingAverage(movingAverage &&toMove) noexcept;
		movingAverage& operator=(movingAverage &&toMove) noexcept;
		long long int getNMean() const;
		void setNMean(long long int nMean);
		signal* getX();
		void setX(signal *x);
		std::complex<double> get(long long int n);

	private:
		long long int nMean;
		signal *x;
};




#endif /* DPSCPP_MOVINGAVERAGE_HPP_ */
