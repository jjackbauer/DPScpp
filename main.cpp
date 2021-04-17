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
#include "fourierTransformation.hpp"
#include "product.hpp"
#include <iostream>
#include <complex>
#define begin -10
#define end 10

void print(std::vector<std::complex<double>> seq, bool mode=true, bool polar=false)
{
	long long int k;

	std::cout<<"([";
	if(polar)
	{
		if(mode)
		{

			for(k=0;k<seq.size()-1;k++)
			{
				std::cout<<std::abs(seq.at(k))<<" ,";
			}
			std::cout<<std::abs(seq.at(k))<<" ])";

		}
		else
		{
			for(k=0;k<seq.size()-1;k++)
			{
				std::cout<<std::arg(seq.at(k))<<" ,";
			}
			std::cout<<std::arg(seq.at(k))<<" ])";
		}
	}
	else
	{
		if(mode)
		{
			for(k=0;k<seq.size()-1;k++)
			{
				std::cout<<std::real(seq.at(k))<<" ,";
			}
			std::cout<<std::real(seq.at(k))<<" ])";
		}
		else
		{
			for(k=0;k<seq.size()-1;k++)
			{
				std::cout<<std::imag(seq.at(k))<<" ,";
			}
			std::cout<<std::imag(seq.at(k))<<" ])";
		}
	}

	std::cout<<std::endl;
}

void p1_question1A()
{
	std::cout<<"Question 1A"<<std::endl;
	impulse i;
	delay	i3(3,&i), i8(8,&i);
	sum x(&i3,&i8);
	std::vector<std::complex<double>> seq;
	seq = x.getSequence(begin, end);
	print(seq);
}
void p1_question1B()
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
void p1_question1C()
{
	std::cout<<"Question 1C"<<std::endl;
	cosine	cossenoide(0.05,90.0);
	std::vector<std::complex<double>> seq;
	seq = cossenoide.getSequence(1.5*begin,1.5*end);
	print(seq);
}
void p1_question1D()
{
	std::cout<<"Question 1D"<<std::endl;
	exponential exponencial(std::complex<double> (1/12.0 , M_PI/6.0));
	std::vector<std::complex<double>> seq;
	seq = exponencial.getSequence(1.5*begin,1.5*end);
	print(seq);
	print(seq,false);
}
void p1_question2A()
{
	std::cout<<"Question 2A"<<std::endl;
	step d;
	delay	d8(8,&d), d4(4,&d);
	scalar nd8(-1.0,&d8),nd4(-1.0,&d4);
	sum x(&d,&nd8),h(&d,&nd4);
	convolution y(30,&x,&h);
	std::vector<std::complex<double>> seq;
	seq = y.getSequence(3*begin,3*end);
	print(seq);
}
void p1_question2B()
{
	std::cout<<"Question 2B"<<std::endl;
	step d;
	delay	dn1(-1,&d),d2(2,&d), d4(4,&d);
	scalar nd2(-1.0,&d2),nd4(-1.0,&d4);
	sum x(&dn1,&nd2),h(&d,&nd4);
	convolution y(30,&x,&h);
	std::vector<std::complex<double>> seq;
	seq = y.getSequence(3*begin,3*end);
	print(seq);
}
void p1_question3A()
{
	std::cout<<"Question 3A"<<std::endl;
	powerSeries p(2.0,0.9);
	noise n(1.0,-0.5);
	sum x(&p,&n);
	sequence xt(0,40,&x);
	std::vector<std::complex<double>> seq;
	seq = xt.getSequence(0,4*end);
	print(seq);

	for(int m=2; m<10; m++)
	{
		std::cout<<"M : "<<m<<std::endl;
		movingAverage y(m,&xt);
		seq = y.getSequence(0,4*end);
		print(seq);
	}


}
void p1_question4A()
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

void project01()
{
	std::cout<<"Projeto 1"<<std::endl;
	p1_question1A();
	p1_question1B();
	p1_question1C();
	p1_question1D();
	p1_question2A();
	p1_question2B();
	p1_question3A();
	p1_question4A();
}

void p2_question1A()
{
	std::cout<<"Question 1A"<<std::endl;
	std::vector<std::complex<double>> seq;
	cosine s1(0.05,0),s2(0.47,0);
	sum y(&s1,&s2);
	sequence yt(0,100,&y);
	seq = yt.getSequence(0, 100);
	std::cout<<"Unfiltered Signal"<<std::endl;
	print(seq);
	movingAverage f(2,&yt);
	seq = f.getSequence(0, 100);
	std::cout<<"Filtered Signal"<<std::endl;
	print(seq);
	fourierTransformation ytF(100,&yt), fF(100,&f);
	std::cout<<"Unfiltered Signal Fourier Transformation Magnitude"<<std::endl;
	print(ytF.getFourierSampling(1000));
	std::cout<<"Unfiltered Signal Fourier Transformation Phase"<<std::endl;
	print(ytF.getFourierSampling(1000),false);
	std::cout<<"Filtered Signal Fourier Transformation Magnitude"<<std::endl;
	print(fF.getFourierSampling(1000));
	std::cout<<"Filtered Signal Fourier Transformation Phase"<<std::endl;
	print(fF.getFourierSampling(1000),false);
}
void p2_question1B()
{
	std::cout<<"Question 1B"<<std::endl;
	std::vector<std::complex<double>> seq;
	cosine s1(0.05,0),s2(0.47,0);
	sum y(&s1,&s2);
	sequence yt(0,100,&y);
	seq = yt.getSequence(0, 100);
	std::cout<<"Unfiltered Signal"<<std::endl;
	print(seq);
	std::vector<std::complex<double>> a, b;
	//vector a
	a.push_back(1.0);
	//vector b
	b.push_back(0.5);
	b.push_back(-0.5);
	differenceEquation h(a,b);
	h.impulse(100);
	std::cout<<"Filter Impulse Response"<<std::endl;
	print(h.getSequence(0, 100));
	convolution s(100,&yt,&h);
	std::cout<<"Signal Filtered"<<std::endl;
	print(s.getSequence(0, 100));
	fourierTransformation ytF(100,&yt), sF(100,&s);
	std::cout<<"Unfiltered Signal Fourier Transformation Magnitude"<<std::endl;
	print(ytF.getFourierSampling(1000));
	std::cout<<"Unfiltered Signal Fourier Transformation Phase"<<std::endl;
	print(ytF.getFourierSampling(1000),false);
	std::cout<<"Signal Filtered Fourier Transformation Magnitude"<<std::endl;
	print(sF.getFourierSampling(1000));
	std::cout<<"Signal Filtered Fourier Transformation Phase"<<std::endl;
	print(sF.getFourierSampling(1000),false);
}
void p2_question2A()
{
	std::cout<<"Question 2A"<<std::endl;
	step u;
	impulse i;
	std::vector<std::complex<double>> seq;
	cosine x1(0.1/(2*M_PI),0),x2(0.4/(2*M_PI),0);
	product x1u(&x1,&u),x2u(&x2,&u);
	sum x(&x1u,&x2u);
	std::cout<<"Signal Unfiltered"<<std::endl;
	print(x.getSequence(0, 100));
	fourierTransformation xF(100,&x);
	std::cout<<"Signal Unfiltered Fourier Transformation Magnitude"<<std::endl;
	print(xF.getFourierSampling(1000));
	std::cout<<"Signal Unfiltered Fourier Transformation Phase"<<std::endl;
	print(xF.getFourierSampling(1000),false);
	delay i1(1,&i),i2(2,&i);
	scalar p1(-6.76,&i),p2(13.46,&i1),p3(-6.76,&i2);
	sum aux(&p1,&p2),h(&aux,&p3);
	convolution y(100,&x,&h);
	seq=y.getSequence(0, 100);
	std::cout<<"Signal Filtered"<<std::endl;
	print(seq);
	fourierTransformation yF(100,&y);
	std::cout<<"Signal Filtered Fourier Transformation Magnitude"<<std::endl;
	print(yF.getFourierSampling(1000));
	std::cout<<"Signal Filtered Fourier Transformation Phase"<<std::endl;
	print(yF.getFourierSampling(1000),false);

}
void p2_question3()
{
	std::cout<<"Question 3"<<std::endl;
	step u;
	delay u5(5,&u);
	scalar nu5(-1.0,&u5);
	sum quad(&u,&nu5);
	scalar x(5.0,&quad);
	fourierTransformation xF(100,&x);
	std::cout<<"Signal Filtered Fourier Transformation Magnitude"<<std::endl;
	print(xF.getFourierSampling(1000),true,true);
	std::cout<<"Signal Filtered Fourier Transformation Phase"<<std::endl;
	print(xF.getFourierSampling(1000),false,true);
	std::cout<<"Signal Filtered Fourier Transformation Real"<<std::endl;
	print(xF.getFourierSampling(1000));
	std::cout<<"Signal Filtered Fourier Transformation Imaginary"<<std::endl;
	print(xF.getFourierSampling(1000),false);
}

void project02()
{
	p2_question1A();
	p2_question1B();
	p2_question2A();
	p2_question3();
}

int main ()
{
	//project01();
	project02();
}
