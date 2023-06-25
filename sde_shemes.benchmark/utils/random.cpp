#include <iostream> 
#include <random> 
#include <cmath> 
#include <boost/math/distributions/normal.hpp> 

double uniform_random(){
  random_device rd ;
  mt19937 gen(rd()) ;
  uniform_real_distribution <> dis(0,1);
  return dis(gen) ;
}

double normal_random(double m, double s){
  double p = unif_random();
  boost::math::normal dist(m,s) ;
  return quantile(dist,p) ;
}

