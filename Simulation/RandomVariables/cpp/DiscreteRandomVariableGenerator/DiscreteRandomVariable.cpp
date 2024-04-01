// DiscreateRandomVariable.cpp

#include "DiscreteRandomVariable.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>



namespace  QuantResearch {

DiscreteRandomVariableGenerator::DiscreteRandomVariableGenerator(GeneratorType type, double p0, int sides)
: m_generatorType(type), m_p0(p0), m_sides(sides)
{
	srand(time(0));
	
	if (m_generatorType == GeneratorType::BERNOULLI) {	
		double p = p0;
		double q = 1 - p;
		m_partion.push_back(p);
		m_partion.push_back(q);
	}
	
	else if (m_generatorType == GeneratorType::DISCRETE) {
		if (p0 < 0.0) {
			double sum = 0.0;
			for (int i = 0; i < sides; ++i) {
				sum += (1.0 / (double)sides);
				m_partion.push_back(sum);
			}
		}
		

	}
	else {
		throw std::exception("Invalid generator type");
	}


}

DiscreteRandomVariableGenerator::~DiscreteRandomVariableGenerator()
{
		
}

double DiscreteRandomVariableGenerator::uniform()
{
	return (double)rand() / double(RAND_MAX);
}


int DiscreteRandomVariableGenerator::RollDie()
{	
		
	double u = uniform();
	for (int i = 0; i < m_sides; ++i) {
	if ( u>=0.0 && u < m_partion[0])
		return	1;
	if (u >= m_partion[0] && u < m_partion[1])
		return	2;
	if (u >= m_partion[1] && u < m_partion[2])
		return	3;
	if (u >= m_partion[2] && u < m_partion[3])
		return	4;
	if (u >= m_partion[3] && u < m_partion[4])
		return	5;
	if (u >= m_partion[4] && u < m_partion[5])
		return	6;
	
	}

	return 0;
}

double DiscreteRandomVariableGenerator::probability(int w)
{
	if (m_generatorType == GeneratorType::BERNOULLI) {
		switch (w) {
		case 1:
			return m_partion[0];
			break;
		case 0:
			return m_partion[1];
			break;
		}
	}
	if (m_generatorType == GeneratorType::DISCRETE) {
		switch (w) {
		case 1:
			return m_partion[0];
			break;
		case 2:
			return m_partion[1];
			break;
		case 3:
			return m_partion[2];
			break;
		case 4:
			return m_partion[3];
			break;
		case 5:
			return m_partion[4];
			break;
		case 6:
			return m_partion[5];
			break;
		}
	}
	return 0.0;
}



int DiscreteRandomVariableGenerator::GenerateBernoulli()
{
	if (m_generatorType != GeneratorType::BERNOULLI) throw std::exception("Invalid Generator type");	
	double u = uniform();
	
	if (u < m_partion[0])
		return 1;
		else
		return 0;
}

}