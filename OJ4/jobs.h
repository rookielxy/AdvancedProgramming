#ifndef OJ4_JOBSCHEDUAL_H
#define OJ4_JOBSCHEDUAL_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

struct Job {
	int id;
	int enter_time;
	int duration;
	int priority;
	int leftTime;
};

bool timeCompare(const Job &job1, const Job &job2) {
	return job1.enter_time < job2.enter_time;
}

bool priorityCompare(const Job &job1, const Job &job2) {
	return (job1.enter_time < job2.enter_time) or
			(job1.enter_time == job2.enter_time and job1.priority > job2.priority);
}

bool compare(const Job &job1, const Job &job2) {
	return job1.priority > job2.priority;
}

class JobSchedual {
private:
	vector<Job> queue;
public:
	JobSchedual(Job js[], int length): queue(js, js + length) {}
	~JobSchedual() = default;

	void FCFS();
	void RoundRobin(int time_slice);
	void PrioritySchedual();
};

void JobSchedual::FCFS() {
	if (queue.empty())
		return;
	for (auto &ele : queue)
		ele.leftTime = ele.duration;
	sort(queue.begin(), queue.end(), timeCompare);
	vector<Job> scheduler;
	for (int time = 0; not (scheduler.empty() and queue.empty()); ++time) {
		if (time == queue[0].enter_time) {
			scheduler.emplace_back(queue[0]);
			queue.erase(queue.begin());
		}
		if (scheduler.empty())
			continue;
		if (scheduler[0].leftTime == 0) {
			cout << scheduler[0].id << " " << time << endl;
			scheduler.erase(scheduler.begin());
		}
		--scheduler[0].leftTime;
	}
}

void JobSchedual::RoundRobin(int time_slice) {
	if (queue.empty())
		return;
	for (auto &ele : queue)
		ele.leftTime = ele.duration;

	sort(queue.begin(), queue.end(), timeCompare);
	vector<Job> scheduler;
	int slice = time_slice;
	for (int time = 0; not (scheduler.empty() and queue.empty()); ++time) {
		if (time == queue[0].enter_time) {
			scheduler.emplace_back(queue[0]);
			queue.erase(queue.begin());
		}
		if (scheduler.empty())
			continue;
		if (scheduler[0].leftTime == 0) {
			cout << scheduler[0].id << " " << time << endl;
			scheduler.erase(scheduler.begin());
			slice = time_slice;
		} else if (slice == 0 and scheduler[0].leftTime > 0){
			scheduler.emplace_back(scheduler[0]);
			scheduler.erase(scheduler.begin());
			slice = time_slice;
		}
		--scheduler[0].leftTime;
		--slice;
	}

}

void JobSchedual::PrioritySchedual() {
	if (queue.empty())
		return;
	sort(queue.begin(), queue.end(), priorityCompare);
	for (auto &ele : queue)
		ele.leftTime = ele.duration;
	vector<Job> scheduler;
	for (int time = 0; not (scheduler.empty() and queue.empty()); ++time) {
		if (time == queue[0].enter_time) {
			scheduler.emplace_back(queue[0]);
			queue.erase(queue.begin());
		}
		if (scheduler.empty())
			continue;
		sort(scheduler.begin(), scheduler.end(), compare);
		if (scheduler[0].leftTime == 0) {
			cout << scheduler[0].id << " " << time << endl;
			scheduler.erase(scheduler.begin());
		}
		--scheduler[0].leftTime;
	}
}

#endif //OJ4_JOBSCHEDUAL_H
