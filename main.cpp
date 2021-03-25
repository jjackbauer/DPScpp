#include "signal.hpp"
#include "impulse.hpp"
#include "step.hpp"
#include "cosine.hpp"
#include <iostream>

int main ()
{
	step degrau;
	impulse impulso;
	cosine	cossenoide(0.05,90.0);
	signal *sinalDegrau=&degrau,*sinalImpulso= &impulso,*sinalCossenoide=&cossenoide;
	std::vector<std::complex<double>> sequenceDegrau,sequenceImpulso,sequenceCossenoide,sequenceSinalDegrau, sequenceSinalImpulso,sequenceSinalCossenoide;


	sequenceDegrau = degrau.getSequence(-10, 10);
	sequenceImpulso = impulso.getSequence(-10, 10);
	sequenceSinalDegrau = sinalDegrau->getSequence(-10, 10);
	sequenceSinalImpulso = sinalImpulso->getSequence(-10, 10);
	sequenceCossenoide = cossenoide.getSequence(-10, 10);
	sequenceSinalCossenoide = sinalCossenoide->getSequence(-10, 10);

	for(auto valor : sequenceDegrau)
		std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceImpulso)
			std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalDegrau)
			std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalImpulso)
			std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceCossenoide)
		std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalCossenoide)
		std::cout<<std::real(valor)<<" ";
	std::cout<<std::endl;




}
