#ifndef TotalEnergy_h
#define TotalEnergy_h

... include header files ...

class TotalEnergy: ...base classes... {

  ... friend declaration ...

 public:

  // function to be called when a new event arrives
  virtual void update( const Event& ev );

  // sum of measurements, no background subtraction
  float rawSum();

 private:

  // sum of data, no background subtraction
  ...

  TotalEnergy();
  ~TotalEnergy();
  TotalEnergy           ( const TotalEnergy& x );
  TotalEnergy& operator=( const TotalEnergy& x );

};

#endif

