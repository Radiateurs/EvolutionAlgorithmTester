/**
 *
 * Created by Pierre-Marie (aka Radiateurs)
 * The 29th of January 2018
 *
 */

#include	<stdexcept>

#include	<cstdlib>
#include	<ctime>

#include	"Agent.hh"

Agent::Agent(int id)
{
  int		i;
  int		tmp;
  
  i = 0;
  this->_seed = time(NULL);
  this->_id = id;
  this->_fitness = 0;
  this->_minValue = MIN_VALUE;
  this->_maxValue = MAX_VALUE;
  this->_lengthMax = GENOTYPE_LENGTH;
  this->_genotype = new std::list<int>();
  srand(this->_seed);
  while (i < this->_lengthMax)
    {
      this->_genotype->push_back((rand() % this->_maxValue) + this->_minValue);
      i++;
    }
}

Agent::Agent(int id, int seed, const std::list<int> *genotype)
{
  int		i;
  std::list<int>::iterator	it;
  
  i = 0;
  this->_id = id;
  this->_seed = seed;
  this->_fitness = 0;
  this->_minValue = MIN_VALUE;
  this->_maxValue = MAX_VALUE;
  this->_lengthMax = GENOTYPE_LENGTH;
  this->_genotype = std::list<int>();
  srand(this->_seed);
  if (genotype != NULL)
    {
      it = genotype->begin();
      while (it != genotype->end() && i < this->_lengthMax)
	{
	  this->_genotype->push_back(*it);
	  it++;
	  i++;
	}
    }
  while (i < this->_lengthMax)
    {
      this->_genotype->push_back((rand() % this->_maxValue) + this->_minValue);
      i++;
    }
}

Agent::Agent(int id, int seed, int lengthMax, const std::list<int> *genotype)
{
  int		i;
  std::list<int>::iterator	it;
  
  i = 0;
  this->_id = id;
  this->_seed = seed;
  this->_fitness = 0;
  this->_minValue = MIN_VALUE;
  this->_maxValue = MAX_VALUE;
  this->_lengthMax = lengthMax;
  this->_genotype = std::list<int>();
  srand(this->_seed);
  if (genotype != NULL)
    {
      it = genotype->begin();
      while (it != genotype->end() && i < this->_lengthMax)
	{
	  this->_genotype->push_back(*it);
	  it++;
	  i++;
	}
    }
  while (i < this->_lengthMax)
    {
      this->_genotype->push_back((rand() % this->_maxValue) + this->_minValue);
      i++;
    }
}

Agent::Agent(int id, int seed, int lengthMax, int minValue, int maxValue,
	     const std::list<int> *genotype)
{
  int		i;
  std::list<int>::iterator	it;
  
  i = 0;
  this->_id = id;
  this->_seed = seed;
  this->_fitness = 0;
  this->_minValue = minValue;
  this->_maxValue = maxValue;
  this->_lengthMax = lengthMax;
  this->_genotype = std::list<int>();
  srand(this->_seed);
  if (genotype != NULL)
    {
      it = genotype->begin();
      while (it != genotype->end() && i < this->_lengthMax)
	{
	  this->_genotype->push_back(*it);
	  it++;
	  i++;
	}
    }
  while (i < this->_lengthMax)
    {
      this->_genotype->push_back((rand() % this->_maxValue) + this->_minValue);
      i++;
    }
}

Agent::Agent(int id, const Agent& parent1, const Agent& parent2, int crossover_point)
{
  int		i;
  
  i = 0;
  this->_id = id;
  if (parent1.getSeed() == parent2.getSeed())
    this->_seed = parent1.getSeed();
  else
    this->_seed = time(NULL);
  this->_fitness = 0;
  if (parent1.getMinValue() == parent2.getMinValue())
    this->_minValue = parent1.getMinValue();
  else    
    this->_minValue = MIN_VALUE;
  if (parent1.getMaxValue() == parent2.getMaxValue())
    this->_maxValue = parent1.getMaxValue();
  else    
    this->_minValue = MAX_VALUE;
  if (parent1.getLengthMax() == parent2.getLengthMax())
    this->_lengthMax = parent1.getLengthMax();
  else
    this->_lengthMax = GENOTYPE_LENGTH;
  this->_genotype = std::list<int>();
  while (i < this->_lengthMax)
    {
      if (i < crossover_point)
	this->_genotype->push_back(parent1.getGene(i));
      else
	this->_genotype->push_back(parent2.getGene(i));
      i++;
    }
}

Agent::Agent(const Agent& old)
{
  int		i;
  
  i = 0;
  this->_id = old.getId();
  this->_seed = old.getSeed();
  this->_fitness = old.getFitness();
  this->_lengthMax = old.getLengthMax();
  this->_minValue = old.getMinValue();
  this->_maxValue = old.getMaxValue();
  this->_genotype = std::list<int>();
  while (i < old.getGenotypeSize() && i < this->_lengthMax)
    {
      this->_genotype->push_back(old.getGene(i));
      i++;
    }
}

Agent::~Agent()
{
  if (this->genotype != NULL)
    {
      this->_genotype->clear();
      delete (this->_genotype);
    }
}

Agent&		Agent::operator=(const Agent & old)
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

int	Agent::getId() const
{
  int	id;

  id = this->_id;
  return (id);
}

int	Agent::getSeed() const
{
  return (this->_seed);
}

char	Agent::getGene(int index) const
{
  if (index < DNA_LENGTH)
    return (this->_DNA[index]);
  throw (new std::out_of_range("Index too large for the DNA_LENGTH defined."));
}

int	Agent::getFitness() const
{
  return (_fitness);
}

void	Agent::setFitness(int fitness)
{
  this->_fitness = fitness;
}
