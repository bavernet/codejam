#include <iostream>
#include <set>
#include <atomic>
#include <cstring>
#include <climits>

using namespace std;

class HitCounter {
private:
	static constexpr int PERIOD_MAX = 5*60;
	int lastCount, lastTimestamp;
	set<pair<int,int> > timeline;
	atomic_flag lock;

public:
	/** Initialize your data structure here. */
	HitCounter(): lastCount(0), lastTimestamp(INT_MIN), lock(ATOMIC_FLAG_INIT) {
	}

	/** Record a hit.
	 * @param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		int prevCount, prevTimestamp;
		bool turned = false;

		while (lock.test_and_set(memory_order_acquire))
			;

		if (lastTimestamp < timestamp) {
			prevCount = lastCount;
			prevTimestamp = lastTimestamp;
			lastTimestamp = timestamp;
			turned = true;
		}
		++lastCount;

		lock.clear(memory_order_release);

		if (turned) {
			timeline.insert(timeline.rbegin().base(), make_pair(prevTimestamp, prevCount));
			if (timeline.size() > PERIOD_MAX + 1)
				timeline.erase(timeline.begin());
		}
	}

	/** Return the number of hits in the past 5 minutes.
	 * @param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		int ans;
		while (lock.test_and_set(memory_order_acquire))
			;

		if (timestamp - PERIOD_MAX < lastTimestamp) {
			auto it = timeline.lower_bound(make_pair(timestamp - PERIOD_MAX + 1, INT_MIN));
			if (it == timeline.begin()) {
				ans = lastCount;
			} else {
				--it;
				ans = lastCount - it->second;
				timeline.erase(timeline.begin(), it);
			}
		} else {
			timeline.clear();
			ans = lastCount = 0;
			lastTimestamp = timestamp;
		}

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
