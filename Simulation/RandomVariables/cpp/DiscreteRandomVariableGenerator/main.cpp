#include "DiscreteRandomVariable.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace QuantResearch;

int main()
{

    try {
    // Generate 100 Bernoulli Random Variables with p = 1/2 (Show in set of ten bernoulli random variables
    DiscreteRandomVariableGenerator bernoulli_gen(DiscreteRandomVariableGenerator::GeneratorType::BERNOULLI, 0.5, 2);    
    int count = 0;
    for (int i = 0; i < 100; ++i) {
        std::cout << bernoulli_gen.GenerateBernoulli() << ", ";
        count++;
        if (count == 10) {
            std::cout <<"\n";
            count = 0;
        }
    }    
    std::cout << "\n";
    std::cout << "Bernoulli: Probability of getting head  P(X = H) = " << bernoulli_gen.probability(1) << std::endl;
    
    // Roll 10 Dice p = 1/6 
    std::cout << "Rolling 6 sides die 10 times with P = 1/6" << std::endl;
    DiscreteRandomVariableGenerator g(DiscreteRandomVariableGenerator::GeneratorType::DISCRETE, -1.0, 6);
    for (int i = 0; i < 10; ++i) {
        std::cout << g.RollDie() << ", ";
    }
   
    std::cout << "\n";

    std::cout << "Die face probability of getting 4: P(X = 4) = " << g.probability(4) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

}   


    