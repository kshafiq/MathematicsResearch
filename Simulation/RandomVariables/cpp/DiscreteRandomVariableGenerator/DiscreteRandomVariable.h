#ifndef HEADER_DISCRETE_RANDOM_VARIABLE_GENERATOR_INCLUDED

#include <map>
#include <vector>


namespace  QuantResearch {


class DiscreteRandomVariableGenerator {
public:	
	enum class GeneratorType {
		BERNOULLI,
		DISCRETE


	};
	DiscreteRandomVariableGenerator(GeneratorType type, double p0, int sides);
	virtual ~DiscreteRandomVariableGenerator();

	double uniform();
	int RollDie();
	int GenerateBernoulli();
	double probability(int w);


private:
	double m_p0;
	std::vector<double> m_partion;
	GeneratorType m_generatorType;	
	int m_sides;

};




}

#endif HEADER_DISCRETE_RANDOM_VARIABLE_GENERATOR_INCLUDED

