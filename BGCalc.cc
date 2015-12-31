
... include header files ...

using namespace std;

// define a builder for this analyzer and register it
...

BGCalc::BGCalc( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}


BGCalc::~BGCalc() {
}


void BGCalc::beginJob() {

  // min and max energy, min and max point, number of selected events
  ...

  // sum of energies and sum of square energies
  ...

  return;

}


void BGCalc::update( const Event& ev ) {

  // total energy
  ...

  // loop over points and update sums
  ...
  for ( ... ) {
    ...
  }

  // update event counter
  ...
  return;

}


void BGCalc::endJob() {

  // compute background

  // number of points
  ...
  // total number of measurements
  ...
  // compute mean and rms
  ...
  // printout result
  cout << "background " << ... << " +- " << ... << endl;

  return;

}

