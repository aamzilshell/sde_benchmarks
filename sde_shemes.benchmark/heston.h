#ifndef _HESTON_H_
#define _HESTON_H_


#include <./utils/random.cpp>

// global variables for heston model
// dS = nu * S * dt + sqrt(V) * S * dW1
// dV = kappa * ( theta - V ) + gamma * sqrt(V) * dW2
// dW1 * dW2 = rho * dt

extern double nu      ;
extern double kappa   ;
extern double theta   ;
extern double gamma   ;


// correlated brownian motions W1 and W2
// dW1 * dW2 = rho * dt
extern double rho ;


class Heston {
  public :
    typedef vector< double > state_type;
    typedef vector< double > brown_type;
    void operator()(state_type& X, state_type& dX, double dt)
    {
      brownian_type dW ;
      dW[0] = normal_random(0,1) * sqrt(dt) ;
      dW[1] = rho * dW[0] + sqrt(1 - rho**2) * normal_random(0,1) * sqrt(dt)   ;

      dX[1] = kappa * ( theta - X [1] ) + gamma * sqrt(X[1]) * dW[1] ;
      dX[0] = nu * X[0] * dt + sqrt(X[1]) * X[0] * dW[0] ;
    }
};


#endif
