/**
 *
 * Created by Pierre-Marie (aka Radiateurs)
 * The 30th of January 2018
 *
 * This class implement the fitness function of a developping Agent.
 *
 */

#ifndef		DEVELOPPING_AGENT_HH
# define	DEVELOPPING_AGENT_HH

# include	"Agent.hh"

class		DeveloppingAgent : public Agent
{
public:
  DeveloppingAgent(int id);
  DeveloppingAgent(int id, int seed, char DNA[DNA_LENGTH] = NULL);
  DeveloppingAgent(int id, const Agent& parent1, const Agent& parent2, int crossover_point);
  DeveloppingAgent(int id, const DeveloppingAgent& parent1,		\
		   const DeveloppingAgent& parent2, int crossover_point);
  DeveloppingAgent(const Agent& old);
  DeveloppingAgent(const DeveloppingAgent& old);

  // DTOR
  virtual ~DeveloppingAgent();

  // CTOR by copy
  DeveloppingAgent& operator=(const DeveloppingAgent& old);
  DeveloppingAgent& operator=(const Agent& old);

  virtual int	fitnessFunction();
};

#endif		/* DEVELOPPING_AGENT_HH */
