//
// Created by shmuelsuna on 13/01/2020.
//

#ifndef EX4__CACHEMANAGER_H_
#define EX4__CACHEMANAGER_H_


using namespace std;

template<class P, class S>
class CacheManager {
 public:
  virtual void save(P problem, S solution) = 0;

  virtual S getSolution(P problem) = 0;

  virtual bool isThereASolution(P problem) = 0;

};














#endif //EX4__CACHEMANAGER_H_
