#ifndef BGCalc_h
#define BGCalc_h

... include header files ...

class BGCalc: ...base classes... {

 public:

  BGCalc( const AnalysisInfo* info );
  virtual ~BGCalc();

  // function to be called at execution start
  virtual void beginJob();
  // function to be called at execution end
  virtual void   endJob();
  // function to be called for each event
  virtual void update( const Event& ev );

 private:

  // min and max energy, min and max point, number of selected events
  ...

  // sum of energies and sum of square energies
  ...

  BGCalc           ( const BGCalc& x );
  BGCalc& operator=( const BGCalc& x );

};

#endif

