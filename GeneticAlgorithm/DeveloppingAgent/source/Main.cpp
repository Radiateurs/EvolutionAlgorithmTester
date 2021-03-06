/**
 *
 * Created by Pierre-Marie (aka Radiateurs)
 * The 29th of January 2018
 *
 */

#include	<iostream>

#include	"Population.hh"
#include	"DeveloppingAgent.hh"

int		main(int argc, char *argv[])
{
  Population<DeveloppingAgent>	pop(10);
  Agent		ag = DeveloppingAgent(1);
  
  (void)argc;
  (void)argv;
  std::cout << "Initiate... ";
  pop.initiate();
  std::cout << "Done!" << std::endl << "Simulating:" << std::endl;
  pop.simulate();
  std::cout << "Simulation done succesfully." << std::endl;
  std::cout << "Mutation...";
  pop.crossoverMutate(DNA_LENGTH / 2);
  std::cout << "Done 100%." << std::endl;
  return (0);
}
