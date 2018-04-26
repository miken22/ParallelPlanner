#pragma once
#include "LiteState.h"
#include <algorithm>
#include <map>
#include <memory>
#include <vector>

/*
	Simple bucket priority queue implementation. Not generic.
*/

class BucketQueue{

	struct QueueComp{
		bool operator()(const std::shared_ptr<LiteState>& lhs, const std::shared_ptr<LiteState>& rhs) {
			return lhs->get_g() > rhs->get_g();
		}
	};

private:
	typedef std::vector<std::shared_ptr<LiteState> > Bucket;
	std::map<int, Bucket> queue;

public:
	BucketQueue() {}
	~BucketQueue() {}

	bool empty() {
		return queue.empty();
	}

	void push(std::shared_ptr<LiteState> state) {
		int current_f = state->get_f();
		Bucket& bucket = queue[current_f];
		bucket.push_back(state);
		std::sort(bucket.begin(), bucket.end(), QueueComp());
	}

	void pop() {
		if (!queue.empty()) {
			Bucket& bucket = queue.begin()->second;
			bucket.erase(bucket.begin());
			if (bucket.empty()) {
				queue.erase(queue.begin());
			}
		}
	}

	std::shared_ptr<LiteState> top() {
		return queue.begin()->second.front();
	}
};