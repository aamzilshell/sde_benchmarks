#ifndef _STEPPER_H_
#define _STEPPER_H_

#include <utils/iterators.cpp> 
#include <state_attributes.h> 


template < 
  class state_type      , // vector<double> by default
  class time = double   ,
  class Traits = State_traits<state_type>
>
class EulerStepper() {
  public :
    typedef time time_type ;
    typedef typename Traits::state_stype state_stype  ;
    typedef typename Traits::value_type  value_type   ;

  public :
    EulerStepper() = default ;
    EulerStepper(const state_type& X){
      adjustSize(X) ; 
    }
    void adjustSize(const state_type& X) { 
      Traits::adjust_size(X , m_dX);
    } 
    // perform one step : dX
    template <class stochastic_model>
    void step_forward(stochastic_model& model, state_type& X, const state_type& const_dX, time dt) {
      increment(Traits::begin(X), Traits::end(X), Traits::begin(const_dX)) ;
    }
  
    template <class stochastic_model>
    void step_forward(stochastic_model& model, state_type& X, time dt){
      model(X, m_dX, dt) ;
      step_forward(model, X, m_dX, dt) ;
    }

 private :
    state_type m_dX ; 
};






#endif
