//
// Created by shmuelsuna on 13/01/2020.
//

#include "FileCacheManager.h"


FileCacheManager::FileCacheManager(){

}



string FileCacheManager::getSolution(string problem) {

  string solution =  this->problem_solution_map[problem];
  return solution;
}




void FileCacheManager::save(string problem, string solution) {

  this->problem_solution_map[problem] = solution;

}


bool FileCacheManager::isThereASolution(string problem) {

  bool f =  this->problem_solution_map.find(problem) != this->problem_solution_map.end();
  return f;
}