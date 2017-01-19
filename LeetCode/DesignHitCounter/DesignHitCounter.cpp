#include <iostream>
#include <queue>
#include <atomic>
#include <cstring>

#define PERIOD_MAX  (5*60)

using namespace std;

class HitCounter {
private:
	int total;
	atomic_flag lock;
	queue<pair<int,int> > timeline; /* (timestamp, count) */

	void update(int timestamp) {
		int low = timestamp - PERIOD_MAX;
		while (!timeline.empty() && timeline.front().first <= low) {
			total -= timeline.front().second;
			timeline.pop();
		}
	}

public:
	/** Initialize your data structure here. */
	HitCounter(): total(0), lock(ATOMIC_FLAG_INIT) {
	}

	/** Record a hit.
	 * @param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		while (lock.test_and_set(memory_order_acquire))
			;

		update(timestamp);

		if (!timeline.empty() && timeline.back().first == timestamp)
			++timeline.back().second;
		else
			timeline.push(make_pair(timestamp, 1));

		++total;

		lock.clear(memory_order_release);
	}

	/** Return the number of hits in the past 5 minutes.
	 * @param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		int ans;
		while (lock.test_and_set(memory_order_acquire))
			;

		update(timestamp);
		ans = total;

		lock.clear(memory_order_release);
		return ans;
	}
};

/**
 * Your HitCounter object will be instantiatied and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

int main(void) {
	cout.sync_with_stdio(false);
	HitCounter obj;
	obj.hit(1);
	obj.hit(2);
	obj.hit(3);
	cout << obj.getHits(4) << endl;
	obj.hit(300);
	cout << obj.getHits(300) << endl;
	cout << obj.getHits(301) << endl;
	cout << obj.getHits(1000) << endl;
	return 0;
}
