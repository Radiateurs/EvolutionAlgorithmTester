/**
 *
 * Created by Pierre-Marie (aka Radiateurs)
 * The 30th of January 2018
 *
 */

#ifndef		POPULATION_HH
# define	POPULATION_HH

# include	<list>

# include	"Agent.hh"

# define	DEFAULT_SIZE	(30)
# define	KILLING_AGENT_RATE	(10)

template <class T>
class		Population
{
private:
  std::list<Agent*>	*_agents;
  int		_size;

public:
  Population();
  Population(int size);
  Population(const Population& old);

  Population& operator=(const Population& old);

  ~Population();

  const std::list<Agent*>	*getAgents() const;
  const Agent*	getAgent(unsigned int index) const;
  int		getSize() const;
  int		getDNASize() const;

  void		setSize(int size);

  void		initiate();
  void		simulate();
  void		killWeakAgents(); // Kill half agents based on fitness
  void		crossoverMutate(int crossover_point);

private:
  void		sort();
  void		shake();
};

#endif		/* POPULATION_HH */
