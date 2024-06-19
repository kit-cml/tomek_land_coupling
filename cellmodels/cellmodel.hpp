#ifndef CELL_HPP
#define CELL_HPP

class Cellmodel
{

protected:
	Cellmodel(){}
public:
  bool isEctopic;
  bool isS1;
	unsigned short algebraic_size;
  unsigned short constants_size;
  unsigned short states_size;
  unsigned short gates_size;
  unsigned short current_size;
  unsigned short concs_size;
  double ALGEBRAIC[255];
  double CONSTANTS[255];
  double RATES[255];
  double STATES[255];
  char gates_header[255];
  unsigned short gates_indices[255];
  char current_header[255];
  unsigned short current_indices[255];
  char concs_header[255];
  unsigned short concs_indices[255];
  virtual ~Cellmodel() {}

  virtual void initConsts() = 0;
  virtual void initConsts(double type){} // in tomek
  virtual void initConsts (double type, bool is_dutta){}
  virtual void initConsts(double type, double conc, double *hill){} //in tomek
  // virtual void initConsts (double type, double conc, const double *hill, const double *herg){}
  virtual void initConsts(double type, double conc, double *hill, bool is_dutta){}
  virtual void initConsts (double type, double bcl, double conc, double *hill, double *herg){} // here is what theyre using
  virtual void initConsts(double type, double bcl, double conc, double *hill, bool is_dutta){}
  virtual void initConsts(double type, double conc, double *hill, double* boot){}
  virtual void initConsts( bool is_skinned, bool BETA, double* y){}
  
  // virtual void computeRates() = 0;
  virtual void computeRates(double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC){} // in tomek
  virtual void computeRates(double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC, double land_trpn){} // now tomek should use this, for coupling
  virtual void computeRates(double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC, double *y){}

  virtual double set_time_step (double TIME, double time_point, double min_time_step, double max_time_step, double min_dV, double max_dV,
                                double* CONSTANTS, double* RATES,double* STATES, double* ALGEBRAIC) {};

  // virtual void solveAnalytical() = 0;
  virtual void solveAnalytical(double dt) {} // created for tomek
  // virtual void solveAnalytical(double dt, double Ca_TRPN) {}
  virtual void solveAnalytical(int forward_euler_only, double dt, double *CONSTANTS, double *RATES, double* STATES, double* ALGEBRAIC) {};

  virtual void solveEuler( double dt, double t, double Cai_input ){}
  virtual void gaussElimination(double *A, double *b, double *x, int N){};
  virtual void solveRK4(double TIME,double dt) {}
};

#endif
