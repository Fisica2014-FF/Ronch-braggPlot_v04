
... include header files ...

using namespace std;


TotalEnergy::TotalEnergy() {
}


TotalEnergy::~TotalEnergy() {
}


// function to be called when a new event arrives
void TotalEnergy::update( const Event& ev ) {
  // set sum at 0
  ...
  // loop over points
  ...
  for ( ... ) {
    // get energy measurement
    ...
    // increment sum
    ...
  }
  return;
}


// sum of measurements, no background subtraction
float TotalEnergy::rawSum() {
  // check for new event and return result
  ...
}

