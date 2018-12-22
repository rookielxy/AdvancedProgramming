#include "jobs.h"

int main () {
	int n = 4;

	Job myjobs[4];

	myjobs[0] = {1,1,9,1};

	myjobs[1] = {2,4,3,2};

	myjobs[2] = {3,5,1,3};

	myjobs[3] = {4,17,5,4};

	JobSchedual *jobs = new JobSchedual(myjobs,n);

	jobs->RoundRobin(3);

	delete jobs;
}