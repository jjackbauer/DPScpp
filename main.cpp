#include "signal.hpp"
#include "impulse.hpp"
#include "step.hpp"
#include <iostream>

int main ()
{
	step degrau;
	impulse impulso;
	signal *sinalDegrau=&degrau,*sinalImpulso= &impulso;
	std::vector<std::complex<double>> sequenceDegrau,sequenceImpulso, sequenceSinalDegrau, sequenceSinalImpulso;


	sequenceDegrau = degrau.getSequence(-10, 10);
	sequenceImpulso = impulso.getSequence(-10, 10);
	sequenceSinalDegrau = sinalDegrau->getSequence(-10, 10);
	sequenceSinalImpulso = sinalImpulso->getSequence(-10, 10);

	for(auto valor : sequenceDegrau)
		std::cout<<valor<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceImpulso)
			std::cout<<valor<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalDegrau)
			std::cout<<valor<<" ";
	std::cout<<std::endl;

	for(auto valor : sequenceSinalImpulso)
			std::cout<<valor<<" ";
	std::cout<<std::endl;




}
