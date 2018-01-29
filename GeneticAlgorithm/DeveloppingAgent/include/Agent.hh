/**
 *
 * Created by Pierre-Marie
 * The 29th of January 2018
 *
 */

#ifndef		AGENT_HH
# define	AGENT_HH

# define	DNA_LENGTH		(127)
# define	MINIMIZE_RATE		(100)

class		Agent
{
private:
  int		_id;
  char		_DNA[DNA_LENGTH];
  int		_seed;

public:
  // CTOR
  Agent(int id);
  Agent(int id, int seed, char DNA[DNA_LENGTH] = NULL);

  Agent(int id, const Agent parent1, const Agent parent2, int crossover_point);
  Agent(const Agent& old);

  // DTOR
  ~Agent();

  // CTOR by copy
  Agent& operator=(const Agent& old);

  // GTOR
  int		getId() const;
  int		getSeed() const;
  char		getGenome(int index) const;
};

#endif		/*AGENT_HH*/
