/**
 *
 * Created by Pierre-Marie
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
  
  i = 0;
  this->_seed = time(NULL);
  this->_id = id;
  srand(this->_seed);
  while (i < DNA_LENGTH)
    {
      this->_DNA[i] = rand() % MINIMIZE_RATE;
      i++;
    }
}

Agent::Agent(int id, int seed, char DNA[DNA_LENGTH])
{
  int		i;
  
  i = 0;
  this->_id = id;
  this->_seed = time(NULL);
  _id = 0;
  srand(this->_seed);
  while (i < DNA_LENGTH)
    {
      if (DNA == NULL)
	this->_DNA[i] = rand() % MINIMIZE_RATE;
      else
	this->_DNA[i] = DNA[i];
      i++;
    }
}

Agent::Agent(int id, const Agent parent1, const Agent parent2, int crossover_point)
{
  int		i;
  
  i = 0;
  this->_seed = 0;
  this->_id = id;
  while (i < DNA_LENGTH)
    {
      if (i < crossover_point)
	this->_DNA[i] = parent1.getGenome(i);
      else
	this->_DNA[i] = parent2.getGenome(i);
      i++;
    }
}

Agent::Agent(const Agent& old)
{
  int		i;
  
  i = 0;
  this->_id = old.getId();
  this->_seed = old.getSeed();
  while (i < DNA_LENGTH)
    {
      this->_DNA[i] = old.getGenome(i);
      i++;
    }
}

Agent&		Agent::operator=(const Agent & old)
{
  int		i;
  
  i = 0;
  this->_id = old.getId();
  this->_seed = old.getSeed();
  while (i < DNA_LENGTH)
    {
      this->_DNA[i] = old.getGenome(i);
      i++;
    }
  return (*this);
}

Agent::~Agent()
{
}

int	Agent::getId() const
{
  return (this->_id);
}

int	Agent::getSeed() const
{
  return (this->_seed);
}

char	Agent::getGenome(int index) const
{
  if (index < DNA_LENGTH)
    return (this->_DNA[index]);
  throw (new std::out_of_range("Index too large for the DNA LENGTH defined."));
}
