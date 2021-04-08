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
#include "scalar.hpp"
#include "powerSeries.hpp"
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
	impulse i;
	delay	i3(3,&i), i8(8,&i);
	sum x(&i3,&i8);
	std::vector<std::complex<double>> seq;
	seq = x.getSequence(begin, end);
	print(seq);


}
void question1B()
{
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
	cosine	cossenoide(0.05,90.0);
	std::vector<std::complex<double>> seq;
	seq = cossenoide.getSequence(1.5*begin,1.5*end);
	print(seq);
}
void question1D()
{
	exponential exponencial(std::complex<double> (1/12.0 , M_PI/6.0));
	std::vector<std::complex<double>> seq;
	seq = exponencial.getSequence(1.5*begin,1.5*end);
	print(seq);
	print(seq,false);
}
void question2A()
{
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

}
void question3B()
{

}
void question4A()
{

}
void question4B()
{

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
	question3B();
	question4A();
	question4B();





	/*int begin=-10,end=10;
	step degrau;
	impulse impulso;
	//std::cout<<"Antes de AQUI 0";
	cosine	cossenoide(0.05,90.0);
	exponential exponencial(std::complex < double > (1/12.0 , M_PI/6.0));
	//std::cout<<"AQUI 0";

	delay degrauAtrasado(4,&degrau);
	//std::cout<<"AQUI0.1";
	convolution H(40,&impulso,&degrauAtrasado);
	signal *sinalDegrau=&degrau,*sinalImpulso= &impulso,*sinalCossenoide=&cossenoide,*sinalExponencial=&exponencial;
	std::vector<std::complex<double>> sequenceSinalDegrau, sequenceSinalImpulso,sequenceSinalCossenoide, sequenceSinalExponencial,sequenceDegrauAtrasado, SequenceConvolucao;

	sequenceSinalDegrau = (*sinalDegrau).getSequence(begin, end);
	sequenceSinalImpulso = sinalImpulso->getSequence(begin, end);
	sequenceSinalCossenoide = sinalCossenoide->getSequence(begin, end);
	sequenceSinalExponencial = sinalExponencial->getSequence(begin, end);
	sequenceDegrauAtrasado =   degrauAtrasado.getSequence(begin, end);
	//std::cout<<"AQUI"<<H.get(0)<<std::endl;
	SequenceConvolucao =  H.getSequence(-40, 40);
	//std::cout<<"AQUI 2";


	for(auto valor : sequenceSinalDegrau)
			std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalImpulso)
			std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalCossenoide)
		std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalExponencial)
		std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalExponencial)
		std::cout<<std::imag(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceDegrauAtrasado)
		std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : SequenceConvolucao)
		std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;//*/






}
