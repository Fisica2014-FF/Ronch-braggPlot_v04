//============================================================================
// Name        : bP_v04.cpp
// Author      : Francesco Forcher
// Version     : 1.3
// Description : Modify Plot_v03 and use dispatcher&observers to loop over events
//============================================================================

#include <iostream>
#include <vector>

#include "AnalysisFactory.h"
#include "AnalysisInfo.h"
#include "AnalysisSteering.h"
#include "Event.h"
#include "EventSource.h"
#include "SourceFactory.h"

int main(int argc, char* argv[]) {
	using namespace std;

	// store command line parameters
	AnalysisInfo* info = new AnalysisInfo(argc, argv);

	// create data source
	EventSource* es = SourceFactory::create(info);

	// create a list of analyzers
	vector<AnalysisSteering*> aList = AnalysisFactory::create(info);

	cerr << "aList.size(): " << aList.size() << endl;

	// initialize all analyzers
	for (auto& as : aList) {
		as->beginJob();
	}

	// loop over events
	es->run();

	// finalize all analyzers
	for (auto& as : aList) {
		as->endJob();
	}

	//Clear memory
	for (auto& as : aList) {
		delete as;
	}
	delete es;

	return 0;
}

