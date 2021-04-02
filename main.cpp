#define _USE_MATH_DEFINES
#include "signal.hpp"
#include <cmath>
#include "impulse.hpp"
#include "step.hpp"
#include "cosine.hpp"
#include "exponential.hpp"
#include "convolution.hpp"
#include "delay.hpp"
#include <iostream>
#include <complex>

int main ()
{
	int begin=-10,end=10;
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
	std::cout<<std::endl;






}
