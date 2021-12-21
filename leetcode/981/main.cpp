#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class TimeMap {
public:
  unordered_map<string, vector<pair<int, string>>> map;
  TimeMap() {}
  
  void set(string key, string value, int timestamp) {
    map[key].push_back({timestamp, value});
  }

  int binSearch(const vector<pair<int, string>>& arr, int target) {
    int begin = 0, end = arr.size() - 1, mid;
    while (begin + 1 < end) {
      mid = int(floor((begin + end) / 2));
      if (arr[mid].first == target) return mid;
      else if (arr[mid].first > target) end = mid;
      else begin = mid;
    }
    if (begin < arr.size() - 1 && arr[begin + 1].first <= target) begin++;
    return begin;
  }
  
  string get(string key, int timestamp) {
    if (map.find(key) == map.end()) return "";
    vector<pair<int, string>>& values = map.at(key);
    int idx = binSearch(values, timestamp);
    if (values[idx].first <= timestamp) return values[idx].second;
    return "";
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */