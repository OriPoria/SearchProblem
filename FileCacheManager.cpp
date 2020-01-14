//
// Created by shmuelsuna on 13/01/2020.
//

#include <fstream>
#include <cstring>
#include <sstream>
#include "FileCacheManager.h"


FileCacheManager::FileCacheManager(){

}



string FileCacheManager::getSolution(string problem) {
  string solution;
  string name_of_file =  this->problem_solution_map[problem];

  string item_name;
  ifstream nameFileout;
  nameFileout.open(name_of_file+".txt");
  string line;
  while(std::getline(nameFileout, line))
  {
   solution +=line;
    // TODO: assign item_name based on line (or if the entire line is
    // the item name, replace line with item_name in the code above)
  }

  return solution;
}


//void FileCacheManager::loadFromFile(){

//}


//void FileCacheManager::saveToFile() {

//}





void FileCacheManager::save(string problem, string solution) {

  string name_of_file =getFileNameFromHash(problem);

  this->problem_solution_map[problem] = name_of_file;//save to map


  //write to file
  std::ofstream out(name_of_file+".txt");
  out << solution;
  out.close();

}


bool FileCacheManager::isThereASolution(string problem) {

  bool f =  this->problem_solution_map.find(problem) != this->problem_solution_map.end();
  return f;
}

unsigned int FileCacheManager::fnv_hash (string key, int len)
{
  unsigned int h = 2166136261;
  int i;

  for (i = 0; i < len; i++)
    h = (h*16777619) ^ key[i];

  return h;
}

string FileCacheManager::getFileNameFromHash(string problem){


  int n = problem.length();

  // declaring character array
  char char_array[n + 1];

  // copying the contents of the
  // string to char array
  strcpy(char_array, problem.c_str());

  unsigned int digit =  fnv_hash(problem,n+1);
  // declaring output string stream
  ostringstream str1;
  // Sending a number as a stream into output
  // string
  str1 << digit;
  // the str() coverts number into string
  string geek = str1.str();
  string file_name = "file"+geek;
  return file_name;
}
