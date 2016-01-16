#include "../EventSource.h"

#include "../Event.h"


EventSource::EventSource() {
}


EventSource::~EventSource() {
}

void EventSource::run() {
	const Event* ev;
	while ((ev = get())) {
		Dispatcher<Event>::notify(*ev);
		delete ev;
	}
}
