/**
 *
 * Created by Pierre-Marie (aka Radiateurs)
 * The 29th of January 2018
 *
 * This abstract class is a crossover mutating genetic agent.
 * Everything is defined, only the fitness function is to define.
 *
 */

#ifndef		AGENT_HH
# define	AGENT_HH

# include	<list>

# define	MAX_VALUE		(127)
# define	MIN_VALUE		(-MAX_VALUE)
# define	GENOTYPE_LENGTH		(127)

class		Agent
{
protected:
  int		_id;
  std::list<int>	*_genotype;
  int		_seed;
  int		_lengthMax;
  int		_maxValue;
  int		_minValue;
  int		_fitness;

public:
  // CTOR
  Agent(int id);
  Agent(int id, int seed, const std::list<int> *genotype = NULL);
  Agent(int id, int seed, int lengthMax, const std::list<int> *genotype = NULL);
  Agent(int id, int seed, int minValue, int maxValue, int lenghtMax,
	const std::list<int> *genotype = NULL);
  Agent(int id, const Agent& parent1, const Agent& parent2, int crossover_point);
  Agent(const Agent& old);

  // DTOR
  ~Agent();

  // CTOR by copy
  Agent& operator=(const Agent& old);

  // GTOR
  int		getId() const;
  int		getSeed() const;
  int		getGene(int index) const;
  int		getGenotypeSize() const;
  int		getFitness() const;
  int		getMaxValue() const;
  int		getMinValue() const;
  int		getLengthMax() const;

  //STOR
  void		setFitness(int fitness);
  void		setMaxValue(int maxValue);
  void		setMinValue(int minValue);
  void		setLengthMax(int lengthMax);
  
  virtual int	fitnessFunction() = 0;
};

#endif		/*AGENT_HH*/
