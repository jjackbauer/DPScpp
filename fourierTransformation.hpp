#ifndef DPSCPP_FOURIERTRANSFORMATION_HPP_
#define DPSCPP_FOURIERTRANSFORMATION_HPP_
#define _USE_MATH_DEFINES
#include "signal.hpp"
#include <cmath>
class fourierTransformation : public signal
{
	public:
		fourierTransformation(long long int k,signal *x);
		fourierTransformation(const fourierTransformation &toCopy) noexcept;
		fourierTransformation& operator=(const fourierTransformation &toCopy) noexcept;
		fourierTransformation(fourierTransformation &&toMove) noexcept;
		fourierTransformation& operator=(fourierTransformation &&toMove) noexcept;
		~fourierTransformation();
		std::complex<double>	get(long long int n);
		std::vector<std::complex<double>> getFourierSampling(long long int samples);
		long long int getK() const;
		void setK(long long int k);
		const std::vector<std::complex<double> >& getSeq() const;
		void setSeq(const std::vector<std::complex<double> > &seq);

	private:
		long long int k;
		std::vector<std::complex<double>> seq;
};
#endif /* DPSCPP_FOURIERTRANSFORMATION_HPP_ */
