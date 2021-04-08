#define _USE_MATH_DEFINES
#include "signal.hpp"
#include <cmath>
#include "impulse.hpp"
#include "step.hpp"
#include "cosine.hpp"
#include "exponential.hpp"
#include "convolution.hpp"
#include "delay.hpp"
#include "sum.hpp"
#include "movingAverage.hpp"
#include "scalar.hpp"
#include "powerSeries.hpp"
#include "differenceEquation.hpp"
#include "noise.hpp"
#include <iostream>
#include <complex>
#define begin -10
#define end 10

void print(std::vector<std::complex<double>> seq, bool mode=true)
{
	for(auto valor : seq)
		if(mode)
			std::cout<<std::real(valor)<<" ";
		else
			std::cout<<std::imag(valor)<<" ";
	std::cout<<std::endl;
}

void question1A()
{
	std::cout<<"Question 1A"<<std::endl;
	impulse i;
	delay	i3(3,&i), i8(8,&i);
	sum x(&i3,&i8);
	std::vector<std::complex<double>> seq;
	seq = x.getSequence(begin, end);
	print(seq);
}
void question1B()
{
	std::cout<<"Question 1B"<<std::endl;
	step d;
	delay	d1(1,&d), d4(4,&d);
	scalar s(-1,&d4);
	sum x(&d1,&s);
	std::vector<std::complex<double>> seq;
	seq = x.getSequence(begin, end);
	print(seq);
}
void question1C()
{
	std::cout<<"Question 1C"<<std::endl;
	cosine	cossenoide(0.05,90.0);
	std::vector<std::complex<double>> seq;
	seq = cossenoide.getSequence(1.5*begin,1.5*end);
	print(seq);
}
void question1D()
{
	std::cout<<"Question 1D"<<std::endl;
	exponential exponencial(std::complex<double> (1/12.0 , M_PI/6.0));
	std::vector<std::complex<double>> seq;
	seq = exponencial.getSequence(1.5*begin,1.5*end);
	print(seq);
	print(seq,false);
}
void question2A()
{
	std::cout<<"Question 2A"<<std::endl;
	step d;
	delay	d8(8,&d), d4(4,&d);
	scalar nd8(-1,&d8),nd4(-1,&d4);
	sum x(&d,&nd8),h(&d,&nd4);
	convolution y(30,&x,&h);
	std::vector<std::complex<double>> seq;
	seq = y.getSequence(3*begin,3*end);
	print(seq);
}
void question2B()
{
	std::cout<<"Question 2B"<<std::endl;
	step d;
	delay	dn1(-1,&d),d2(2,&d), d4(4,&d);
	scalar nd2(-1,&d2),nd4(-1,&d4);
	sum x(&dn1,&nd2),h(&d,&nd4);
	convolution y(30,&x,&h);
	std::vector<std::complex<double>> seq;
	seq = y.getSequence(3*begin,3*end);
	print(seq);
}
void question3A()
{
	std::cout<<"Question 3A"<<std::endl;
	powerSeries p(2.0,0.9);
	noise n(1.0,-0.5);
	sum x(&p,&n);
	std::vector<std::complex<double>> seq;
	seq = x.getSequence(0,4*end);
	print(seq);

	for(int m=2; m<10; m++)
	{
		std::cout<<"M : "<<m<<std::endl;
		movingAverage y(m,&x);
		seq = y.getSequence(0,4*end);
		print(seq);
	}


}
void question4A()
{
	std::cout<<"Question 4A"<<std::endl;
	std::vector<std::complex<double>> a, b;
	//vector a
	a.push_back(1.0);
	a.push_back(0.71);
	a.push_back(-0.46);
	a.push_back(-0.62);
	a.push_back(-0.46);
	//vector b
	b.push_back(0.9);
	b.push_back(-0.45);
	b.push_back(0.35);
	b.push_back(0.002);

	differenceEquation h(a,b);
	std::vector<std::complex<double>> seq;
	seq = h.impulse(40);
	print(seq);

}


int main ()
{
	question1A();
	question1B();
	question1C();
	question1D();
	question2A();
	question2B();
	question3A();
	question4A();
}
