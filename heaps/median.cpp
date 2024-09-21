#include <queue>

using namespace std;

/*
  Maintain the median of a stream of numbers

  We will maintain the left half of the stream in a max-heap and the right half
  in a min-heap. The heaps will always be balanced
*/
class StreamMedian {
public:
  // Push to the correct heap then balance
  void insertNum(int num) {
    if (maxHeap.empty() || maxHeap.top() >= num) {
      maxHeap.push(num);
    } else {
      minHeap.push(num);
    }

    // pop from the maxHeap and put it into the minHeap
    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  float getMedian() {
    if (maxHeap.size() == minHeap.size()) {
      return (maxHeap.top() + minHeap.top()) / 2.0;
    }

    return maxHeap.top();
  }

private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
};

int main() {
  StreamMedian streamMedian;

  vector<int> vec{1, 10, 2, 7, 8, 12};

  for (auto x : vec) {
    printf("Added: %d\n", x);
    streamMedian.insertNum(x);
    printf("Median: %.1f\n", streamMedian.getMedian());
  }

  return 0;
}
