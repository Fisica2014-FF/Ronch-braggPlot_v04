//... include header files ...

using namespace std;

// define a builder for this analyzer and register it
// builder to create an EnergyDist analyzer
class BGCalcBuilder: public AnalysisFactory::Builder {
public:
	// assign "bgcalc" as name for this analyzer and builder
	BGCalcBuilder() :
			AnalysisFactory::Builder("bgcalc") {
	}
	// create an EnergyDist when builder is run
	virtual AnalysisSteering* build(const AnalysisInfo* info) {
		return new BGCalc(info);
	}
};
// create a global BGCalcBuilder, so that it is created and registered
// before main execution start:
// when the AnalysisFactory::create function is run,
// an EnergyDistBuilder will be available with name "bgcalc".
static BGCalcBuilder bgcalcbuilder;

BGCalc::BGCalc(const AnalysisInfo* info) :
		AnalysisSteering(info) {
}

BGCalc::~BGCalc() {
}

void BGCalc::beginJob() {

	// min and max energy, min and max point, number of selected events
	MIN_ENERGY_ = 3000;
	MAX_ENERGY_ = 5000;
	min_points = 100;
	max_points = 120;
	number_of_events_ = 0;

	// sum of energies and sum of square energies
	sumenergies(max_points-min_points,0);
	sumsquares(max_points-min_points,0);
	return;

}

void BGCalc::update(const Event& ev) {

	// total energy
	auto totalenergy = TotalEnergy::instance()->rawSum();

	// check for total energy being in the required range,
	// if not return
	if (!(totalenergy > MIN_ENERGY_ and totalenergy < MAX_ENERGY_)) {
		return;
	}

	// loop over points and update sums
	// I'm not sure i have understood correctly, i suppose
	// i have to calculate the mean and RMS of the last 100 to 120
	// points
	for (unsigned i = 0; i < max_points - min_points; ++i) {
		sumenergies[i] += ev.energy(i);
		sumsquares[i] += (ev.energy(i) * ev.energy(i));
	}

	// update event counter
	++number_of_events_;

	return;
}

void BGCalc::endJob() {

	// compute background

	// number of points
	numpoints = max_points-min_points;
	// total number of measurements
	...
	// compute mean and rms
	for (unsigned i = 0; i < Event::minSize(); ++i) {
		meanenergies[i] = sumenergies[i] / double(number_of_events_);
		rmsenergies[i] = sqrt(
				sumsquares[i] / double(number_of_events_) - pow(
						sumenergies[i] / double(number_of_events_), 2));
	}
	// printout result
	cout << "background " << ... << " +- " << ... << endl;

	return;

}

