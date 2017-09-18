#include <iostream>
#include <string>
#include <map>

using namespace std;

class MapSum {
	public:
	/** Initialize your data structure here. */
	MapSum() : mOrigin(), mPrefix() {
	}

	void insert(string key, int val) {
		auto it = mOrigin.find(key);
		if (it != mOrigin.end()) {
			int originVal = it->second;
			mOrigin[key] = val;
			val -= originVal;
		} else mOrigin[key] = val;
		for (int i = 1; i <= key.size(); i++) {
			string prefix = key.substr(0, i);
			if (mPrefix.find(prefix) == mPrefix.end()) mPrefix[prefix] = val;
			else mPrefix[prefix] += val;
		}
	}

	int sum(string prefix) {
		auto it = mPrefix.find(prefix);
		if (it == mPrefix.end()) return 0;
		return it->second;
	}

	private:
	map<string, int> mOrigin;
	map<string, int> mPrefix;
};

int main() {
	MapSum test;

	test.insert("apple", 3);
	cout<<test.sum("ap")<<endl;
	test.insert("app", 2);
	cout<<test.sum("ap")<<endl;

	return 0;
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
