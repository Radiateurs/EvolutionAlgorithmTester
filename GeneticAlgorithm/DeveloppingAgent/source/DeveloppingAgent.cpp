/*
 *
 * Created by Pierre-Marie (aka Radiateurs)
 * The 30th of January 2018
 *
 */

#include	<stdexcept>

#include	<cstdlib>
#include	<ctime>

#include	"DeveloppingAgent.hh"

DeveloppingAgent::DeveloppingAgent(int id) : Agent(id)
{
}

DeveloppingAgent::DeveloppingAgent(int id, int seed, char DNA[DNA_LENGTH])
  : Agent(id, seed, DNA)
{
}

DeveloppingAgent::DeveloppingAgent(int id, const Agent& parent1,		\
				   const Agent& parent2, int crossover_point)
  : Agent(id, parent1, parent2, crossover_point)
{
}

DeveloppingAgent::DeveloppingAgent(int id, const DeveloppingAgent& parent1, \
				   const DeveloppingAgent& parent2, int crossover_point)
  : Agent(id, parent1, parent2, crossover_point)
{
}

DeveloppingAgent::DeveloppingAgent(const Agent& old) : Agent(old)
{
}

DeveloppingAgent::DeveloppingAgent(const DeveloppingAgent& old) : Agent(old)
{
}

DeveloppingAgent&		DeveloppingAgent::operator=(const DeveloppingAgent & old)
{
  int		i;
  
  i = 0;
  this->_id = old.getId();
  this->_seed = old.getSeed();
  this->_fitness = old.getFitness();
  while (i < DNA_LENGTH)
    {
      this->_DNA[i] = old.getGene(i);
      i++;
    }
  return (*this);
}

DeveloppingAgent&		DeveloppingAgent::operator=(const Agent & old)
{
  int		i;
  
  i = 0;
  this->_id = old.getId();
  this->_seed = old.getSeed();
  this->_fitness = old.getFitness();
  while (i < DNA_LENGTH)
    {
      this->_DNA[i] = old.getGene(i);
      i++;
    }
  return (*this);
}

DeveloppingAgent::~DeveloppingAgent()
{
}

int		DeveloppingAgent::fitnessFunction()
{
  
  return (_fitness);
}
