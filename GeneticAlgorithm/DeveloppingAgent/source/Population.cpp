/**
 *
 * Created by Pierre-Marie (aka Radiateurs)
 * The 30th of January 2018
 *
 */

#include	<stdexcept>
#include	<iostream>

#include	<cstdlib>

#include	"Population.hh"
#include	"DeveloppingAgent.hh"

template <class T>
Population<T>::Population()
{
  this->_size = DEFAULT_SIZE;
  this->_agents = new std::list<Agent*>();
}
  
template <class T>
Population<T>::Population(int size)
{
  this->_size = size;
  this->_agents = new std::list<Agent*>();
}

template <class T>
Population<T>::Population(const Population& old)
{
  std::list<Agent*>::const_iterator	it;
  const std::list<Agent*>	*tmp;
  
  this->_size = old.getSize();
  this->_agents = new std::list<Agent*>();
  tmp = old.getAgents();
  if (tmp != NULL)
    {
      it = tmp->begin();
      while (it != tmp->end())
	{
	  this->_agents->push_back(*it);
	  it++;
	}
    }
  else
    this->_agents = NULL;
}

template <class T>
Population<T>&	Population<T>::operator=(const Population& old)
{
  std::list<Agent*>::const_iterator	it;
  const std::list<Agent*>	*tmp;
  
  this->_size = old.getSize();
  this->_agents = new std::list<Agent*>();
  tmp = old.getAgents();
  if (tmp != NULL)
    {
      it = tmp->begin();
      while (it != tmp->end())
	{
	  this->_agents->push_back(*it);
	  it++;
	}
    }
  else
    this->_agents = NULL;
  return (*this);
}

template <class T>
Population<T>::~Population()
{
  if (this->_agents != NULL)
    {
      while (this->_agents->size() != 0)
	{
	  this->_agents->pop_front();
	}
      delete (this->_agents);
    }
}

template <class T>
const std::list<Agent*>	*Population<T>::getAgents() const
{
  return (_agents);
}

template <class T>
const Agent	*Population<T>::getAgent(unsigned int index) const
{
  unsigned int	i;
  std::list<Agent*>::const_iterator	it;

  if (this->_agents == NULL || this->_agents->empty() || this->_agents->size() < index)
    throw (new std::out_of_range("No agent at this index"));
  it = this->_agents->begin();
  i = 0;
  while (i != index)
    {
      i++;
      it++;
    }
  return (*it);
}

template <class T>
int		Population<T>::getSize() const
{
  return (this->_size);
}

template <class T>
void		Population<T>::setSize(int size)
{
  this->_size = size;
}

template <class T>
void		Population<T>::initiate()
{
  int		id;

  id = 1;
  if (this->_agents == NULL)
    this->_agents = new std::list<Agent*>();
  while (this->_agents->size() < (unsigned int)this->_size)
    {
      this->_agents->push_back(new T(id));
      id++;
    }
}

template <class T>
void		Population<T>::simulate()
{
  std::list<Agent*>::iterator	it;

  if (this->_agents == NULL || this->_agents->empty())
    throw (new std::runtime_error("The agents aren't initiate"));
  it = this->_agents->begin();
  while (it != this->_agents->end())
    {
      (*it)->setFitness((*it)->fitnessFunction());
      it++;
    }
}


/**
 *
 * Kill half of the population based on the 
 *
 */
template <class T>
void		Population<T>::killWeakAgents()
{
  unsigned int	i;
  std::list<Agent*>::iterator	it;

  it = this->_agents->begin();
  i = 0;
  while (i < this->_agents->size() / 2)
    {
      it++;
      i++;
    }
  this->_agents->erase(it, this->_agents->end()--);
}

template <class T>
void		Population<T>::crossoverMutate(int crossover_point)
{
  std::list<Agent*>	*tmp;
  int		i;
  std::list<Agent*>::iterator	it;
  std::list<Agent*>::iterator	itNext;

  this->sort(); // Allow to have the population sorted by fitness order
  this->killWeakAgents();
  i = this->_agents->size();
  tmp = new std::list<Agent*>();
  it = this->_agents->begin();
  itNext = this->_agents->begin();
  itNext++;
  while (itNext != this->_agents->end())
    {
      tmp->push_back(new T(i, *(*it), *(*itNext), crossover_point));
      itNext++;
      it++;
      i++;
    }
  tmp->push_back(new T(i, *(*(this->_agents->begin())), *(*it), crossover_point));
  it = tmp->begin();
  while (it != tmp->end())
    {
      this->_agents->push_back(new T(*(*it)));
      it++;
    }
  tmp->clear();
  delete (tmp);
}

template <class T>
void		Population<T>::sort()
{
  std::list<Agent*>	*sorted;
  std::list<Agent*>::iterator	it;
  std::list<Agent*>::iterator	itTmp;
  
  sorted = new std::list<Agent*>();
  while (!(this->_agents->empty()))
    {
      it = this->_agents->begin();
      itTmp = this->_agents->begin();
      while (it != this->_agents->end())
	{
	  if (*it != NULL && (*itTmp)->getFitness() < (*it)->getFitness())
	    itTmp = it;
	  it++;
	}
      if (*itTmp != NULL)
	  sorted->push_back(new T(*(*itTmp)));
      this->_agents->erase(itTmp);
    }
  this->_agents = sorted;
}
  
template class Population<DeveloppingAgent>;
